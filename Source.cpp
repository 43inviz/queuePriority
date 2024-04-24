#include <iostream>
#include "QueuePriority.h"
using namespace std;


void menu() {

	cout << "1 - Add el with priority\t2 - Return el\n";
	cout << "3 - Delete in queue\t4 - is Full\n";
	cout << "5 - is Empty\t6 - show\n";
	cout << "Enter choice: ";

}



int main() {

	int size = 5;

	QueuePriority<int> que1(size);

	
	int choice;

	int addValue;
	int addPriority;

	int returnedEl;

	bool isFull;
	bool isEmpty;

	do {
		menu();
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "Value: ";
			cin >> addValue;
			cout << "Priority: ";
			cin >> addPriority;
			que1.addWithPriority(addValue, addPriority);
			break;
		case 2:
			returnedEl = que1.dequeuePriority();
			cout << "\nElem: " << returnedEl << endl;
			break;
		case 3:
			que1.removeByPriority();
			break;
		case 4:
			isFull = que1.isFull();
			if (isFull == true) {
				cout << "\nQueue is FULL\n";
			}
			else {
				cout << "Queue is NOT FULL\n";
			}
			break;
		case 5:
			isEmpty = que1.isEmpty();
			if (isEmpty == true) {
				cout << "Queue is Empty\n";
			}
			else {
				cout << "Queue is FILL\n";
			}
			break;
		case 6:
			que1.show();
			break;
		default:
			break;
		}
	} while (choice != 0);

	return 0;
}