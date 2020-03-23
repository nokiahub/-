#include <stdio.h>

typedef struct _Node {
	int key;
	struct _Node *link;
}Node;


Node *pQueue = NULL;
int count = 0;

void create();
void destroy();
void print();
int isEmpty();
int isFull();

Node* createNode(int key);
void insert(int key);
void deleteMax();
int searchMax();

int main() {

	int idx;
	print();

	insert(1);
	insert(9);
	insert(3);
	insert(5);
	insert(2);
	insert(4);
	insert(7);
	insert(8);
	insert(10);
	insert(6);  // full
	insert(12); // full
	print();

	printf("max = %d\n\n", searchMax());

	// ����
	deleteMax();
	print();
	deleteMax();
	print();
	deleteMax();
	print();


	printf("max = %d\n\n", searchMax());

	// ���� 
	destroy();

	system("pause");
	return 0;
}

void create() {
	//����
}

void destroy() {
	Node *del;
	while (pQueue) {
		del = pQueue;
		pQueue = pQueue->link;
		count--;
		free(del);
		printf("free node!, remains count=%d\n", count);
	}
}

void print() {
	Node *nptr = pQueue;
	
	printf("\npriority\t");
	nptr = pQueue;
	while (nptr) {
		printf("%d\t", nptr->key);
		nptr = nptr->link;
	}
	printf("\n\n");
}

int isEmpty() {
	return (count == 0);
}

int isFull() {

	return 0;
}

Node* createNode(int key) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->key = key;
	newNode->link = NULL;

	return newNode;
}

void insert(int key) {
	Node *newNode;
	if (isEmpty()) {
		pQueue = createNode(key);
	}
	else {
		newNode = createNode(key);
		newNode->link = pQueue;
		//���� ��尡 pQueue��带 �����Ѽ� newNode �ڿ� ����� �� �ֵ��� ��.
		pQueue = newNode;
	}
	count++;
}

void deleteMax() {
	Node *prev = NULL;
	Node *max = NULL;
	Node *current = NULL;
	//pQ�� ���� ���
	if (!pQueue) return;
	//pQ ��尡 �Ѱ��� ���
	if (!(pQueue->link)) {
		free(pQueue);
		pQueue = NULL;
		count = 0;
	}
	//��尡 �ΰ� �̻��� ���
	else {
		max = pQueue;
		prev = NULL;
		current = pQueue;
		while (current->link) {
			if (max->key < current->link->key) {
				prev = current;
				max = current->link;
			}
			current = current->link;
		}
		if (prev == NULL) {
			pQueue = max->link;
		}
		else {
			prev->link = max->link;
		}
		free(max);
		count--;
	}
}
int searchMax() {
	int max = -1;
	Node *nptr = pQueue;

	while (nptr) {
		if (nptr->key > max)
			max = nptr->key;
		nptr = nptr->link;
	}
	return max;
}