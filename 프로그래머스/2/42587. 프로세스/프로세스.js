function solution(priorities, location) {
    const queue = priorities.map((priority, index) => ({
      priority,
      index
    }));
    let count = 0;
    
    while (queue.length) {
        const current = queue.shift();

        if (queue.some(p => p.priority > current.priority)) {
            queue.push(current);
        } else {
            count++;
            if (location === current.index) break;
        }
    }
    
    return count;
}