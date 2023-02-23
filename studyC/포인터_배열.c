#include <stdio.h>

int main(void)
{
    int arr[3] = { 5, 10, 15 };
    for (int i = 0; i < 3; i++)
    {
        printf("1. 배열 arr[%d] 의 값 : %d\n", i, arr[i]);
    }

    int* ptr = arr;
    for (int i = 0; i < 3; i++)
    {
        printf("2. 포인터 ptr[%d] 의 값 : %d\n", i, ptr[i]);
    }

    ptr[0] = 100;
    ptr[1] = 200;
    ptr[2] = 300;
    for (int i = 0; i < 3; i++)
    {
        //printf("배열 arr[%d] 의 값 : %d\n", i, arr[i]);
        printf("3. 배열 arr[%d] 의 값 : %d\n", i, *(arr + i));
    }
    for (int i = 0; i < 3; i++)
    {
        //printf("포인터 ptr[%d] 의 값 : %d\n", i, ptr[i]);
        printf("4. 포인터 ptr[%d] 의 값 : %d\n", i, *(ptr + i));
    }

    printf("5. arr 자체의 값 : %p\n", arr);
    printf("6. arr[0] 의 주소 : %p\n", &arr[0]);

    printf("7. arr 자체의 값이 가지는 주소의 실제 값 : %d\n", *arr); // *(arr + 0)
    printf("8. arr[0] 의 실제 값 : %d\n", *&arr[0]);

    return 0;
}
