#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_NODES 1001
#define INF INT_MAX

// 인접 리스트의 노드 구조체
typedef struct Edge {
    int to;
    int cost;
    struct Edge* next;
} Edge;

// 우선순위 큐를 위한 구조체
typedef struct {
    int node;
    int dist;
} PQNode;

// 우선순위 큐 구조체 (최소힙)
typedef struct {
    PQNode heap[MAX_NODES * 100];
    int size;
} PriorityQueue;

// 인접 리스트
Edge* graph[MAX_NODES];

// 우선순위 큐 함수들
void pq_init(PriorityQueue* pq) {
    // TODO: 우선순위 큐 초기화
    pq->size = 0;
}

void pq_push(PriorityQueue* pq, int node, int dist) {
    // TODO: 1. 배열 끝에 새 노드 추가
    // TODO: 2. bubbleUp 구현 (부모와 비교하며 위로 올라가기)
    int idx = pq->size++;
    pq->heap[idx].node = node;
    pq->heap[idx].dist = dist;
    
    while (idx > 0) {
        int parent = (idx - 1) / 2;
        if (pq->heap[parent].dist <= pq->heap[idx].dist) break;
        PQNode temp = pq->heap[parent];
        pq->heap[parent] = pq->heap[idx];
        pq->heap[idx] = temp;
        idx = parent;
    }
}

PQNode pq_pop(PriorityQueue* pq) {
    // TODO: 1. 루트 노드(최솟값) 저장
    // TODO: 2. 마지막 노드를 루트로 이동  
    // TODO: 3. bubbleDown 구현 (자식들과 비교하며 아래로 내려가기)
    // TODO: 4. 저장해둔 최솟값 반환
    PQNode root = pq->heap[0];
    pq->heap[0] = pq->heap[--pq->size];  // 크기 감소 추가
    int idx = 0;
    while (2 * idx + 1 < pq->size) {
        int left = 2 * idx + 1;
        int right = 2 * idx + 2;
        
        // 오른쪽 자식이 존재하고, 왼쪽보다 작으면 오른쪽, 아니면 왼쪽
        PQNode child = (right < pq->size && pq->heap[right].dist < pq->heap[left].dist) ? 
                       pq->heap[right] : pq->heap[left];
        
        if(child.dist >= pq->heap[idx].dist) break;  // >= 로 변경, .dist로 접근
        
        PQNode tmpPQ = pq->heap[idx];
        pq->heap[idx] = child;
        
        // child가 어느 인덱스인지 찾아서 교환
        if (right < pq->size && pq->heap[right].dist == child.dist && pq->heap[right].node == child.node) {
            pq->heap[right] = tmpPQ;
            idx = right;
        } else {
            pq->heap[left] = tmpPQ;
            idx = left;
        }
    }
    return root;
 }

int pq_empty(PriorityQueue* pq) {
    // TODO: 큐가 비어있는지 확인
    return pq->size == 0;
}

// 간선 추가 함수
void add_edge(int from, int to, int cost) {
    // TODO: 1. 새 간선 동적 할당
    // TODO: 2. 간선 정보 설정 (to, cost, next)
    // TODO: 3. 기존 리스트 앞에 추가
    Edge *newEdge = (Edge *)malloc(sizeof(Edge));
    newEdge->to = to;
    newEdge->cost = cost;
    newEdge->next = graph[from];
    graph[from] = newEdge;
}

// 다익스트라 알고리즘
int dijkstra(int start, int end, int n) {
    int dist[MAX_NODES];
    int visited[MAX_NODES] = {0};
    PriorityQueue pq;
    
    // 초기화
    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
    }
    dist[start] = 0;
    
    pq_init(&pq);
    pq_push(&pq, start, 0);
    
    while (!pq_empty(&pq)) {
        PQNode current = pq_pop(&pq);
        int cur_node = current.node;
        int cur_dist = current.dist;
        
        // 이미 방문했거나 더 긴 거리면 스킵
        if (visited[cur_node] || cur_dist > dist[cur_node]) continue;
        
        visited[cur_node] = 1;
        
        // 목표 도시에 도달하면 종료
        if (cur_node == end) {
            return dist[end];
        }
        
        // 인접 노드들 확인
        Edge* edge = graph[cur_node];
        while (edge != NULL) {
            int next_node = edge->to;
            int new_dist = dist[cur_node] + edge->cost;
            
            if (new_dist < dist[next_node]) {
                dist[next_node] = new_dist;
                pq_push(&pq, next_node, new_dist);
            }
            
            edge = edge->next;
        }
    }
    
    return dist[end];
}

int main() {
    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);
    
    // TODO: 그래프 초기화 (모든 포인터를 NULL로)
    for (int i = 1; i <= n; i++) {
        graph[i] = NULL;
    }
    // TODO: 간선 입력받아서 그래프 구성
    for (int i = 0; i < m; i++) {
        int from, to, cost;
        scanf("%d %d %d", &from, &to, &cost);
        add_edge(from, to, cost);
    }

    // TODO: 시작점과 끝점 입력
    int start, end;
    scanf("%d %d", &start, &end);

    // TODO: 다익스트라 실행 및 결과 출력
    int result = dijkstra(start, end, n);
    printf("%d\n", result);

    return 0;
} 