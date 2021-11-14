#include<iostream>
#include<cstring>

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

    do {
      if (local_key == mydatabase[i].roll_no) {
        cout << "Found! \n";
        cout << "ROLL NO:" << mydatabase[i].roll_no << "\n";
        cout << "NAME:" << mydatabase[i].name << "\n";
        cout << "SGPA:" << mydatabase[i].SGPA << "\n";
        return;
      }
      i++;
    } while ((mydatabase[i].roll_no != local_key));

    cout << "Not Found";

  };

  void bubble_sort_rollno() {
    int i, j;
    int n = 5;
    struct student temp;

    for (i = 0; i < n - 1; i++) { //loop for iterations
      for (j = 0; j < (n - 1) - i; j++) {  //reduce comparisons for every itteration
        if (mydatabase[j].roll_no > mydatabase[j + 1].roll_no) {
          temp = mydatabase[j];
          mydatabase[j] = mydatabase[j + 1];
          mydatabase[j + 1] = temp;
        }
      }
    }
  }

  void l_search_name(char key[50]) {

    int i, j;
    struct student swap;

    for (i = 0; i < 5 - 1; i++) //itterations
    {
      for (j = 0; j < 5 - i - 1; j++) //comparisons decress for every itteration
      {
        if (strcmp(mydatabase[j].name, mydatabase[j + 1].name) > 0)
        {
          swap = mydatabase[j];
          mydatabase[j] = mydatabase[j + 1];
          mydatabase[j + 1] = swap;
        }
      }
    }

    int l = 0;
    int r = 5;

    int not_found = 1;
    while (l <= r) {
      int mid = l + (r - l) / 2;

      // Check if x is present at mid
      if (strcmp(mydatabase[mid].name, key) == 0) {
        not_found = 0;
        cout << "Found! \n";
        cout << "ROLL NO:" << mydatabase[mid].roll_no << "\n";
        cout << "NAME:" << mydatabase[mid].name << "\n";
        cout << "SGPA:" << mydatabase[mid].SGPA << "\n";
        break;
      }

      // If x greater, ignore left half
      if (strcmp(mydatabase[mid].name, key) < 0)
        l = mid + 1;

      // If x is smaller, ignore right half
      else
        r = mid - 1;
    }
    if (not_found) cout << "not found";
  }

  void insertion_sort_alphabetically() {
    int j, i;
    student key;

    for (i = 0; i < 5; i++) {
      key = mydatabase[i];

      j = i - 1;
      while (strcmp(mydatabase[i].name, key.name) < 0) {
        mydatabase[j + 1] = mydatabase[j];
        j--;
      }
      mydatabase[j + 1] = key;

    }
  }

  void quick_sorta() {
    quick_sort(mydatabase, 0, 4);
  }

  void quick_sort(student a[], int l, int u) {
    int j;
    if (l < u) {
      j = partition(a, l, u);
      quick_sort(a, l, j - l);
      quick_sort(a, j + 1, u);
    };
  };

  int partition(student a[], int l, int u) {
    int i, j;
    float key;
    student swap;
    key = a[l].SGPA;

    i = l;
    j = u + 1;

    do
    {
      do
        i++;
      while (a[i].SGPA < key && i <= u);
      do
        j--;
      while (key < a[j].SGPA);

      if (i < j)
      {
        //swap
        swap = a[i];
        a[i] = a[j];
        a[j] = swap;
      }
    } while (i < j);

    a[l] = a[j];
    a[j].SGPA = key;

    return j;
  }



  void display() {
    for (int i = 0; i < 5; i++) {
      cout << "\n NAME:" << mydatabase[i].name;
      cout << "         Roll NO:" << mydatabase[i].roll_no;
      cout << "         SGPA:" << mydatabase[i].SGPA;
    }
  }
};


int main() {
  stu_database List1;

  for (;;) {
    cout << "Menu: \n \t 1. Enter Data \n \t 2. Sort by Roll no. (Bubble Sort) \n \t 3. Sort Alphabetically (Insertion Sort) \n \t 4.Display \n \t 5. Search by Roll no.  \n \t 6. Toper List \n \t 7.Search by name";
    int input;
    cin >> input;
    switch (input)
    {
    case 1:
      List1.get_data();
      break;
    case 2:
      cout << "Bubble sort by roll no:";
      List1.bubble_sort_rollno();
      List1.display();
      break;
    case 3:
      cout << "Insertion Sort Albhbetically:";
      List1.insertion_sort_alphabetically();
      List1.display();
      break;
    case 4:
      List1.display();
      break;
    case 5:
      int key;
      cout << "What to search:";
      cin >> key;
      List1.l_search_rollno(key);
      break;
    case 6:
      //toper list
      List1.quick_sorta();
      List1.display();
      break;

    case 7:
      char temp[50];
      cin >> temp;
      cout << "What to search name:";
      List1.l_search_name(temp);
      break;
    }

  }
  return 0;

}
