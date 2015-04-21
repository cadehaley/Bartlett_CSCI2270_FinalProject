#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H
#include "string"
#include "vector"

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
	void addContact(std::string name, int phone, int group);
	void deleteContact(std::string name, int phone, int group);
	void printContacts();
	ContactNode* findContact();
	void editContact();
  	void groupCreate();
  	void addContactToGroup(std::string name, int group);
private:
	ContactNode *head;
	ContactNode *tail;
};
#endif // ADDRESSBOOK_H
