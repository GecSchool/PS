function solution(n, computers) {
    let counts = 0;
    const visited = Array.from({length: n}, () => false);
    function bfs(node) {
        visited[node] = true;
        
        for (let nei = 0; nei < n; nei++) {
            if(!visited[nei] && computers[node][nei] === 1){
                bfs(nei);
            }
        }
    }
    
    for (let i = 0; i < n; i++){
        if (!visited[i]){
            bfs(i);
            counts++;
        }
    }
    
    return counts;
}