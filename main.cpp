#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Contact
{
public:
    string name;
    string phone;

    void addContact()
    {
        ofstream file("contacts.txt", ios::app);

        cin.ignore();

        cout << "\nEnter Name: ";
        getline(cin, name);

        cout << "Enter Phone Number: ";
        getline(cin, phone);

        file << name << endl;
        file << phone << endl;

        file.close();

        cout << "\nContact Saved Successfully!\n";
    }

    void viewContacts()
    {
        ifstream file("contacts.txt");

        if (!file)
        {
            cout << "\nNo Contacts Found!\n";
            return;
        }

        cout << "\n===== CONTACT LIST =====\n";

        while (getline(file, name))
        {
            getline(file, phone);

            cout << "\nName  : " << name;
            cout << "\nPhone : " << phone;
            cout << "\n------------------------";
        }

        file.close();
    }

    void searchContact()
    {
        ifstream file("contacts.txt");

        string searchName;
        bool found = false;

        cin.ignore();

        cout << "\nEnter Name to Search: ";
        getline(cin, searchName);

        while (getline(file, name))
        {
            getline(file, phone);

            if (name == searchName)
            {
                cout << "\nContact Found!";
                cout << "\nName  : " << name;
                cout << "\nPhone : " << phone << endl;

                found = true;
                break;
            }
        }

        if (!found)
        {
            cout << "\nContact Not Found!\n";
        }

        file.close();
    }

    void deleteContact()
    {
        ifstream file("contacts.txt");
        ofstream temp("temp.txt");

        string deleteName;
        bool found = false;

        cin.ignore();

        cout << "\nEnter Name to Delete: ";
        getline(cin, deleteName);

        while (getline(file, name))
        {
            getline(file, phone);

            if (name != deleteName)
            {
                temp << name << endl;
                temp << phone << endl;
            }
            else
            {
                found = true;
            }
        }

        file.close();
        temp.close();

        remove("contacts.txt");
        rename("temp.txt", "contacts.txt");

        if (found)
        {
            cout << "\nContact Deleted Successfully!\n";
        }
        else
        {
            cout << "\nContact Not Found!\n";
        }
    }
};

int main()
{
    Contact c;
    int choice;

    do
    {
        cout << "\n===================================";
        cout << "\n   CONTACT MANAGEMENT SYSTEM";
        cout << "\n===================================";
        cout << "\n1. Add Contact";
        cout << "\n2. View All Contacts";
        cout << "\n3. Search Contact";
        cout << "\n4. Delete Contact";
        cout << "\n5. Exit";
        cout << "\n\nEnter Your Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            c.addContact();
            break;

        case 2:
            c.viewContacts();
            break;

        case 3:
            c.searchContact();
            break;

        case 4:
            c.deleteContact();
            break;

        case 5:
            cout << "\nExiting Program...\n";
            break;

        default:
            cout << "\nInvalid Choice! Try Again.\n";
        }

    } while (choice != 5);

    return 0;
}
