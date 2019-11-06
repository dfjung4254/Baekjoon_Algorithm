#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct planet {
    int x, y, z, num;
};
bool cmpx(const planet& p1, const planet& p2) {
    return p1.x > p2.x;
}
bool cmpy(const planet& p1, const planet& p2) {
    return p1.y > p2.y;
}
bool cmpz(const planet& p1, const planet& p2) {
    return p1.z > p2.z;
}
planet pl[100000];

struct edge {
    int weight, from, to;
};
bool operator<(const edge& e1, const edge& e2) {
    return e1.weight > e2.weight;
}
vector<edge> ed;


int parent[100000];

int find(int x) {
    if (x == parent[x])
        return x;
    else
        return parent[x] = find(parent[x]);
}
void unite(int x, int y) {
    x = find(x);
    y = find(y);

    parent[x] = y;
}

int n, i;

int main() {
    scanf("%d", &n);
    for (i = 0; i < n; ++i) {
        scanf("%d %d %d", &pl[i].x, &pl[i].y, &pl[i].z);
        pl[i].num = i;
        parent[i] = i;
    }

    sort(pl, pl + n, cmpx);
    for (i = 0; i < n - 1; ++i)
        ed.push_back({ abs(pl[i].x - pl[i + 1].x), pl[i].num, pl[i + 1].num });

    sort(pl, pl + n, cmpy);
    for (i = 0; i < n - 1; ++i)
        ed.push_back({ abs(pl[i].y - pl[i + 1].y), pl[i].num, pl[i + 1].num });

    sort(pl, pl + n, cmpz);
    for (i = 0; i < n - 1; ++i)
        ed.push_back({ abs(pl[i].z - pl[i + 1].z), pl[i].num, pl[i + 1].num });

    sort(ed.begin(), ed.end());

    int ans = 0;
    int cnt = 0;
    for (int i = ed.size() - 1; cnt != n - 1;--i) {
        if (find(ed[i].from) != find(ed[i].to)) {
            cnt++;
            ans += ed[i].weight;
            cout << ed[i].from << " - " << ed[i].to << " connected(" << ed[i].weight << ")" << '\n';
            unite(ed[i].from, ed[i].to);
        }
        if (cnt == n - 1)
            break;
    }
    printf("%d", ans);

    return 0;
}
