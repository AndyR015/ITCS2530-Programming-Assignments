

// Andy Rizo     Course: ITCS-2530     Programming Assignment ( Part 4 )



//Headers
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;



int main()
{

    //Variables
    ofstream outData;

    string name;
    string category;
    string description;
    string file_choice;
    string template_choice;

    char output;

    int amount;
    int i = 1;

    int age_days = 0;
    int age_months = 0;
    int age_years = 0;

    int height_inches = 0;
    int height_feet = 0;
    int height_inches_remainder = 0;

    double height_centimeters = 0;
    double weight_lbs = 0;
    double weight_kilos = 0;



    //Welcome Banner
    cout << endl;
    cout << endl;
    cout << " __                __ _________  ___         _______    ________       __      __       ________" << endl;
    cout << " \\ \\      /\\      / / | ______|  | |        |  _____|  |  ____  |     /  \\    /  \\     | _______|" << endl;
    cout << "  \\ \\    /  \\    / /  | |_____   | |        | |        | |    | |    / /\\ \\  / /\\ \\    | |______" << endl;
    cout << "   \\ \\  / /\\ \\  / /   | ______|  | |        | |        | |    | |   / /  \\ \\/ /  \\ \\   | _______|" << endl;
    cout << "    \\ \\/ /  \\ \\/ /    | |_____   | |______  | |_____   | |____| |  / /    \\  /    \\ \\  | |______" << endl;
    cout << "     \\__/    \\__/     |_______|  |_______|  |_______|  |________| /_/      \\/      \\_\\ |________|" << endl;
    cout << endl;
    cout << endl;
    cout << "This program will allow you to save information to a file, ranging from simple notes to anything you can think of.";
    cout << endl;
    cout << endl;
  


    //Option to create a new file or add to the current file using ios::app
    cout << "Erase all saved data to create a new file, or keep using the current file?";
    cout << endl;
    cout << endl;
    cout << "Type \"erase\" to create a new file, otherwise press the enter key: ";
    getline(cin, file_choice);
    cout << endl;
    cout << endl;

    if (file_choice == "Erase" || file_choice == "erase")
    {
        outData.open("report.txt");
        cout << "Creating a new file named: report.txt";
        cout << endl;
        cout << endl;

    }
    else
    {
        outData.open("report.txt", ios::app);
        cout << "Adding to the current file: report.txt";
        cout << endl;
        cout << endl;
    }


    //Main Menu is where the user selects a template to create a note, there are many nested selection statements inside.
    cout << "(Main menu)" << " You can select a template based on your needs.";
    cout << endl;
    cout << endl;

    do
    {
        cout << "Templates: ( Person / Creature ) = \"a\", ( Location / Place ) = \"b\", ( Custom Note ) = \"c\", or to end the program type \"Stop\"";
        cout << endl;
        cout << endl;

        cout << "Selected Template: ";  getline(cin, template_choice);

        cout << endl;



        //Error Handler For Template Choice variable
        while (template_choice != "a" && template_choice != "A" && template_choice != "b" && template_choice != "B" && template_choice != "c" && template_choice != "C" && template_choice != "stop" && template_choice != "Stop")
        {
            cout << "Try selecting a template again: "; getline(cin, template_choice);
            cout << endl;
        }



        //I would like to have a char variables present in my code and use switch for them but wish not to create more cases, so I reduced them this way.
        if (template_choice == "A" || template_choice == "a") 
        {
            output = 'a';
        }
        if (template_choice == "B" || template_choice == "b")
        {
            output = 'b';
        }
        if (template_choice == "C" || template_choice == "c")
        {
            output = 'c';
        }
        

        //We start to make the notes using the templates chosen and output them to the console and text file once finished
        switch (output)
        {   
        case 'a':// Characters / Creatures
          
            //Name
            cout << "Character template chosen." << endl << endl << "Name: ";
            getline(cin, name);
            cout << endl;

            //Catagory
            cout << "In one or two words, what would " << name << " be categorized as: ";
            getline(cin, category);
            cout << endl;

            //Age
            cout << "Age of " << name << " in years, months, and days.\nEnter three seperate zeros if it does not apply or a zero on any you are unsure of:";
            cout << endl;
            cout << endl;
            cin >> age_years >> age_months >> age_days;
            if (cin.fail())
            {
                cin.clear();
                cout << "Error: Year, Month, or Day has a non number as input.";
                cout << endl;
                cin.ignore(200, '\n');
            }
            cout << endl;

            //Height
            cout << "Height of " << name << " in inches. Enter a zero if it does not apply:";
            cout << endl;
            cout << endl;
            cin.ignore(200, '\n');
            cin >> height_inches;
            if (cin.fail())
            {
                cin.clear();
                cout << "Error: Height has a non number as input.";
                cout << endl;
                cin.ignore(200, '\n');
            }
            cout << endl;

            //Weight
            cout << "Weight of " << name << " in lbs. Enter a zero if it does not apply:"; 
            cout << endl;
            cout << endl;
            cin.ignore(200, '\n');
            cin >> weight_lbs;
            if (cin.fail())
            {
                cin.clear();
                cout << "Error: Weight has a non number as input.";
                cout << endl;
                cin.ignore(200, '\n');
            }
            cout << endl;

            //Description
            cout << "Now what should the description of " << name << " be, before saving the entry?";
            cout << endl;
            cout << endl;
            cin.ignore(200, '\n');
            getline(cin, description);
            cout << endl;
            cout << endl;
            cout << endl;



            //Height and Weight Calculator
            height_feet = height_inches / 12;
            height_inches_remainder = height_inches % 12;
            height_centimeters = height_inches * 2.54;

            weight_kilos = weight_lbs * 0.45359237;



            //Console output
            cout << "\t" << name << setw(24) << "( " << category << " )";
            cout << endl;
            cout << endl;

            cout << "\t" << "Age: " << setw(13) << " " << age_years << " Years " << age_months << " Months " << age_days << " Days";
            cout << endl;

            cout << "\t" << "Height: " << setw(10) << " " << height_feet << "\'" << height_inches_remainder << "\"  or  " << height_centimeters << "cm";
            cout << endl;

            cout << "\t" << fixed << setprecision(2) << "Weight: " << setw(10) << " " << weight_lbs << "lb  or  " << weight_kilos << "kg";
            cout << endl;
            cout << endl;

            cout << "\t" << "Description: " << description;
            cout << endl;
            cout << endl;
            cout << endl;
            


            //Text File Output
            outData << "\t" << name << setw(24) << "( " << category << " )";
            outData << endl;
            outData << endl;

            outData << "\t" << "Age: " << setw(13) << " " << age_years << " Years " << age_months << " Months " << age_days << " Days";
            outData << endl;

            outData << "\t" << "Height: " << setw(10) << " " << height_feet << "\'" << height_inches_remainder << "\"  or  " << height_centimeters << "cm";
            outData << endl;

            outData << "\t" << fixed << setprecision(2) << "Weight: " << setw(10) << " " << weight_lbs << "lb  or  " << weight_kilos << "kg";
            outData << endl;
            outData << endl;

            outData << "\t" << "Description: " << description;
            outData << endl;
            outData << endl;
            outData << endl;
            outData << endl;
            break;



        case 'b':// Location / Place

            //Name
            cout << "Location template chosen. ";
            cout << endl;
            cout << endl; 
            cout << "Name of location: ";
            getline(cin, name);
            cout << endl;

            //Catagory
            cout << "What is " << name << " categorized as? ";
            getline(cin, category);
            cout << endl;

            //Description
            cout << "Provide a description: ";
            cout << endl << endl;
            getline(cin, description);
            cout << endl;
            cout << endl;
            cout << endl;



            //Console Output
            cout << "\t" << name << setw(7) << "( " << category << " )";
            cout << endl;
            cout << endl;
            cout << "\t" << "Description: " << description;
            cout << endl;
            cout << endl;
            cout << endl;



            //Text File Output
            outData << "\t" << name << setw(14) << "( " << category << " )";
            outData << endl;
            outData << endl;
            outData << "\t" << "Description: " << description;
            outData << endl;
            outData << endl;
            outData << endl;
            outData << endl;
            break;



        case 'c':// Custom Note

            //Name
            cout << "Custom Note template chosen. Unfortunetly no display will be created except on the report.txt file.";
            cout << endl;
            cout << endl;
            cout << "Topic name: "; getline(cin, name);
            cout << endl;

            outData << "\t" << name;
            outData << endl;

            //This will ask for description boxes needed so you can name each one and add a description for each, cant have less than 1..
  
            cout << "How many text sections do you need: "; 
            cin >> amount;
            cout << endl;
            if (cin.fail())
            {
                do {
                    cin.clear();
                    cin.ignore(200, '\n');
                    cout << "Error try again. How many text sections do you need: "; cin >> amount;
                    cout << endl;
                }
                while (amount != true);
            }
            cout << endl;

            //Depending on the amount of description boxes chosen, this will create one each repition.
            for (int i = 1; i <= amount; i++)
            {
                cin.ignore(200, '\n');
                cout << "Catagory: "; getline(cin, category);
                cout << endl;
                cout << endl;
                cout << "Description: "; getline(cin, description);
                cout << endl;
                
                
                //Output to text File
                outData << category << ": " << description;
                outData << endl;  
            }
            outData << endl;
            outData << endl;
            outData << endl;
            break;



        default:
            cout << "Closing Program";

        }

        
        //Repeats unless "Stop" is typed.
    } while (template_choice != "Stop" || template_choice != "stop");


    //Text File Closed
    outData.close();
    //End of section.

    return 0;
}

