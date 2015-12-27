// http://codeforces.com/problemset/problem/405/A

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using vi = vector<int>;

int main(){
    int n;
    cin >> n;

    vi v(n);

    for(int i = 0; i < n; i++){
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    for(int i = 0; i < v.size() - 1; i++){
        cout << v[i] << " ";
    }

    cout << v[v.size() - 1] << endl;

    return 0;
}

