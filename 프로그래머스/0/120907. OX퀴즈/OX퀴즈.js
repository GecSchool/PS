function solution(quiz) {
    return quiz.map(equation => {
        const parts = equation.split(' ');
        
        const X = parseInt(parts[0]);
        const operator = parts[1];
        const Y = parseInt(parts[2]);
        const Z = parseInt(parts[4]);
        
        const result = operator === '+' ? X + Y : X - Y;
        
        return result === Z ? 'O' : 'X';
    });
}