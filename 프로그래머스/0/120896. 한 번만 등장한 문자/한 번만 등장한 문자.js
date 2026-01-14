function solution(s) {
    const count = {};
    
    for (const char of s){
        count[char] = (count[char] || 0) + 1;
    }
    
    return Object.keys(count)
        .filter(char => count[char] === 1)
        .sort()
        .join('');
}