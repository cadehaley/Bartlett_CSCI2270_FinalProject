#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H
#include "string"
#include "vector"

struct ContactNode{
	std::string name;
	int phoneNumber;
	std::string Group;
	ContactNode *next;
	ContactNode *previous;

	ContactNode(){};

	ContactNode(std::string in_name, int in_phoneNumber, std::string in_Group){
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
	void addContact(std::string name, int phone, std::string group);
	void deleteContact(std::string name);
	void printContacts();
	ContactNode* findContact(std::string name);
	void editContact(std::string name);
  	void groupCreate();
  	void addContactToGroup(std::string name, std::string group);
private:
	ContactNode *head;
	ContactNode *tail;
};
#endif // ADDRESSBOOK_H
