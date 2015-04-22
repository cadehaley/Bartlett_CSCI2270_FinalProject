#include "AddressBook.h"
#include "iostream"
#include "string"
#include "vector"

AddressBook::AddressBook(){
	head = NULL;
	tail = NULL;
}

AddressBook::~AddressBook(){

}

void AddressBook::addContact(std::string name, int phone, std::string group){
	ContactNode *node = new ContactNode(name, phone);

	if(head == NULL)
	{
	  node->previous = NULL;
	  head = node;
	  tail = node;
	}

	else
	{
	  node->previous = tail;
	  tail->next = node;
	  tail = node;
	}
}

void AddressBook::deleteContact(std::string name){
	if(head == NULL)
	{
	  printf("There are no contacts to delete.\n");
	}

	else
	{
		ContactNode *node = AddressBook::findContact(name);
		if(node->previous == NULL)
		{
			head = head->next;
			head->previous = NULL;
			node = NULL;
		}

		else if(node->next == NULL)
		{
			tail = tail->previous;
			tail->next = NULL;
			node = NULL;
		}

		else
		{
			node->previous->next = node->next;
			node->next->previous = node->previous;
			node = NULL;
		}
	}
}

void AddressBook::printContacts(){
    // Calls the private function printContacts
    AddressBook::printContacts(head);
}

void AddressBook::printContacts(ContactNode *node)
{
    // It will enter this if statement if the head of the list is NULL it means there are no contacts to print out
    if (head == NULL)
    {
        std::cout << "There are no contacts to print." << std::endl;
    }
    // If the head does not equal NULL it will enter this else statement and print out the contact info
    else
    {
        std::cout << "Name: " << node->name << std::endl;
        std::cout << "Phone Number: " << node->phoneNumber << std::endl;
        std::cout << "Group: " << node->Group << std::endl;
        // This moves it to the next contact and it will keep doing that until there are not anymore
        AddressBook::printContacts(node->next);
    }
}

ContactNode* AddressBook::findContact(std::string name){
	ContactNode *node = NULL;
	return node;
}

void AddressBook::editContact(std::string name){
    // What type of information they are going to change
    std::string userInput;
    // The new information they want to put in
    std::string userNew;
    // Finds which contact you are looking for
    ContactNode *node = AddressBook::findContact(name);
    std::cout << "1. Name: " << node->name << std::endl;
    std::cout << "2. Phone Number: " << node->phoneNumber << std::endl;
    std::cout << "3. Group: " << node->Group << std::endl;
    std::cout << "To Edit Input Number Corresponding To Item." << std::endl;
    // Takes in what option the user wants to change
    std::cin >> userInput;
    // This is where we are going to switch the old contact info with the new contact info we want to put in
    switch(userInput)
    {
        // Case 1 is for the name
        case 1:
            std:cout << "Type In New Name: " << std::endl;
            // This is for even if you have spaces or periods in the input line you will still get the whole thing
            std::cin.ignore(100, '\n');
            // This gets the whole input line and puts it into the userNew
            std::getline(std::cin, userNew);
            // This changes the nodes name to userNew name
            node->name = userNew;
            std::cout << "Contacts Name Now Changed To: " << std::endl;
            std::cout << "Name: " << node->name << std::endl;
            break;
        // Case 2 is for the phone number
        case 2:
            std:cout << "Type In New Phone Number: " << std::endl;
            // This is for even if you have spaces or periods in the input line you will still get the whole thing
            std::cin.ignore(100, '\n');
            // This gets the whole input line and puts it into the userNew
            std::getline(std::cin, userNew);
            // This changes the nodes phone number to userNew phone number
            node->phoneNumber = std::stoi(userNew);
            std::cout << "Contacts Phone Number Now Changed To: " << std::endl;
            std::cout << "Phone Number: " << node->phoneNumber << std::endl;
            break;
        // Case 3 if for the group
        case 3:
            std:cout << "Type In New Group: " << std::endl;
            // This is for even if you have spaces or periods in the input line you will still get the whole thing
            std::cin.ignore(100, '\n');
            // This gets the whole input line and puts it into the userNew
            std::getline(std::cin, userNew);
            // Calls the addContactToGroup function
            AddressBook::addContactToGroup(node->name, userNew);
            break;
        default:
            break;
    }
}

void AddressBook::groupCreate(std::string name){
	GroupNames.push_back(name);
	std::cout<<"Group "<<name<<" was created."<<std::endl;
}

void AddressBook::addContactToGroup(std::string name, std::string group){
	ContactNode *node = AddressBook::findContact(name);
	if(node != NULL){
		node->Group = group;
	}
	else{
		std::cout<<group<<" is not a group. Create it first or Choose from the list of groups."<<std::endl;
		printf("Contact was not added to a group.\n");
	}
}

void AddressBook::printGroups(){
	if(GroupNames.empty()){
		printf("No Groups have been made yet.\n");
	}
	else{
		printf("Groups:\n");
		std::cout << GroupNames[0];
		for (unsigned int i = 1; i < GroupNames.size(); ++i){
			std::cout<<", "<<GroupNames[i];
		}
		std::cout<<std::endl;
	}
}
