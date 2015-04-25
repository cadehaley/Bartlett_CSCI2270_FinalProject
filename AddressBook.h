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

	ContactNode(std::string in_name, int in_phoneNumber){
		name = in_name;
		phoneNumber = in_phoneNumber;
		Group = " ";
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
  	void groupCreate(std::string name);
  	void addContactToGroup(std::string name, std::string group);
	void removeGroup(std::string group);
  	void printGroups();
private:
    void printContacts(ContactNode *node);
	ContactNode *head;
	ContactNode *tail;
	std::vector<std::string> GroupNames;
};
#endif // ADDRESSBOOK_H
