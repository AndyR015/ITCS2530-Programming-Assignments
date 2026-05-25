
//Andy Rizo ITCS-2530 Assignment 1



#include <iostream>
#include <string> // Useful as we will primarily use strings.

using namespace std; // Removes tedious work


/*

The main purpose of this program will be to take in three inputs from the user, and output them back in a way that makes sense.
For this scenario we will ask for a name, this can be a person place or thing, then we will ask for how to catagorize it, and then ask for a description.

We are limited to three inputs only.

No if, else, switch, for, or while functions.

Use variables, cin, and cout only.


*/

int main()
{
    string name = "Empty";
    string catagory = "Empty";
    string description = "Empty";

    

    cout << "To begin, what is the name of the person, place, or thing that interests you?\n";
    getline(std::cin, name);

    cout << endl;

    cout << "In one or two words, what is the topic or rather what would " << name << " be catagorized as:\n";
    getline(std::cin, catagory);

    cout << endl;

    cout << "Now what should the description of " << name << " be, before saving the entry?\n";
    getline(std::cin, description);

    cout << endl;
    cout << endl;
    cout << endl;


    cout << "Name: " << name;
    cout << endl;

    cout << "Catagory: " << catagory;
    cout << endl;

    cout << "Description: " << description;






    return 0;
}

// Write this as the commit message "Commit for Week 01 programming assignment"