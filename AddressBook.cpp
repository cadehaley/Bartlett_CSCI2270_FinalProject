#include "AddressBook.h"
#include "iostream"
#include "string"
#include "vector"

/*
Function Prototype:
AddressBook();

Function Description:
This is the constructor. We initialize the head and tail to NULL
*/
AddressBook::AddressBook(){
	head = NULL;
	tail = NULL;
}

/*
Function Prototype:
~AddressBook();

Function Description:
This is the destructor.
*/
AddressBook::~AddressBook(){

}

/*
Function Prototype:
void addContact(std::string name, int phone, std::string group);

Function Description:
This function adds contacts to the address book.

Example:
AddressBook *FunctionCall = new AddressBook();
FunctionCall->addContact("John Doe");
*/
void AddressBook::addContact(std::string name, int phone, std::string group){
	ContactNode *node = new ContactNode(name, phone);

	if(head == NULL)
	{
		node->previous = NULL;
		head = node;
		tail = node;
		AddressBook::addContactToGroup(name, group);
	}

	else
	{
		node->previous = tail;
		tail->next = node;
		tail = node;
		AddressBook::addContactToGroup(name, group);
	}
}

/*
Function Prototype:
void deleteContact(std::string name);

Function Description:
This function deletes contacts from the address book.

Example:
AddressBook *FunctionCall = new AddressBook();
FunctionCall->deleteContact("John Doe");
*/
void AddressBook::deleteContact(std::string name){
	if(head == NULL)
	{
	  printf("There are no contacts to delete.\n");
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

/*
Function Prototype:
void printContacts();

Function Description:
This is the public function of printContacts that calls the private function printContacts.

Example:
AddressBook *FunctionCall = new AddressBook();
FunctionCall->printContacts();
*/
void AddressBook::printContacts(){
    // Calls the private function printContacts
    AddressBook::printContacts(head);
}

/*
Function Prototype:
void printContacts(ContactNode *node);

Function Description:
This is the private function of printContacts that the public function of printContacts calls.
This is the function that actually prints the contacts.

Example:
AddressBook *FunctionCall = new AddressBook();
FunctionCall->printContacts();
*/
void AddressBook::printContacts(ContactNode *node)
{
    // It will enter this if statement if the head of the list is NULL it means there are no contacts to print out
    if (head == NULL)
    {
        std::cout << "There are no contacts to print." << std::endl;
    }
    // If the head does not equal NULL it will enter this else statement and print out the contact info
    else
    {
        std::cout << "Name: " << node->name << std::endl;
        std::cout << "Phone Number: " << node->phoneNumber << std::endl;
        std::cout << "Group: " << node->Group << std::endl;

        // This moves it to the next contact and it will keep doing that until there are not anymore
        if(node->next != NULL){
			AddressBook::printContacts(node->next);
		}
    }
}

/*
Function Prototype:
ContactNode* findContact(std::string name);

Function Description:
This function finds the contacts in the address book. It uses the type ContactNode*.

Example:
AddressBook *FunctionCall = new AddressBook();
FunctionCall->findContact("John Doe");
*/
ContactNode* AddressBook::findContact(std::string name){
	ContactNode *node = new ContactNode();
	ContactNode *runner = head;
	while(runner->next != NULL){
		if(runner->name == name){
			node = runner;
		}
		runner = runner->next;
	}
	if(node == NULL){
		printf("Contact does not exist or was misspelled\n");
	}
	return node;
}

/*
Function Prototype:
void editContact(std::string name);

Function Description:
This function edits the contacts in the address book.

Example:
AddressBook *FunctionCall = new AddressBook();
FunctionCall->editContact("John Doe");
*/
void AddressBook::editContact(std::string name){
    // What type of information they are going to change
    int userInput;
    // The new information they want to put in
    std::string userNew;
    // Finds which contact you are looking for
    ContactNode *node = AddressBook::findContact(name);
    std::cout << "1. Name: " << node->name << std::endl;
    std::cout << "2. Phone Number: " << node->phoneNumber << std::endl;
    std::cout << "3. Group: " << node->Group << std::endl;
    std::cout << "To Edit Input Number Corresponding To Item." << std::endl;
    // Takes in what option the user wants to change
    std::cin >> userInput;
    // This is where we are going to switch the old contact info with the new contact info we want to put in
    switch(userInput)
    {
        // Case 1 is for the name
        case 1:
            std::cout << "Type In New Name: " << std::endl;
            // This is for even if you have spaces or periods in the input line you will still get the whole thing
            std::cin.ignore(100, '\n');
            // This gets the whole input line and puts it into the userNew
            std::getline(std::cin, userNew);
            // This changes the nodes name to userNew name
            node->name = userNew;
            std::cout << "Contacts Name Now Changed To: " << std::endl;
            std::cout << "Name: " << node->name << std::endl;
            break;
        // Case 2 is for the phone number
        case 2:
            std::cout << "Type In New Phone Number: " << std::endl;
            // This is for even if you have spaces or periods in the input line you will still get the whole thing
            std::cin.ignore(100, '\n');
            // This gets the whole input line and puts it into the userNew
            std::getline(std::cin, userNew);
            // This changes the nodes phone number to userNew phone number
            node->phoneNumber = std::stoi(userNew);
            std::cout << "Contacts Phone Number Now Changed To: " << std::endl;
            std::cout << "Phone Number: " << node->phoneNumber << std::endl;
            break;
        // Case 3 if for the group
        case 3:
            std::cout << "Type In New Group: " << std::endl;
            // This is for even if you have spaces or periods in the input line you will still get the whole thing
            std::cin.ignore(100, '\n');
            // This gets the whole input line and puts it into the userNew
            std::getline(std::cin, userNew);
            // Calls the addContactToGroup function
            AddressBook::addContactToGroup(node->name, userNew);
            break;
        default:
            break;
    }
}

/*
Function Prototype:
void groupCreate(std::string name);

Function Description:
This function creates a group within the address book. It uses a vector called group names.

Example:
AddressBook *FunctionCall = new AddressBook();
FunctionCall->groupCreate("Group Name");
*/
void AddressBook::groupCreate(std::string name){
	for (unsigned int i = 0; i < GroupNames.size(); i++) {
		if(GroupNames[i] == name){
			printf("Group already exsits\n");
			return;
		}
	}
	GroupNames.push_back(name);
	std::cout<<"Group "<<name<<" was created."<<std::endl;
}

/*
Function Prototype:
void addContactToGroup(std::string name, std::string group);

Function Description:
This function adds the contacts into the group we created. It uses a vector called group names.

Example:
AddressBook *FunctionCall = new AddressBook();
FunctionCall->addContactToGroup("John Doe", "Group Name");
*/
void AddressBook::addContactToGroup(std::string name, std::string group){
	ContactNode *node = AddressBook::findContact(name);
	if(node != NULL)
    {
		node->Group = group;

		// Added this which adds the group to the GroupNames vector if it isn't already
        bool GroupExists = false;
        for(int i = 0; i < GroupNames.size(); i++)
        {
            if(GroupNames[i] == group)
            {
                GroupExists = true;

            }


        }
        if(GroupExists == false)
        {
            GroupNames.push_back(group);

        }
	}
	else{
		node->Group = " ";
		std::cout<<group<<" is not a group. Create it first or Choose from the list of groups."<<std::endl;
		printf("Contact was not added to a group.\n");
	}
}

/*
Function Prototype:
void removeGroup(std::string group);

Function Description:
This function removes a group from a vector called group names. It uses a vector called group names.

Example:
AddressBook *FunctionCall = new AddressBook();
FunctionCall->removeGroup("Group Name");
*/
void AddressBook::removeGroup(std::string group){
	bool isReal = false;
	for(unsigned int i = 0; i < GroupNames.size(); i++){
		if(GroupNames[i] == group){
			GroupNames.erase(GroupNames.begin()+i);
			isReal = true;
		}
	}
	if(isReal == false){
		printf("That is not a Group\n");
	}
	else{
		ContactNode *node = head;
		while(node->next != NULL){
			if(node->Group == group){
				node->Group = " ";
				std::cout << node->name << " was removed from " << group << std::endl;
			}
			node = node->next;
		}
	}
}

/*
Function Prototype:
void printGroups();

Function Description:
This function prints out the different groups. It uses a vector called group names.

Example:
AddressBook *FunctionCall = new AddressBook();
FunctionCall->printGroups();
*/
void AddressBook::printGroups(){
	if(GroupNames.empty()){
		printf("No Groups have been made yet.\n");
	}
	else{
		printf("Groups:\n");
		std::cout << GroupNames[0];
		for (unsigned int i = 1; i < GroupNames.size(); ++i){
			std::cout<<", "<<GroupNames[i];
		}
		std::cout<<std::endl;
	}
}

/*
Function Prototype:
void addFavorite(std::string name);

Function Description:
This function adds contacts to default group favorites.
Everything is either in favorite or not in favorite, meaning that it is true or false. Since we are adding it makes it true.

Example:
AddressBook *FunctionCall = new AddressBook();
FunctionCall->addFavorite("John Doe");
*/
void AddressBook::addFavorite(std::string name){
    ContactNode *node = AddressBook::findContact(name);
	if(node != NULL){
        if(node->Favorite == true){
            printf("Already in favorites.\n");
        }
        else{
		node->Favorite = true;
        }
	}
	else{
		node->Favorite = false;
		std::cout<<name<<" could not be found"<<std::endl;
		printf("Contact was not added to favorites.\n");
	}

}

/*
Function Prototype:
void removeFavorite(std::string name);

Function Description:
This function removes contacts from favorites.
Everything is either in favorite or not in favorite, meaning that it is true or false. Since we are adding it makes it true.

Example:
AddressBook *FunctionCall = new AddressBook();
FunctionCall->removeFavorite("John Doe");
*/
void AddressBook::removeFavorite(std::string name){
    ContactNode *node = AddressBook::findContact(name);
	if(node != NULL){
		if(node->Favorite == true){
            node->Favorite = false;
            std::cout<<node->name<<" removed from favorites"<<std::endl;
		}
        else if(node->Favorite == false){
            std::cout<<name<<" not in favorites"<<std::endl;
        }
    }
    else{
		node->Favorite = false;/////////
		std::cout<<name<<" could not be found"<<std::endl;
	}
}

/*
Function Prototype:
void printFavorites();

Function Description:
This is the public function of printFavorites that calls the private function printFavorites.

Example:
AddressBook *FunctionCall = new AddressBook();
FunctionCall->printFavorites();
*/
void AddressBook::printFavorites(){
    // Calls the private function printFavorites
    AddressBook::printFavorites(head);
}

/*
Function Prototype:
void printFavorites(ContactNode *node);

Function Description:
This is the private function of printFavorites that the public function of printFavorites calls.
This is the function that actually prints the favorites.

Example:
AddressBook *FunctionCall = new AddressBook();
FunctionCall->printFavorites();
*/
void AddressBook::printFavorites(ContactNode *node){
    // It will enter this if statement if the head of the list is NULL it means there are no contacts to print out
    if (head == NULL)
    {
        std::cout << "There are no contacts to print." << std::endl;
        return;
    }
    // If the head does not equal NULL it will enter this else statement and print out the contact info of the favorite
    else if(node->Favorite == true)
    {
        std::cout << "Name: " << node->name << std::endl;
        std::cout << "Phone Number: " << node->phoneNumber << std::endl;
        std::cout << "Group: " << node->Group << std::endl;

        // This moves it to the next favorite and it will keep doing that until there are not anymore
        if(node->next != NULL){
			AddressBook::printFavorites(node->next);
		}
    }

    // Added this since the code originally stopped if you got to something that
    // wasn't a favorite, instead of calling it for whats next
    else
    {


        if(node->next != NULL){
			AddressBook::printFavorites(node->next);
		}


    }
}
