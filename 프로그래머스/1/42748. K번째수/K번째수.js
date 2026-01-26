function solution(array, commands) {
    const result = [];
    
    for (let i = 0;i < commands.length; i++) {
        const [s, e, k] = commands[i];
        result[i] = array.slice(s - 1, e).sort((a, b) => a - b)[k - 1];
    }
    return result;
}
