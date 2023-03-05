//10811
#include <iostream>
using namespace std;

int main(){
    int n,m,i,j;
    cin >> n >> m;
    int arr[1001];
    for(int a=0; a<n; a++){
        arr[a]=a+1;
    }
    for(int a=0;a<m;a++){
        cin >> i >> j;
        int k;
        k = j-i;
        for(int b=0; b<k+1; b++){
            int time;
            time = arr[j-1];
            arr[i+b-1]= time-b;
            // cout<<"*"<<arr[i+b-1]<<endl;
            // cout<<"!"<<arr[j-b-1]<<endl;
        }
    }
    for(int a=0; a<n; a++){
        cout<<arr[a]<<" ";
    }
    cout<<endl;
    return 0;
}