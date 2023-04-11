#include <stdio.h>
#include <iostream>
using namespace std;
#include <stack>
#include <queue>
 
int main()
{
    int n;
    char ad;
    int arr[20];
    stack <int> a;
    queue <int> A;
    stack <int> d;
    queue <int> D;
    cin >> n >> ad;
 
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    if (ad == 'a')
    {
        int num = 1;
        for (int i = 0; i < n+1; i++)
        {
            while (!a.empty() && a.top() == num)
            {
                A.push(a.top());
                a.pop();
                num++;
            }
 
            if (arr[i] > 0 && arr[i] < n + 1)
            {
                if (arr[i] == num)
                {
                    A.push(num);
                    num++;
                }
                else
                    a.push(arr[i]);
            }
 
        }
 
        if (A.size() == n)
            printf("Yes\n");
        else
            printf("No\n");
 
    }
    if (ad == 'd')
    {
        int num = n;
        for (int i = 0; i < n+1; i++)
        {
            while (!d.empty() && d.top() == num)
            {
                D.push(d.top());
                d.pop();
                num--;
 
            }
            if (arr[i] > 0 && arr[i] < n + 1)
            {
                if (arr[i] == num)
                {
                    D.push(num);
                    num--;
                }
                else
                    d.push(arr[i]);
            }
 
        }
 
        if (D.size() == n)
            printf("Yes\n");
        else
            printf("No\n");
    }
}