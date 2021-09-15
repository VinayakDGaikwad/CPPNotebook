#include<iostream>
#include<string>

using namespace std;

class stu_database {
private:
	struct student {
		int roll_no;
		char name[50];
		float SGPA;
	} mydatabase[5];

public:	
	void get_data() {

		for (int i = 0; i <= 4; i++) {
			cout << "Roll no:";
			cin >> mydatabase[i].roll_no;
			cout << "Name:";
			cin >> mydatabase[i].name;
			cout << "SGPA";
			cin >> mydatabase[i].SGPA;
		};

	};

	void l_search_rollno(int key) {
		int i = 0;
		int local_key = key;

		do  {
			if (local_key == mydatabase[i].roll_no) {
				cout << "Found! \n";
				cout << "ROLL NO:"<< mydatabase[i].roll_no << "\n";
				cout << "NAME:"<<mydatabase[i].name << "\n";
				cout << "SGPA:" <<mydatabase[i].SGPA << "\n";
				break;
			}
			i++;
		} while ((mydatabase[i].roll_no != local_key));

	};

	void l_search_name(char key[50]){
		
		int i, j;
		struct student swap;
		
		for (i = 0; i < 5 - 1; i++)
		{
			for (j = 0; j < 5 - i - 1; j++)
			{
				if (strcmp(mydatabase[j].name , mydatabase[j + 1].name) >0 )
				{
					swap = mydatabase[j];
					mydatabase[j] = mydatabase[j + 1];
					mydatabase[j + 1] = swap;
				}
			}
		}

		int l = 0;
		int r = 5;

		while (l <= r) {
			int mid = l + (r - l) / 2;

			// Check if x is present at mid
			if (strcmp(mydatabase[mid].name, key) ==0)
				cout << "Found! \n";
			cout << "ROLL NO:" << mydatabase[i].roll_no << "\n";
			cout << "NAME:" << mydatabase[i].name << "\n";
			cout << "SGPA:" << mydatabase[i].SGPA << "\n";
			break;

			// If x greater, ignore left half
			if (strcmp(mydatabase[mid].name, key) < 0)
				l = mid + 1;

			// If x is smaller, ignore right half
			else
				r = mid - 1;
		}

	}

};

int main() {
	
	stu_database List1;
	List1.get_data();

	int key;
	cout << "What to search:";
	cin >> key;
	List1.l_search_rollno(key);

	cout << "What to search name:";
	char temp[50];
	cin >> temp;
	List1.l_search_name(temp);

	
	return 0;
		
}