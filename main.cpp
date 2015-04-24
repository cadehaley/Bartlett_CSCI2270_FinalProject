#include "iostream"
#include "string"
#include "AddressBook.h"

int main(int argc, char const *argv[])
{
    // So we can call the functions based on what the user inputs
	AddressBook *FunctionCall = new AddressBook();
	// So we can enter the while loop
	bool whileLoop = true;
	// Initializes the string user name
	std::string userName;

	while(whileLoop == true)
	{
        // This initializes the integer that the user is going to input to select a menu option
		int userInput = 0;
		// This prints the menu that opens first
		printf("===Address Book===\n");
		printf("1. Add Contact\n");
		printf("2. Remove Contact\n");
		printf("3. Search Contact\n");
		printf("4. Print Contacts\n");
		printf("5. Edit Contact\n");
		printf("6. Create New Group\n");
		printf("7. Print Groups\n");
		printf("8. Quit\n");
        // This takes in what number the user inputed
		std::cin>>userInput;

        // This tells the computer what to do based on what number the user puts in
		switch(userInput){
		    // If the user enters 1
			case 1:
				break;
            // If the user enters 2
			case 2:
				break;
            // If the user enters 3
			case 3:
				break;
            // If the user enter 4
            case 4:
                // Calls the printContact function
                FunctionCall->printContacts();
                break;
            // If the user enters 5
			case 5:
			    printf("Name of Contact You Wish To Change:\n");
			    // This is for even if you have spaces or periods in the input line you will still get the whole thing
				std::cin.ignore(100, '\n');
				// This gets the whole input line and puts it into the userNew
				std::getline(std::cin, userNew);
				// Calls the editContact function
			    FunctionCall->editContact(userNew);
				break;
            // If the user enters 6
			case 6:
				printf("Enter Name of new Group:\n");
				std::cin.ignore(100, '\n');
				std::getline(std::cin, userName);
				FunctionCall->groupCreate(userName);
				break;
            // If the user enters 7
			case 7:
				FunctionCall->printGroups();
				break;
            // If the user enters 8
			case 8:
				whileLoop = false;
				break;
            // If the user enters anything else
			default:
				break;
		}
	}
	return 0;
}
