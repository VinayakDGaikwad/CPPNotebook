#include<iostream>

using namespace std;



students students_array[10];

int main() {
	int i;
	int search_key;
	
	int information[10];

	for (i = 0; i < 10; i++) {
		cin >> information[i];
		cout << "\n";
	}

	//linear search
	cout << "Entre what to search?:";
	cin >> search_key;
	
	int e=0;
	int flag = 0;
	
	while ((e<10) && (flag == 0)) {
		
		if (search_key == information[e]) {
			flag = 1;
			cout << "Found!  @" << e;
			break;
		}

		e++;
	}
		
}