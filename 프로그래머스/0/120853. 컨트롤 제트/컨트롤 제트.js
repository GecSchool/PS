function solution(s) {
    const arr = s.split(' ');
    return arr.reduce((acc, cur) => {
        if (cur !== 'Z') acc.push(cur)
        else acc.pop();
        
        return acc;
    },[]).map(Number)
        .reduce((sum, num) => sum + num, 0);
}