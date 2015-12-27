#include <iostream>
#include <vector>

using namespace std;

using vi = vector<int>;

int sum(int i, vi& bit){
    i += 1;

    int sum = 0;
    while(i > 0){
        sum += bit[i];
        i -= i & -i;
    }
    return sum;
}

void update(int i, int v, vi& bit){
    i += 1;

    while(i < bit.size()){
        cout << i << endl;
        bit[i] += v;
        i += i & -i;
    }
}

vi make_bit(vi& a){
    vi bit(a.size() + 1);
    for(int i = 0; i < a.size(); i++){
        update(i, a[i], bit);
    }
    return bit;
}

int main(){
    vi a = {1, 2, 3, 4, 5, 6, 7};

    vi bit = make_bit(a);
    for(int i : bit){
        cout << i << ", ";
    }
    cout << endl;
    cout << endl;

    cout << sum(6, bit) << endl;
    update(0, 10, bit);
    cout << sum(6, bit) << endl;
    cout << sum(0, bit) << endl;

    a = {1, 2};
    bit = make_bit(a);

    cout << sum(0, bit) << endl;

    return 0;
}


