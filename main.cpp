//45
#include <iostream>
#include <string>
#include <fstream>
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
                cout << "=== Login ===" << endl;
                cout << "\nUsername: ";
                cin >> username;
                cout << "Password: " ;
                cin >> password;
                
                // Reads eachline of file data.txt
                ifstream file("login.txt");
                getline(file, firstLine);
                getline(file, secondLine);
                getline(file, thirdLine);
                getline(file, fourthLine);
                // If data in file and user input is correct, succesful login
                if(firstLine == username && secondLine == password)
                {
                    cout << "Logged in succesfully!" << endl;
                    cout << "Welcome Back " << thirdLine << " " << fourthLine << endl;
                    break;
                }
                else{
                    cout << "Failed to login: try again...\n" << endl;
                }
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
            }
            else{// Error display
                cout << "Error: please try again...\n" << endl;
            }
        }
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
    
    // Start with the Login Page
    frontPage part1;
    part1.mainMenu();
}