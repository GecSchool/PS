function solution(num, k) {
    return (Number(String(num).split('').indexOf(String(k))) + 1) || -1;
}