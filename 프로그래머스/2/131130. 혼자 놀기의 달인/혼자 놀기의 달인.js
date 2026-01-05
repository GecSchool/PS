function solution(cards) {
    const n = cards.length;
    const visited = Array(n).fill(false);
    const cycles = [];
    
    for (let i = 0; i < n; i++) {
        if (visited[i]) continue;
        
        let count = 0;
        let curr = i;
        
        while (!visited[curr]) {
            visited[curr] = true;
            curr = cards[curr] - 1;  // 카드 번호는 1부터, 인덱스는 0부터
            count++;
        }
        
        cycles.push(count);
    }
    
    cycles.sort((a, b) => b - a);
    return cycles.length >= 2 ? cycles[0] * cycles[1] : 0;
}

// 결국 어떻게 사이클을 찾을까가 핵심 union find or 단순 사이클 체크
// 단순 방문 복잡도 O(n)
// 사이클 크기 내림차순 정렬