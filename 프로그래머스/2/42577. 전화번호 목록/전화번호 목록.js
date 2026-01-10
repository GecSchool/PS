function solution(phone_book) {
    const map = new Map();
    for (const number of phone_book) {
        map.set(number, true);
    }
    
    for (const number of phone_book) {
        for (let i = 1; i < number.length; i++) {
            const prefix = number.substring(0, i);
            
            if (map.has(prefix))
                return false;
        }
    }
    
    return true;
}