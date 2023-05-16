#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

const int MAX_STACK_SIZE = 10;

class CircularStack {
protected:
   int top;
   int bottom;
   char data[MAX_STACK_SIZE];
public:
   CircularStack()
   {
      top = -1;
      bottom = 0;
   }
   bool isEmpty() { return top == bottom - 1; }
   int size()
   {
      return top - bottom + 1;
   }
   void push(char al)
   {
      if (size() >= MAX_STACK_SIZE)
      {
         top++;
         bottom++;
         data[top] = al;
         cout << top <<" ";
      }
      else
      {
         top++;
         data[top] = al;
      }

   }
   char pop()
   {
      if (!isEmpty())
      {
         char al = data[top];
         top--;
         return al;
      }
      else{
        printf("공백에러\n");
        exit(0);
      }
      
   }
   
};
int main()
{
   char al;
   CircularStack undo;

   do {
      cin >> al;
      if (al >='a' && al <= 'z')
      {
        undo.push(al);
      }

      else if (al == 'U')
      {
        if (undo.isEmpty())
        {
        cout << "ERROR " << endl;
        return 0;
        }
        else
        undo.pop();

      }

   } while (getc(stdin) == ' '); //엔터를 입력하면 입력 반복문 탈출

   if (undo.size() == 0)
      cout << "EMPTY ";
   while (undo.size() > 0)
   {    
        char tmp = undo.pop();
        cout << tmp << " ";
   }
   cout << endl;

   return 0;

}