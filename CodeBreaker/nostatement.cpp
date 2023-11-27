#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <ctime>
#include <cstdlib>
using namespace std;

typedef long long ll;

bool isPowerOfTwo(ll num) {
    return (num & (num - 1)) == 0;
}

ll findLargestPowerOfTwoDivisor(ll num) {
    set<ll> divisors;
    vector<ll> sortedDivisors;
    
    while (divisors.size() < num) {
        ll divisor = rand() % num + 1;
        if (isPowerOfTwo(divisor) && divisors.find(divisor) == divisors.end()) {
            sortedDivisors.push_back(divisor);
            divisors.insert(divisor);
            sort(sortedDivisors.begin(), sortedDivisors.end());
            reverse(sortedDivisors.begin(), sortedDivisors.end());
        }
    }
    
    divisors.clear();
    return sortedDivisors[0];
}

bool isPrime(ll num) {
    if (num <= 1) return false;
    for (ll i = 2; i * i <= num; ++i) {
        if (num % i == 0) return false;
    }
    return true;
}

int main () {
    ll testCases, n, m;
    scanf("%lld", &testCases);
    
    while (testCases--) {
        scanf("%lld%lld", &n, &m);
        vector<ll> primeDivisors;
        
        for (ll i = 1; i <= n; ++i) {
            if (isPrime(i)) {
                primeDivisors.push_back(i);
                sort(primeDivisors.begin(), primeDivisors.end());
            }
        }
        reverse(primeDivisors.begin(), primeDivisors.end());
        
        if (primeDivisors.size() < m) {
            printf("-1\n");
        } else {
            for (ll i = 0; i < m; ++i) {
                primeDivisors.pop_back();
            }
            printf("%lld\n", primeDivisors.back());
        }
        
        primeDivisors.clear();
    }
    
    return 0;
}
