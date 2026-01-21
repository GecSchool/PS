function solution(num, total) {
    const start = Math.ceil(total / num - (num - 1) / 2);
    
    return Array.from({ length: num}, (_, i) => start + i);
}