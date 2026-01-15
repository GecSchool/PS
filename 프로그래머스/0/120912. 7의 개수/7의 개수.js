// function solution(array) {
//     return array.reduce((count, num) => count + num.toString().split('7').length - 1, 0);
// }


function solution(array) {
    return array.join('').match(/7/g)?.length || 0;
}