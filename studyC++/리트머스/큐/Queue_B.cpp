#include <iostream>
#include <string>
#include <queue>
#include <stack>
using namespace std;

int main(){
    queue <int> q;
    stack <int> s;
    queue <int> pq; //print queue
    string ans;

    int n;
    cin >> n;

    char type; //오름차순인지 내림차순인지
    cin >> type;
    
    int a;
    for(int i=0; i<n; i++){//순서대로 입력받기
        cin >> a;
        q.push(a);
    }

    int num=1;
    //오름차순
    if(type =='a'){
        while(!q.empty()){
            if(q.front()==num){
                pq.push(q.front());
                q.pop();
                num++;

                if(!s.empty()){
                    while(s.top()==num){
                        pq.push(s.top());
                        s.pop();
                        num++;
                    }
                }
            }
            else{
                s.push(q.front());
            }
        }
        if(num == n+1){
            cout << "Yes" <<endl;
        }
        else{
            cout << "No" <<endl;
        }
    }
    

    int number=n;
    //내림차순
    if(type == 'd'){
        while(!q.empty()){
            if(q.front()==number){
                pq.push(q.front());
                q.pop();
                number--;

                if(!s.empty()){
                    while(s.top()==number){
                        pq.push(s.top());
                        s.pop();
                        number--;
                    }
                }
            }
            else{
                s.push(q.front());
            }
        }
        if(number == 0){
            cout << "Yes" <<endl;
        }
        else{
            cout << "No" <<endl;
        }
    }

    return 0;
}