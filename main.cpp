#include <iostream>
#include <string>
#include <fstream>
#include <limits>
using namespace std;

class frontPage{
    // Private variables of frontPage class
    private:
    string username;
    string password;
    int introOption;
    string firstLine;
    string secondLine;
    string thirdLine;
    string fourthLine;

    // The only thing displayed onto the front page is the login and register options
    public:
    void mainMenu()
    {
        // Runs at constant loop until the user has logged in properly, giving permission to access the Personal Tracker
        while(true)
        {
            // Asks user to select one of ther displayed options by entering a digit
            cout << "Enter a number option please ..." << endl;
            cout << "1. Login" << endl;
            cout << "2. Register" << endl;
            cout << "Enter: ";
            cin >> introOption;

            // Asks user for Password and Username
            if(introOption == 1)
            {
                cout << "\n=== Login ===" << endl;
                cout << "Username: ";
                cin >> username;
                cout << "Password: " ;
                cin >> password;
                
                // Reads eachline of file data.txt
                ifstream Myfile("login.txt");
                getline(Myfile, firstLine);
                getline(Myfile, secondLine);
                getline(Myfile, thirdLine);
                getline(Myfile, fourthLine);
                // If data in file and user input is correct, succesful login
                if(firstLine == username && secondLine == password)
                {
                    cout << "Logged in succesfully!" << endl;
                    cout << "Welcome Back " << thirdLine << " " << fourthLine << "\n" << endl;
                    break;
                }
                else{
                    cout << "Failed to login: try again...\n" << endl;
                }
                Myfile.close();
            }
            // Asks user for FirstName, Lastname, New Password and New Username to register write on file
            else if(introOption == 2)
            {
                cout << "=== Register ===" << endl;
                cout << "First Name: ";
                cin >> thirdLine;
                cout << "Last Name: ";
                cin >> fourthLine;
                cout << "New Username: ";
                cin >> firstLine;
                cout << "New Password: ";
                cin >> secondLine;

                // Open file that already exists, then writes new info onto eachline
                ofstream MyFile("login.txt");
                MyFile << firstLine << endl;
                MyFile << secondLine << endl;
                MyFile << thirdLine << endl;
                MyFile << fourthLine << endl;
                cout << "Succesfully created an account!" << endl;
                cout << "Please login...\n" << endl; //Verify again by logging in
                MyFile.close();
            }
            else{// Error display
                cout << "Error: please try again...\n" << endl;
            }
        }
    }
};

class transactions{
    //Declaring variables when adding a new transaction
    private:
    string title;
    float amount;
    string date;
    string category;
    string description;
    string findATitle;

    public:
    
    void addTransaction()
    {
        cout << "Fill Out the Transaction details." << endl;

        cout << "Title: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, title);

        cout << "Amount: $";
        cin >> amount;

        cout << "Date: ";
        cin >> date;

        cout << "Category: ";
        cin >> category;

        cout << "Description: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin,description);

        ofstream MyFile("transactions.txt", ios::app);
        MyFile << title << endl;
        MyFile << amount << endl;
        MyFile << date << endl;
        MyFile << category << endl;
        MyFile << description << "\n" << endl;
        MyFile.close();
        cout << "Added New Transaction" << endl;
    }

    void deleteTransaction()
    {
        //Open my transaction file and temp file
        ifstream MyFile("transactions.txt");
        ofstream Tempfile("temp.txt"); // Reprint the new file without the deleted Transaction

        // Specifically find the title of a transaction to delete
        cout << "Enter the title of the transaction: ";
        getline(cin , findATitle);

        // current line
        string line;

        while(getline(MyFile, line)) // on the current line to compare
        {
            //if the current line == the title I am looking for
            if(line == findATitle)
            {
                //skips the next 4 lines
                getline(MyFile, line);
                getline(MyFile, line);
                getline(MyFile, line);
                getline(MyFile, line);
                getline(MyFile, line);
                
                //continues the next lines
                continue;
            }
            //Keeps everything else in file, not the deleted parts
            Tempfile << line << endl;
        }
        //Closing files
        MyFile.close();
        Tempfile.close();

        //remove the old transaction
        remove("transactions.txt");
        //rename the temp.txt into the new transaction
        rename ("temp.txt", "transactions.txt");
    }

    void viewTransations()
    {
        cout << "=======================================" << endl;
        // Acces the transaaction file history
        ifstream MyFile("transactions.txt");
        string title, amount, date, category, description, line;
        
        //Goes through each line
       while(getline(MyFile, title))
       { 
            //skips blanks
            if(title.empty())
            {
                continue;
            }
            //Displats Transactions on screen
            cout << "Title: ";
            cout << title << endl;

            cout << "Amount: ";
            getline(MyFile, amount);
            cout << amount << endl;

            cout << "Date: ";
            getline(MyFile, date);
            cout << date << endl;

            cout << "Category: ";
            getline(MyFile, category);
            cout << category << endl;

            cout << "Description: ";
            getline(MyFile, description);
            cout << description << endl;
            cout << "=======================================" << endl;
       }
    }
    
    void calculateBalance()
    {

    }
    void searchTransactions()
    {

    }
    void spendSummary()
    {

    }

    
};

int main()
{
    // Opening or creating a file for user
    ifstream check("login.txt");
    if(!check) // Creates the file if doesnt exist in local file drive
    {
        cout << "=== Welcome New User to Kage Personal Expense Tracker ===\n" << endl;
    }
    else // Greets the user, different due to the file already create, proving that its a regular user
    {
        cout << "=== Welcome Back to Kage Personal Expense Tracker ===\n" << endl;    
    }
    check.close();
    
    // Start with the Login Page
    frontPage part1;
    part1.mainMenu();

    // Open or create transaction file histoy
    ifstream checkT("transactions.txt");
    if(!checkT)
    {
        cout << "=== New Transaction Page Loaded ===" << endl;
    }
    else
    {
        cout << "=== Transaction Page Loaded ===" << endl;
    }
    checkT.close();


    transactions part2;
    // part2.addTransaction();
    part2.viewTransations();


}