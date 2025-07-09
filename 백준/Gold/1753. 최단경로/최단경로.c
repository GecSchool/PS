#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_NODES 20001
#define INF INT_MAX

typedef struct Edge {
    int to;
    int cost;
    struct Edge* next;
} Edge;

typedef struct {
    int node;
    int dist;
} PQNode;

typedef struct {
    PQNode heap[MAX_NODES * 15]; // 힙 크기 증가
    int size;
} PriorityQueue;

Edge* graph[MAX_NODES];

void pq_init(PriorityQueue* pq) {
    pq->size = 0;
}

void pq_push(PriorityQueue* pq, int node, int dist) {
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
    PQNode root = pq->heap[0];
    pq->heap[0] = pq->heap[--pq->size];
    
    int idx = 0;
    while (1) {
        int left = 2 * idx + 1;
        int right = 2 * idx + 2;
        int smallest = idx;
        
        if (left < pq->size && pq->heap[left].dist < pq->heap[smallest].dist)
            smallest = left;
        if (right < pq->size && pq->heap[right].dist < pq->heap[smallest].dist)
            smallest = right;
            
        if (smallest == idx) break;
        
        PQNode temp = pq->heap[idx];
        pq->heap[idx] = pq->heap[smallest];
        pq->heap[smallest] = temp;
        
        idx = smallest;
    }
    return root;
}

int pq_empty(PriorityQueue* pq) {
    return pq->size == 0;
}

void add_edge(int from, int to, int cost) {
    Edge *newEdge = (Edge *)malloc(sizeof(Edge));
    newEdge->to = to;
    newEdge->cost = cost;
    newEdge->next = graph[from];
    graph[from] = newEdge;
}

// 한 번의 다익스트라로 모든 정점까지의 최단 거리 계산
void dijkstra(int start, int n, int dist[]) {
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
        
        // 이미 처리된 노드이거나 더 긴 거리면 스킵
        if (visited[cur_node] || cur_dist > dist[cur_node]) continue;
        
        visited[cur_node] = 1;
        
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
}

int main() {
    int V, E, K;
    scanf("%d %d", &V, &E);
    scanf("%d", &K);
    
    // 그래프 초기화
    for (int i = 1; i <= V; i++) {
        graph[i] = NULL;
    }
    
    // 간선 입력
    for (int i = 0; i < E; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        add_edge(u, v, w);
    }
    
    // 한 번의 다익스트라로 모든 최단 거리 계산
    int dist[MAX_NODES];
    dijkstra(K, V, dist);
    
    // 결과 출력
    for (int i = 1; i <= V; i++) {
        if (dist[i] == INF) {
            printf("INF\n");
        } else {
            printf("%d\n", dist[i]);
        }
    }
    
    return 0;
}