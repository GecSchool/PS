function solution(X, Y) {
    const countX = Array(10).fill(0);
    const countY = Array(10).fill(0);
    
    for (const c of X) countX[c]++;
    for (const c of Y) countY[c]++;
    
    let result = ''
    for (let i = 9;i >= 0 ; i--){
        const common = Math.min(countX[i], countY[i]);
        result += String(i).repeat(common);
    }
    
    if(!result) return '-1';
    if (result[0] === '0') return '0';  // 전부 0인 경우
    return result;
}