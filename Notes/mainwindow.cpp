#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QClipboard>
#include <iostream>
#include <stdio.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //adding empty string vectors to notes vector for default groups
    for (int i=0;i<3;i++)
    {
        QVector<QString> x;
        notes.push_back(x);
    }
    //intializating shortcut V for adding note from clipboard
    shortcut_key=new QShortcut(this);
    shortcut_key->setKey(Qt::Key_V);
    connect(shortcut_key,SIGNAL(activated()),this,SLOT(on_shortcut_pushed()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_yourNotesComboBox_currentIndexChanged(int index)
{
    ui->yourNotesListWidget->clear();
    for (int i=0;i<notes[index].size();i++)
        ui->yourNotesListWidget->addItem(notes[index][i]);
}

void MainWindow::on_addNoteButton_clicked()
{
    QString note=ui->addNoteTextEdit->toPlainText();
    int add_note_combo_box_index=ui->addNoteComboBox->currentIndex();
    int your_notes_combo_box_index=ui->yourNotesComboBox->currentIndex();
    notes[add_note_combo_box_index].push_back(note);
    on_yourNotesComboBox_currentIndexChanged(your_notes_combo_box_index);
    ui->addNoteTextEdit->clear();
}

void MainWindow::on_archiveUpdateButton_clicked()
{
    ui->archiveListWidget->clear();
    for (int i=0;i<archive.size();i++)
        ui->archiveListWidget->addItem(archive[i]);
}

void MainWindow::moveToArchive(int index)
{
    int your_notes_combo_box_index=ui->yourNotesComboBox->currentIndex();
    int your_notes_list_index=index;
    if (your_notes_list_index==-1) {return;}
    archive.push_back(notes[your_notes_combo_box_index][your_notes_list_index]);
    on_archiveUpdateButton_clicked();
    notes[your_notes_combo_box_index].erase(notes[your_notes_combo_box_index].begin()+your_notes_list_index);
    on_yourNotesComboBox_currentIndexChanged(your_notes_combo_box_index);
}

void MainWindow::on_moveToArchiveButton_clicked()
{
    QItemSelectionModel *selections=ui->yourNotesListWidget->selectionModel();
    QModelIndexList indexes=selections->selectedIndexes();
    QVector<int> ind;
    for (auto it:indexes)
    {
        ind.push_back(it.row());
    }
    sort(ind.begin(),ind.end());
    for (int i=0;i<ind.size();i++)
    {
         moveToArchive(ind[i]-i);
    }
}

void MainWindow::on_archiveDeleteButton_clicked()
{
    int archive_list_index=ui->archiveListWidget->currentIndex().row();
    if (archive_list_index==-1) {return;}
    archive.erase(archive.begin()+archive_list_index);
    on_archiveUpdateButton_clicked();
}

void MainWindow::on_exportButton_clicked()
{
    int your_notes_combo_box_index=ui->yourNotesComboBox->currentIndex();
    if (your_notes_combo_box_index==-1) {return;}
    string file_name=ui->yourNotesComboBox->currentText().toLocal8Bit().constData();
    string category=file_name;
    file_name+=".txt";
    freopen(file_name.c_str(),"w",stdout);
    cout<<"Notes from category "<<category<<endl;
    for (int i=0;i<notes[your_notes_combo_box_index].size();i++)
    {
        string s=notes[your_notes_combo_box_index][i].toLocal8Bit().constData();
        cout<<"Note #"<<i+1<<":"<<endl;
        cout<<s<<endl;
        cout<<endl;
    }
}

void MainWindow::on_exportAllButton_clicked()
{
    freopen("All notes.txt","w",stdout);
    int pos=1;
    for (int i=0;i<notes.size();i++)
    {
        for (int j=0;j<notes[i].size();j++)
        {
            string s=notes[i][j].toLocal8Bit().constData();
            cout<<"Note #"<<pos<<":"<<endl;
            cout<<s<<endl;
            cout<<endl;
            pos++;
        }
    }
}

void MainWindow::on_shortcut_pushed()
{
    QString clipboard_text=QApplication::clipboard()->text();
    QString old_note=ui->addNoteTextEdit->toPlainText();
    cout<<clipboard_text.toLocal8Bit().constData();
    ui->addNoteTextEdit->setText(clipboard_text);
    on_addNoteButton_clicked();
    ui->addNoteTextEdit->setText(old_note);
}

void MainWindow::on_archiveDeleteAllButton_clicked()
{
    while (archive.size()>0)
    {
        archive.erase(archive.begin());
    }
    on_archiveUpdateButton_clicked();
}
