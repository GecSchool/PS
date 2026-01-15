function solution(my_string) {
    return my_string
        .split(/[a-zA-Z]/)
        .filter(num => num !== '')
        .reduce((sum, num) => sum + Number(num), 0);
    
}