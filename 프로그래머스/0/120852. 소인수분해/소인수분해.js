function solution(n) {
    const result = [];
    
    if (n % 2 === 0) {
        result.push(2);
        while (n % 2 === 0) {
            n /= 2;
        }
    }
    
    for (let i = 3; i <= n; i += 2) {
        if (n % i === 0) {
            result.push(i);
            while (n % i === 0) {
                n = n / i;
            }
        }
    }
    
    return result;
}