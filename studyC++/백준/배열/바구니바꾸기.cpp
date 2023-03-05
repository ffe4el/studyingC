//10811
#include <iostream>
using namespace std;

void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

int main(){
    int n,m,i,j;
    cin >> n >> m;
    int arr[1001];
    for(int i=0; i<n; i++){
        arr[i]=i+1;
    }
    for(int a=0;a<m;a++){
        cin >> i >> j;
        int k;
        k = j-i;
        for(int b=0; b<=(k)/2; b++){
            // cout << arr[b+i];
            swap(arr[b+i-1], arr[j-b-1]);
        }
    }
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}