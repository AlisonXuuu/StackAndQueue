#include <stdio.h>
#include <stdlib.h>

typedef struct Queue
{
	int *p_Queue;       // 队列数组基地址
	int queueLen;       // 队列元素长度
	int queueCap;       // 队列数组容量
	int qHead;      // 队头
	int qTail;      // 队尾
} queue;

queue *initQueue(int length);       // 初始化队列信息
void inQueue(queue *queue, int data);       // 入队
void outQueue(queue *queue);        // 出队
void inquireQueueNode(queue *queue, int position);      // 查询
void changeQueueNode(queue *queue, int position, int data);     // 修改
void outputQueue(queue *queue);     // 遍历

int main()
{
	queue *qu;
	int size;
	printf("请输入队列长度：");
	scanf_s("%d", &size);
	qu = initQueue(size);

	int data = 1;
	while (size--)
	{
		printf("请输入要入队的数据（int类型）:");
		scanf_s("%d", &data);
		inQueue(qu, data);
	}
	for (int i = qu->qHead; i < qu->queueLen + qu->qHead; i++)
		printf("%d ", qu->p_Queue[i % qu->queueCap]);
	printf("\n");

	int position;
	printf("请输入要查询队列中的节点的位置 ：");
	scanf_s("%d", &position);
	inquireQueueNode(qu, position);

	printf("请输入要修改队列中节点的位置和数据:");
	scanf_s("%d %d", &position, &data);
	changeQueueNode(qu, position, data);
	for (int i = qu->qHead; i < qu->queueLen + qu->qHead; i++)
		printf("%d ", qu->p_Queue[i % qu->queueCap]);
	printf("\n");

	int times;
	printf("请输入要出队的个数:");
	scanf_s("%d", &times);
	while (times--)
		outQueue(qu);
	for (int i = qu->qHead; i < qu->queueLen + qu->qHead; i++)
		printf("%d ", qu->p_Queue[i % qu->queueCap]);
	printf("\n");
	system("pause");
	return 0;
}

// 初始化队列信息
queue *initQueue(int length)
{
	queue *qu;
	qu = (struct Queue *)malloc(sizeof(queue));
	qu->p_Queue = (int *)malloc(length * sizeof(int));        // 动态创建内存
	if (qu->p_Queue == NULL)
	{
		printf("内存分配失败，队列创建无效!");
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

// 查询队列信息
void inquireQueueNode(queue *queue, int position)
{
	printf("%d\n", queue->p_Queue[position - 1]);
}

// 修改队列信息
void changeQueueNode(queue *queue, int position, int data)
{
	queue->p_Queue[position - 1] = data;
}

// 输出队列信息
void outputQueue(queue *queue)
{
	// queue->queueLen + queue->qHead防止长度溢出
	for (int i = queue->qHead; i < queue->queueLen + queue->qHead; i++)
		printf("%d ", queue->p_Queue[i % queue->queueCap]);

	printf("\n");
}

// 入队
void inQueue(queue *queue, int data)
{
	if (queue->queueLen == queue->queueCap ? true : false)
		printf("队列已满！");
	else
	{
		queue->p_Queue[queue->qTail] = data;
		queue->qTail++;
		queue->qTail = queue->qTail % queue->queueCap;       // 防止下标越界
		queue->queueLen++;
	}
}


// 出队
void outQueue(queue *queue)
{
	if (queue->queueLen == 0 ? true : false)
		printf("队列已空！");
	else
	{
		queue->qHead++;
		queue->qHead = queue->qHead % queue->queueCap;       // 防止下标越界
		queue->queueLen--;
	}
}
