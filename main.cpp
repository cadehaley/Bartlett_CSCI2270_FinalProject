#include "iostream"
#include "string"
#include "AddressBook.h"

int main(int argc, char const *argv[])
{
	AddressBook *FunctionCall = new AddressBook();
	bool whileLoop = true;
	std::string userName;

	while(whileLoop == true){
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
                // Calls the printContact function
                FunctionCall->printContacts();
                break;
			case 5:
			    printf("Name of Contact You Wish To Change:\n");
			    // This is for even if you have spaces or periods in the input line you will still get the whole thing
				std::cin.ignore(100, '\n');
				// This gets the whole input line and puts it into the userNew
				std::getline(std::cin, userNew);
				// Calls the editContact function
			    FunctionCall->editContact(userNew);
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
				whileLoop = false;
				break;
			default:
				break;
		}
	}
	return 0;
}
