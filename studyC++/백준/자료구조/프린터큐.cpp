//우선순위큐 사용 -> pair로
#include <iostream>
#include <queue>
using namespace std;

int main(){
    int tc;
    cin >>tc;
    int cnt=0;
    int n;
    int m;
    int im;


    for(int i=0; i<tc; i++){//test_case시작  
        cnt = 0;    //tc마다 cnt 초기화
        cin >> n >> m;

        //queue tc마다 초기화
        queue <pair<int,int>> pq; //pair queue
        priority_queue <int> q; //우선순위 큐, 내림차순 정렬해야 pop할때 높은게 빠져나옴.
        
        for(int j=0; j<n; j++){
            cin >> im;
            pq.push({j,im}); //인덱스와 중요도를 pair로 넣음
            q.push(im); 
        }

        while(!pq.empty()){
            int loc = pq.front().first;
            int val = pq.front().second;
            pq.pop();

            if(q.top()==val){
                q.pop();
                cnt++;
                if(m==loc){
                    cout << cnt <<endl;
                    break;
                }
            }
            else{
                pq.push({loc, val});
            }
        }
    }

    return 0;
}