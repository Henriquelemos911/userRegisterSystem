#include <iostream>
using namespace std;

// Max number of users I will save
const int MAXUSERS = 100;

// Function to show the menu
char showMenu();

// This struct is for store user data
struct User
{
    string username;
    string email;
    string password;
};

int main()
{
    User users[MAXUSERS]; // Array to save all users
    int registredUsers = 0; // How many users I already added
    char option;

    do
    {
        option = showMenu(); // Show the menu and get the option
        cout << "\n\n";

        if (option == '1') // Add new user
        {
            if (registredUsers < MAXUSERS) // If I can add more
            {
                cout << "Type username: ";
                cin.ignore(); // To fix the getline after cin
                getline(cin, users[registredUsers].username);

                cout << "type user email: ";
                getline(cin, users[registredUsers].email);

                cout << "Type user password: ";
                getline(cin, users[registredUsers].password);

                registredUsers++; // One more user added

                // Show success message
                cout << "\nNew user: " << users[registredUsers - 1].username << " added!\n\n\n";
            }
            else
            {
                // Can't add more
                cout << "Numero maximo de user alcançados.\n\n\n"; // (I forgot to translate this part lol)
            }
        }
        else if (option == '2') // Show all users
        {
            cout << "\n+------ Users List ------\n";
            for (int i = 0; i < registredUsers; i++)
            {
                cout << "| " << i + 1 << ". username: " << users[i].username << endl;
                cout << "|    email: " << users[i].email << endl;
                cout << "|    password: " << users[i].password << endl;
                cout << "+------------------------" << endl;
            }
        }

    } while (option != '3'); // 3 means exit
    return 0;
}

// This function show the options and return the selected one
char showMenu()
{
    char option;

    cout << "\n\n= CHOOSE A OPTION =" << endl;
    cout << "1.Add new user" << endl;
    cout << "2.Show all users" << endl;
    cout << "3.exit" << endl;
    cout << "Choose a option: ";
    cin >> option;

    return option;
}
