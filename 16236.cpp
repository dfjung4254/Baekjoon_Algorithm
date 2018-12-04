#include <iostream>
#include <utility>
#include <queue>
using namespace std;

int time = 0;
int sharkSize = 2;
pair<int, int> currentLocation;
int sizeUpStack = 0;
int n;
int fishMatrix[21][21];

void eating() {

    while(true){
        bool fishOn = true;
        int targetI = 0;
        int targetJ = 0;
        int targetDistance = 99999;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (fishMatrix[i][j] < sharkSize && fishMatrix[i][j] != 0 && fishMatrix[i][j] != 9) {
                    fishOn = false;
                    int plusI = (currentLocation.first > i) ? currentLocation.first-i:i-currentLocation.first;
                    int plusJ = (currentLocation.second > j) ? currentLocation.second-j:j-currentLocation.second;
                    int tmpDistance = plusI+plusJ;
                    if (targetDistance > tmpDistance) {
                        targetI = i;
                        targetJ = j;
                        targetDistance = tmpDistance;
                    }
                }
            }
        }
        if (fishOn) {
            return;
        }

        int visited[21][21] = {0, };
        queue<pair<int, int>> q;
        q.push(make_pair(currentLocation.first, currentLocation.second));
        visited[currentLocation.first][currentLocation.second] = 0;
        while (!q.empty()) {
            pair<int, int> cur = q.front();
            q.pop();
            //left
            if (cur.second - 1 >= 1 && visited[cur.first][cur.second - 1] == 0
                && fishMatrix[cur.first][cur.second - 1] <= sharkSize) {
                visited[cur.first][cur.second - 1] = visited[cur.first][cur.second] + 1;
                q.push(make_pair(cur.first, cur.second - 1));
            }
            //right
            if (cur.second + 1 <= n && visited[cur.first][cur.second + 1] == 0
                && fishMatrix[cur.first][cur.second + 1] <= sharkSize) {
                visited[cur.first][cur.second + 1] = visited[cur.first][cur.second] + 1;
                q.push(make_pair(cur.first, cur.second + 1));
            }
            //up
            if (cur.first - 1 >= 1 && visited[cur.first - 1][cur.second] == 0
                && fishMatrix[cur.first - 1][cur.second] <= sharkSize) {
                visited[cur.first - 1][cur.second] = visited[cur.first][cur.second] + 1;
                q.push(make_pair(cur.first - 1, cur.second));
            }
            //down
            if (cur.first + 1 <= n && visited[cur.first + 1][cur.second] == 0
                && fishMatrix[cur.first + 1][cur.second] <= sharkSize) {
                visited[cur.first + 1][cur.second] = visited[cur.first][cur.second] + 1;
                q.push(make_pair(cur.first + 1, cur.second));
            }
        }
        int addTime = visited[targetI][targetJ];
        fishMatrix[currentLocation.first][currentLocation.second] = 0;
        fishMatrix[targetI][targetJ] = 9;
        currentLocation.first = targetI;
        currentLocation.second = targetJ;
        time += addTime;
        sizeUpStack++;
        if (sizeUpStack == sharkSize) {
            sharkSize++;
            sizeUpStack = 0;
        }
        cout << "------------상태점검-------------" << endl;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                cout << fishMatrix[i][j] << " ";
            }
            cout << '\n';
        }
        cout << "---------------------------------" << endl;
    }

}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> fishMatrix[i][j];
			if (fishMatrix[i][j] == 9) {
				currentLocation.first = i;
				currentLocation.second = j;
			}
		}
	}
	eating();
	cout << time << endl;
	return 0;
}
