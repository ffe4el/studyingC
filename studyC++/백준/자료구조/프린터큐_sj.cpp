#include <iostream>
#include <queue>
using namespace std;

int main()
{
   
   int n, m;
   int textn;
   int input;
   cin >> textn;
   
   for (int i = 0; i < textn; i++)
   {
      cin >> n >> m;
      int cnt = 0;

    queue <int> num;
    queue <int> import;
    priority_queue <int> pri;
      for (int i = 0; i < n; i++)
      {
        cin >> input;
        import.push(input);
        num.push(i);

        pri.push(input);
      }

      while (!num.empty())
      {
        int Num = num.front();
        num.pop();
        int Import = import.front();
        import.pop();

        if (pri.top() == Import)
        {
        pri.pop();
        cnt++;
            if (m == Num)
            {
                cout << cnt << endl;
                break;
            }
        }
        else
        {
            import.push(Import);
            num.push(Num);
        }
    }
      
   }


   return 0;
}