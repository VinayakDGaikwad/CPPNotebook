//#include <iomanip>
//#include <iostream>
//#include <fstream>
//#include <conio>
//#include <string>
//#include <fstream>
//
//using namespace std;
//
//struct student {
//  int rollno;
//  char name[20];
//
//float marks; int status;
//};
//
//class sequential {
//  char master1[30];
//  fstream mas;
//public:
//  sequential(char* a)
//  {
//    strcpy(master1(master1, a));
//    mas.open(master1, ios::binary | ios::in);
//    if (mas.fail())
//      mas.open(master1, ios::binary | ios::out);
//    mas.close();
//  }
//
//  void read();
//  void insert(student rec1);
//  int Delete(int roll);
//  int search(int rillno);
//  void pack();
//  void update();
//  void display(int recnp) {
//    student rec1;
//    mas.open(master1, ios::binary | ios::in);
//    mas.seekg(rec1 * sizeof(student), ios::beg);
//    mas.read((char*) &rec1, sizeof(student));
//    cout << "\n" << rec1.rollno << "  " << setprecision(2) << rec1.marks;
//    mas.close();
//  }
//};
//
//
//
//void main() {
//  sequential object ("master.txt");
//  int roll, op, rcno;
//  student rec1;
//  do {
//    cout << "\n\n1)Read print \n2Insert \n 3)Delete \n 4)Update";
//    cout << "\n5)Search \n 6)pack \n &)Quit";
//    cout << "\n Enter your choise:";
//    cin >> op;
//    switch (op) {
//    case 1:
//      object.read();
//      break;
//    case2:
//      cout << "\nEnter a recprd tobe instered (roll no,name,marks";
//      cin >> rec1.rollno >> rec1.name >> rec1.marks;
//      break;
//    case 3:
//      cout << "\nEnter the roll no:";
//      cin >> rollno;
//      object.Delete(rollno);
//      break;
//    case 4: object.update();
//      break();
//    case 5:
//      cout << "\nEntre a roll no.";
//      recno = object.search(rollno);
//      if (recno >= 0) {
//        cout << "\nRecord No." << recno;
//        object.display(recno);
//      }
//      else {
//        cout << "\nRecord Not Found";
//        break;
//      }
//    case 6:
//      object.pack();
//      break;
//    }
//  } while (op != 7);
//}
//
//void sequential::read() {
//  student crec;
//  int i = 1; , n;
//  cout << "\n****data file*****\n";
//  mas.open(master1, ios::binary | ios::in);
//  mas.seekg(0, ios::end);
//  n = mas.tellg() / sizeof(student);
//  mas.seekg(0, ios::beg);
//  for (int i = 1; i <= n; i++) {
//    mas.read((char*)
//  }
//}
