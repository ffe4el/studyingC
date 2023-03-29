#include <iostream>
using namespace std;

int arr[3]={10,20,30};
int*ptr_arr = arr;

int main(){
    cout << "배열의 이름을 이용하여 배열 요소에 접근 : "<<arr[0]<<","<<arr[1]<<","<<arr[2]<<endl;
    cout << "포인터를 이용하여 배열 요소에 접근 : "<< ptr_arr[0]<<","<<ptr_arr[1]<<","<<ptr_arr[2]<<endl;
    cout<<"배열의 이름을 이용한 배열의 크기 계산 : "<<sizeof(arr)<<endl;
    cout<<"포인트를 이용한 배열의 크기 계산 : " << sizeof(ptr_arr);
    return 0;
}