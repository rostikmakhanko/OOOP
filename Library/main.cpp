#include <iostream>
#include <string>
#include <vector>
#include "classes/book/book.hpp"
#include "classes/binary_search_tree.hpp"
#include "series.h"

using namespace std;

int main()
{
    BinarySearchTree library;//library in format of binary search tree
    vector<Character> characters;//vector of characters
    Book book1;

    ///ADDING BOOKS
    book1.set_title("A Scandal in Bohemia");
    book1.add_author("Arthur Conan Doyle");
    book1.set_day(25); book1.set_month(6); book1.set_year(1891);
    book1.set_number_of_pages(150);
    book1.set_short_annotation("The story is notable for introducing the character of Irene Adler, who is one of the most notable female characters in the Sherlock Holmes series, despite appearing in only one story.");
    library.paste(book1);
    book1.clear();

    book1.set_title("The Jungle Book");
    book1.add_author("Rudyard Kipling");
    book1.set_day(12); book1.set_month(2); book1.set_year(1894);
    book1.set_number_of_pages(243);
    book1.set_short_annotation("A major theme in the book is abandonment followed by fostering, as in the life of Mowgli, echoing Kipling's own childhood.");
    library.paste(book1);
    book1.clear();

    book1.set_title("The Hound of the Baskervilles");
    book1.add_author("Arthur Conan Doyle");
    book1.set_day(1); book1.set_month(12); book1.set_year(1901);
    book1.set_number_of_pages(340);
    book1.set_short_annotation("Originally serialised in The Strand Magazine from August 1901 to April 1902, it is set largely on Dartmoor in Devon in England's West Country and tells the story of an attempted murder inspired by the legend of a fearsome, diabolical hound of supernatural origin.");
    library.paste(book1);
    book1.clear();

    book1.set_title("The Adventure of the Empty House");
    book1.add_author("Arthur Conan Doyle");
    book1.set_day(14); book1.set_month(5); book1.set_year(1903);
    book1.set_number_of_pages(50);
    book1.set_short_annotation("The story takes place in 1894, three years after the death of Sherlock Holmes. On the night of March 30, an apparently unsolvable locked-room murder takes place in London: the Park Lane Mystery, the killing of the Honourable Ronald Adair, son of the Earl of Maynooth, a colonial governor in Australia.");
    library.paste(book1);
    book1.clear();

    book1.set_title("The Second Jungle Book");
    book1.add_author("Rudyard Kipling");
    book1.set_day(19); book1.set_month(4); book1.set_year(1895);
    book1.set_number_of_pages(220);
    book1.set_short_annotation("First published in 1895, it features five stories about Mowgli and three unrelated stories, all but one set in India, most of which Kipling wrote while living in Vermont.");
    library.paste(book1);
    book1.clear();
    ///END OF ADDING BOOKS

    library.print();

    ///ADDING CHARACTERS
    Character c1;
    c1.add_name("Sherlock Holmes");
    c1.add_name("Sherlock");
    c1.add_book("A Scandal in Bohemia",0);
    c1.add_book("The Hound of the Baskervilles",0);
    characters.push_back(c1);
    c1.clear();

    c1.add_name("John Watson");
    c1.add_name("Dr Watson");
    c1.add_book("A Scandal in Bohemia",0);
    c1.add_book("The Hound of the Baskervilles",0);
    characters.push_back(c1);
    c1.clear();

    c1.add_name("Mycroft Holmes");
    c1.add_book("A Scandal in Bohemia",2);
    c1.add_book("The Adventure of the Empty House",1);
    characters.push_back(c1);
    c1.clear();

    c1.add_name("Iren Adler");
    c1.add_name("Mrs Adler");
    c1.add_book("A Scandal in Bohemia",1);
    characters.push_back(c1);
    c1.clear();

    c1.add_name("Mowgli");
    c1.add_name("Man-cub");
    c1.add_name("Frog");
    c1.add_book("The Jungle Book",0);
    c1.add_book("The Second Jungle Book",0);
    characters.push_back(c1);
    c1.clear();

    c1.add_name("Kaa");
    c1.add_book("The Jungle Book",1);
    characters.push_back(c1);
    c1.clear();
    ///END OF ADDING CHARACTERS

    Series series(library,characters);
    series.print();
    return 0;
}
