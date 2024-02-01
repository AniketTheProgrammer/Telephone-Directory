import java.util.Scanner;

class Contact {
    String name;
    String telephone;
    String address;
    String relationship;
}

public class TelephoneDirectory {
    final static int MAX_CONTACTS = 100;
    static Contact[] directory = new Contact[MAX_CONTACTS];
    static int contactCount = 0;
    static Scanner scanner = new Scanner(System.in);

    static void addContact() {
        if (contactCount < MAX_CONTACTS) {
            Contact newContact = new Contact();
            System.out.print("Enter name: ");
            newContact.name = scanner.next();
            System.out.print("Enter telephone number: ");
            newContact.telephone = scanner.next();
            System.out.print("Enter address: ");
            newContact.address = scanner.next();
            System.out.print("Enter relationship: ");
            newContact.relationship = scanner.next();

            directory[contactCount] = newContact;
            contactCount++;
            System.out.println("Contact added successfully!");
        } else {
            System.out.println("Directory is full.");
        }
    }

    static void showContacts() {
        if (contactCount == 0) {
            System.out.println("No contacts in the directory.");
        } else {
            System.out.println("Contacts in the directory:");
            for (int i = 0; i < contactCount; i++) {
                System.out.println("Contact " + (i + 1) + ":");
                System.out.println("Name: " + directory[i].name);
                System.out.println("Telephone: " + directory[i].telephone);
                System.out.println("Address: " + directory[i].address);
                System.out.println("Relationship: " + directory[i].relationship);
                System.out.println();
            }
        }
    }

    static void updateContact() {
        if (contactCount == 0) {
            System.out.println("No contacts in the directory to update.");
        } else {
            System.out.print("Enter the name of the contact to update: ");
            String name = scanner.next();
            boolean found = false;
            for (int i = 0; i < contactCount; i++) {
                if (directory[i].name.equals(name)) {
                    System.out.print("Enter new telephone number: ");
                    directory[i].telephone = scanner.next();
                    System.out.print("Enter new address: ");
                    directory[i].address = scanner.next();
                    System.out.print("Enter new relationship: ");
                    directory[i].relationship = scanner.next();
                    System.out.println("Contact updated successfully!");
                    found = true;
                    break;
                }
            }
            if (!found) {
                System.out.println("Contact not found.");
            }
        }
    }

    static void deleteContact() {
        if (contactCount == 0) {
            System.out.println("No contacts in the directory to delete.");
        } else {
            System.out.print("Enter the name of the contact to delete: ");
            String name = scanner.next();
            boolean found = false;
            for (int i = 0; i < contactCount; i++) {
                if (directory[i].name.equals(name)) {
                    for (int j = i; j < contactCount - 1; j++) {
                        directory[j] = directory[j + 1];
                    }
                    contactCount--;
                    System.out.println("Contact deleted successfully!");
                    found = true;
                    break;
                }
            }
            if (!found) {
                System.out.println("Contact not found.");
            }
        }
    }

    public static void main(String[] args) {
        int choice;
        do {
            System.out.println("\nTelephone Directory");
            System.out.println("1. Add Contact");
            System.out.println("2. Show Contacts");
            System.out.println("3. Update Contact");
            System.out.println("4. Delete Contact");
            System.out.println("5. Exit");
            System.out.print("Enter your choice: ");
            choice = scanner.nextInt();

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
                    System.out.println("Exiting program. Goodbye!");
                    break;
                default:
                    System.out.println("Invalid choice. Please enter a valid option.");
            }
        } while (choice != 5);
    }
}
