#include <fstream>
#include <iostream>

using namespace std;

struct student {
  char name[20];
  int rollno;
  string address;
};

void main() {
  fstream myfile;
  student x;

  myfile.open("student.txt",ios::in);
  cout << "Enter the following infirmation";

  for (int i = 0; i < 3; i++) {
    cout << "Name:";
    cin >> x.name;

    cout << "Roll No:";
    cin >> x.rollno;

    cout << "Height:";
    cin >> x.address;

    myfile.write((char*)&x, sizeof(x));

  }

  myfile.seekg(0, ios::beg);
  cout << "contents of file";
  int i = 0;

  for (i = 0; i < 3; i++) {
    myfile.read((char*)&x, sizeof(x));
    cout << x.name << "   " << x.rollno << "   " << x.address;
    cout << "\n";
  }

  myfile.close();
}
