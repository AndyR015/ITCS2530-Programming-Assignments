

/*

Andy Rizo

Course: ITCS-2530

Programming Assignment ( Part 3 )

*/


//Headers
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

//End of section


int main()
{

    //Variables
    ofstream outData;

    string name;
    string category;
    string description;

    char file_choice;
    char menu_choice;

    int age_days;
    int age_months;
    int age_years;

    int height_inches;
    int height_feet;
    int height_inches_remainder;

    double height_centimeters;
    double weight_lbs;
    double weight_kilos;
    //End of section


    //Welcome Banner
    cout << endl << endl;
    cout << " __                __ _________  ___         _______    ________       __      __       ________" << endl;
    cout << " \\ \\      /\\      / / | ______|  | |        |  _____|  |  ____  |     /  \\    /  \\     | _______|" << endl;
    cout << "  \\ \\    /  \\    / /  | |_____   | |        | |        | |    | |    / /\\ \\  / /\\ \\    | |______" << endl;
    cout << "   \\ \\  / /\\ \\  / /   | ______|  | |        | |        | |    | |   / /  \\ \\/ /  \\ \\   | _______|" << endl;
    cout << "    \\ \\/ /  \\ \\/ /    | |_____   | |______  | |_____   | |____| |  / /    \\  /    \\ \\  | |______" << endl;
    cout << "     \\__/    \\__/     |_______|  |_______|  |_______|  |________| /_/      \\/      \\_\\ |________|" << endl;
    cout << endl << endl;
    cout << "This program will allow you to save information to a file, ranging from simple notes to anything you can think of." << endl << endl;
    //End of section

    //Option to open file with or without ios::app
    cout << "To begin, would you like to start a new file or add entries to an existing file?" << endl << endl;
    cout << "Enter x to create a new file or y to continue with an existing file: ";
    cin >> file_choice;
    cout << endl << endl;

    if (file_choice == 'X' || file_choice == 'x')
    {
        outData.open("report.txt");
        cout << "Creating a new file." << endl << endl;
    }
    else 
        if (file_choice == 'Y' || file_choice == 'y')
    {

        outData.open("report.txt", ios::app);
        cout << "Adding to previous file." << endl << endl;
        
    }
    else
        cout << "An error occured. Adding to a previous file as a safegaurd." << endl << endl;
    //End of section.


    //Menu options
    cout << "(Main menu)" << "  Choose a template for your needs:" << endl <<"Character/Creature = \"a\", Location/Place = \"b\" Or create a simple note with just a description = \"c\"" << endl << endl;

    cout << "Option: ";
    cin >> menu_choice;
    cin.ignore(200, '\n');
    cout << endl;


    switch (menu_choice)
    {
        case 'a':
        cout << "Character template chosen." << endl << endl << "Name: "; //Ask for name
        getline(cin, name);
        cout << endl;

        cout << "In one or two words, what would " << name << " be categorized as: "; //Ask for catagory
        getline(cin, category);
        cout << endl;

        cout << "Age of " << name << " in years, months, and days.\nEnter three seperate zeros if it does not apply or a zero on any you are unsure of:"; //Ask for age
        cout << endl << endl;
        cin >> age_years >> age_months >> age_days;
        if (cin.fail())
        {   // Error Handler 
            cin.clear();
            cout << "Error: Year, Month, or Day has a non number as input." << endl;
            cin.ignore(200, '\n');
        }
        cout << endl;

        cout << "Height of " << name << " in inches. Enter a zero if it does not apply:"; //Ask for Height
        cout << endl << endl;
        cin.ignore(200, '\n');
        cin >> height_inches;
        if (cin.fail())
        {   // Error Handler 
            cin.clear();
            cout << "Error: Height has a non number as input." << endl;
            cin.ignore(200, '\n');
        }
        cout << endl;

        cout << "Weight of " << name << " in lbs. Enter a zero if it does not apply:"; //Ask for Height
        cout << endl << endl;
        cin.ignore(200, '\n');
        cin >> weight_lbs;
        if (cin.fail())
        {   // Error Handler 
            cin.clear();
            cout << "Error: Weight has a non number as input." << endl;
            cin.ignore(200, '\n');
        }
        cout << endl;

        cout << "Now what should the description of " << name << " be, before saving the entry?"; //Ask for a description
        cout << endl << endl;
        cin.ignore(200, '\n');
        getline(cin, description);
        cout << endl << endl << endl;
        break;
        
        //Seperator

        case 'A':
        cout << "Character template chosen." << endl << "Name: "; //Ask for name
        getline(cin, name);
        cout << endl;

        cout << "In one or two words, what would " << name << " be categorized as: "; //Ask for catagory
        getline(cin, category);
        cout << endl;

        cout << "Age of " << name << " in years, months, and days.\nEnter three seperate zeros if it does not apply or a zero on any you are unsure of:"; //Ask for age
        cout << endl << endl;
        cin >> age_years >> age_months >> age_days;
        if (cin.fail())
        {   // Error Handler 
            cin.clear();
            cout << "Error: Year, Month, or Day has a non number as input." << endl;
            cin.ignore(200, '\n');
        }
        cout << endl;

        cout << "Height of " << name << " in inches. Enter a zero if it does not apply:"; //Ask for Height
        cout << endl << endl;
        cin.ignore(200, '\n');
        cin >> height_inches;
        if (cin.fail())
        {   // Error Handler 
            cin.clear();
            cout << "Error: Height has a non number as input." << endl;
            cin.ignore(200, '\n');
        }
        cout << endl;

        cout << "Weight of " << name << " in lbs. Enter a zero if it does not apply:"; //Ask for Height
        cout << endl << endl;
        cin.ignore(200, '\n');
        cin >> weight_lbs;
        if (cin.fail())
        {   // Error Handler 
            cin.clear();
            cout << "Error: Weight has a non number as input." << endl;
            cin.ignore(200, '\n');
        }
        cout << endl;

        cout << "Now what should the description of " << name << " be, before saving the entry?"; //Ask for a description
        cout << endl << endl;
        cin.ignore(200, '\n');
        getline(cin, description);
        cout << endl << endl << endl;
        break;

        //Seperator 

        case 'b':
        cout << "Location template chosen. " << endl << endl << "Name of location: "; //Ask for name
        getline(cin, name);
        cout << endl;

        cout << "What is " << name << " categorized as? "; //Ask for catagory like city or country
        getline(cin, category);
        cout << endl;

        cout << "Provide a description: "; //Ask for a description
        cout << endl << endl;
        getline(cin, description);
        cout << endl << endl << endl;

        break;

        //Seperator 

        case 'B':
        cout << "Location template chosen. " << endl << endl << "Name of location: "; //Ask for name
        getline(cin, name);
        cout << endl;

        cout << "What is " << name << " categorized as? "; //Ask for catagory like city or country
        getline(cin, category);
        cout << endl;

        cout << "Provide a description: "; //Ask for a description
        cout << endl << endl;
        getline(cin, description);
        cout << endl << endl << endl;

        break;

        //Seperator 

        case 'c':
        cout << "Simple note template chosen. " << endl << "Topic name: "; //Ask for name
        cout << endl << endl;
        getline(cin, name);
        cout << endl;

        cout << "Description: "; //Ask for a description
        cout << endl << endl;
        cin.ignore(200, '\n');
        getline(cin, description);
        cout << endl << endl << endl;
        break;

        //Seperator

        case 'C':
        cout << "Simple note template chosen. " << endl << "Topic name: "; //Ask for name
        cout << endl << endl;
        getline(cin, name);
        cout << endl;

        cout << "Description: "; //Ask for a description
        cout << endl << endl;
        cin.ignore(200, '\n');
        getline(cin, description);
        cout << endl << endl << endl;
        break;

        //Seperator 

        default:
        cout << "An error occured. Missing a, b, or c as input." << endl;
        break;
    }


    //Height and Weight Calculator
    if (menu_choice == 'a')
    {
        height_feet = height_inches / 12;
        height_inches_remainder = height_inches % 12;
        height_centimeters = height_inches * 2.54;

        weight_kilos = weight_lbs * 0.45359237;
    }
    //End of calculations



    //Final Results on the console

    switch (menu_choice)
    {
        case 'a':
        cout << "\t" << name << setw(24) << "( " << category << " )" << endl << endl;

        cout << "\t" << "Age: " << setw(13) << " " << age_years << " Years " << age_months << " Months " << age_days << " Days";
        cout << endl;

        cout << "\t" << "Height: " << setw(10) << " " << height_feet << "\'" << height_inches_remainder << "\"  or  " << height_centimeters << "cm";
        cout << endl;

        cout << "\t" << fixed << setprecision(2) << "Weight: " << setw(10) << " " << weight_lbs << "lb  or  " << weight_kilos << "kg";
        cout << endl << endl;

        cout << "\t" << "Description: " << description;
        cout << endl << endl << endl;
        break;

        //Seperator

        case 'A':
        cout << "\t" << name << setw(24) << "( " << category << " )" << endl << endl;

        cout << "\t" << "Age: " << setw(13) << " " << age_years << " Years " << age_months << " Months " << age_days << " Days";
        cout << endl;

        cout << "\t" << "Height: " << setw(10) << " " << height_feet << "\'" << height_inches_remainder << "\"  or  " << height_centimeters << "cm";
        cout << endl;

        cout << "\t" << fixed << setprecision(2) << "Weight: " << setw(10) << " " << weight_lbs << "lb  or  " << weight_kilos << "kg";
        cout << endl << endl;

        cout << "\t" << "Description: " << description;
        cout << endl << endl << endl;
        break;

        //Seperator

        case 'b':
        cout << "\t" << name << setw(7) << "( " << category << " )" << endl << endl;

        cout << "\t" << "Description: " << description;
        cout << endl << endl << endl;
        break;

        //Seperator

        case 'B':
        cout << "\t" << name << setw(7) << "( " << category << " )" << endl << endl;

        cout << "\t" << "Description: " << description;
        cout << endl << endl << endl;
        break;

        //Seperator

        case 'c':
        cout << "\t" << name << endl << endl;

        cout << "\t" << "Description: " << description;
        cout << endl << endl << endl;
        break;

        //Seperator

        case 'C':
        cout << "\t" << name << endl << endl;

        cout << "\t" << "Description: " << description;
        cout << endl << endl << endl;
        break;
    }
    //End of section.


    //Final Results on the text file
    switch (menu_choice)
    {
        case 'a':
        outData << "\t" << name << setw(24) << "( " << category << " )" << endl << endl;

        outData << "\t" << "Age: " << setw(13) << " " << age_years << " Years " << age_months << " Months " << age_days << " Days";
        outData << endl;

        outData << "\t" << "Height: " << setw(10) << " " << height_feet << "\'" << height_inches_remainder << "\"  or  " << height_centimeters << "cm";
        outData << endl;

        outData << "\t" << fixed << setprecision(2) << "Weight: " << setw(10) << " " << weight_lbs << "lb  or  " << weight_kilos << "kg";
        outData << endl << endl;

        outData << "\t" << "Description: " << description;
        outData << endl << endl << endl;
        break;

        //Seperator

        case 'A':
        outData << "\t" << name << setw(24) << "( " << category << " )" << endl << endl;

        outData << "\t" << "Age: " << setw(13) << " " << age_years << " Years " << age_months << " Months " << age_days << " Days";
        outData << endl;

        outData << "\t" << "Height: " << setw(10) << " " << height_feet << "\'" << height_inches_remainder << "\"  or  " << height_centimeters << "cm";
        outData << endl;

        outData << "\t" << fixed << setprecision(2) << "Weight: " << setw(10) << " " << weight_lbs << "lb  or  " << weight_kilos << "kg";
        outData << endl << endl;

        outData << "\t" << "Description: " << description;
        outData << endl << endl << endl;
        break;

        //Seperator

        case 'b':
        outData << "\t" << name << setw(14) << "( " << category << " )" << endl << endl;

        outData << "\t" << "Description: " << description;
        outData << endl << endl << endl;
        break;

        //Seperator
        
        case 'B':
        cout << "\t" << name << setw(14) << "( " << category << " )" << endl << endl;

        cout << "\t" << "Description: " << description;
        cout << endl << endl << endl;
        break;

        //Seperator

        case 'c':
        outData << "\t" << name << endl << endl;

        outData << "\t" << "Description: " << description;
        outData << endl << endl << endl;
        break;

        //Seperator

        case 'C':
        outData << "\t" << name << endl << endl;

        outData << "\t" << "Description: " << description;
        outData << endl << endl << endl;
        break;
    }
    ////End of section.


    //Text File Closed
    outData.close();
    //End of section.

    return 0;
}

