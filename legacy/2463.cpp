#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
long long maxSum = 0;
long long ret = 0;
class Edge{
public:
    int i;
    int j;
    int w;
    Edge(int i = 0, int j = 0, int w = 0)
    :i(i), j(j), w(w) {}
    bool operator < (const Edge &e) const {
        //sort를 위한 '내림' 차순 정렬
        return w > e.w;
    }
};
vector<Edge> edge;
int vRoot[100001] = {0, };
long long gSize[100001] = {0, };

int findRoot(int v){
    if(vRoot[v] == v) return v;
    return vRoot[v] = findRoot(vRoot[v]);
}

void reKruskal(){
    //루트 배열 초기화 및 그룹크기 초기화.
    for(int i = 1; i <= n; i++){
        vRoot[i] = i;
        gSize[i] = 1;
    }
    //일반적인 오름차순이 아니라 내림차순
    sort(edge.begin(), edge.end());
    for(Edge e : edge){
        //일반적인 kruskal 알고리즘 처럼 루트를 찾고 연결해준다
        //다만 이 과정에서 root배열 뿐만 아니라 배열이 하나 더 필요한데
        //각 노드가 속해있는 그룹의 인원 수를 default 1로 정의 해놓고
        //합쳐질때마다 그룹의 인원수를 갱신해주어야 한다.
        int rootI = findRoot(e.i);
        int rootJ = findRoot(e.j);
        if(rootI != rootJ){
            //cycle 여부를 확인을 안해도되지않나라고 생각할 수 있지만
            //엄연히 원래는 작은것 부터 제거해나가는 것이므로 cycle이 해제
            //가 된 시점을 기준으로 root구조가 달라진다
            //따라서 큰것부터 다리를 설치한다고 생각하여도 cycle이 돌지않을때가
            //root가 변경이 되는 최초시점이기때문에 반드시 확인해주어야 함.

            //cost를 더하고 root를 합병
            //
            ret += (gSize[rootI] * gSize[rootJ] * maxSum);
            ret %= 1000000000;

            //rootJ그룹은 rootI 그룹에 병합된다
            vRoot[rootJ] = rootI;
            //rootI 그룹의 사이즈는 rootJ그룹의 인원수를 흡수한다.
            gSize[rootI] += gSize[rootJ];
        }
        //다음 연산을위해 현재 코스트를 빼줌.
        maxSum -= e.w;
    }
    cout << ret << endl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    while(m--){
        int x, y, w;
        cin >> x >> y >> w;
        maxSum += w;
        edge.push_back(Edge(x, y, w));
    }
    reKruskal();

    return 0;
}
