function solution(common) {
// 등비 등차 구분, 이후 마지막 값에 계산
    const [a, b, c] = common;
    
    if (b - a === c - b) return common[common.length - 1] + (b - a);
    return common[common.length - 1] * (b / a);
}  