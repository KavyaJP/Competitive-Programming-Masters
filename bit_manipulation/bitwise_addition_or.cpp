#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

// Fast exponentiation
int power(int base, int exp)
{
    int result = 1;
    base %= MOD;
    while (exp > 0)
    {
        if (exp & 1)
            result = (result * base) % MOD;
        base = (base * base) % MOD;
        exp >>= 1;
    }
    return result;
}

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        long long N;
        cin >> N;

        // Count set bits
        int k = __builtin_popcountll(N);

        int p3 = power(3, k);
        int p2 = power(2, k);

        int ans = (p3 - (3 * p2) % MOD + 3) % MOD;

        if (ans < 0)
            ans += MOD;

        cout << ans << '\n';
    }

    return 0;
}