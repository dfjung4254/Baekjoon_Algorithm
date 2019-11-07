#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
string db[100][100] = {"", };
pair<string, int> questions[100];
int main(){

    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> db[i][0];
        int num;
        cin >> num;
        for(int j = 1; j <= num; j++){
            cin >> db[i][j];
        }
        sort(db[i]+1, db[i]+num+1);
    }
    for(int i = 0; i < m; i++){
        cin >> questions[i].first >> questions[i].second;
    }
    //
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; db[i][j] != ""; j++){
    //         cout << db[i][j] << " ";
    //     }
    //     cout << '\n';
    // }
    //
    for(int i = 0; i < m; i++){
        if(questions[i].second == 1){
            for(int a = 0; a < n; a++){
                for(int b = 1; db[a][b] != ""; b++){
                    if(db[a][b].compare(questions[i].first) == 0){
                        cout << db[a][0] << '\n';
                    }
                }
            }
        }else{
            for(int a = 0; a < n; a++){
                if(db[a][0].compare(questions[i].first) == 0){
                    for(int b = 1; db[a][b] != ""; b++){
                        cout << db[a][b] << '\n';
                    }
                }
            }
        }
    }
    return 0;
}
