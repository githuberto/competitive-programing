// http://codeforces.com/problemset/problem/520/B

#include <iostream>
#include <vector>
#include <queue>

#define LIMIT 10000
#define INF 999999

using namespace std;
using vi = vector<int>;

int main(){
    int n, m;
    cin >> n >> m;


    int guard = -1;
    queue<int> q;
    q.push(n);
    q.push(guard);

    vector<bool> visited(2*LIMIT + 1, 0);

    bool found = false;

    int length = 0;

    while(!found){
        int c = q.front();
        q.pop();

        if(c == guard){
            q.push(guard);
            length++;
        }
        else if(c == m){
            cout << length << endl;
            found = true;
        }
        else{
            if(c > 1 && !visited[c-1]){
                visited[c-1] = true;
                q.push(c-1);
            }
            if(2 * c <= 2 * m && !visited[2*c]){
                q.push(2 * c); 
                visited[2 * c] = true;
            }
        }
    }


    return 0;
}

