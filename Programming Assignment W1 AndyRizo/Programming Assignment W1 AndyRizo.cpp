
/*

Andy Rizo

Course: ITCS-2530 

Assignment: Programming Assignment 2

Tasks: 
     
Tasks Completed:  
    * Create a welcome banner.
    * At least three different kinds of inputs, int, double, strings, chars, etc.
    * Have at least one derived value.
    * Save to a text file.
    * Create if-then statements for invalid inputs.
    * Present a summary table using setw and alignment.
*/


//Headers
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{   
    //File Stream
    ofstream outData;


    //Variables
    string name = " ";
    string category = " ";
    string description = " ";

    int age_days = 0;
    int age_months = 0;
    int age_years = 0;

    int height_inches = 0;
    int height_feet = 0;
    int height_inches_remainder = 0;

    double height_centimeters = 0.0;
    double weight_lbs = 0.0;
    double weight_kilos = 0.0;
    //End of Variables



    //Opening Files
    outData.open("file_output.txt", ios::app);
    //End of File Opening


    //Welcome Banner
    cout << endl << endl;
    cout << " __                __ _________  ___         _______    ________       __      __       ________" << endl;
    cout << " \\ \\      /\\      / / | ______|  | |        |  _____|  |  ____  |     /  \\    /  \\     | _______|" << endl;
    cout << "  \\ \\    /  \\    / /  | |_____   | |        | |        | |    | |    / /\\ \\  / /\\ \\    | |______" << endl;
    cout << "   \\ \\  / /\\ \\  / /   | ______|  | |        | |        | |    | |   / /  \\ \\/ /  \\ \\   | _______|" << endl;
    cout << "    \\ \\/ /  \\ \\/ /    | |_____   | |______  | |_____   | |____| |  / /    \\  /    \\ \\  | |______" << endl;
    cout << "     \\__/    \\__/     |_______|  |_______|  |_______|  |________| /_/      \\/      \\_\\ |________|" << endl;
    cout << endl << endl;
    cout << "This program will create a text file saving your entries of anything you wish to catalog." << endl << endl << endl;
    //End of Welcome Banner




    //Data Input Section
    cout << "To begin, what is the name of the person, place, or thing that interests you?"; //Ask for name
    cout << endl << endl;
    getline(cin, name);
    cout << endl;
    

    cout << "In one or two words, what is the topic or rather what would " << name << " be categorized as:"; //Ask for catagory
    cout << endl << endl;
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
    //End of Data Input Section



    //Height and Weight Calculator
    height_feet = height_inches / 12;
    height_inches_remainder = height_inches % 12;
    height_centimeters = height_inches * 2.54;

    weight_kilos = weight_lbs * 0.45359237;
    // End of calculations



    //Final Results on the console
    cout << "\t" << name << setw(24) << "( " << category << " )" << endl << endl;

    cout << "\t" << "Age: " << setw(17) << age_years << " Years " << age_months << " Months " << age_days << " Days";
    cout << endl;

    cout << "\t" << "Height: " << setw(20) << height_feet << "\'" << height_inches_remainder << "\"  or  " << height_centimeters << "cm";
    cout << endl;

    cout << "\t" << "Weight: " << setw(20) << weight_lbs << "lb  or  " << weight_kilos << "kg";
    cout << endl << endl;

    cout << "\t" << "Description: " << description;
    cout << endl << endl << endl;
    //End of Final Results to Console


    //Final Results on the text file
    outData << "\t" << name << setw(20) << "( " << category << " )" << endl << endl;

    outData << "\t" << "Age: " << setw(17) << age_years << " Years " << age_months << " Months " << age_days << " Days";
    outData << endl;

    outData << "\t" << "Height: " << setw(20) << height_feet << "\'" << height_inches_remainder << "\"  or  " << height_centimeters << "cm";
    outData << endl;

    outData << "\t" << "Weight: " << setw(20) << weight_lbs << "lb  or  " << weight_kilos << "kg";
    outData << endl << endl;

    outData << "\t" << "Description: " << description;
    outData << endl << endl << endl;
    //End of Final Results to Text File


    //Text File Closed
    outData.close();
    //End of File Closing

    return 0;
}