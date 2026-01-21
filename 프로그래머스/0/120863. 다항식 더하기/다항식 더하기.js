function solution(polynomial) {
    const [xCount, numCount] = polynomial.split(' + ').reduce((acc, cur) => {
        if (cur.includes('x')) 
            acc[0] += Number(cur.replace('x','') || '1');
        else 
            acc[1] += Number(cur);
        return acc;
    },[0, 0]);
    
    const result = [];
    
    if (xCount > 0) result.push(xCount === 1 ? 'x' : `${xCount}x`);
    if (numCount > 0) result.push(numCount);
    
    return result.join(' + ');
}