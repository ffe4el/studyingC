#include <iostream>
using namespace std;

int big(int *arr, int n, int max_num);

int main()
{
    int n, i, max_num;
    int arr[100];
    cin >> n;
    for(i = 0; i< n; i++) cin >> arr[i];
    for(i = 0; i< n; i++) cout << arr[i];
    cout << arr;
    max_num = 0;
    big(arr, n, max_num);
    cout << max_num;
    return 0;
}

int big(int *arr, int n, int max_num){
    max_num = arr[0];
    int i;
    for(i=1; i<n; i++){
        if (arr[i+1]>arr[i]){
            max_num = arr[i+1];
        }
    }
    return max_num;
}