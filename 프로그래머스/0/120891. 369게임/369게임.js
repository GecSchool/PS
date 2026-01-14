function solution(order) {
    return order.toString().split('').filter(a => [3, 6, 9].includes(+a)).length;
}