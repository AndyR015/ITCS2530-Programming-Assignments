
*/
int main()
{

    //Variables
    string categories[10]; // SWITCHED TO ARRAY FOR CATEGORIES
    string descriptions[10]; // SWITCHED TO ARRAY FOR DESCRIPTIONS

    templateType output = CHARACTER; // INITIALIZE

    int greenText = 10;
    int redText = 4;


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

        //I would like to have a char variables present in my code and use switch for them but wish not to create more cases, so I reduced them this way.
        if (template_choice == "A" || template_choice == "a")
        {
            output = CHARACTER;
        }
        else if (template_choice == "B" || template_choice == "b") // CHAGED TO ELSE IF
        {
            output = LOCATION;
        }
        else if (template_choice == "C" || template_choice == "c") // CHANGED TO ELSE IF
        {
            output = CUSTOM;
        }
        else if (template_choice == "Stop" || template_choice == "stop") // ADDED STOP CONDITION
        {
            output = STOP;
        }

        //We start to make the notes using the templates chosen and output them to the console and text file once finished
        switch (output)
        {
        case CHARACTER:// Characters / Creatures

            changeColor(greenText);

            //Catagory
            cout << "In one or two words, what would " << name << " be categorized as: ";
            getline(cin, categories[0]); 
            cout << endl;

            //Description
            cout << "Now what should the description of " << name << " be, before saving the entry?";
            cout << endl;
            cout << endl;
            cin.ignore(200, '\n');
            getline(cin, descriptions[0]); // DESCRIPTION AT ARRAY INDEX 0
            cout << endl;
            cout << endl;
            cout << endl;

            //Height and Weight Calculator
            height_feet = height_inches / 12;
            height_inches_remainder = height_inches % 12;
            height_centimeters = height_inches * 2.54;

            weight_kilos = weight_lbs * 0.45359237;

            //Console output
            cout << "\t" << name << setw(24) << "( " << categories[0] << " )";
            cout << endl;
            cout << endl;

            cout << "\t" << "Age: " << setw(13) << " " << age_years << " Years " << age_months << " Months " << age_days << " Days";
            cout << endl;

            cout << "\t" << "Height: " << setw(10) << " " << height_feet << "\'" << height_inches_remainder << "\"  or  " << height_centimeters << "cm";
            cout << endl;

            cout << "\t" << fixed << setprecision(2) << "Weight: " << setw(10) << " " << weight_lbs << "lb  or  " << weight_kilos << "kg";
            cout << endl;
            cout << endl;

            cout << "\t" << "Description: " << descriptions[0];
            cout << endl;
            cout << endl;
            cout << endl;

            //Text File Output
            outData << "\t" << name << setw(24) << "( " << categories[0] << " )"; // OUTPUT CATEGORY ARRAY INDEX 0
            outData << endl;
            outData << endl;

            outData << "\t" << "Age: " << setw(13) << " " << age_years << " Years " << age_months << " Months " << age_days << " Days";
            outData << endl;

            outData << "\t" << "Height: " << setw(10) << " " << height_feet << "\'" << height_inches_remainder << "\"  or  " << height_centimeters << "cm";
            outData << endl;

            outData << "\t" << fixed << setprecision(2) << "Weight: " << setw(10) << " " << weight_lbs << "lb  or  " << weight_kilos << "kg";
            outData << endl;
            outData << endl;

            outData << "\t" << "Description: " << descriptions[0]; // OUTPUT DESCRIPTION ARRAY INDEX 0
            outData << endl;
            outData << endl;
            outData << endl;
            outData << endl;
            break;

        case LOCATION:// Location / Place

            changeColor(greenText);
            //Name
            cout << "Location template chosen. ";
            cout << endl;
            cout << endl;
            cout << "Name of location: ";
            getline(cin, name);
            cout << endl;

            //Catagory
            cout << "What is " << name << " categorized as? ";
            getline(cin, categories[0]);
            cout << endl;

            //Description
            cout << "Provide a description: ";
            cout << endl << endl;
            getline(cin, descriptions[0]);
            cout << endl;
            cout << endl;
            cout << endl;

            //Console Output
            cout << "\t" << name << setw(7) << "( " << categories[0] << " )"; // OUTPUT CATEGORY ARRAY INDEX 0
            cout << endl;
            cout << endl;
            cout << "\t" << "Description: " << descriptions[0];
            cout << endl;
            cout << endl;
            cout << endl;

            //Text File Output
            outData << "\t" << name << setw(14) << "( " << categories[0] << " )";
            outData << endl;
            outData << endl;
            outData << "\t" << "Description: " << descriptions[0]; // OUTPUT DESCRIPITON ARRAY INDEX 0
            outData << endl;
            outData << endl;
            outData << endl;
            outData << endl;
            break;

        case CUSTOM:// Custom Note

            changeColor(greenText);
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
            while (amount < 1 || amount > 10) { // ADDED WHILE LOOP TO HANDLE INPUT ERRORS, MUST HAVE 1-10 DESCRIPTION BOXES

                changeColor(redText);
                cin.clear();
                cin.ignore(200, '\n');

                cout << "\nPlease enter a number between 1 and 10.";
                cin >> amount;
            }

            changeColor(greenText);
            cout << endl;

            //Depending on the amount of description boxes chosen, this will create one each repition.
            for (int i = 0; i < amount; i++) // LOOP TO ASSIGN CATEGORIES/DESCRIPTIONS
            {
                cin.ignore(200, '\n');
                cout << "Category: ";
                getline(cin, categories[i]);
                while (categories[i].empty()) {

                    changeColor(redText);
                    cout << "Category cannot be blank: ";
                    getline(cin, categories[i]);
                }
                changeColor(greenText);
                cout << endl;
                cout << "Description: ";
                getline(cin, descriptions[i]);
                while (descriptions[i].empty()) {

                    changeColor(redText);
                    cout << "Description cannot be blank: ";
                    getline(cin, descriptions[i]);
                }
                changeColor(greenText);
                cout << endl;
            }

            // Output to report file
            outputCustom(categories, descriptions, amount, outData);
            cout << "Average description length: " << averageDescLength(descriptions, amount) << " characters" << endl << endl; // DISPLAY AVERAGE DESCRIPTION LENGTH
            break;

        default:

            changeColor(redText);
            cout << "Closing Program..." << endl;
        }

        //Repeats unless "Stop" is typed.
    } while ((template_choice != "Stop") && (template_choice != "stop")); // CHANGED || RELATION TO &&, LOOP CANNOT EXIT OTHERWISE

    //Text File Closed
    outData.close();
    //End of section.

    return 0;
}