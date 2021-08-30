#include<iostream>
//#include<conio.h>

using namespace std;

class myStudent {
	private:
		int roll_no;
		string name;
		float sgpa;
    public:
	    void getData();
	    void showData();
};


//function impementation outside the class
void myStudent::getData() {
	cout << "Enter your name:";
	cin >> name;
	cout << "Enter your roll no:";
	cin >> roll_no;
	cout << "Enter your SCGPA:";
	cin >> sgpa;
};

//function impementation outside the class
void myStudent::showData() {
	cout << "Name:" << name;
	cout << "Roll no:" << roll_no;
	cout << "SCGPA:" << sgpa;
};

int main() {
	myStudent student1;
	int i;
	for (i = 0; i < 10; i++) {
		student1.getData();
		student1.showData();
	}
	return 0;
}