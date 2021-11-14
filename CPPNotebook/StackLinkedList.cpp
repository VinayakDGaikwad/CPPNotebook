#include <stdio.h>
#include <iostream>
#include<cstring>
#include <math.h>

using namespace std;


struct Node
{
  int data;
  struct Node* link;
};

struct Node* top;

void push(int data)
{

  struct Node* temp;
  temp = new Node();

  if (!temp)
  {
    cout << "\nHeap Overflow";
    exit(1);
  }

  temp->data = data;

  temp->link = top;

  top = temp;
}

int isEmpty()
{
  return top == NULL;
}

int peek()
{

  if (!isEmpty())
    return top->data;
  else
    exit(1);
}

int pop()
{
  struct Node* temp;

  if (top == NULL)
  {
    return 0;
  }
  else
  {
    temp = top;
    top = top->link;

    return temp->data;
  }
}

void display()
{
  struct Node* temp;


  if (top == NULL)
  {
    cout << "\nStack Underflow";
    exit(1);
  }
  else
  {
    temp = top;
    while (temp != NULL)
    {
      cout << temp->data << "-> ";
      temp = temp->link;
    }
  }
}

int evalute(char x, int op1, int op2) {
  if (x == '+') return (op1 + op2);
  if (x == '-') return(op1 - op2);
  if (x == '*') return op1 * op2;
  if (x == '/') return op1 / op2;
  if (x == '%') return(op1 % op2);
}

int prec(char c) {
  if (c == '^')
    return 3;
  else if (c == '/' || c == '*')
    return 2;
  else if (c == '+' || c == '-')
    return 1;
  else
    return -1;
}

void eval_prefix(char prefix[]) {
  char x;
  int op1, op2, val, i;
  for (i = strlen(prefix) - 1; i >= 0; i--) {
    x = prefix[i];
    if (isalpha(x)) {
      cout << "Entre the value of" << x << " : ";
      cin >> val;
      push(val);
    }
    else {
      op1 = pop();
      op2 = pop();
      val = evalute(x, op1, op2);
    }
  }
  push(val);
  cout << "value of expresssion = " << val;
};

void eval_postfix(char exp[])
{
  char ch;
  string type;
  double result{}, val, op1, op2;
  int i;
  top = 0;
  i = 0;
  ch = exp[i];

  while (ch != '$') {
    if (ch >= '0' && ch <= '9')
      type = "operand";
    else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')
      type = "operator";

    if (type == "operand") {
      push(ch - 48);
    }
    else {
      op2 = pop();
      op1 = pop();
      switch (ch)
      {
      case '+': result = op1 + op2;
        break;
      case '-': result = op1 - op2;
        break;
      case '*': result = op1 * op2;
        break;
      case '/': result = op1 / op2;
        break;
      case '^': result = pow(op1, op2);
        break;
      }
      push(result);
    }
    i++;
    ch = exp[i];
  }

  result = pop();
  cout << "Prefix is:" << result;
};



void infixToPostfix(string s) {

  string result;

  for (int i = 0; i < s.length(); i++) {
    char c = s[i];

    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
      result += c;

    else if (c == '(')
      push('(');

    else if (c == ')') {
      while (top->data != '(')
      {
        result += top->data;
        pop();
      }
      pop();
    }

    //If an operator is scanned
    else {
      while (!isEmpty() && prec(s[i]) <= prec(top->data)) {
        result += top->data;
        pop();
      }
      push(c);
    }
  }

  while (!isEmpty()) {
    result += top->data;
    pop();
  }

  cout << result << endl;
}

int main()
{
  for (size_t i = 0; i < 100; i++)
  {
    int input;
    cout << "\n \t Menu: \n \t 1.Infix expression to postfix \n \t 2. Infix to Prefix \n \t 3. Evaluate postfix \n \t 4. Evaluate prefix expression.";
    cin >> input;
    char exp[50];
    switch (input)
    {
    case 1:
      cout << "Enter infix expression: ";
      cin >> exp[50];
      infixToPostfix(exp);
      break;
    case 2:
      cout << "Enter infix expression: ";
      cin >> exp[50];

      break;
    case 3:
      cout << "Enter infix expression: ";
      cin >> exp[50];
      eval_postfix(exp);
      break;
    case 4:
      cout << "Enter postfix expression: ";
      cin >> exp[50];
      eval_postfix(exp);
      break;
    case 5:
      cout << "Enter prefix expression: ";
      cin >> exp[50];
      eval_prefix(exp);
      break;
    }
  }
  return 0;
}
