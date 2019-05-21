/*
*   Algorithm Programming Assignment #3
*   Professor : 정균락 교수님
*   class : 알고리즘 분석 - 1
*   Student No : B354025
*   Name : 정근화
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 987654321
using namespace std;

struct Node {
    int dist;
    vector<pair<int, pair<int, int>>> next;
    bool operator < (const Node &node) const{
        return dist > node.dist;
    }
};
Node nodes[11][51]; // 노선번호 1 - 10, 역의 번호 1 - 50
priority_queue<Node> pq;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ifstream input;
    input.open("input.txt");

    if (input.is_open())
    {
        int n;
        input >> n;   // 노선의 수
        for (int i = 0; i < n; i++){
            int line, cnt;  // 노선 번호, 노선의 역 번호
            input >> line >> cnt;
            for (int j = 1; j < cnt; j++){
                // 지하철이 직통으로 연결되어 있으면 가중치 1
                nodes[line][j].next.push_back(make_pair(1, make_pair(line, j + 1)));
                nodes[line][j + 1].next.push_back(make_pair(1, make_pair(line, j)));
            }
        }

        int change_n;
        input >> change_n; // 지하철 환승역의 수
        for (int i = 0; i < change_n; i++){
            int a_line, a_cnt, b_line, b_cnt;
            input >> a_line >> a_cnt >> b_line >> b_cnt;
            // 지하철이 환승으로 되어 있으면 가중치 -1 --> 추후 t를 입력받으면 그 시간을 더해준다.
            nodes[a_line][a_cnt].next.push_back(make_pair(-1, make_pair(b_line, b_cnt)));
            nodes[b_line][b_cnt].next.push_back(make_pair(-1, make_pair(a_line, a_cnt)));
        }

        int bus_n;
        input >> bus_n; // 버스 환승역의 수
        for (int i = 0; i < bus_n; i++){
            int a_line, a_cnt, b_line, b_cnt, s;
            input >> a_line >> a_cnt >> b_line >> b_cnt >> s;
            nodes[a_line][a_cnt].next.push_back(make_pair(s, make_pair(b_line, b_cnt)));
            nodes[b_line][b_cnt].next.push_back(make_pair(s, make_pair(a_line, a_cnt)));
        }

        int tc;
        input >> tc; // 테스트 케이스
        while(tc--){
            int t, a_line, a_cnt, b_line, b_cnt;
            input >> t >> a_line >> a_cnt >> b_line >> b_cnt;

            /*
            
                여기서 알고리즘 구현.
            
            */

            // 가중치 배열 및 t로 초기화
            for (int i = 0; i < 11; i++){
                for (int j = 0; j < 51; j++){
                    nodes[i][j].dist = INF;
                }
            }

            nodes[a_line][a_cnt].dist = 0;     // 시작점
            pq.push(nodes[a_line][a_cnt]);
            while(!pq.empty()){
                Node curNode = pq.top();
                pq.pop();
                for(pair<int, pair<int, int>> pa : curNode.next){
                    int hwanseung = 0;
                    if(pa.first == -1){
                        hwanseung = t + 1;
                    }
                    if(nodes[pa.second.first][pa.second.second].dist > curNode.dist + pa.first + hwanseung){
                        nodes[pa.second.first][pa.second.second].dist = curNode.dist + pa.first + hwanseung;
                        pq.push(nodes[pa.second.first][pa.second.second]);
                    }
                }
            }

            cout << nodes[b_line][b_cnt].dist << '\n';
        }
    }
    
    return 0;
}