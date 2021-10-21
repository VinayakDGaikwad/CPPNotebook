#include<iostream>

using namespace std;

class student
 {
 
  int number, marks[6], total;
  char name[20];
  float avg;
public:
  void initialize() {
    int i;
    cout << "Number: ";    cin >> number;
    cout << "Name: ";        cin >> name;
    cout << "Marks in 5 Subjects: ";
    for (i = 0; i < 5; i++) cin >> marks[i];
  };

  void display() {
    int i;

    cout << number << " " << name << " ( ";

    for (i = 0; i < 5; i++) cout << marks[i] << " ";

    cout << ") " << total << " " << avg << endl;
  };

  friend void totavg(student&);

};


void totavg(student& st1)

{

  int i, sum = 0;

  for (i = 0; i < 5; i++)         sum = sum + st1.marks[i];

  st1.total = sum;

  st1.avg = st1.total / 6.0;

}


//int main()
//
//{
//
//  student st[5];
//  student fst;
//
//  int number, i;
//
//  cout << "No. of Students: ";
//
//  cin >> number;
//
//  for (i = 0; i < number; i++)
//
//  {
//
//    cout << "Student " << i + 1 << "\n";
//
//    st[i].initialize();
//
//  }
//
//  for (i = 0; i < number; i++)
//
//    totavg(st[i]);
//
//  cout << "\nNumber, Name, Marks, Total and Average of ";
//
//  cout << number << " students:\n";
//
//  cout << "-----------------------------------------------------\n";
//
//  for (i = 0; i < number; i++)
//
//    st[i].display();
//
//}
