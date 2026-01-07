function solution(prices) {
    const n = prices.length;
    const answer = Array(n).fill(0);
    const stack = []; // 인덱스 저장

    for (let i = 0; i < n; i++) {
        while (
            stack.length > 0 &&
            prices[stack[stack.length - 1]] > prices[i]
        ) {
            const j = stack.pop();
            answer[j] = i - j; // 떨어진 시점까지의 시간
        }

        stack.push(i);
    }

    while (stack.length > 0) {
        const j = stack.pop();
        answer[j] = n - 1 - j;
    }

    return answer;
}
