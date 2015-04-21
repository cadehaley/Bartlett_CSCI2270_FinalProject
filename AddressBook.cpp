#include "AddressBook.h"
#include "iostream"
#include "string"

AddressBook::AddressBook(){
    head = NULL;
    tail = NULL;
}

AddressBook::~AddressBook(){

}

void AddressBook::addContact(string name, int phone, string group){
    ContactNode *node = ContactNode(name, phone, group);

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

void AddressBook::deleteContact(){
    if(head == NULL)
    {
        cout << "There are no contacts to delete." << endl;
    }

    else
    {
        ContactNode *node = AddressBook::findContact(string, int, int);
    }
}

void AddressBook::printContacts(){

}

void AddressBook::findContact(){

}

void AddressBook::editContact(std::string name){	

}

void AddressBook::groupCreate(){

}

void AddressBook::addContactToGroup(std::string name, std::string group){
	ContactNode *node = AddressBook::findContact(name);
	node->Group = group;
}