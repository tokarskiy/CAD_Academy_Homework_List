/*
 *	CAD Academy
 *	Data structures homework
 */
#include <iostream>
#include "List.h"

void printList(List<int>&);

int main(int argc, char* argv[]) {
	List<int> list;
	
	list.PushBack(1);
	list.PushFront(0);
	list.PushBack(1);
	printList(list); // 0 1 1

	list.PopBack();
	printList(list); // 0 1

	list.PopFront();
	printList(list); // 1
	
	list.PopFront();
	printList(list); //Empty list

	list.PushBack(2);
	printList(list); // 2

	list.PushFront(3);
	printList(list); // 3 2

	list.PushBack(5);
	printList(list); // 3 2 5

	std::cout << std::endl;
	system("pause");
	return 0;
}

void printList(List<int>& list) {
	if (list.Empty()) {
		std::cout << "Empty list" << std::endl;
		return;
	}

	while (!list.IsCurrentNull()) {
		std::cout << list.Current() << " ";
		list.IncCurrent();
	}
	std::cout << std::endl;
}

