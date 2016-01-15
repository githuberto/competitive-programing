// http://codeforces.com/problemset/problem/60/B

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct point{
    int x, y, z;

    point(int x, int y, int z) : x(x), y(y), z(z){
    }
};

int main(){
    int k, n, m;
    cin >> k >> n >> m;

    vector<vector<vector<char> > > grid(n, vector<vector<char> >(m, vector<char>(k)));
    vector<vector<vector<bool> > > visited(n, vector<vector<bool> >(m, vector<bool>(k, false)));

    for(int i = 0; i < k; i++){
        for(int r = 0; r < n; r++){
            for(int c = 0; c < m; c++){
                cin >> grid[r][c][i];
            }
        }
    }

    int sx, sy;
    cin >> sx >> sy;
    sx--;
    sy--;

    queue<point> q;
    q.push({sx, sy, 0});
    visited[sx][sy][0] = true;

    int vol = 0;

    int dx[] = {-1, 1, 0, 0, 0, 0};
    int dy[] = {0, 0, -1, 1, 0, 0};
    int dz[] = {0, 0, 0, 0, -1, 1};

    while(!q.empty()){
        point p = q.front();
        q.pop();


        vol++;

        for(int i = 0; i < 6; i++){
            int x = p.x + dx[i];
            int y = p.y + dy[i];
            int z = p.z + dz[i];

            if(x >= 0 && x < n && y >= 0 && y < m && z >= 0 && z < k
                    && grid[x][y][z] == '.'
                    && !visited[x][y][z]){
                q.push({x, y, z});
                visited[x][y][z] = true;
            }
        }
    }

    cout << vol << endl;


    return 0;
}
