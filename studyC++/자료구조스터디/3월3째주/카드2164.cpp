#include <iostream>
#include <queue>

using namespace std;

int main(){
    queue<int> q;
    int n;
    cin >> n;
    for(int i=1; i<=n;i++){
        q.push(i);
    }
    // cout <<q.size()<<endl;
    while(q.size()>1){
        q.pop();
        q.push(q.front());
        q.pop();
    }
    cout<<q.front()<<endl;
    
    return 0;
}