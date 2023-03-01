#include <iostream>
using namespace std;

int arr[3] = {10, 20, 30}; // 배열 선언

 
int main(){
    cout << " 배열의 이름을 이용하여 배열 요소에 접근 : " << arr[0] << ", " << arr[1] << ", " << arr[2] << endl;

    cout << "배열의 이름으로 포인터 연산을 해 배열 요소에 접근 : "<< *(arr+0) << ", " << *(arr+1) << ", " << *(arr+2);
}
