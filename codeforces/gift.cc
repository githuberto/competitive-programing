// http://codeforces.com/problemset/problem/505/A

#include <iostream>
#include <vector>
#include <string>

using namespace std;
using vi = vector<int>;

bool is_palindrome(string& w){
    for(int i = 0; i < w.size() / 2; i++){
        if(w[i] != w[w.size() - 1 - i]){
            return false;
        }
    }
    return true;
}

int opposite_idx(int idx, int size){
    int mid = size / 2;

    if(idx == mid){
        return idx;
    }

    if(idx < mid){
        return size - idx;
    }
    else{ // idx > mid
        return size - idx - 1;
    }
}

void print_palindrome(int idx, string& w){
    //int opp_idx = w.size() - idx;
    int opp_idx = opposite_idx(idx, w.size());

    int j = 0;
    for(int i = 0; i < w.size() + 1; i++){
        if(i == opp_idx){
            cout << w[idx];
        }
        else{
            cout << w[j];
            j++;
        }
    }
    cout << endl;
}


int main(){
    string w;
    cin >> w;

    bool found = false;
    for(int i = 0; i < w.size(); i++){
        string candidate = w.substr(0, i) + w.substr(i+1, w.size() - i);

        if(is_palindrome(candidate)){
            print_palindrome(i, w);
            found = true;
            break;
        }
    }

    if(w == ""){
        cout << "a" << endl;
    }
    else if(!found){
        cout << "NA" << endl;
    }


    return 0;
}

