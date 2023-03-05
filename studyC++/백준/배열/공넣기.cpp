//10810
#include <iostream>
using namespace std;

int main(){
    int n, m, i, j, k;
    cin >> n >> m;
    int arr[101];
    for(int a=0; a<n; a++){
        arr[a]=0;
    }
    // cout << arr[2] <<endl;
    for(int a=0; a<m; a++){
        cin >> i >> j >> k;
        for(int b=i-1; b<j;b++){
            arr[b]=k;
        }
    }
    for(int a=0; a<n; a++){
        cout<<arr[a]<<" ";
    }
    cout<<endl;
    return 0;
}