#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

// DFS 문제... (재귀함수)

int r, c, res;  // 행과 열 그리고 몇번 갔는지 카운트
int gift[27];       // 비교할 알파벳 배열
char map[21][21];      // 행열 선언
// void DFS(int x, int y, int cnt); // dfs 함수 선언
int dx[4] = { 1,  -1, 0, 0 };   // 가로이동
int dy[4] = { 0, 0, 1, -1 };    // 세로이동
int tc;  // testcase


void DFS(int x, int y, int cnt){   //DFS함수
    int next_x;
    int next_y;
    if(cnt>res){    // 이전 카운트 개수랑 현재 카운트 개수랑 비교
        res = cnt;  // 현재 카운트 개수가 이전 카운트 개수보다 크면 이전 카운트 개수에 현재 카운트 개수를 저장
    }
    gift[map[x][y]-'A']=1;   // 현재위치 알파벳 체크
    for(int i =0; i<4; i++){
        next_x=dx[i]+x;     // 한칸 이동시키기(가로)
        next_y=dy[i]+y;     // 한칸 이동시키기(세로)

        if((next_x>=1 && next_x<=r)&&(next_y>=1 && next_y<=c)){  // 행열 범위 내에 있는지 체크
            if(gift[map[next_x][next_y]-'A']!=1){
                DFS(next_x, next_y, cnt+1);     //재귀, 다시 dfs 함수를 돌면서 next_x,next_y에 있는 알파벳을 1처리 할것임
            }
        }
    }
    gift[map[x][y]-'A']=0; //초기화...

}



int main(){
    scanf("%d", &tc);       // testcase 입력받기
    for(int i=1; i<=tc; i++){       //testcase만큼 반복문 돌리기
        scanf("%d %d", &r, &c);     // 행열 크기 받기
        for(int j=1; j<=r; j++){    // 배열 만들기
            for(int k=1; k<=c; k++){
                scanf(" %c", &map[j][k]);
            }
        }

        res = 0;
        DFS(1,1,1);                 // 함수 호출
        printf("#%d %d\n", i, res);
    }

    return 0;
}