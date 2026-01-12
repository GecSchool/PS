function solution(rsp) {
    return [...rsp].reduce((acc, cur)=> {
        return acc += cur === '0' ? '5' : cur === '2' ? '0' : '2';
    }, '');
}