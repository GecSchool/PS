function solution(chicken) {
    let total_chicken = 0;
    while (chicken >= 10) {
        const service_chicken = Math.floor(chicken / 10);
        total_chicken += service_chicken;
        chicken = service_chicken + chicken % 10;
    }
    
    return total_chicken;
}