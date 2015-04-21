#include "AddressBook.h"
#include "iostream"
#include "string"

AddressBook::AddressBook(){
    head = NULL;
    tail = NULL;
}

AddressBook::~AddressBook(){

}

void AddressBook::addContact(std::string name, int phone, std::string group){
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

void AddressBook::deleteContact(std::string name){
    if(head == NULL)
    {
        std::cout << "There are no contacts to delete." << std::endl;
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

void AddressBook::groupCreate(){

}

void AddressBook::addContactToGroup(std::string name, std::string group){
	ContactNode *node = AddressBook::findContact(name);
	node->Group = group;
}
