#include<iostream>
using namespace std;
 
int M, N;
int map[501][501];
int dp[501][501];
bool visited[501][501];
 
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
 
int dfs(int _x, int _y)
{
    // 목적지에 도착하면 최초 경우의 수 1 반환
    if (_x == M - 1 && _y == N - 1)    return 1;
 
    // 이미 방문한 곳이면 그 곳의 값을 반환
    if (visited[_x][_y]) return dp[_x][_y];
 
    // 방문 여부 표시
    visited[_x][_y] = true;
 
    for (int i = 0; i < 4; i++)
    {
        int mx = _x + dx[i];
        int my = _y + dy[i];
 
        if (mx >= 0 && mx < M && my >= 0 && my < N)
        {
            if (map[_x][_y] > map[mx][my])
            {
                // 도착지점에서부터 출발지점까지 역순으로 경우의 수를 추가하면서 채워나간다.
                dp[_x][_y] += dfs(mx, my);
            }
        }
    }
    // 현재 좌표에서 갈 수 있는 곳이 없으면 현재 좌표까지 갈 수 있는 경우의 수를 반환
    return dp[_x][_y];
}
 
int main(void)
{
    cin >> M >> N;
 
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> map[i][j];
        }
    }
 
    cout << dfs(0,0) << '\n';
 
    return 0;
}
