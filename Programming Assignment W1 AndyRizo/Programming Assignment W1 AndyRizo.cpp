

// Andy Rizo     Course : ITCS - 2530     Programming Assignment    Part 5  



//Headers
    #include <iostream>
    #include <string>
    #include <fstream>
    #include <iomanip>
    #include <windows.h>

    using namespace std;

//Prototypes in order
    void setColor(int color);

    void fileOpen(ofstream& outData);

    void closeFile(ofstream& outData);


    void welcomeBanner();


    string templateOptions();
    char convertToUppercase(string template_Chosen);


    string askForName();

    string askForCategory(string name);

    void askForAge(string name, int& age_years, int& age_months, int& age_days);

    int askForHeight(string name);

    double askForWeight(string name);

    string askForDescription();

    void convertMeasurements(int inches, double weight_lbs, int& height_feet, int& height_inches_remainder, double& height_centimeters, double& weight_kilos);
    


    void characterOutput(ofstream& outData, string name, string category, int age_years, int age_months, int age_days, int height_feet, int height_inches_remainder, double height_centimeters, double weight_lbs, double weight_kilos, string description);

    void locationOutput(ofstream& outData, string name, string category, string description);

    void textBoxCreator(ofstream& outdata);



    void characterTemplate(ofstream& outData);

    void locationTemplate(ofstream& outData);

    void customTemplate(ofstream& outData);

    void templateCreator(char template_chosen, ofstream& outData);
     

    void mainMenu(ofstream& outData);


//Main program
    int main()
    {
        ofstream outData;

        welcomeBanner();

        fileOpen(outData);

        mainMenu(outData);

        closeFile(outData);

        return 0;
    }
     





//Definitions Below
    
    //Color for console text
    void setColor(int color)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
    }

    //Welcome Banner
    void welcomeBanner()
    {
        setColor(2);

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

        setColor(15);
    }


    //Create new or add to file
    void fileOpen(ofstream& outData)
    {
        string file_choice = " ";

        cout << "Erase all saved data to create a new file, or keep using the current file?";
        cout << endl;
        cout << endl;
        cout << "Type \"erase\" to create a new file, otherwise press the enter key: ";
        getline(cin, file_choice);
        cout << endl;
        cout << endl;

        setColor(2);//Red

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

        setColor(15);//White
    }
    


    //Present the templates available to choose from, asking for variable choice.
    string templateOptions()
    {
        string template_chosen = " ";

        setColor(6);

        cout << "Templates: ( Person / Creature ) = \"a\", ( Location / Place ) = \"b\", ( Custom Note ) = \"c\", or to end the program type \"Stop\"";
        cout << endl;
        cout << endl;

        setColor(15);

        cout << "Selected Template: "; getline(cin, template_chosen);

        cout << endl;


        while (template_chosen != "a" && template_chosen != "A" && template_chosen != "b" && template_chosen != "B" && template_chosen != "c" && template_chosen != "C" && template_chosen != "stop" && template_chosen != "Stop")
        {

            setColor(4);
            cout << "Try selecting a template again: "; getline(cin, template_chosen);
            cout << endl;
            setColor(15);
        }

        return template_chosen;
    }


    //Converts uppercase strings to lowercase for switch statement later on
    char convertToUppercase(string template_Chosen)
    {

        if (template_Chosen == "A" || template_Chosen == "a")
        {
            return 'A';
        }
        if (template_Chosen == "B" || template_Chosen == "b")
        {
            return 'B';
        }
        if (template_Chosen == "C" || template_Chosen == "c")
        {
            return 'C';
        }

        return 'D';
    }

    //Asks for variable name
    string askForName()
    {
        string name = " ";

        cout << "Name: ";
        getline(cin, name);
        cout << endl;

        return name;
    }



    //Asks for variable catagory
    string askForCategory(string name)
    {

        string category = " ";

        cout << "What would " << name << " be categorized as: "; getline(cin, category);
        cout << endl;

        return category;
    }



    //Asks for age, variables: years months and days
    void askForAge(string name, int& age_years, int& age_months, int& age_days)
    {
        cout << "Age of " << name << " in years, months, and days: "; cin >> age_years >> age_months >> age_days;

        if (cin.fail())
        {
            do
            {
                setColor(4);
                cin.clear();
                cin.ignore(200, '\n');
                cout << "Try again using integer numbers. Age in years, months, and days: ";
                cin >> age_years >> age_months >> age_days;
                cout << endl;
                setColor(15);

            } while (cin.fail());
        }
        cout << endl;
    }



    //Asks for variable height
    int askForHeight(string name)
    {
        int height_inches = 0;

        cout << "Height of " << name << " in inches. Enter a zero if it does not apply:";
        cout << endl;
        cout << endl;
        cin.ignore(200, '\n');
        cin >> height_inches;
        if (cin.fail())
        {
            do
            {
                setColor(4);
                cin.clear();
                cin.ignore(200, '\n');
                cout << "Try again using an integer number. Height in inches: ";
                cin >> height_inches;
                cout << endl;
                setColor(15);

            } while (cin.fail());
        }
        cout << endl;
        return height_inches;
    }



    //Asks for variable weight
    double askForWeight(string name)
    {
        double weight_lbs = 0;

        cout << "Weight of " << name << " in lbs. Enter a zero if it does not apply:";
        cout << endl;
        cout << endl;
        cin.ignore(200, '\n');
        cin >> weight_lbs;
        if (cin.fail())
        {
            do
            {
                setColor(4);
                cin.clear();
                cin.ignore(200, '\n');
                cout << "Try again using an integer number. Weight in pounds: ";
                cin >> weight_lbs;
                cout << endl;
                setColor(15);
            } while (cin.fail());
        }

        cin.ignore(200, '\n');
        cout << endl;

        return weight_lbs;
    }



    //Asks for variable description
    string  askForDescription()
    {
        string description = " ";

        cout << "Description: ";
        getline(cin, description);
        cout << endl;
        cout << endl;
        cout << endl;

        return description;
    }



    //Height and Weight convertor
    void convertMeasurements(int height_inches, double weight_lbs, int& height_feet, int& height_inches_remainder, double& height_centimeters, double& weight_kilos)
    {
        height_feet = height_inches / 12;
        height_inches_remainder = height_inches % 12;
        height_centimeters = height_inches * 2.54;

        weight_kilos = weight_lbs * 0.45359237;
    }



    //Output graph to console and txt file. Option A.
    void characterOutput(ofstream& outData, string name, string category, int age_years, int age_months, int age_days, int height_feet, int height_inches_remainder, double height_centimeters, double weight_lbs, double weight_kilos, string description)
    {
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
    }

  

    //Output graph to console and txt file. Option B.
    void locationOutput(ofstream& outData, string name, string category, string description)
    {

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
    }



    //Template option A: Character/Creature.
    void characterTemplate(ofstream& outData)
    {
        int age_days = 0;
        int age_months = 0;
        int age_years = 0;

        int height_feet = 0;
        int height_inches_remainder = 0;

        double height_centimeters = 0;
        double weight_kilos = 0;

        setColor(2);
        cout << "Character template chosen.";
        setColor(15);

        cout << endl;
        cout << endl;

        //User Input Name
        string name = askForName();

        //User Input Catagory
        string category = askForCategory(name);

        //User Input Age
        askForAge(name, age_years, age_months, age_days);

        //User Input Height
        int height_inches = askForHeight(name);

        //User Input Weight
        double weight_lbs = askForWeight(name);

        //Inches to feet and weight lbs to kg
        convertMeasurements(height_inches, weight_lbs, height_feet, height_inches_remainder, height_centimeters, weight_kilos);

        //Description
        string description = askForDescription();

        characterOutput(outData, name, category, age_years, age_months, age_days, height_feet, height_inches_remainder, height_centimeters, weight_lbs, weight_kilos, description);
    }



    //Template option B: Location/Places.
    void locationTemplate(ofstream& outData)
    {
        //Display template chosen
        setColor(2);
        cout << "Location template chosen. ";
        setColor(15);

        cout << endl;
        cout << endl;

        //Name
        string name = askForName();

        //Catagory
        string category = askForCategory(name);

        //Description
        string description = askForDescription();

        locationOutput(outData, name, category, description);
    }



    //Template option C: Custom.
    void customTemplate(ofstream& outData)
    {
        string name = " ";
        //Name of topic as a whole
        setColor(2);
        cout << "Custom Note template chosen. No display will be created on the console, only on report.txt";
        setColor(15);

        cout << endl;
        cout << endl;

        cout << "Topic name: "; getline(cin, name);
        cout << endl;

        outData << "\t" << name;
        outData << endl;

        //This will create description boxes to use
        textBoxCreator(outData);
        outData << endl;
        outData << endl;
        outData << endl;
    }



    //Creates Text Boxes Based On Amount Needed 
    void textBoxCreator(ofstream& outData)
    {
        int amount = 0;

        cout << "How many text sections do you need: ";
        cin >> amount;
        cout << endl;
        if (cin.fail())
        {
            do {
                setColor(4);

                cin.clear();
                cin.ignore(200, '\n');
                cout << "Error try again. How many text sections do you need: "; cin >> amount;
                cout << endl;

                setColor(15);
            } while (cin.fail());
        }
        cout << endl;

        cin.ignore(200, '\n');

        //Depending on the amount of description boxes chosen, this will create one each repition.
        for (int i = 1; i <= amount; i++)
        {
            string category;
            string description;

            cout << "Catagory: "; getline(cin, category);
            cout << endl;
            cout << "Description: "; getline(cin, description);

            cout << endl;
            cout << endl;
            cout << endl;


            //Output to text File
            outData << category << ": " << description;
            outData << endl;
        }
    }



    //A switch statement that uses inputs to fill out the templates chosen earlier.
    void templateCreator(char template_chosen, ofstream& outData)
    {
        switch (template_chosen)
        {
        case 'A':
            characterTemplate(outData);
                break;

        case 'B':
            locationTemplate(outData);
            break;

        case 'C':
            customTemplate(outData);
            break;

        case 'D':
            break;
        }
    }


    //Not needed but may come in use later. Closes the text file.
    void closeFile(ofstream& outData)
    {
        outData.close();
    }

    //Main menu contains most of the functions and loops.
    void mainMenu(ofstream& outData)
    {
        string template_chosen;

        cout << "(Main menu)" << " You can select a template based on your needs.";
        cout << endl;
        cout << endl;
        
        do
        {
            //Functions Called
            template_chosen = templateOptions();

            char output = convertToUppercase(template_chosen);

            templateCreator(output, outData);

        } while (template_chosen != "Stop" && template_chosen != "stop");
    }
    

        

