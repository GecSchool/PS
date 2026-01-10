function solution(array, n) {
    return array.reduce((acc, cur)=> acc + +(cur===n), 0);
}