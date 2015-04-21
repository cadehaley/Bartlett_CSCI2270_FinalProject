#include "AddressBook.h"
#include "iostream"
#include "string"

<<<<<<< HEAD
AddressBook::AddressBook(){
	head = NULL;
	tail = NULL;
=======
AddressBook::AddressBook()
{
    head = NULL;
    tail = NULL;
}

AddressBook::~AddressBook()
{

}

void AddressBook::addContact(string name, int phone, string group)
{
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

void AddressBook::deleteContact()
{
    if(head == NULL)
    {
        cout << "There are no contacts to delete." << endl;
    }

    else
    {
        ContactNode *node = AddressBook::findContact(string, int, int);
    }
>>>>>>> cf45ff4ebfcd5c5ad167990c372e1cc1a70ca379
}

void AddressBook::printContacts()
{

}

<<<<<<< HEAD
void AddressBook::addContact(std::string name, int phone, std::string group){

}

void AddressBook::deleteContact(std::string name, int phone, std::string group){}
=======
void AddressBook::findContact()
{

}
>>>>>>> cf45ff4ebfcd5c5ad167990c372e1cc1a70ca379

void AddressBook::editContact()
{

<<<<<<< HEAD
ContactNode* AddressBook::findContact(std::string name){}
=======
}
>>>>>>> cf45ff4ebfcd5c5ad167990c372e1cc1a70ca379

void AddressBook::groupCreate()
{

<<<<<<< HEAD
void AddressBook::groupCreate(){

}

void AddressBook::addContactToGroup(std::string name, std::string group){
	ContactNode *node = AddressBook::findContact(name);
	node->Group = group;
}
=======
}

void AddressBook::addContactToGroup()
{

}
>>>>>>> cf45ff4ebfcd5c5ad167990c372e1cc1a70ca379
