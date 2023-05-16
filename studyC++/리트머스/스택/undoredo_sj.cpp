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
   CircularStack(){
      top = -1;
      bottom = 0;
   }
   bool isEmpty() { return top == bottom - 1; }
   int size(){
      return top - bottom + 1;
   }
   void push(char al){
      if (size() >= MAX_STACK_SIZE){
         top++;
         bottom++;
         data[top] = al;
      }
      else{
         top++;
         data[top] = al;
         cout << top <<" ";
      }
   }
   char pop(){
      if (!isEmpty()){
         char al = data[top];
         top--;
         return al;
      }
      else{return 0;}
   }
};
int main()
{
   char al;
   CircularStack undo;
   CircularStack redo;

   do {
      cin >> al;
      if (al >='a' && al <= 'z'){
         undo.push(al);
         while (!redo.isEmpty())
            redo.pop();
      }

      else if (al == 'U'){
         if (undo.isEmpty())
         {
            cout << "ERROR " << endl;
            return 0;
         }
         else
            redo.push(undo.pop());

      }

      else if (al == 'R'){
         if (redo.isEmpty())
         {
            cout << "ERROR " << endl;
            return 0;
         }
         else
            undo.push(redo.pop());
         
      }
   } while (getc(stdin) == ' '); //엔터를 입력하면 입력 반복문 탈출

   if (undo.size() == 0)
      cout << "EMPTY ";
   while (undo.size() > 0){
      cout << undo.pop() << " ";
   }
   cout << endl;

   if (redo.size() == 0)
      cout << "EMPTY ";
   while (redo.size()>0)
      cout << redo.pop() << " ";
   cout<<endl;

   return 0;

}