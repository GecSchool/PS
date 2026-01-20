function solution(score) {
    const averages = score
        .map(([e, m]) => (e + m) / 2);
        
    
    return averages.map(avg => {
        return averages.filter(otherAvg => otherAvg > avg).length + 1;
    });
}