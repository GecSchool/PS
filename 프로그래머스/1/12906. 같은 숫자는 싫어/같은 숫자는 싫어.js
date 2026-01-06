function solution(arr) {
    const answer = [];
    for (const ele of arr) {
        if (!answer.length || answer[answer.length - 1] !== ele) 
            answer.push(ele);
    }
    return answer;
}