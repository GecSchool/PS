function solution(clothes) {
    const map = new Map();
    
    for (const [cloth, category] of clothes) {
        map.set(category, [...(map.get(category) || []),cloth]);
    }

    let count = [...map].reduce((acc, [_, cloths]) => (cloths.length + 1) * acc , 1) - 1;
    return count;
}