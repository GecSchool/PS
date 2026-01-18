const STRING_NUM = ["zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"];

// function solution(numbers) {
//     let result = '';
//     for (let i = 0;i < numbers.length - 2; i++) {
//         for (let j = 3; j <= 5; j++) {
//             const word = numbers.slice(i, i + j);
//             if (STRING_NUM.includes(word)) {
//                 result += STRING_NUM.indexOf(word);
//                 i += j - 1;
//                 break;
//             }
//         }
//     }
//     return Number(result);
// }


function solution(numbers) {
    STRING_NUM.forEach((word, idx) => {
        numbers = numbers.replaceAll(word, idx);
    });
    
    return Number(numbers);
}