#include "iostream"
#include "fstream"
#include "sstream"
#include "string"
#include "AddressBook.h"

int main(int argc, char const *argv[])
{
    // So we can call the functions based on what the user inputs
	AddressBook *FunctionCall = new AddressBook();
	// So we can enter the while loop
	bool whileLoop = true;
	std::string line;
	std::string in_name;
	std::string in_number;
	std::string in_group;
	int in_number2;

	std::ifstream inFile("Added_Contacts.txt");
	if(inFile.peek() == std::ifstream::traits_type::eof()){
		while(std::getline(inFile, line)){
			std::stringstream iss(line);

			std::getline(iss,in_name,',');

			std::getline(iss,in_number,',');
			in_number2 = stoi(in_number);

			std::getline(iss,in_group,',');

			FunctionCall->groupCreate(in_group);
			FunctionCall->addContact(in_name,in_number2,in_group);
		}
	}
	inFile.close();
	std::ofstream outFile("Added_Contacts.txt", std::ios_base::app | std::ios_base::out);
	std::stringstream one(in_number);
	while(whileLoop == true)
	{
        // This initializes the integer that the user is going to input to select a menu option
		int userInput = 0;
		int numberized_input;
		// This prints the menu that opens first
		printf("===Address Book===\n");
		printf("1. Add Contact\n");
		printf("2. Remove Contact\n");
		printf("3. Search Contact\n");
		printf("4. Print Contacts\n");
		printf("5. Edit Contact\n");
		printf("6. Create New Group\n");
		printf("7. Add Contact to Group\n");
		printf("8. Remove Group\n");
		printf("9. Print Groups\n");
		printf("10. Add Favorite\n");
		printf("11. Remove Favorite\n");
        printf("12. Print Favorites\n");
		printf("13. Quit\n");
        // This takes in what number the user inputed
		std::cin>>userInput;

        // This tells the computer what to do based on what number the user puts in
		switch(userInput){
		    // If the user enters 1
		    // This calls the function that adds contacts
			case 1:
				printf("Enter the name of the contact:\n");
				std::cin.ignore(100, '\n');
				std::getline(std::cin, in_name);
				printf("Enter the phone number of the contact:\n");
				std::getline(std::cin, in_number);

				one.str( std::string() );
				one.clear();
				one << in_number;
                if (!(one >> numberized_input)){ // Using string-to-int stringstream method
                printf("Number invalid. Digits only please\n");
                numberized_input = 999;
                }
                in_number2 = numberized_input;
				printf("Enter the Group of the contact:\n");
				std::getline(std::cin, in_group);
				FunctionCall->addContact(in_name,in_number2,in_group);
				outFile<<in_name<<","<<in_number<<","<<in_group<<std::endl;
				break;
            // If the user enters 2
            // This calls the function that deletes contacts
			case 2:
				printf("Enter the name of the contact you want to remove:\n");
				std::cin.ignore(100, '\n');
				std::getline(std::cin, in_name);
				FunctionCall->deleteContact(in_name);
				break;
            // If the user enters 3
            // This calls the function that finds the contacts
			case 3:
				printf("Enter the name of the contact:\n");
				std::cin.ignore(100, '\n');
				std::getline(std::cin, in_name);
				FunctionCall->findContact(in_name);
				break;
            // If the user enter 4
            // This calls the function that prints contacts
            case 4:
                // Calls the printContact function
                FunctionCall->printContacts();
                break;
            // If the user enters 5
            // This calls the function that edits the contacts
			case 5:
			    printf("Name of Contact You Wish To Change:\n");
			    // This is for even if you have spaces or periods in the input line you will still get the whole thing
				std::cin.ignore(100, '\n');
				// This gets the whole input line and puts it into the userNew
				std::getline(std::cin, in_name);
				// Calls the editContact function
			    FunctionCall->editContact(in_name);
				break;
            // If the user enters 6
            // This calls the function that creates a group
			case 6:
				printf("Enter Name of new Group:\n");
				std::cin.ignore(100, '\n');
				std::getline(std::cin, in_group);
				FunctionCall->groupCreate(in_group);
				break;
             // If the user enters 7
            // This calls the function that adds a contact to a group
			case 7:
				printf("Enter Name of new Group:\n");
				std::cin.ignore(100, '\n');
				std::getline(std::cin, in_group);
				printf("Enter the name of the contact:\n");
				std::cin.ignore(100, '\n');
				std::getline(std::cin, in_name);
				FunctionCall->addContactToGroup(in_name, in_group);
				break;
            // If the user enters 8
            // This calls the function that removes groups
			case 8:
				printf("Enter Name of new Group:\n");
				std::cin.ignore(100, '\n');
				std::getline(std::cin, in_group);
				FunctionCall->removeGroup(in_group);
				break;
			// If the user enters 9
			// This calls the function that prints the groups
			case 9:
				FunctionCall->printGroups();
				break;
            // If the user enters 10
            // This calls the function that adds favorites
            case 10:
				printf("Enter the name of the contact:\n");
				std::cin.ignore(100, '\n');
				std::getline(std::cin, in_name);
				FunctionCall->addFavorite(in_name);
				break;
            // If the user enters 11
            // This calls the function that removes favorites
            case 11:
				printf("Enter the name of the contact:\n");
				std::cin.ignore(100, '\n');
				std::getline(std::cin, in_name);
				FunctionCall->removeFavorite(in_name);
				break;
            // If the user enters 12
            // This calls the function that prints the favorites
            case 12:
				FunctionCall->printFavorites();
				break;
            // If the user enters 13
            // This quits the program
			case 13:
				whileLoop = false;
				break;
            // If the user enters anything else
			default:
				break;
		}
	}
	outFile.close();
	return 0;
}
