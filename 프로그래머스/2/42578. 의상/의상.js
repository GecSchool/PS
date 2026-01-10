function solution(clothes) {
    const map = new Map();
    
    for (const [_, category] of clothes) {
        map.set(category, (map.get(category) || 0) + 1);
    }

    let answer = 1;
    for (const count of map.values()){
        answer *= (count + 1);
    }
    
    return answer - 1;
}