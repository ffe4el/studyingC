//10813
#include <iostream>
using namespace std;

void swap(int* arr,int i, int j){
    int time;
    time = arr[i];
    arr[i] = arr[j];
    arr[j] = time;
}

int main(){
    int n, m, i, j;
    cin >> n >> m;
    int arr[1001];
    for(int a=0; a<n; a++){
        arr[a]=a+1;
    }
    for(int a=0;a<m;a++){
        cin >> i >> j;
        swap(arr,i-1,j-1);
    }
    for(int a=0;a<n;a++){
        cout<<arr[a]<<" ";
    }
    cout<<endl;
    return 0;
}