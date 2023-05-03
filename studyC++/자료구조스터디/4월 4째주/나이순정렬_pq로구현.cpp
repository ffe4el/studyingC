#include <iostream>
#include <string>
#include <queue>
#include <stack>
using namespace std;

int main(){
    priority_queue <pair<int, string>> p;
    // queue <pair<int, string>> q;
    stack <pair<int, string>> s;
    int tc;
    cin >> tc;
    for(int i=0; i<tc; i++){
        int age;
        string name;
        cin >> age;
        cin >> name;
        p.push(make_pair(age, name));
    }

    // cout << type(p.pop());
    for(int i=0; i<tc; i++){
        int age1 = p.top().first;
        string name1 = p.top().second;
        // cout << age1 << " " << name1 <<endl;
        s.push(make_pair(age1,name1));
        p.pop();
    
         
        // s.push(make_pair(1,"name"));
    }
    for(int i=0; i<tc; i++){
        int age1 = s.top().first;
        string name1 = s.top().second;
        cout << age1 << " " << name1 <<endl;
        s.pop();
        // s.push(make_pair(age1,name1));
         
        // s.push(make_pair(1,"name"));
    }

    return 0;
}