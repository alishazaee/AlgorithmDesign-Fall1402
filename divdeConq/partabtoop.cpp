#include <iostream>

using namespace std;

const int maxn = 1e6 + 5;

void ans(int n, int count, int &anss) {
    if (n == 0)
        return;
    n--;
    if (count % 2 == 1) {
        anss *= 2;
        return ans(n, count / 2 + 1, anss);
    } else {
        anss = anss * 2 + 1;
        return ans(n, count / 2, anss);
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, r, anss = 1;
        cin >> n >> r;
        ans(n, r, anss);
        cout << anss/2<<endl;
    }
    cin>>t;
}