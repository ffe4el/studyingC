#include <iostream>
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

bool isValidLoc(int n, int m, int r, int c, char miro[][51]){
    if(r<0||c<0||r>=n|| c>=m) return false;
    else return miro[r][c] =='0' || miro[r][c]=='T'; //bool타입 반환
}

int main(){
    queue <Location2D> q;
    int cnt; //지나온 거리 세기
    int n,m;
    cin >> n >> m;
    char miro[51][51] = {0, }; //미로행렬

    //미로 입력받기
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> miro[i][j];
            if(miro[i][j]=='S'){
                Location2D entry(i,j);
                q.push(entry); //덱에 입구 위치 삽입
                // cnt++;
            }
        }
    }

    //미로 출력하기 => 잘들어 왔네...
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<m; j++){
    //         cout << miro[i][j];
    //     }
    //     cout << endl;
    // }


    while(q.empty()==false){
        Location2D here=q.front();  //덱의 front 상단 객체 복사
        q.pop(); //덱의 상단 객체 삭제
        cnt++;

        int r=here.row; 
        int c = here.col;
        // printf("(%d, %d)", r,c);    //현재위치 화면 출력
        if(miro[r][c] =='T'){    // 출구를 만났으면 -> 탐색 성공
            cout << cnt <<endl;
            return 0;
        }
        else {      //출구가 아니면
            miro[r][c] ='.'; //현재 위치를 지나옴처리
            if(isValidLoc(n,m,r-1,c,miro)) q.push(Location2D(r-1,c));
            if(isValidLoc(n,m,r+1,c,miro)) q.push(Location2D(r+1,c));
            if(isValidLoc(n,m,r,c-1,miro)) q.push(Location2D(r,c-1));
            if(isValidLoc(n,m,r,c+1,miro)) q.push(Location2D(r,c+1));
        }
    }
    return 0;
}