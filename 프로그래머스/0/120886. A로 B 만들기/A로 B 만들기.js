function solution(before, after) {
    const count = {};
    
    for (const char of before) count[char] = (count[char] || 0) + 1;
    
    for (const char of after) {
        if (!count[char]) return 0;
        count[char]--;
    }
    
    return Object.values(count).every(v => v === 0) ? 1 : 0;
}