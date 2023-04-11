#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

#define MAX_SIZE 50

int n, m;
char map[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE];
//간길을 count할 배열
// int dist[MAX_SIZE][MAX_SIZE];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

bool isValid(int ny, int nx){
    return (0 <= nx && 0<= ny && nx<m && ny<n);
}

int bfs(int y, int x, int aa, int bb){
    queue< pair<char, char> > q;
    visited[y][x] = true;
    int cnt=0;
    q.push(make_pair(y,x));

    while(!q.empty()){
        //큐의 현재 원소 꺼내기
        y=q.front().first;
        x=q.front().second;
        q.pop();
        
        if(y==aa && y==bb) {return cnt-1;}    //종료조건

        // 해당 위치 주변으로 갈 수 있는지 확인하고, 갈 수 있으면 가기
        for(int i=0; i<4; i++){
            int next_y = y+dy[i];
            int next_x = x+dx[i];
            //지도 범위를 벗어나지 않고, 이동할 수 있는 칸이면서, 아직 방문 안했으면 가기
            if(isValid(next_y, next_x) && map[next_y][next_x]=='0' && !visited[next_y][next_x]){
                visited[next_y][next_x] = true;
                cnt++;
                q.push(make_pair(next_y,next_x));
            }
            // if(map[next_y][next_x]=='T'){
            //     aa = next_y;
            //     bb = next_x;
            //     cout << dist[aa][bb] << endl;
            //     break;
            // }
        }
    }
    return cnt-1;
}

int main(){
    //초기화
    memset(map, false, sizeof(map));
    memset(visited, false, sizeof(visited));

    cin >> n >> m;

    int a,b;
    int aa, bb;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> map[i][j];
            if(map[i][j]=='S'){
                a = i;
                b = j;
            }
            else if(map[i][j]=='T'){
                aa = i;
                bb = j;
            }
        }
    }

    cout << bfs(a,b,aa,bb)<< endl;

    return 0;
}
