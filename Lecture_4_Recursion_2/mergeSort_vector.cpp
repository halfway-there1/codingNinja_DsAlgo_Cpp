#include "bits\stdc++.h"
using namespace std;
#define NO_MORE_BITS_AND_STD
#include <anurag_defines.h>
#include <debugging.h>

void merge_sorted_segments(vi &v, int si, int mid, int ei) {
    vi lhs(v.begin() + si, v.begin() + mid + 1);
    vi rhs(v.begin() + mid + 1, v.begin() + ei + 1);

    int i = 0, n1 = lhs.size();
    int j = 0, n2 = rhs.size();
    int k = si;

    while (i < n1 && j < n2) {
        if (lhs[i] <= rhs[j])
            v[k++] = lhs[i++];
        else
            v[k++] = rhs[j++];
    }

    while (i < n1) {
        v[k++] = lhs[i++];
    }

    while (j < n2) {
        v[k++] = rhs[j++];
    }
}

void merge_sort(vi &v, int si, int ei) {
    if (si >= ei)
        return;

    int mid = si + (ei - si) / 2;
    merge_sort(v, si, mid);
    merge_sort(v, mid + 1, ei);

    // the segments being v[si...mid] and v[mid+1...ei]
    merge_sorted_segments(v, si, mid, ei);
}

void solve() {
    int n;
    cin >> n;
    vi v(n);
    for (int &num : v)
        cin >> num;

    debug(v);
    merge_sort(v, 0, n - 1);

    for (auto num : v)
        cout << num << " ";
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