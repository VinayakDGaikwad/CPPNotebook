#include<iostream>

using namespace std;

class list {
	int arry[10];
public:

	void get_data() {

		for (int i = 0; i <= 9; i++) {
			cout << "Enter the array:";
			cin >> arry[i];
		}
	}

	void print_data() {

		for (int i = 0; i <= 9; i++) {
			cout << " : "<<arry[i];
		}
	}

	void insertion_sort() {
		int j, key;
		int i = 9;
		

		for (i = 1; i < 10; i++)
		{
			key = arry[i];
			j = i - 1;
			while (arry[j] > key)
			{
				arry[j + 1] = arry[j];
				j = j - 1;
			}

			arry[j + 1] = key;
		}
	}

};

//int main() {
//
//	list li;
//	li.get_data();
//	li.insertion_sort();
//	li.print_data();
//
//	return 0;
//}