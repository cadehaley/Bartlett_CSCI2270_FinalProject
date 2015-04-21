#include "iostream"
#include "string"
#include "AddressBook.h"

int main(int argc, char const *argv[])
{
	AddressBook *FunctionCall = new AddressBook();
	bool wl = true;
	std::string userName;
	std::string SphoneNumber;
	int phoneNumber;
	std::string groupName;

	while(wl == true){
		int userInput = 0;
		printf("===Address Book===\n");
		printf("1. Add Contact\n");
		printf("2. Remove Contact\n");
		printf("3. Search Contact\n");
		printf("4. Print Contacts\n", );
		printf("5. Edit Contact\n");
		printf("6. Create New Group\n");
		printf("7. Print Groups\n");
		printf("8. Quit\n");
		std::cin>>userInput;

		switch(userInput){
			case 1:
			    printf("Enter the name of a contact that you would like to add:\n");
			    std::cin.ignore(100, '\n');
			    std::getline(std::cin, userName);
			    printf("Enter the phone number for the contact:\n");
			    std::getline(std::cin, SphoneNumber);
			    phoneNumber = std::stoi(SphoneNumber);
			    printf("Enter the group you would like to add this contact to:\n");
			    std::getline(std::cin, groupName);
			    FunctionCall->addContact(userName, phoneNumber, groupName);
			    printf("Contact has been added.\n");
				break;
			case 2:
			    printf("Enter the name of the contact that you would like to delete:\n");
			    std::cin.ignore(100, '\n');
			    std::getline(std::cin, userName);
			    FunctionCall->deleteContact(userName);
			    printf("Contact has been deleted.\n");
				break;
			case 3:
				break;
			case 4:
				break;
			case 5:
				break;
			case 6:
				printf("Enter Name of new Group:\n");
				std::cin.ignore(100, '\n');
				std::getline(std::cin, userName);
				FunctionCall->groupCreate(userName);
				break;
			case 7:
				FunctionCall->printGroups();
				break;
			case 8:
				wl = false;
				break;
			default:
				break;
		}
	}
	return 0;
}
