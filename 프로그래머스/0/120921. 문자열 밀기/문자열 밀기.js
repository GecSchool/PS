function solution(A, B) {
    return (B + B).indexOf(A);
}

// function solution(A, B) {
//     const ele = [...A];
    
//     for (let i = 0;i < B.length; i++) {
//         if (ele.join('') === B) return i;
//         ele.unshift(ele.pop());
//     }
    
//     return -1;
// }