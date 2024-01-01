#include <iostream>

using namespace std;

const int maxn = 1e6 + 5;
int a[maxn], b[maxn];

void sort(int l, int r) {
    if ((r - l) <= 1)
        return;
    int mid = (l + r) / 2;
    sort(l, mid);
    sort(mid, r);
    int ptrr = mid, ptrl = l;
    for (int i = l; i < r; i++) {
        if (ptrr == r) {
            for (int j = ptrl; j < mid; j++) {
                b[i] = a[ptrl];
                ptrl++;
                i++;
            }
        } else if (ptrl == mid) {
            for (int j = ptrr; j < r; j++) {
                b[i] = a[ptrr];
                ptrr++;
                i++;
            }
        } else if (a[ptrl] < a[ptrr]) {
            b[i] = a[ptrl];
            ptrl++;
        } else {
            b[i] = a[ptrr];
            ptrr++;
        }
    }
    for (int j = l; j < r; j++)
        a[j] = b[j];
}

bool binery_serch(int l, int r, int data) {
    int mid = (l + r) / 2;
    while (l + 1 < r) {
        if (a[mid] == data)
            return 1;
        if (a[mid] < data) {
            l = mid;
        } else {
            r = mid;
        }
        mid = (l + r) / 2;

    }
    if (a[l] == data || a[r] == data)
        return 1;
    return 0;
}

bool div(int l, int r, int data) {
    if ((r - l) < 1)
        return 0;
    int mid = (l + r) / 2;
    bool x = div(l, mid-1 , data);
    bool y = div(mid + 1, r, data);
    bool m = binery_serch(l, mid - 1, data - a[mid]) | binery_serch(mid + 1, r, data - a[mid]);
    return m || x || y;
}

int main() {
    int c, data;
    cin >> c >> data;
    for (int i = 0; i < c; i++)
        cin >> a[i];
    sort(0, c);
    bool x = div(0, c-1, data);
    if (x)
        cout << "YES";
    else
        cout << "NO";
}