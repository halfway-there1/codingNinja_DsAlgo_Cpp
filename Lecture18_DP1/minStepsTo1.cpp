#include <iostream>
using namespace std;
#include <algorithm>
#include <climits>
#include <vector>

int countStepsTo1(int n) {
    if (n == 1) {
        return 0;
    }

    int option1 = countStepsTo1(n - 1);
    // we can also use option1 instead of INT_MAX as as a fallback value
    // value because option1 is always a valid operation
    int option2 = (n % 2 == 0) ? countStepsTo1(n / 2) : INT_MAX;
    int option3 = (n % 3 == 0) ? countStepsTo1(n / 3) : INT_MAX;

    return min({option1, option2, option3}) + 1;
}

// -----------------------------------------------------------------------

int countStepsTo1_DP(int n) {
    vector<int> dp(n + 1, 0);

    for (int i = 2; i < n + 1; i++) {
        int option1 = dp[i - 1];
        int option2 = (i % 2 == 0) ? dp[i / 2] : option1;
        int option3 = (i % 3 == 0) ? dp[i / 3] : option1;
        dp[i] = min({option1, option2, option3}) + 1;
    }

    return dp[n];
}

int main() {
    int n;
    cin >> n;
    cout << countStepsTo1(n) << " " << countStepsTo1_DP(n) << endl;
    return 0;
}