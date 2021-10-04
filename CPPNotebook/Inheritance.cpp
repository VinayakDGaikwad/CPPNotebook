#include<iostream>
#include <string>

using namespace std;
class basic_info {
public:
	string Name;
	int age;
};

class department_info : public basic_info {
public:
	string position_in_department;
};


class loan_info : public basic_info {
public:
	float lone_amount;
	float instrest_rate;
};

//int main() {
//	department_info d1;
//	loan_info l1;
//	string name;
//	int age;
//	cout << "Enter the employe name:";
//	cin >> name;
//	cout << "Enter the employe age";
//	cin >> age;
//
//	l1.Name = name;
//	l1.age = age;
//	d1.Name = name;
//	d1.age = age;
//
//	cout << "Entre position in department:";
//	cin >> d1.position_in_department;
//
//	cout << "Entre loan ammount:";
//	cin >> l1.lone_amount;
//
//	cout << "Enter intrest rate:";
//	cin >> l1.instrest_rate;
//	return 0;
//};