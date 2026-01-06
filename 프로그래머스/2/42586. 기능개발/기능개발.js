function solution(progresses, speeds) {
    const days = progresses.map((p, i) => Math.ceil((100 - p) / speeds[i]));
    
    const answer = [];
    let maxDay = days[0];
    let count = 0;
    
    for (const day of days) {
        if (day > maxDay) {
            answer.push(count);
            maxDay = day;
            count = 1;
        } else {
            count++;
        }
    }
    answer.push(count);
    
    return answer;
}