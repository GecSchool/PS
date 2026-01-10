// 방법 1
// function solution(price) {
//     if( price >= 500000){
//         price *= 0.8; 
//     } else if ( price >= 300000) {
//         price *= 0.9;
//     } else if (price >= 100000) {
//         price *= 0.95; 
//     }
//     return Math.trunc(price);
// }


// 방법 2
// 방법 1이 가독성이 너무 떯어져서, early return
// function solution(price) {
//     if ( price >= 500000 ) {
//         return Math.trunc(price * 0.8);
//     } else if ( price >= 300000 ) {
//         return Math.trunc(price * 0.9);
//     } else if ( price >= 100000 ){
//         return Math.trunc(price * 0.95);
//     }
//     return price;
// }

// 방법 3
// 방법 2에서 확장성 고려
function solution(price) {
    const discounts = [
        [500000, 0.20],
        [300000, 0.10],
        [100000, 0.05],
        [0, 0],
    ]
    
    for (const [threshold, discount] of discounts) {
        if (price >= threshold) return Math.trunc(price * (1 - discount));
    }
}

// 방법 4
// 가장 간단하게 해결하기
// function solution(price){
//     const rate = price >= 500000 ? 0.8 :
//                  price >= 300000 ? 0.9 :
//                  price >= 100000 ? 0.95 : 1;
    
//     return Math.trunc(price * rate);
// }