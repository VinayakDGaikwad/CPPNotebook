#include<iostream>
#include<string>

using namespace std;

class stu_database {
private:
	struct student {
		int roll_no;
		string name;
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

		do  {
			if (key == mydatabase[i].roll_no) {
				cout << "Found! \n";
				cout << mydatabase[i].roll_no <<"\n";
				cout << mydatabase[i].name << "\n";
				cout << mydatabase[i].SGPA << "\n";
				break;
			}
			i++;
		} while ((mydatabase[i].roll_no != key));

	};

};

int main() {
	
	stu_database List1;
	List1.get_data();

	int key;
	cout << "What to search:";
	cin >> key;
	List1.l_search_rollno(key);

	
	return 0;
		
}