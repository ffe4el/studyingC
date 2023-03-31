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
    
    int input;
    for(int i=0; i<n; i++){//순서대로 입력받기
        cin >> input;
        q.push(input);
    }

    //오름차순
    if(type =='a'){
        int num=1;
        while(!q.empty()){
            if(q.front()==num){
                pq.push(q.front());
                q.pop();
                cout << q.front();
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
                cout<<"스택에 넣는중";
                cout << q.front();
                q.pop();
                
            }
        }
        if(num == n+1){
            cout << "Yes" <<endl;
        }
        else{
            cout << "No" <<endl;
        }
    }
    

    //내림차순
    else if(type == 'd'){
        int number=n;
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
                cout<<"스택에 넣는중";
                cout << q.front();
                q.pop();
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