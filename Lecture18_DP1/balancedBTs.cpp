#include <iostream>
using namespace std;

#define M 1000000007

/* int balancedBTs(int n) {
    if (n <= 1)
        return 1;
    
    int ans1 = balancedBTs(n-1) * balancedBTs(n-1) + balancedBTs(n-2) * balancedBTs(n-1) + balancedBTs(n-1) * balancedBTs(n-2);

    return ans1;
} */

int balancedBTs(int n) {
    if (n <= 1)
        return 1;
    
    long long int x = balancedBTs(n-1);
    long long int y = balancedBTs(n-2);
    
    long long int temp1 = (x * x) % M;
    long long int temp2 = (2 * (x * y)) % M;
    long long int ans = (temp1 + temp2) % M;
    
    return ans;
}

int main() {
    int n;
    cin >> n;
    cout << balancedBTs(n);
}