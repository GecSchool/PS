function solution(numbers, target) {
    let answer = 0;
    const n = numbers.length;
    
    function dfs(index, curSum) {
        if (index === n) {
            if (curSum === target){
                answer++;
            }
            return ;
        }
        dfs(index + 1, curSum + numbers[index]);
        dfs(index + 1, curSum - numbers[index]);
    }
    
    dfs(0, 0);
    return answer;
}