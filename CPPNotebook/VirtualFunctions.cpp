#include <iostream>
using namespace std;

class shape {
public:
  virtual void sound()
  {
    cout << "prints sound" << endl;
  }
};

class Dog : public shape {
public:
  void sound()
  {
    cout << "dog barks" << endl;
  }

};

class cat : public shape {
public:
  void sound()
  {
    cout << "cat meaows" << endl;
  }

};

//int main()
//{
//  shape* bptr;
//  Dog d;
//  cat w;
//  bptr = &d;
//  bptr->sound();
//
//  bptr = &w;
//  bptr->sound();
//}
