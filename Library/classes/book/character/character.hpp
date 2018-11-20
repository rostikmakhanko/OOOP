#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <vector>

using namespace std;

class Character
{
private:
    vector<string> names;
    string get_type_of_role(int);

public:
    vector<pair<string,int>> books;//title of book and role (0-main character, 1 - supporting, 2 - episode role)
    void print_info();
};

#endif // CHARACTER_H
