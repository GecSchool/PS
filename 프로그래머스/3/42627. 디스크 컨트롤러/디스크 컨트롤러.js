class PriorityQueue {
    constructor() {
        this.heap = []; // [들어온 시간, 소요시간, 프로세스 번호]
    }

    deQ() {
        const size = this.size();

        if (size === 0) return -1;
        if (size === 1) return this.heap.pop();

        this.swap(0, size - 1);
        const ele = this.heap.pop();
        this.downInf();

        return ele;
    }

    enQ(value) {
        this.heap.push(value);
        this.upInf();
    }

    downInf() {
        let index = 0;
        const size = this.size();
        while (true) {
            const leftIndex = this.getLeftChildIndex(index);
            const rightIndex = this.getRightChildIndex(index);

            let minIndex = index;
            if (
                leftIndex < size &&
                this.compare(this.heap[leftIndex], this.heap[minIndex]) < 0
            )
                minIndex = leftIndex;
            if (
                rightIndex < size &&
                this.compare(this.heap[rightIndex], this.heap[minIndex]) < 0
            )
                minIndex = rightIndex;

            if (index !== minIndex) {
                this.swap(index, minIndex);
                index = minIndex;
            } else break;
        }
    }

    upInf() {
        let index = this.size() - 1;
        while (true) {
            if (index === 0) break;
            const parentIndex = this.getParentIndex(index);
            if (this.compare(this.heap[index], this.heap[parentIndex]) < 0) {
                this.swap(index, parentIndex);
                index = parentIndex;
            } else break;
        }
    }

    getParentIndex(index) {
        return Math.floor((index - 1) / 2);
    }

    getLeftChildIndex(index) {
        return index * 2 + 1;
    }

    getRightChildIndex(index) {
        return index * 2 + 2;
    }

    swap(a, b) {
        [this.heap[a], this.heap[b]] = [this.heap[b], this.heap[a]];
    }

    size() {
        return this.heap.length;
    }

    compare(a, b) {
        // 음수 a가 높은, 양수 b가 높음
        return a[1] - b[1] || a[0] - b[0] || a[2] - b[2];
    }
}

function solution(jobs) {
    const jobsWithIndex = jobs
        .map((job, idx) => [job[0], job[1], idx])
        .sort((a, b) => a[0] - b[0]);

    const que = new PriorityQueue();

    let totalTime = 0;
    let curTime = jobsWithIndex[0][0];

    while (jobsWithIndex.length || que.size()) {
        // 둘 다 비었을 때
        // 시간 지내면서 삽입
        let index = 0;
        for (const job of jobsWithIndex) {
            if (job[0] <= curTime) {
                que.enQ(job);
                index++;
            } else {
                break;
            }
        }
        jobsWithIndex.splice(0, index);

        // 힙이 비어있다 () -> 시간 점프 jobs에 현재 시각으로
        if (que.size() === 0) {
            curTime = jobsWithIndex[0][0];
            continue;
        }
        // 우선순위 높은거 빼기
        const [requestTime, duration] = que.deQ();
        // 시간 점프 및 토탈 타임 더하기
        curTime += duration;
        totalTime += curTime - requestTime;
    }
    // return 평균값
    return Math.floor(totalTime / jobs.length);
}