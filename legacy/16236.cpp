
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

// 상어 구조체
struct fish {
int r;
int c;
// 현재 사이즈를 표시
int size;
// 몇 마리를 잡아 먹었는지 표시
int eat;
// 이동한 시간을 표시
int time;
};

int N;
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
int map[21][21];
int visited[21][21];

queue<fish> q;
vector<fish> v;

// 문제 조건에 맞는 비교연산
bool cmp(fish a, fish b) {
// 가장 짧은 시간
if (a.time <= b.time) {
    // 시간이 같을 경우
    if (a.time == b.time) {
        // y값이 더 작은 순서
        if (a.r <= b.r) {
            // y값이 같다면
            if (a.r == b.r) {
                // x값이 작은 순서로 정렬
                if (a.c < b.c) {
                    return true;
                }
                return false;
            }
            return true;
        }
        return false;
    }
    return true;
}
return false;
}

int main() {
cin >> N;
// 이전 상어의 상태를 저장
fish ex;
for (int r = 0; r < N; r++) {
    for (int c = 0; c < N; c++) {
        cin >> map[r][c];
        if (map[r][c] == 9) {
            // 시작 위치를 설정
            map[r][c] = 0;
            // 물고기 초기화
            ex = {r, c, 2, 0, 0};
        }
    }
}
// 시간 정보
int ans = 0;
while (1) {
    v.clear();
    memset(visited, 0, sizeof(visited));
    visited[ex.r][ex.c] = 1;
    q.push(ex);

    while (!q.empty()) {
        int r = q.front().r;
        int c = q.front().c;
        int size = q.front().size;
        int eat = q.front().eat;
        int time = q.front().time;
        q.pop();

        // 4방향으로 검사를 진행
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr >= 0 && nr < N && nc >= 0 && nc < N) {
                // 맵 사이즈가 유효하고 방문하지 않은 지역
                if (!visited[nr][nc]) {
                    // 사이즈가 같은 상어이거나 길인 경우
                    if (map[nr][nc] == 0 || map[nr][nc] == size) {
                        // 방문 처리
                        visited[nr][nc] = 1;
                        // 시간만 추가하고 계속 작은 상어를 찾음
                        q.push({nr, nc, size, eat, time + 1});
                    }
                    // 만약 작은 상어가 있다면
                    else if (map[nr][nc] < size) {
                        // 방문 처리
                        visited[nr][nc] = 1;
                        // 잡아 먹은 상어와 시간을 표시하고 벡터에 따로 저장
                        v.push_back({nr, nc, size, eat + 1, time + 1});
                    }
                }
            }
        }
    }

    // 만약 벡터가 비어있다면 잡아 먹을수 있는 상어가 없음
    if (v.size() == 0) {
        break;
    }

    // cmp 조건에 맞춰 정렬
    sort(v.begin(), v.end(), cmp);
    // 먹은 상어의 숫자가 현재 사이즈와 같다면 사이즈 증가
    if (v[0].size == v[0].eat) {
        v[0].size++;
        v[0].eat = 0;
    }
    // 잡어 먹은 상어를 지움
    map[v[0].r][v[0].c] = 0;
    // 움직인 시간을 저장
    ans += v[0].time;
    // 시간을 초기화하고 다시 큐에 넣어 이전 과정을 반복
    ex = {v[0].r, v[0].c, v[0].size, v[0].eat, 0};
}

cout << ans;
return 0;
}
