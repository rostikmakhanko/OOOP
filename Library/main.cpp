#include <iostream>
#include <string>
#include <vector>
#include "classes/book/book.hpp"
#include "classes/binary_search_tree.hpp"

using namespace std;

int main()
{
    BinarySearchTree library;//library in format of binary search tree
    Book book1;
    book1.title="A Scandal in Bohemia";
    book1.authors.push_back("Arthur Conan Doyle");
    book1.day=25; book1.month=6; book1.year=1891;
    book1.number_of_pages=150;
    book1.short_annotation="The story is notable for introducing the character of Irene Adler, who is one of the most notable female characters in the Sherlock Holmes series, despite appearing in only one story.";
    library.paste(book1);
    book1.title="The Jungle Book";
    book1.authors.clear();
    book1.authors.push_back("Rudyard Kipling");
    book1.day=12; book1.month=2; book1.year=1894;
    book1.number_of_pages=243;
    book1.short_annotation="A major theme in the book is abandonment followed by fostering, as in the life of Mowgli, echoing Kipling's own childhood.";
    library.paste(book1);
    library.print();
    return 0;
}
