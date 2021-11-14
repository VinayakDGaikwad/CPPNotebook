#include <iostream>
#include <String>
#include <math.h>

using namespace std;

class EVAL
{
private:
  struct stack
  {
    double s[10];
  int top;
  }st;

public:
  double post(char pos[]);
  void push(double);
  double pop();
};

double EVAL::post(char exp[])
{
  char ch;
  string type;
  double result{}, val, op1, op2;
  int i;
  st.top = 0;
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
    else{
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

  return (result);
}

void EVAL::push(double val) {
  if (st.top >= 10)
    cout << "Stack is full";
  st.top++;
  st.s[st.top] = val;
}

double EVAL :: pop()
{
  double val;
  if (st.top == -1)
    cout << "Stack is empty";
    val = st.s[st.top];
    st.top--;
    return (val);

}

//int main()
//{
//  char exp[10];
//  int len;
//  double Result;
//  EVAL obj;
//  cout << "Enter the postfix Expressions";
//  cin >> exp;
//  len = strlen(exp);
//  exp[len] = '$';
//  Result = obj.post(exp);
//  cout << "Tho value of the expression is" << Result;
//  exit(0);
//  return 0;
//}
