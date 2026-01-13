function solution(emergency) {
    const sorted = [...emergency].sort((a, b)=> b - a);
    const map = new Map(sorted.map((value, idx) => [value, idx + 1]));
    return emergency.map(num => map.get(num));
}