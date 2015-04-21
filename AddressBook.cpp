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

}

ContactNode* AddressBook::findContact(std::string name){
	ContactNode *node = NULL;
	return node;
}

void AddressBook::editContact(std::string name){

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
