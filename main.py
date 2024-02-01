class Contact:
    def __init__(self, name, telephone, address, relationship):
        self.name = name
        self.telephone = telephone
        self.address = address
        self.relationship = relationship

MAX_CONTACTS = 100
directory = []
contactCount = 0

def addContact():
    global contactCount
    if contactCount < MAX_CONTACTS:
        name = input("Enter name: ")
        telephone = input("Enter telephone number: ")
        address = input("Enter address: ")
        relationship = input("Enter relationship: ")

        new_contact = Contact(name, telephone, address, relationship)
        directory.append(new_contact)
        contactCount += 1
        print("Contact added successfully!")
    else:
        print("Directory is full.")

def showContacts():
    global contactCount
    if contactCount == 0:
        print("No contacts in the directory.")
    else:
        print("Contacts in the directory:")
        print("")
        print(f"Contact\t\tName\t\tTelephone\tAddress\t\tRelationship")
        print("---------------------------------------------------------------------------")
        for i, contact in enumerate(directory, start=1):
            print(f"{i}\t\t{contact.name}\t\t{contact.telephone}\t\t{contact.address}\t\t{contact.relationship}")
            print("-----------------------------------------------------------------------------")
            # print(f"Name: {contact.name}")
            # print(f"Telephone: {contact.telephone}")
            # print(f"Address: {contact.address}")
            # print(f"Relationship: {contact.relationship}")
            print()

def updateContact():
    global contactCount
    if contactCount == 0:
        print("No contacts in the directory to update.")
    else:
        name = input("Enter the name of the contact to update: ")
        found = False
        for contact in directory:
            if contact.name == name:
                contact.telephone = input("Enter new telephone number: ")
                contact.address = input("Enter new address: ")
                contact.relationship = input("Enter new relationship: ")
                print("Contact updated successfully!")
                found = True
                break
        if not found:
            print("Contact not found.")

def deleteContact():
    global contactCount
    if contactCount == 0:
        print("No contacts in the directory to delete.")
    else:
        name = input("Enter the name of the contact to delete: ")
        found = False
        for i, contact in enumerate(directory):
            if contact.name == name:
                del directory[i]
                contactCount -= 1
                print("Contact deleted successfully!")
                found = True
                break
        if not found:
            print("Contact not found.")

def main():
    global contactCount
    while True:
        print("\nTelephone Directory")
        print("1. Add Contact")
        print("2. Show Contacts")
        print("3. Update Contact")
        print("4. Delete Contact")
        print("5. Exit")
        choice = int(input("Enter your choice: "))

        if choice == 1:
            addContact()
        elif choice == 2:
            showContacts()
        elif choice == 3:
            updateContact()
        elif choice == 4:
            deleteContact()
        elif choice == 5:
            print("Exiting program. Goodbye!")
            break
        else:
            print("Invalid choice. Please enter a valid option.")

if __name__ == "__main__":
    main()
