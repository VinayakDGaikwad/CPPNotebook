//#include <iostream>
//#include <stdio.h>
//#include <string>
//#include <vector>
//#include <list>
//#include <cstring>
//#include <fstream>
//
//int size = 0;   //size of pending task list
//int completed_tasks = 0;
//
//struct task {
//  std::string name;
//  int priority;
//public:
//  task() {
//    this->name = "";
//    this->priority = 0;
//  }
//  task(std::string name, int p) {
//    this->name = name;
//    this->priority = p;
//  };
//};
//
//std::string completed[20] = {""};
//
//struct task* mylist[50];
//
//class f {
//  std::fstream myfile;
//  
//public:
//  
//  void load_textfile() {
//    task *x = new task();
//    std::ifstream myFile;
//    myFile.open("task.txt", std::ios::in);
//    //myFile.seekg(0, std::ios::beg);
//    int i = 0;
//
//    for (int h = 0; i <= 30; i++)
//    {
//      myFile.read((char*)&x, sizeof(x));
//
//      if (x==nullptr) {
//        continue;
//      };
//
//      mylist[i] = x;
//      size++;
//    }
//
//    x = new task();
//  
//    for (int h = 31; h <= 50; h++)
//    {
//      myFile.read((char*)x, sizeof(x));
//      std::cout << myFile.tellg();
//      if(myFile.eof()) break;
//
//      if (x != nullptr) {
//        completed_tasks++;
//      };
//      completed[h-31] = x->name;
//      
//    }
//    
//    myFile.close();
//  };
//
//  void save_file() {
//    myfile.open("task.txt", std::ios::out);
//
//    task *q = new task();
//    
//    for (int i = 0; i <= 29; i++) {
//      myfile.write((char*) &q, sizeof(q));
//      q = mylist[i];   
//            
//    }
//
//    q = new task();
//    std::cout << myfile.tellp();
//    for (int i = 31; i <= 50;i++){
//      myfile.write((char*)&q, sizeof(q));
//      q->name = completed[i - 31];      
//    }
//
//    size = 0;
//    completed_tasks = 0;
//    myfile.close();
//  };
//
//  void add_task(std::string name, int p) {
//    mylist[p] = new task(name, p);
//    size++;
//
//    std::cout << "Added task : " << name << " with priority " << p << "\n";
//  };
//
//  bool del_task(int p) {
//    if (mylist[p]) {
//      //nothing to delete
//      return false;
//    }
//    mylist[p] = nullptr;
//    size--;
//    return true;
//  };
//
//  void print_report() {
//    std::cout << "Pending: " << size << "\n";
//
//    int index = 1;
//    for (int q = 0; q <= 30; q++) {
//      if (mylist[q] != nullptr) {
//        std::cout << index << ". " << mylist[q]->name << " [" << mylist[q]->priority << "]\n";
//        index++;
//      }
//    }
//
//    std::cout << "Compeleted: " << completed_tasks << "\n";
//
//    index = 1;
//    for (int q = 31; q <= 50; q++) {
//      if (completed[q-31] != "") {
//        std::cout << index << ". " << completed[q-31] << "\n";
//        index++;
//      }
//    }
//
//  };
//
//  bool mark_done(int p) {
//    if (mylist[p] == nullptr) {
//      return false;
//    }
//    //add to complete
//    completed[completed_tasks] = (mylist[p]->name);
//    completed_tasks++;
//
//    //remove form mylist
//    mylist[p] = nullptr;
//;
//    return true;
//  };
//
//  void ls() {
//    std::cout << "Pending: " << size << "\n";
//
//    int index = 1;
//    for (int q = 0; q <= 30; q++) {
//      if (mylist[q] != nullptr) {
//        std::cout << index << ". " << mylist[q]->name << " [" << mylist[q]->priority << "]\n";
//        index++;
//      }
//    }
//  }
//};
//
//
//int main()
//{
//  /*int argc = 2;
//  char* arg1, arg2, arg3;*/
//  
//  class f s;
//
//  s.add_task("asdasd", 3);
//  s.add_task("asdasd", 6);
//  s.mark_done(3);
//  s.save_file();
//  s.load_textfile();
//  s.print_report();
//
//  // if (argc == 1) {
//
//  //  printf("Usage :-\n");
//  //  printf("$ ./task add 2 hello world    # Add a new item with priority 2 and text \"hello world\" to the list\n");
//  //  printf("$ ./task ls                   # Show incomplete priority list items sorted by priority in ascending order\n");
//  //  printf("$ ./task del INDEX            # Delete the incomplete item with the given index\n");
//  //  printf("$ ./task done INDEX           # Mark the incomplete item with the given index as complete\n");
//  //  printf("$ ./task help                 # Show usage\n");
//  //  printf("$ ./task report               # Statistics");
//
//  //}
//  //else if (argc == 2)
//  //{
//  //  if (!strcmp(arg1, "help")) {
//
//  //    printf("Usage :-\n");
//  //    printf("$ ./task add 2 hello world    # Add a new item with priority 2 and text \"hello world\" to the list\n");
//  //    printf("$ ./task ls                   # Show incomplete priority list items sorted by priority in ascending order\n");
//  //    printf("$ ./task del INDEX            # Delete the incomplete item with the given index\n");
//  //    printf("$ ./task done INDEX           # Mark the incomplete item with the given index as complete\n");
//  //    printf("$ ./task help                 # Show usage\n");
//  //    printf("$ ./task report               # Statistics");
//
//  //  }
//
//  //  if (!strcmp(arg1, "ls")) {
//  //    s.load_textfile();
//  //    s.ls();
//  //  }
//
//  //  if (!strcmp(arg1, "report")) {
//  //    s.load_textfile();
//  //    s.print_report();
//  //  }
//
//  //}
//
//  //else if (argc == 4) {
//
//
//  //  if (!strcmp(arg1, "add")) {
//  //    int p = arg2 - 48;
//  //    if (isalpha(arg3)) {
//
//  //          //put a pointer in argv[2]
//  //          
//  //          //s.add_task( argv[3], p);    
//  //    }
//  //    else {
//  //      printf("Error: Missing tasks string. Nothing added!");
//  //    }
// 
//  //
//  //  }
//
//  //}
//
//  return 0;
//}
