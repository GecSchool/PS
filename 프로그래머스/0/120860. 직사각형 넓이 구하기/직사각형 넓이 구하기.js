function solution(dots) {
    dots.sort(([x1, y1], [x2 ,y2]) => {
        if (x1 !== x2) return x1 - x2;
        return y1 - y2;
    });
    
    return (dots[3][0] - dots[0][0]) * (dots[3][1] -dots[0][1]); 
}