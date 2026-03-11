function solution(sizes) {
    const [maxWidth, maxHeight] = sizes.reduce(([maxW, maxH], [w, h]) => [
        Math.max(maxW, Math.max(w, h)),
        Math.max(maxH, Math.min(w, h))
    ], [0, 0]);
    
    return maxWidth * maxHeight;
}