#include <iostream>
#include "List.hpp"

int main()
{
	List<int> myList;
	myList.push_front(5);
	std::cout << "Pushed 5 to front." << std::endl;
	myList.push_front(9);
	std::cout << "Pushed 9 to front." << std::endl;
	std::cout << std::endl << "Deleted | Not Deleted" << std::endl;
	std::cout << std::endl << myList.deletedNodes << " | " << myList.tangibleNodes << std::endl;
	myList.printTheList();
	myList.pop_back();
	std::cout << std::endl << "Popped back." << std::endl;
	std::cout << std::endl << myList.deletedNodes << " | " << myList.tangibleNodes << std::endl;
	myList.printTheList();
	myList.fullDelete();
	std::cout << std::endl << "Full deleted." << std::endl;
	myList.printTheList();
	std::cout << std::endl << myList.deletedNodes << " | " << myList.tangibleNodes << std::endl;
}