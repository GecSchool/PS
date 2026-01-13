function solution(array) {
    let max = array[0];
    let maxIndex = 0;
    
    for (let i = 1;i < array.length; i++){
        if (array[i] > max) {
            max = array[i];
            maxIndex = i;
        }
    }
    return [max, maxIndex];
}