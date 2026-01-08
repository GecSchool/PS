function solution(k, num, links) {
    // 루트 노드 찾기
    const root = findRootNode(links);    
    // setting bi search scope
    
    let left = Math.max(...num);// 최소 1?  
    let right = num.reduce((a, b) => a + b)// 최대 다 더한 값
    // bi search 
    // mid가 limit일 때, 필요한 최소 그룹 수에 따라 재귀
    
    while ( left < right ) {
        const mid = Math.floor((left + right) / 2)
        
        // 그룹 갯수 찾기 함수 작동
        const groupCount = countMinGroups(root, mid, num, links);
        
        if (groupCount <= k) {
            // 그룹수가 작거나 같을 때 -> 리밋 늘리기
            right = mid;
        } else {
            // 그룹수가 클 때 -> 리밋 줄이기
            left = mid + 1;
        }
    }
    
    return left;
}

// 결국 최대값에 따라서 최선에 선택을 할 떄 그룹 수가 달라지는 구조
// 이떄 최대값을 변경하면서, 그룹 개수 확인 했을 떄 k인 경우 중 최댓값 구하기
// 최대값은 bisearch, 이진 트리이기 때문에 재귀로 해결 가능성 농후, 그룹 분할 dp, 
// 그리디 맞음. 큰 쪽을 자르는게 항상 최선으로 생각


const findRootNode = (links) => {
    const hasParent = new Set();
    
    // set으로 링크 돌면서, 왼쪽 오른쪽에 존재 시 삽입
    for (const [left, right] of links) {
        if (left !== -1) hasParent.add(left);
        if (right !== -1) hasParent.add(right);
    }
    
    // 이떄 자식으로 등장 x -> 루트
    for (let i = 0;i < links.length; i++) {
        if (!hasParent.has(i)) return i;
    }
}

// const countMinGroups = (root, limit, num, links) => {
//     let groupCount = 1; // 루트 그룹
    
//     // 결국 노드 돌아가면서, 왼쪽, 오른쪽 자를지 말지 결정 
//     // 리밋 보다 작다, 크다, 같다.
//     // 크다 -> 무조건 자르기 왼쪽 오른쪽
//     // 작다, 같다 -> 유지
//     const dfs = (nodeIdx) => {
//         if(nodeIdx === -1) return 0;
        
//         const [leftChild, rightChild] = links[nodeIdx];
        
//         const leftSum = dfs(leftChild);
//         const rightSum = dfs(rightChild);
        
//         const currentValue = num[nodeIdx];
        
//         const total = currentValue + leftSum + rightSum;
        
//         if (total <= limit) return total;
        
//         // 음 왼쪽 오른쪽 어떻게 할까 고민중 -> 큰거 먼저 자르는게 맞다. why? 부모에서 그시기 하는게 맞음
//         if (leftSum >= rightSum) {
//             // left 자르기
//             groupCount++;
//             const withoutLeft = currentValue + rightSum;
            
//             if (withoutLeft <= limit) {
//                 return withoutLeft;
//             }
            
//             // right 자르기
//             groupCount++;
//             return currentValue;
//         } else {
//             groupCount++;
//             const withoutRight = currentValue + leftSum;
            
//             if (withoutRight <= limit) {
//                 return withoutRight;
//             }
            
//             groupCount++;
//             return currentValue;
//         }
//     }
    
//     dfs(root)
//     return groupCount;
// }


// 음 런타임 나는데, 가능성은 콜스택이 너무 깊게 들어가는 문제일거로 예상중. 이를 해결하기 위해 배열로 반복문 구현하는게 맞을 듯.
// 후위 순회로 스택에 넣고, 방문 유무 갖는 배열로 넣은다음, 그 뒤에 스택에서 하나씩 꺼내면서 반복문 실행.

const countMinGroups = (root, limit, num, links) => {
    const postOrder = [];
    const stack = [[root, false]];
    
    
    while (stack.length > 0) {
        const [node, visited] = stack.pop();
        
        if (node === -1) continue;
        
        if (visited) {
            postOrder.push(node);
        } else {
            // 현재 노드 방문 처리
            stack.push([node, true]);
            
            // 오른쪽 먼저 스택에 넣기 (나중에 처리위함)
            const [leftChild, rightChild] = links[node];
            if (rightChild !== -1) stack.push([rightChild, false]);
            // 왼쪽 나중에 스택에 넣기 (먼저 처리)
            if (leftChild !== -1) stack.push([leftChild, false]);
        }
    }
    
    let groupCount = 1; // 루트 그룹
    const sums = new Array(num.length).fill(0); // dense 유지
    // 결국 노드 돌아가면서, 왼쪽, 오른쪽 자를지 말지 결정 
    // 리밋 보다 작다, 크다, 같다.
    // 크다 -> 무조건 자르기 왼쪽 오른쪽
    // 작다, 같다 -> 유지
    
    for (const nodeIdx of postOrder) {
        const [leftChild, rightChild] = links[nodeIdx];
        
        const leftSum = leftChild === -1 ? 0 : sums[leftChild];
        const rightSum = rightChild === -1 ? 0 : sums[rightChild];
        
        const currentValue = num[nodeIdx];
        let total = currentValue + leftSum + rightSum;
        
        if (total <= limit) {
            sums[nodeIdx] = total;
        } else {
            groupCount++;
            total = currentValue + Math.min(leftSum, rightSum);

            if (total > limit) {
                groupCount++;
                total = currentValue;
            }
            
            sums[nodeIdx] = total;
        }
    }
    
    return groupCount;
}