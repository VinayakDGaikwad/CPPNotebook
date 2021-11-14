#include<stdio.h>
#include<conio.h>
#include<iostream>
#include<ctype.h>
#include<string.h>

using namespace std;

class stack
{
  int data[10];
  int top;

public:
  stack() {
    top = -1;
  }

  void push(int x) {
    data[++top] = x;
  }

  int pop()
  {
    return (data[top--]);
  }

  int empty() {
    if (top == -1) return 1;
    return 0;
  }

  int full()
  {
    if (top == 9)
      return 1;
    return 0;
  }

  void eval_prefixx(char prefix[]);

  int evalute(char x, int op1, int op2);

};

int evalute(char x, int op1, int op2) {
  if (x == '+') return (op1 + op2);
  if (x == '-') return(op1 - op2);
  if (x == '*') return op1 * op2;
  if (x == '/') return op1 / op2;
  if (x == '%') return(op1 % op2);
};

void eval_prefix(char prefix[]) {
  stack s;
  char x;
  int op1, op2, val, i;
  for (i = strlen(prefix) - 1; i >= 0; i--) {
    x = prefix[i];
    if (isalpha(x)) {
      cout << "Entre the value of" << x << " : ";
      cin >> val;
      s.push(val);
    }
    else {
      op1 = s.pop();
      op2 = s.pop();
      val = evalute(x, op1, op2);
      
    }
  }
  s.push(val);
  cout << "value of expresssion = " << val;
}

//void main()
//{
//   char prefix[30];
//   cout << "Enter a prefix expression";
//   cin >> prefix;
//   eval_prefix(prefix);
//  }


