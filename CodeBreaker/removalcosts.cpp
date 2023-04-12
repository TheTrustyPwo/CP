#include <algorithm>
#include <iostream>

const int MOD = 998244353;

int min_cost(const std::vector<int>& permutation) {
    int cost = 0;
    for (int i = 0; i < permutation.size(); i++) {
        cost += std::abs(permutation[i] - (i + 1));
    }
    return cost;
}

int solve(int n, const std::vector<int>& permutation) {
    // Fill in missing elements with all possible values
    std::vector<int> filled_permutation = permutation;
    int missing = std::count(filled_permutation.begin(), filled_permutation.end(), -1);
    for (int i = 0; i < n; i++) {
        if (filled_permutation[i] == -1) {
            filled_permutation[i] = n - missing + 1;
            missing--;
        }
    }
    // Find the minimum cost for each filled permutation
    int sum = 0;
    do {
        sum += min_cost(filled_permutation);
        sum %= MOD;
    } while (std::next_permutation(filled_permutation.begin(), filled_permutation.end()));
    // Return the sum of the minimum costs modulo MOD
    return sum;
}

int main() {
    // Test the solve function
    std::cout << solve(3, {3, -1, 2}) << std::endl;
    std::cout << solve(5, {2, 3, -1, 4, -1}) << std::endl;
    std::cout << solve(15, {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}) << std::endl;
    return 0;
}
