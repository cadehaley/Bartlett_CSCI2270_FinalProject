#include "iostream"
#include "string"
#include "AddressBook.h"

int main(int argc, char const *argv[])
{
	bool wl = true;

	while(wl == true){
		int userInput = 0;
		printf("===Address Book===\n");
		printf("1. Add Contact\n");
		printf("2. Remove Contact\n");
		printf("3. Search Contact\n");
		printf("4. Edit Contact\n");
		printf("5. Create New Group\n");
		printf("6. Quit\n");
		std::cin>>userInput;

		switch(userInput){
			case 1:
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
			case 5:
				break;
			case 6:
				wl = false;
				break;
			default:
				break;
		}
	}
	return 0;
}
