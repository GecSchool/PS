function solution(numlist, n) {
    return numlist.sort((a, b) => {
        const aoffset = Math.abs(n - a);
        const boffset = Math.abs(n - b);
        
        if (aoffset !== boffset) return aoffset - boffset;
        
        return b - a;
    });
    
}