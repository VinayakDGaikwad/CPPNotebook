#include<iostream>
#include<string>		
using namespace std;

class user {
private:
	string username, password;
		
public:
	user() {
		username = "user";
		password = "pwd";
	}
	void check_user() {
		string s_username, s_password;
		cout << "Enter your username:";

		cin >> s_username;
		cout << "Enter your password:";
		cin >> s_password;

		if (s_username == username && s_password == password) {
			cout << "Successful!";
		}
		else {
			cout << "Not Successful!";
		};
	};
};

//int main() {
//	user u1;
//	u1.check_user();
//	
//	return 0;
//};