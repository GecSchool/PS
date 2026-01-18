function solution(keyinput, board) {
    const [maxX, maxY] = [(board[0] - 1) / 2, (board[1] - 1) / 2];
    let [x, y] = [0, 0];
    
    const direction = {
        'up': [0, 1],
        'down': [0, -1],
        'left': [-1 ,0],
        'right': [1, 0],
    }
    
    for (const key of keyinput) {
        const [dx, dy] = direction[key];
        const [newX, newY] = [x + dx, y + dy];
        
        if (Math.abs(newX) <= maxX && Math.abs(newY) <= maxY) {
            x = newX;
            y = newY;
        }
    }
    
    return [x, y];
}
