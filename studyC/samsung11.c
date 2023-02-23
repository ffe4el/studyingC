#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#define MAX_SIZE 21

int N, M, res=1;
char map[MAX_SIZE][MAX_SIZE];
int alpha[27];
int dx[4] = { 1,  -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

void DFS(int x_, int y_,int cnt) {
	int nextX;
	int nextY;
	if (cnt > res) {
		res = cnt;
	}

	for (int i = 0; i < 4; i++) {
		nextX = dx[i] + x_;
		nextY = dy[i] + y_;

		if (1 <= nextX && nextX <= N && 1 <= nextY && nextY <= M) {
			if (!alpha[map[nextX][nextY]-'A'] ) {
				alpha[map[nextX][nextY] - 'A'] = 1;
				DFS(nextX, nextY,cnt+1);
				alpha[map[nextX][nextY] - 'A'] = 0;
			}
		}
	}
}

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf(" %c", &map[i][j]);
		}
	}
	alpha[map[1][1] - 'A'] = 1;
	DFS(1, 1, 1);
	printf("%d", res);

	return 0;
}