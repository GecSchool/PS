function solution(n) {
    const gcd = (a,b)=> (b === 0) ? a : gcd(b, a % b);
    const lcm = (6 * n) / gcd(6, n);
    return lcm / 6;
}