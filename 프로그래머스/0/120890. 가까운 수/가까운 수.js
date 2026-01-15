function solution(array, n) {
    return array
        .sort((a, b) => a - b)
        .reduce((closest, num) => {
        return Math.abs(n - num) < Math.abs(n - closest) ? num : closest;
    });
}