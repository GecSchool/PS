function solution(my_string) {
    const set = new Set();
    return my_string.split('').reduce((acc, cur)=> {
        if(!set.has(cur)){ 
            set.add(cur);
            return acc + cur
        }
        else return acc;
    }, '');
}