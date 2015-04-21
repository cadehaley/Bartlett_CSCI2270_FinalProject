#include "iostream"
#include "string"
#include "AddressBook.h"

int main(int argc, char const *argv[])
{
	AddressBook *FunctionCall = new AddressBook();
	bool wl = true;
	std::string userName;

	while(wl == true){
		int userInput = 0;
		printf("===Address Book===\n");
		printf("1. Add Contact\n");
		printf("2. Remove Contact\n");
		printf("3. Search Contact\n");
		printf("4. Print Contacts\n");
		printf("5. Edit Contact\n");
		printf("6. Create New Group\n");
		printf("7. Print Groups\n");
		printf("8. Quit\n");
		std::cin>>userInput;

		switch(userInput){
			case 1:
				break;
			case 2:
				break;
			case 3:
				break;
            case 4:
                FunctionCall->printContacts();
                break;
			case 5:
			    printf("Name of Contact You Wish To Change:\n");
				std::cin.ignore(100, '\n');
				std::getline(std::cin, userName);
			    FunctionCall->editContact(userName);
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
