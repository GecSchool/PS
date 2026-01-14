class MinHeap {
    constructor(){
        this.heap = [];
    }

    getParentIndex(i) {
        return Math.floor((i - 1) / 2);
    }
    
    getLeftChildIndex(i) {
        return 2 * i + 1;
    }
    
    getRightChildIndex(i) {
        return 2 * i + 2;
    }

    swap(i, j) {
        [this.heap[i], this.heap[j]] = [this.heap[j], this.heap[i]];
    }
    
    insert(value) {
        this.heap.push(value);
        const index = this.size() - 1;
        this.heapifyup(index);
    }
    
    heapifyup(index){
        while(true) {
            if(index === 0) break;
            const parentIndex = this.getParentIndex(index);
            
            if(this.heap[index] < this.heap[parentIndex]){
                this.swap(index, parentIndex);
                index = parentIndex;
            } else break;
        }
    }
    
    extractMin() {
        const size = this.size() 
        
        if(size === 0) return -1;
        if (size === 1) return this.heap.pop();
        
        this.swap(0, size - 1);
        const min = this.heap.pop();
        this.heapifyDown();
        return min;
    }
    
    heapifyDown() {
        let index = 0;
        const size = this.size();
        
        while(true){
            const leftIndex = this.getLeftChildIndex(index);
            const rightIndex = this.getRightChildIndex(index);
            let minIndex = index;
            
            if (leftIndex < size && this.heap[minIndex] > this.heap[leftIndex]) minIndex = leftIndex;
            if (rightIndex < size && this.heap[minIndex] > this.heap[rightIndex]) minIndex = rightIndex;
           
            if (index !== minIndex && this.heap[index] > this.heap[minIndex]) {
                this.swap(index, minIndex);
                index = minIndex;
            } else {
                break;
            }
        }
    }
    
    peek() {
        const size = this.size();
        if(size === 0) return -1;

        return this.heap[0];
    }
    
    size() {
        return this.heap.length;
    }
}

function solution(scoville, K) {
    const heap = new MinHeap();
    let count = 0;
    for (const sco of scoville) {
        heap.insert(sco);
    } 
    
    while (true) {
        if (heap.peek() >= K) return count;
        if (heap.size() < 2) return -1;

        const firMin = heap.extractMin();
        const secMin = heap.extractMin();
        
        heap.insert(firMin + secMin * 2);
        count++;
    }
}


