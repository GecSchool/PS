function solution(n) {
    const isIncludeThree = (n) => {
        return n % 3 === 0 || n.toString().includes('3')
    }
    let result = 0;
    let count = 0;
    
    while (count < n) {
        result++;
        
        if (isIncludeThree(result)) continue;
        
        count++;
    }
    return result;
}