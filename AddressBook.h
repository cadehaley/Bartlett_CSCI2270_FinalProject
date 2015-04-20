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
	}
};

class AddressBook
{
public:
	AddressBook();
	~AddressBook();
	void addContact();
	void deleteContact();
	void printContacts();
	void findContact();
private:

	
};

#endif // ADDRESSBOOK_H