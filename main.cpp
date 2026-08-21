//45
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class frontPage{
    private:
    string username;
    string password;
    int introOption;
    bool ifError = false;

    public:
    void mainMenu()
    {
        while(true)
        {
            cout << "Enter an option please..." << endl;
            cout << "1. Login" << endl;
            cout << "2. Register" << endl;
            cout << "Enter: ";
            cin >> introOption;

            if(introOption == 1)
            {
                string firstLine;
                string secondLine;
                string thirdLine;
                string fourthLine;

                cout << "\nUsername: ";
                cin >> username;
                cout << "Password:" ;
                cin >> password;
                
                ifstream file("data.txt");
                getline(file, firstLine);
                getline(file, secondLine);
                getline(file, thirdLine);
                getline(file, fourthLine);

                if(firstLine == username && secondLine == password)
                {
                    cout << "Logged in succesfully!" << endl;
                    cout << "Welcome Back " << thirdLine << " " << fourthLine << endl;
                    break;
                }
                else{
                    cout << "Failed to login: try again..." << endl;
                }
            }
            else if(introOption == 2)
            {

            }
            else{
                cout << "Error: please try again" << endl;
                break;

            }
        }
    }
};

int main()
{
    ifstream check("data.txt");
    if(!check)
    {
        cout << "=== Welcome New User to Kage Personal Expense Tracker ===\n" << endl;
    }
    else
    {
        cout << "=== Welcome Back to Kage Personal Expense Tracker ===" << endl;
        cout << "Loading...\n" << endl;
    }
    if(!check)
    {
        cout << "error" << endl;
        
    }

    frontPage Person1;
    Person1.mainMenu();
}