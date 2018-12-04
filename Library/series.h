#ifndef SERIES_H
#define SERIES_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "classes/binary_search_tree.hpp"
#include "classes/book/character/character.hpp"

using namespace std;

class Series
{
private:
    vector<vector<string>> series;

public:
    Series(BinarySearchTree&,vector<Character>&);
    void print();

};

#endif // SERIES_H
