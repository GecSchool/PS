function solution(a, b) {
    const getGcd = (a, b) => (b === 0) ? a : getGcd(b ,a % b);
    let num = b / getGcd(a, b);
    while(num % 2 === 0) num /= 2;
    while(num % 5 === 0) num /= 5;
    
    return num === 1 ? 1 : 2;
}