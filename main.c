#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 100

struct Contact {
    char name[50];
    char telephone[20];
    char address[100];
    char relationship[50];
};

struct Contact directory[MAX_CONTACTS];
int contactCount = 0;

void addContact() {
    if (contactCount < MAX_CONTACTS) {
        struct Contact newContact;
        printf("Enter name: ");
        scanf("%s", newContact.name);
        printf("Enter telephone number: ");
        scanf("%s", newContact.telephone);
        printf("Enter address: ");
        scanf("%s", newContact.address);
        printf("Enter relationship: ");
        scanf("%s", newContact.relationship);

        directory[contactCount] = newContact;
        contactCount++;
        printf("Contact added successfully!\n");
    } else {
        printf("Directory is full.\n");
    }
}

void showContacts() {
    if (contactCount == 0) {
        printf("No contacts in the directory.\n");
    } else {
        printf("Contacts in the directory:\n");
        for (int i = 0; i < contactCount; i++) {
            printf("Contact %d:\n", i + 1);
            printf("Name: %s\n", directory[i].name);
            printf("Telephone: %s\n", directory[i].telephone);
            printf("Address: %s\n", directory[i].address);
            printf("Relationship: %s\n", directory[i].relationship);
            printf("\n");
        }
    }
}

void updateContact() {
    if (contactCount == 0) {
        printf("No contacts in the directory to update.\n");
    } else {
        char name[50];
        printf("Enter the name of the contact to update: ");
        scanf("%s", name);
        int found = 0;
        for (int i = 0; i < contactCount; i++) {
            if (strcmp(directory[i].name, name) == 0) {
                printf("Enter new telephone number: ");
                scanf("%s", directory[i].telephone);
                printf("Enter new address: ");
                scanf("%s", directory[i].address);
                printf("Enter new relationship: ");
                scanf("%s", directory[i].relationship);
                printf("Contact updated successfully!\n");
                found = 1;
                break;
            }
        }
        if (!found) {
            printf("Contact not found.\n");
        }
    }
}

void deleteContact() {
    if (contactCount == 0) {
        printf("No contacts in the directory to delete.\n");
    } else {
        char name[50];
        printf("Enter the name of the contact to delete: ");
        scanf("%s", name);
        int found = 0;
        for (int i = 0; i < contactCount; i++) {
            if (strcmp(directory[i].name, name) == 0) {
                for (int j = i; j < contactCount - 1; j++) {
                    directory[j] = directory[j + 1];
                }
                contactCount--;
                printf("Contact deleted successfully!\n");
                found = 1;
                break;
            }
        }
        if (!found) {
            printf("Contact not found.\n");
        }
    }
}

int main() {
    int choice;
    do {
        printf("\nTelephone Directory\n");
        printf("1. Add Contact\n");
        printf("2. Show Contacts\n");
        printf("3. Update Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

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
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 5);

    return 0;
}
