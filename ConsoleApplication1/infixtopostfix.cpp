#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

using namespace std;

char data[10];
class stack
{
  int data[10];
  

public:
  int top;

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
};

    int precedence(char x) {
      if (x == '(')
        return 0;
      if (x == '+' || x == '-')
          return 1;
      if (x == '*' || x == '/;' || x == '%')
          return 2;
      return 3;
    }

    void infix_to_postfix(char infix[], char postfix[]) {
      stack s;
      char x;
      int i, j;
      char token;
      j = 0;
      for (i = 0; infix[i] != '\0'; i++) {
        token = infix[i];
        if (isalnum(token)) postfix[j++] = token;
        else
          if(token == '(')
            s.push('(');
          else {
            if (token == ')')
              while ((x = s.pop() != '('))
                postfix[j++] = x;\
            else {
              while (precedence(token) <= precedence(s.top) && !s.empty()) {
                x = s.pop();
                postfix[j++] = x;
              }
              s.push(token);
            }
          }
      }

      while (!s.empty()) {
        x = s.pop();
        postfix[j++] = x;
      }
      postfix[j] = '\0';

    }

    void infix_to_prefix(char infix[], char prefix[]) {
      int i, j = 0;
      char temp, inl[30];

      for (i = strlen(infix) - 1; j == 0; i >= 0, i--, j++) {
        inl[j] = infix[i];
        inl[j] = '\0';

        for (i = 0; inl[i] != '\0'; i++) {
          if (inl[i] == '(') {
            inl[i] = ')';
          }
          else {
            if (inl[i] = ')') {
              inl[i] = '(';
            }
          }
        }

        infix_to_postfix(inl, prefix);
        for (i = 0, j = (strlen(prefix) - 1); i < j; i++, j--) {
          temp = prefix[i];
          prefix[i] = prefix[j];
          prefix[j] = temp;
        }

      }
    }

      /*int main() {
        char infix[30], postfix[30];
        cout << "Enter an infix expression:";
        cin >> infix;
        infix_to_postfix(infix, postfix);
        cout << "Postfix:" << postfix;
      };*/
