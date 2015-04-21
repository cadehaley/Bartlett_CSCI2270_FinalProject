#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H
#include "string"

struct ContactNode{
	std::string name;
	int phoneNumber;
	int Group;
	ContactNode *next;
	ContactNode *previous;

	ContactNode(){};

	ContactNode(std::string in_name, int in_phoneNumber, int in_Group){
		name = in_name;
		phoneNumber = in_phoneNumber;
		Group = in_Group;
		next = NULL;
	}
};

class AddressBook
{
public:
    AddressBook();
    ~AddressBook();
    void addContact(string, int, string);
    void deleteContact();
    void printContacts();
    void findContact();
    void editContact();
    void groupCreate();
    void addContactToGroup();

private:
    ContactNode *head;
    ContactNode *tail;
};
#endif // ADDRESSBOOK_H
