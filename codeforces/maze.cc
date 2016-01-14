// http://codeforces.com/problemset/problem/377/A

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using vi = vector<int>;
using pii = pair<int, int>;

int main(){
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<char> > grid(n, vector<char>(m));

    vector<vector<bool> > visited(n, vector<bool>(m, false));

    int sX, sY;
    int spaces = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
            if(grid[i][j] == '.'){
                spaces++;
                sX = i;
                sY = j;
            }
        }
    }

    queue<pii> q;

    q.push({sX, sY});


    int dx[] = {0, 0, -1, 1};
    int dy[] = {-1, 1, 0, 0};

    int moves = spaces - k;

    while(moves){
        pii p = q.front();
        q.pop();

        grid[p.first][p.second] = '!';

        for(int i = 0; i < 4; i++){
            int x = p.first + dx[i];
            int y = p.second + dy[i];
            if(x >= 0 && x < n && y >=0 && y < m && !visited[x][y] && grid[x][y] == '.'){
                visited[x][y] = true;
                q.push({x, y});
            }
        }
        moves--;
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            char c = grid[i][j];
            if(c == '!'){
                cout << '.';
            }
            else if(c == '.'){
                cout << 'X';
            }
            else{
                cout << c;
            }
        }
        cout << endl;
    }



    return 0;
}
