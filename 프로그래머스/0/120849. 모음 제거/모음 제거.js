function solution(my_string) {
    const vowel = ['a', 'e', 'i', 'o', 'u'];
    return [...my_string].reduce((acc, cur) => 
        acc + (vowel.includes(cur) ? '' : cur)
        ,'');
}