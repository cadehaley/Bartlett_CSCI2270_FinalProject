#include "AddressBook.h"
#include "iostream"
#include "string"
#include "vector"

// Constructor
AddressBook::AddressBook(){
	head = NULL;
	tail = NULL;
}

// Destructor
AddressBook::~AddressBook(){

}

// Adds contacts to the address book
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

// Deletes contacts from the address book
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

// Public function that call the private function
void AddressBook::printContacts(){
    // Calls the private function printContacts
    AddressBook::printContacts(head);
}

// Private function that prints the contacts
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

// Finds the contacts in the address book
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

// Edits the contacts in the address book
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

// Creates a group within the address book
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

// Adds the contacts into the group we created
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

// Print out the different groups
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

// Add contacts to default group favorites
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

// Remove from favorites
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

void AddressBook::printFavorites(){
    // Calls the private function printFavorites
    AddressBook::printFavorites(head);
}

// Private function that prints the favorites
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
