#include <iostream>
using namespace std;

#define M 1000000007

//? Memoization start--------------------------------------------------------------------

/* int balancedBTs_mem(int n, uint64_t* mem) {
    if (n <= 1)
        return 1;
    
    uint64_t x = (mem[n-1] != 0) ? mem[n-1] : balancedBTs_mem(n-1, mem);
    uint64_t y = (mem[n-2] != 0) ? mem[n-2] : balancedBTs_mem(n-2, mem);
    
    uint64_t temp1 = (x * x) % M;
    uint64_t temp2 = (2 * (x * y)) % M;
    uint64_t ans = (temp1 + temp2) % M;
    
    mem[n] = ans;
    return ans;
}

int balancedBTs(int n) {
    uint64_t* mem = new uint64_t[n+1];
    for (int i = 0; i < n; i++) {
        mem[i] = 0;
    }

    balancedBTs_mem(n, mem);

    return mem[n];
} */

//? Memoization ends-------------------------------------------------------------------

//? DP start***************************************************************************

int balancedBTs(int n) {
    uint64_t* dp = new uint64_t[n+1]{0};
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i < n+1; i++) {
        uint64_t x = dp[i-1];
        uint64_t y = dp[i-2];

        uint64_t temp1 = (x * x) % M;
        uint64_t temp2 = (2 * x * y) % M;
        uint64_t ans = (temp1 + temp2) % M;

        dp[i] = ans;
    }

    return dp[n];
}

//? DP ends***************************************************************************


int main() {
    int n;
    cin >> n;
    cout << balancedBTs(n);
}