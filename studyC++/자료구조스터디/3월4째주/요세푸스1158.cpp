
#include <iostream>
#include <queue>
using namespace std;

//큐를 이용해서 풀기
int main(){
    queue <int> q;
    int n,k;
    string ans;
    cin >> n;
    cin >> k;
    for(int i=1; i<=n; i++){
        q.push(i);
    }
    while(!q.empty()){
        for(int i=0; i<k-1; i++){
            q.push(q.front());
            q.pop();
        }
        
        ans += q.front();
        q.pop();
        if(q.){ // 애는 어떻게 하지...?
            ans += ", ";
        }
        
        
    }

    return 0;
}


//배열을 써서 해보려고 했는데, 시간복잡도가 너무 큼... n제곱이상임...
// int main(){
//     int arr[5001];
//     int n,k;
//     cin >> n;
//     cin >> k;
//     for(int i=1; i<=n; i++){ //배열에 n까지의 수 넣기 
//         arr[i] = i;
//     }


    return 0;
}