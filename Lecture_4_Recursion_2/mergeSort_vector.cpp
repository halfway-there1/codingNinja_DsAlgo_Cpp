#include "bits\stdc++.h"
using namespace std;
#define NO_MORE_BITS_AND_STD
#include <anurag_defines.h>
#include <debugging.h>

void mergeSort(vector<int> &v, int si, int ei) {
    if (si >= ei)
        return;

    int m = si + (ei - si) / 2;
    mergeSort(v, si, m);
    mergeSort(v, m + 1, ei);

    // lhs = v[si...m]
    vector<int> lhs(v.begin() + si, v.begin() + m + 1);
    // rhs = v[m+1...ei]
    vector<int> rhs(v.begin() + m + 1, v.begin() + ei + 1);

    merge(all(lhs), all(rhs), v.begin() + si);
}

void solve() {
    int m;
    cin >> m;

    vector<int> a(m);
    for (auto &ai : a)
        cin >> ai;

    mergeSort(a, 0, m - 1);

    for (auto ai : a)
        cout << ai << " ";
    cout << endl;
}

int32_t main() {
#ifndef ONLINE_JUDGE
    // freopen("error.txt", "w", stderr);
#endif

#if !defined(VSCODE_DEBUG)
    fastio();
#endif

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}