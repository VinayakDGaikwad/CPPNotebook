#include<iostream>

using namespace std;

class values {
public:
	int value;
};

int operator * (values v1, values v2) {
	return (v1.value * v2.value);
};

bool operator == (values v1, values v2) {
	if (v1.value == v2.value) {
		return true;
	}
	else
	{
		return false;
	}
}

//int main() {
//	values v1, v2;
//	v1.value = 12;
//	v2.value = 4;
//	cout << v1 * v2;
//	
//	if (v1 == v2) {
//		cout << "They are equal";
//	}
//	else {
//		cout << "They are not equal";
//	}
//	return 0;
//}