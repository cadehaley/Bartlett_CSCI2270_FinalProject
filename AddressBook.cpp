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
    AddressBook::addContactToGroup(name, group);

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
    //print out name number and group
    AddressBook::printContacts(head);
}

void AddressBook::printContacts(ContactNode *node)
{
    if (head == NULL)
    {
        cout << "There are no contacts to print." << endl;
    }
    else
    {
        std::cout << "Name: " << node->name << std::endl;
        std::cout << "Phone Number: " << node->phoneNumber << std::endl;
        std::cout << "Group: " << node->Group << std::endl;
        AddressBook::printContacts(node->next);
    }
}

ContactNode* AddressBook::findContact(std::string name){
	ContactNode *node = NULL;
	return node;
}

void AddressBook::editContact(std::string name){
    std::string userInput;
    std::string userName;
    ContactNode *node = AddressBook::findContact(name);
    std::cout << "1. Name: " << node->name << std::endl;
    std::cout << "2. Phone Number: " << node->phoneNumber << std::endl;
    std::cout << "3. Group: " << node->Group << std::endl;
    std::cout << "To Edit Input Number Corresponding To Item." << std::endl;
    std::cin >> userInput;
    switch(userInput)
    {
        case 1:
            std:cout << "Type In New Name: " << std::endl;
            std::cin.ignore(100, '\n');
            std::getline(std::cin, userName);
            node->name = userName;
            std::cout << "Contacts Name Now Changed To: " << std::endl;
            std::cout << "Name: " << node->name << endl;
            break;
        case 2:
            std:cout << "Type In New Phone Number: " << std::endl;
            std::cin.ignore(100, '\n');
            std::getline(std::cin, userName);
            node->phoneNumber = std::stoi(userName);
            std::cout << "Contacts Phone Number Now Changed To: " << std::endl;
            std::cout << "Phone Number: " << node->phoneNumber << endl;
            break;
        case 3:
            std:cout << "Type In New Group: " << std::endl;
            std::cin.ignore(100, '\n');
            std::getline(std::cin, userName);
            AddressBook::addContactToGroup(node->name, userName);
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
		std::cout<<group<<" is not a group. Create it first or choose from the list of groups."<<std::endl;
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
