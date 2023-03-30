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


    //오름차순
    if(type =='a'){
        int num=1;
        while(num < 5){
            while(q.front()!=num){
                s.push(q.front());
                q.pop();
            }
            if(q.front()==num){
                pq.push(q.front());
            }
            num++;
            if(s.top()==num){
                pq.push(s.top());
                s.pop();
                num++;
            }
        }
    }

    //내림차순
    else if(type = 'd'){

    }

    
    // while(q.front()!=1){
    //     int num;
    //     num = q.front();
    //     s.push(num);
    //     q.pop();
    // }

    // if(stack.)




    return 0;
}