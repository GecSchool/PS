function solution(sides) {
    let [num1, num2] = sides.sort((a, b) => a - b);
    
    return 2 * num1 - 1; 
}