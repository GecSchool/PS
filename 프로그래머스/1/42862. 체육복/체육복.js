function solution(n, lost, reserve) {
    let ar = reserve
        .filter(r => !lost.includes(r))
        .sort((a, b) => a - b);
    
    let al = lost
        .filter(l => !reserve.includes(l))
        .sort((a, b) => a - b);
    
    ar.forEach(r => {
        let lTF = al.indexOf(r - 1);
        if (lTF !== -1){
            // 앞애 도난
            al.splice(lTF, 1);
        } else {
            let lTB = al.indexOf(r + 1);
            if (lTB !== -1) {
                al.splice(lTB, 1);
            }
        }
    });
    
    return n - al.length;
}