#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QShortcut>
#include <QString>
#include <QVector>
#include <vector>
#include <string>
#include <string.h>

using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_addNoteButton_clicked();

    void on_yourNotesComboBox_currentIndexChanged(int index);

    void on_moveToArchiveButton_clicked();

    void on_archiveUpdateButton_clicked();

    void on_archiveDeleteButton_clicked();

    void on_exportButton_clicked();

    void on_exportAllButton_clicked();

    void on_shortcut_pushed();

    void on_archiveDeleteAllButton_clicked();

private:
    void moveToArchive(int index);

    Ui::MainWindow *ui;
    QVector<QVector<QString>> notes;
    QVector<QString> archive;
    QShortcut *shortcut_key;
};

#endif // MAINWINDOW_H
