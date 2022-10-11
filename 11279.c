#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100000

typedef struct Heap {
	int HeapNode[MAX_SIZE];
	int size;
} Heap;

void init_heap(Heap *h) {
	for (int i = 0; i < MAX_SIZE; i++) h->HeapNode[i] = 0;
	h->size = 0;
}

void upheap(Heap *h, int n) {
	int size = ++(h->size);
	h->HeapNode[size] = n;
	while (size != 1 && h->HeapNode[size] > h->HeapNode[size / 2]) {
		int t = h->HeapNode[size / 2];
		h->HeapNode[size / 2] = h->HeapNode[size];
		h->HeapNode[size] = t;
		size /= 2;
	}
}

int downheap(Heap* h) {
	if (h->size == 0) return 0;
	int root = h->HeapNode[1];
	int end = h->HeapNode[h->size];
	int size = --(h->size);
	int parent = 1, child = 2;
	h->HeapNode[1] = end;
	while (child <= size) {
		if (h->HeapNode[child] < h->HeapNode[child + 1]) child++;
		if (h->HeapNode[parent] < h->HeapNode[child]) {
			int t = h->HeapNode[child];
			h->HeapNode[child] = h->HeapNode[parent];
			h->HeapNode[parent] = t;
		}
		parent = child;
		child *= 2;
	}
	return root;
}

int main() {
	int n, a;
	Heap h;
	init_heap(&h);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a);
		if (a == 0) printf("%d\n", downheap(&h));
		else upheap(&h, a);
	}
}
