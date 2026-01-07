function solution(s1, s2) {
    const set1 = new Set(s1);
    return s2.filter(item => set1.has(item)).length
}