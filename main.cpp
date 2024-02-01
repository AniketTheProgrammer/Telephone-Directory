#include <iostream>
#include <string>
unsing namespace std;
#define MAX_CONTACTS 100

struct Contact {
    string name;
    string telephone;
    string address;
    string relationship;
};

Contact directory[MAX_CONTACTS];
int contactCount = 0;

void addContact() {
    if (contactCount < MAX_CONTACTS) {
        Contact newContact;
        cout << "Enter name: ";
        cin >> newContact.name;
        cout << "Enter telephone number: ";
        cin >> newContact.telephone;
        cout << "Enter address: ";
        cin >> newContact.address;
        cout << "Enter relationship: ";
        cin >> newContact.relationship;

        directory[contactCount] = newContact;
        contactCount++;
        cout << "Contact added successfully!" << endl;
    } else {
        cout << "Directory is full." << endl;
    }
}

void showContacts() {
    if (contactCount == 0) {
        cout << "No contacts in the directory." << endl;
    } else {
        cout << "Contacts in the directory:" << endl;
        for (int i = 0; i < contactCount; i++) {
            cout << "Contact " << i + 1 << ":" << endl;
            cout << "Name: " << directory[i].name << endl;
            cout << "Telephone: " << directory[i].telephone << endl;
            cout << "Address: " << directory[i].address << endl;
            cout << "Relationship: " << directory[i].relationship << endl;
            cout << endl;
        }
    }
}

void updateContact() {
    if (contactCount == 0) {
        cout << "No contacts in the directory to update." << endl;
    } else {
        string name;
        cout << "Enter the name of the contact to update: ";
        cin >> name;
        int found = 0;
        for (int i = 0; i < contactCount; i++) {
            if (directory[i].name == name) {
                cout << "Enter new telephone number: ";
                cin >> directory[i].telephone;
                cout << "Enter new address: ";
                cin >> directory[i].address;
                cout << "Enter new relationship: ";
                cin >> directory[i].relationship;
                cout << "Contact updated successfully!" << endl;
                found = 1;
                break;
            }
        }
        if (!found) {
            cout << "Contact not found." << endl;
        }
    }
}

void deleteContact() {
    if (contactCount == 0) {
        cout << "No contacts in the directory to delete." << endl;
    } else {
        string name;
        cout << "Enter the name of the contact to delete: ";
        cin >> name;
        int found = 0;
        for (int i = 0; i < contactCount; i++) {
            if (directory[i].name == name) {
                for (int j = i; j < contactCount - 1; j++) {
                    directory[j] = directory[j + 1];
                }
                contactCount--;
                cout << "Contact deleted successfully!" << endl;
                found = 1;
                break;
            }
        }
        if (!found) {
            cout << "Contact not found." << endl;
        }
    }
}

int main() {
    int choice;
    do {
        cout << "\nTelephone Directory" << endl;
        cout << "1. Add Contact" << endl;
        cout << "2. Show Contacts" << endl;
        cout << "3. Update Contact" << endl;
        cout << "4. Delete Contact" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                showContacts();
                break;
            case 3:
                updateContact();
                break;
            case 4:
                deleteContact();
                break;
            case 5:
                cout << "Exiting program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
        }
    } while (choice != 5);

    return 0;
}
