#include <iostream>
#include <cstdio>

using namespace std;

int main(){
    int a,b;
    int cnt=0;

    int f;
    //첫번째 식 항의 개수 입력받기
    cin >> a;
    //첫번째 식의 배열
    double list1[21]={0, };
    int c,d;
    //첫번째 식을 배열에 집어넣기
    for(int i=0; i<a; i++){
        cin >> c;
        cin >> d;
        //배열의 d 번째 셀에 c 입력하기 
        list1[d] = c;
        if(i==a-1){
            f = d;
        }
    }

    int s;
    //두번째 식 항의 개수 입력받기
    cin >> b;
    //두번째 식의 배열
    double list2[21]={0, };
    //두번째 식을 배열에 집어넣기
    for(int i=0; i<b; i++){
        cin >> c;
        cin >> d;
        //배열의 d 번째 셀에 c 입력하기 
        list2[d] = c;
        if(i==b-1){
            s = d;
        }
    }

    //리스트1과 리스트2를 더한 리스트3 만들기
    double list3[21]={0, };
    //값이 들어있는 배열 위치 기억하는 리스트
    int list33[21];
    for(int i=0; i<21; i++){
        if (list1[i]!=0 || list2[i]!=0)
            list3[i] = list1[i] + list2[i];
            if(i==0){ //0으로 판별되면 안되니까.. -1 넣어주기
                list33[i]=-1;
            }
            if(list3[i] != 0){
                list33[i]=i;
                cnt++;
            }
    }

    //(1)출력
    printf("(%d) = ", a);
    for(int i=20; i>=0; i--){
        if(list1[i]!=0){
            if(i==f){
                printf("%.1f x^%d", list1[i], i);
            }
            else{
                printf("%.1f x^%d", list1[i], i);
                printf(" + ");
            }
            
        }
    }
    printf("\n");

    //(2)출력
    printf("(%d) = ", b);
    for(int i=20; i>=0; i--){
        if(list2[i]!=0){
            if(i==s){
                printf("%.1f x^%d", list2[i], i);
            }
            else{
                printf("%.1f x^%d", list2[i], i);
                printf(" + ");
            }
        }
    }
    printf("\n");

    //(3)출력
    printf("(%d) = ", cnt);
    int con = (f>=s) ? s : f;
    for(int i=20; i>=0; i--){
        if(list33[i]!=0){
            if(list3[i]!=0){
                if(i==con){
                    printf("%.1f x^%d", list3[i], list33[i]);
                }
                else{
                    printf("%.1f x^%d", list3[i], list33[i]);
                    printf(" + ");
                }
            }
        }
        else if(i==0){
            if(list3[i]!=0){
                printf("%.1f x^0", list3[i]);
            }
        }
    }
    printf("\n");

    return 0;
}
