function solution(my_string) {
    return [...my_string].reduce((acc, cur)=> 
         acc + ((cur <= '9' && cur >= '1') ? +cur : 0) 
     ,0);
}