//#include <stdio.h>
//#include <iostream>
//#include<cstring>
//#include <math.h>
//
//using namespace std;
//
//
//struct Node
//{
//  int data;
//  struct Node* link;
//};
//
//struct Node* top;
//
//void push(int data)
//{
//
//  struct Node* temp;
//  temp = new Node();
//
//  if (!temp)
//  {
//    cout << "\nHeap Overflow";
//    exit(1);
//  }
//
//  temp->data = data;
//
//  temp->link = top;
//
//  top = temp;
//}
//
//int isEmpty()
//{
//  return top == NULL;
//}
//
//int peek()
//{
//
//  if (!isEmpty())
//    return top->data;
//  else
//    exit(1);
//}
//
//int pop()
//{
//  struct Node* temp;
//
//  if (top == NULL)
//  {
//    return 0;
//  }
//  else
//  {
//    temp = top;
//    top = top->link;
//
//    return temp->data;
//  }
//}
//
//void display()
//{
//  struct Node* temp;
//
//
//  if (top == NULL)
//  {
//    cout << "\nStack Underflow";
//    exit(1);
//  }
//  else
//  {
//    temp = top;
//    while (temp != NULL)
//    {
//      cout << temp->data << "-> ";
//      temp = temp->link;
//    }
//  }
//}
//
//int evalute(char x, int op1, int op2) {
//  if (x == '+') return (op1 + op2);
//  if (x == '-') return(op1 - op2);
//  if (x == '*') return op1 * op2;
//  if (x == '/') return op1 / op2;
//  if (x == '%') return(op1 % op2);
//  if (x == '^') return(pow(op1,op2));
//}
//
//int prec(char c) {
//  if (c == '^')
//    return 3;
//  else if (c == '/' || c == '*')
//    return 2;
//  else if (c == '+' || c == '-')
//    return 1;
//  else
//    return -1;
//}
//
//void eval_prefix(char prefix[],int a, int b ,int c) {
//  char x;
//  int op1, op2, val, i;
//  for (i = strlen(prefix) - 1; i >= 0; i--) {
//    x = prefix[i];
//    if (isalpha(x)) {
//      if (x == 'a' || x == 'A') {
//        push(a);
//      }
//      if (x == 'b' || x == 'B') {
//        push(b);
//      }
//      if (x == 'c' || x == 'C') {
//        push(c);
//      }
//    }
//    else {
//      op1 = pop();
//      op2 = pop();
//      val = evalute(x, op1, op2);
//    }
//  }
//  push(val);
//  cout << "value of expresssion = " << val;
//};
//
//void eval_postfix(char exp[],double a, double b, double c)
//{
//  char ch;
//  string type;
//  double result{}, val, op1, op2;
//  int i;
//  top = 0;
//  i = 0;
//  ch = exp[i];
//
//  while (ch != '\0') {
//    if (ch >= 'a' && ch <= 'c' || ch >= 'A' && ch <= 'C')
//      type = "operand";
//    else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')
//      type = "operator";
//    if (type == "operand") {
//      if (ch == 'a' || ch == 'A') {
//        push(a);
//      }
//      if (ch == 'b' || ch == 'B') {
//        push(b);
//      }
//      if (ch == 'c' || ch == 'C') {
//        push(c);
//      }
//      
//    }
//    else {
//      op2 = pop();
//      op1 = pop();
//
//      result = evalute(ch, op1,op2);
//
//      push(result);
//    }
//    i++;
//    ch = exp[i];
//  }
//
//  result = pop();
//  cout << "Prefix result is:" << result;
//};
//
//string infixToPostfix(string s) {
//
//  string post_exp;
//
//  for (int i = 0; i < s.length(); i++) {
//    char c = s[i];
//
//    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
//      post_exp += c;
//
//    else if (c == '(')
//      push('(');
//
//    else if (c == ')') {
//      while (top->data != '(')
//      {
//        post_exp += top->data;
//        pop();
//      }
//      pop();
//    }
//
//    //If an operator is scanned
//    else {
//      while (!isEmpty() && prec(s[i]) <= prec(top->data)) {
//        post_exp += top->data;
//        pop();
//      }
//      push(c);
//    }
//  }
//
//  while (!isEmpty()) {
//    post_exp += top->data;
//    pop();
//  }
//
//  //cout << post_exp << endl;
//  return post_exp;
//}
//
//string infixToPrefix(string infix)
//{
//  int l = infix.size();
//
//  reverse(infix.begin(), infix.end());
//
//  for (int i = 0; i < l; i++) {
//
//    if (infix[i] == '(') {
//      infix[i] = ')';
//      i++;
//    }
//    else if (infix[i] == ')') {
//      infix[i] = '(';
//      i++;
//    }
//  }
//
//  string prefix = infixToPostfix(infix);
//
//  reverse(prefix.begin(), prefix.end());
//
//  return prefix;
//}
//
//int main()
//{
//  for (size_t i = 0; i < 100; i++)
//  {
//    int input;
//    cout << "\n \t Menu: \n \t 1.Infix expression to postfix \n \t 2. Infix to Prefix \n \t 3. Evaluate postfix \n \t 4. Evaluate prefix expression.";
//    cin >> input;
//    char exp[50];
//    double a, b, c;
//    switch (input)
//    {
//    case 1:
//      cout << "Enter infix expression: ";
//      cin >> exp;
//      cout << "Expression is :" << infixToPostfix(exp);
//      break;
//    case 2:
//      cout << "Enter infix expression: ";
//      cin >> exp;
//      cout << "Expression is:" << infixToPrefix(exp);
//      break;
//    case 3:
//      cout << "Enter postfix expression: ";
//      cin >> exp;
//      
//      cout << "Enter a,b,c:";
//      cin >> a;
//      cin >> b;
//      cin >> c;
//      eval_postfix(exp,a,b,c);
//      break;
//    case 4:
//      cout << "Enter prefix expression: ";
//      cin >> exp;
//      cout << "Enter a,b,c:";
//      cin >> a;
//      cin >> b;
//      cin >> c;
//      eval_prefix(exp,a,b,c);
//      break;
//    }
//  }
//  return 0;
//}
