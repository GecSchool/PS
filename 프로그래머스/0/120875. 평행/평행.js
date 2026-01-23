function solution(dots) {
    const getSlope = (p1, p2) => {
        return (p2[1] - p1[1]) / (p2[0] - p1[0]);
    };
    
    const [a, b, c, d] = dots;
    
    if (getSlope(a, b) === getSlope(c, d)) return 1;
    if (getSlope(a, c) === getSlope(b, d)) return 1;
    if (getSlope(a, d) === getSlope(b, c)) return 1;
    
    return 0;
}