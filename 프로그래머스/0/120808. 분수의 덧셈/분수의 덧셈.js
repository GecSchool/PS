function solution(numer1, denom1, numer2, denom2) {
    const getGCD = (a, b) => b === 0 ? a : getGCD(b, a % b);
    let numer = numer1 * denom2 + numer2 * denom1;
    let denom = denom1 * denom2;
    const gcd = getGCD(numer, denom)
    
    return [numer / gcd, denom / gcd];
}