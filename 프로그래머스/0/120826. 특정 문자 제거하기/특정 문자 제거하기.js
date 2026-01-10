function solution(my_string, letter) {
    return [...my_string].reduce((acc, cur)=> acc + (cur === letter ? '' : cur),'');
}