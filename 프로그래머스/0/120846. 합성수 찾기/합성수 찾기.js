function solution(n) {
    let count = 0;
    
    for (let i = 4; i <= n; i++) {
        let divisors = 0;
        
        for (let j = 1; j * j <= i; j++){
            if (i % j === 0) {
                divisors += (j * j === i) ? 1 : 2;
                if (divisors >= 3) {
                    count++;
                    break;
                }
            }
        }
    }
    
    return count;
}