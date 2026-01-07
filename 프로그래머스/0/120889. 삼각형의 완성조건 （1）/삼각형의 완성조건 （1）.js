function solution(sides) {
    const [longest, second, third] = sides.sort((a, b) => b - a);
    return longest < second + third ? 1 : 2;
}