#include "AddressBook.h"
#include "iostream"
#include "string"

AddressBook::AddressBook(){
	head = NULL;
	tail = NULL;
}

AddressBook::~AddressBook(){

}

void AddressBook::addContact(std::string name, int phone, int group, bool is_first){
	
}

void AddressBook::deleteContact(std::string name, int phone, int group){}

void AddressBook::printContacts(){}

ContactNode* AddressBook::findContact(std::string name){}

void AddressBook::editContact(){}

void AddressBook::groupCreate(){

}

void AddressBook::addContactToGroup(std::string name, int group){
	ContactNode *node = AddressBook::findContact(name);
	node->Group = group;
}
