function solution(board) {
    const n = board.length;
    
    const dangerZone = Array.from({ length: n }, () => Array(n).fill(0));
    const directions = [
        [-1, -1], [-1, 0], [-1, 1],
        [0, -1],           [0, 1],
        [1, -1], [1, 0],   [1, 1],
    ];
    
    for (let r = 0; r < n; r++) {
        for (let c = 0; c < n; c++) {
            if (board[r][c] === 1) {
                dangerZone[r][c] = 1;
                directions.forEach(([dr, dc]) => {
                    const nr = r + dr;
                    const nc = c + dc;
                    
                    if (nr >= 0 && nr < n && nc >= 0 && nc < n) {
                        dangerZone[nr][nc] = 1;
                    }
                })
            }
        }
    }
    
    let safeCount = 0;
    for (let r = 0; r < n; r++) {
        for (let c = 0; c < n; c++) {
            if (dangerZone[r][c] === 0) safeCount++;
        }
    }
    
    return safeCount;
}
