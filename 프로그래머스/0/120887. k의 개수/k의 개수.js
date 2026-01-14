function solution(i, j, k) {
    return Array.from({length: j - i + 1}, (_, idx) => i + idx)
        .join('')
        .split(k)
        .length - 1;
}