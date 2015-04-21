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

	ContactNode(std::string in_name, int in_phoneNumber, string in_Group){
		name = in_name;
		phoneNumber = in_phoneNumber;
		Group = in_Group;
		next = NULL;
	}
};

class AddressBook
{
public:
<<<<<<< HEAD
	AddressBook();
	~AddressBook();
	void addContact(std::string name, int phone, std::string group);
	void deleteContact(std::string name, int phone, std::string group);
	void printContacts();
	ContactNode* findContact();
	void editContact();
  	void groupCreate();
  	void addContactToGroup(std::string name, std::string group);
private:
	ContactNode *head;
	ContactNode *tail;
=======
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
>>>>>>> cf45ff4ebfcd5c5ad167990c372e1cc1a70ca379
};
#endif // ADDRESSBOOK_H
