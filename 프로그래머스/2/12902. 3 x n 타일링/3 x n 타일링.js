function solution(n) {
    if (n % 2) return 0;
    
    const MOD = 1000000007;
    
    let prev2 = 1;  // dp[0]
    let prev1 = 3;  // dp[2]
    
    if (n === 0) return 1;
    if (n === 2) return 3;
    
    for (let i = 4; i <= n; i += 2) {
        let curr = ((4 * prev1 - prev2) % MOD + MOD) % MOD;
        prev2 = prev1;
        prev1 = curr;
    }
    
    return prev1;
}

// n = 0 -> 1
// n = 1 -> x
// n = 2 -> 3
// n = 3 -> x
// n = 4 -> 11
// n = 5 -> x
// n = 6 -> 33 + 2
// dp[n] = 3 * dp[n-2] + 2 * dp[n-4] + ... + 2 * dp[0]
// dp[n] = 4 * dp[n-2] - dp[n-4]