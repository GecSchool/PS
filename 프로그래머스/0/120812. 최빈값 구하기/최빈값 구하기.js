function solution(array) {
    const freq = new Map();
    
    for(const ele of array) {
        freq.set(ele, (freq.get(ele) || 0) + 1);
    }
    
    const maxCount = Math.max(...freq.values());
    const modes = [...freq].filter(([_, count]) => count === maxCount);
    
    return modes.length > 1 ? -1 : modes[0][0];
}