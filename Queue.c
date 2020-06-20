#include <stdio.h>
#include <stdlib.h>

typedef struct Queue
{
	int *p_Queue;       // �����������ַ
	int queueLen;       // ����Ԫ�س���
	int queueCap;       // ������������
	int qHead;      // ��ͷ
	int qTail;      // ��β
} queue;

queue *initQueue(int length);       // ��ʼ��������Ϣ
void inQueue(queue *queue, int data);       // ���
void outQueue(queue *queue);        // ����
void inquireQueueNode(queue *queue, int position);      // ��ѯ
void changeQueueNode(queue *queue, int position, int data);     // �޸�
void outputQueue(queue *queue);     // ����

int main()
{
	queue *qu;
	int size;
	printf("��������г��ȣ�");
	scanf_s("%d", &size);
	qu = initQueue(size);

	int data = 1;
	while (size--)
	{
		printf("������Ҫ��ӵ����ݣ�int���ͣ�:");
		scanf_s("%d", &data);
		inQueue(qu, data);
	}
	for (int i = qu->qHead; i < qu->queueLen + qu->qHead; i++)
		printf("%d ", qu->p_Queue[i % qu->queueCap]);
	printf("\n");

	int position;
	printf("������Ҫ��ѯ�����еĽڵ��λ�� ��");
	scanf_s("%d", &position);
	inquireQueueNode(qu, position);

	printf("������Ҫ�޸Ķ����нڵ��λ�ú�����:");
	scanf_s("%d %d", &position, &data);
	changeQueueNode(qu, position, data);
	for (int i = qu->qHead; i < qu->queueLen + qu->qHead; i++)
		printf("%d ", qu->p_Queue[i % qu->queueCap]);
	printf("\n");

	int times;
	printf("������Ҫ���ӵĸ���:");
	scanf_s("%d", &times);
	while (times--)
		outQueue(qu);
	for (int i = qu->qHead; i < qu->queueLen + qu->qHead; i++)
		printf("%d ", qu->p_Queue[i % qu->queueCap]);
	printf("\n");
	system("pause");
	return 0;
}

// ��ʼ��������Ϣ
queue *initQueue(int length)
{
	queue *qu;
	qu = (struct Queue *)malloc(sizeof(queue));
	qu->p_Queue = (int *)malloc(length * sizeof(int));        // ��̬�����ڴ�
	if (qu->p_Queue == NULL)
	{
		printf("�ڴ����ʧ�ܣ����д�����Ч!");
		return NULL;
	}
	else
	{
		qu->queueCap = length;
		qu->qHead = 0;
		qu->qTail = 0;
		return qu;
	}

}

// ��ѯ������Ϣ
void inquireQueueNode(queue *queue, int position)
{
	printf("%d\n", queue->p_Queue[position - 1]);
}

// �޸Ķ�����Ϣ
void changeQueueNode(queue *queue, int position, int data)
{
	queue->p_Queue[position - 1] = data;
}

// ���������Ϣ
void outputQueue(queue *queue)
{
	// queue->queueLen + queue->qHead��ֹ�������
	for (int i = queue->qHead; i < queue->queueLen + queue->qHead; i++)
		printf("%d ", queue->p_Queue[i % queue->queueCap]);

	printf("\n");
}

// ���
void inQueue(queue *queue, int data)
{
	if (queue->queueLen == queue->queueCap ? true : false)
		printf("����������");
	else
	{
		queue->p_Queue[queue->qTail] = data;
		queue->qTail++;
		queue->qTail = queue->qTail % queue->queueCap;       // ��ֹ�±�Խ��
		queue->queueLen++;
	}
}


// ����
void outQueue(queue *queue)
{
	if (queue->queueLen == 0 ? true : false)
		printf("�����ѿգ�");
	else
	{
		queue->qHead++;
		queue->qHead = queue->qHead % queue->queueCap;       // ��ֹ�±�Խ��
		queue->queueLen--;
	}
}
