#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool IsLogged()
{
    string username, password, un, pw;
    cout << "Enter Username: ";
    cin >> username;
    cout << "Enter Password: ";
    cin >> password;

    ifstream read("data\\" + username + ".txt");
    getline(read, un);
    getline(read, pw);

    if ((un == username) && (pw == password))
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    int choice;
    cout << "1. Sign Up\n2. Sign In\nYour Choice: ";
    cin >> choice;

    if (choice == 1)
    {
        string username, password;

        cout << "Enter Your Username: ";
        cin >> username;
        cout << "Enter Your Password: ";
        cin >> password;

        ofstream file;
        file.open("data\\" + username + ".txt");
        file << username << endl
             << password;
        file.close();

        main();
    }
    else if (choice == 2)
    {
        bool status = IsLogged();
        if (!status)
        {
            cout << "Invalid Username/Password" << endl;
            //        For Linux User
            
            system("exit");
            //         For Windows User
            //         system("PAUSE");
            return 0;
        }
        else
        {
            cout << "Successfully Logged In!" << endl;
            //        For Linux User
            system("exit");
            //        For Windows User
            //        system("PAUSE");
            return 1;
        }
    }
}
