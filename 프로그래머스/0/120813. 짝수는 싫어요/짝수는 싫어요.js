function solution(n) {
    const count = Math.ceil(n / 2);
    return Array.from({ length: count }, (_, i) => i * 2 + 1);
}