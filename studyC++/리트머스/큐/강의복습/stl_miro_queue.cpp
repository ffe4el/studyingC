#include <queue>
using namespace std;

struct Location2D{
    int row;    //현재위치의 행번호
    int col;    // 현재위치의 열번호
    Location2D(int r=0, int c=0){row=r; col=c;}
    //위치 p가 자신의 이웃인지 검사하는 함수
    bool isNeighbor(Location2D &p){ //?왜  &을 쓸까...
        return ((row == p.row && (col==p.col-1 || col==p.col+1)) || (col==p.col && (row==p.row-1||row==p.row+1)) );
    }
    //위치 p가 자신과 같은 위치인지를 검사하는 함수(연산자 오버로딩 사용)
    bool operator ==(Location2D &p){return row==p.row && col==p.col;}
};

const int MAZE_SIZE=6;  //미로맵 크기 고정
char map[MAZE_SIZE][MAZE_SIZE] = {  //미로맵 데이터
    {'1','1','1','1','1','1'},
    {'e','0','1','0','0','1'},
    {'1','0','0','0','1','1'},
    {'1','0','1','0','1','1'},
    {'1','0','1','0','0','x'},
    {'1','1','1','1','1','1'},
};

//(r,c)가 갈 수 있는 위치인지를 검사
//(r,c)가 배열 안에 있고, 값이 갈 수 있는 위치 '0'이거나 출구 'x'이어야함
bool isValidLoc(int r, int c){
    if(r<0||c<0||r>=MAZE_SIZE|| c>=MAZE_SIZE) return false;
    else return map[r][c] =='0' || map[r][c]=='x'; //bool타입 반환
}

int main(){
    queue<Location2D> locqueue; //위치 큐 객체 생성
    Location2D entry(1,0); //입구 객체
    locqueue.push(entry);   //큐에 위치 삽입

    while(locqueue.empty()==false){ //큐가 비어있지 않는 동안
        Location2D here = locqueue.front(); //큐의 front 상단 객체 복사
        locqueue.pop(); //큐의 상단 객체 삭제

        int r=here.row; 
        int c = here.col;
        printf("(%d, %d)", r,c);    //현재위치 화면 출력
        if(map[r][c] =='x'){    // 출구를 만났으면 -> 탐색 성공
            printf(" 미로 탐색 성공\n");
            return;
        }
        else {      //출구가 아니면
            map[r][c] ='.'; //현재 위치를 지나옴처리
            if(isValidLoc(r-1,c)) locqueue.push(Location2D(r-1,c));
            if(isValidLoc(r+1,c)) locqueue.push(Location2D(r+1,c));
            if(isValidLoc(r,c-1)) locqueue.push(Location2D(r,c-1));
            if(isValidLoc(r,c+1)) locqueue.push(Location2D(r,c+1));
        }
    }
    return 0;
}