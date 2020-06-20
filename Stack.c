#include <stdio.h>
#include <stdlib.h>

typedef struct Stack
{
	int *p_Stack;
	int sSize;      // 栈容量
	int sTop;       // 栈顶，栈中元素个数};
}stack;

stack *initStack(int size);
void push(stack *stack, int data);
void pop(stack *stack);
void inquireStackNode(stack *stack, int position);
void changeStackNode(stack *stack, int position, int data);
void outputStack(stack *stack);

int main()
{
	stack *stack;

	int size;
	printf("请输入栈的容量：");
	scanf_s("%d", &size);
	stack = initStack(size);

	int data;
	while (size--)
	{
		printf("请输入要入栈的节点:");
		scanf_s("%d", &data);
		push(stack, data);
	}
	outputStack(stack);

	int position;
	printf("请输入要查询的栈节点位置：");
	scanf_s("%d", &position);
	inquireStackNode(stack, position);

	printf("请输入要修改的位置及修改的节点(空格隔开):");
	scanf_s("%d %d", &position, &data);
	changeStackNode(stack, position, data);
	outputStack(stack);

	int times;
	printf("请输入要出栈的个数：");
	scanf_s("%d", &times);
	while (times--)
		pop(stack);
	outputStack(stack);
	system("pause");
	return 0;
}

// 栈的初始化
stack *initStack(int size)
{
	stack *sk;
	sk = (struct Stack *)malloc(sizeof(stack));
	sk->p_Stack = (int *)malloc(size * sizeof(int));
	if (sk->p_Stack == NULL)
	{
		printf("栈内存分配失败");
		return NULL;
	}
	else
	{
		sk->sSize = size;
		sk->sTop = 0;
		return sk;
	}
}

// 查询栈节点
void inquireStackNode(stack *stack, int position)
{
	printf("%d\n", stack->p_Stack[position - 1]);
}

// 修改栈节点
void changeStackNode(stack *stack, int position, int data)
{
	stack->p_Stack[position - 1] = data;
}

// 输出栈所有节点信息
void outputStack(stack *stack)
{
	for (int i = 0; i < stack->sTop; i++)
		printf("%d ", stack->p_Stack[i]);
	printf("\n");
}

// 入栈
void push(stack *stack, int data)
{
	if (stack->sTop == stack->sSize)
		printf("栈已满！");
	else
	{
		stack->p_Stack[stack->sTop] = data;
		stack->sTop++;
	}
}

// 出栈
void pop(stack *stack)
{

	if (stack->sTop == 0)
		printf("栈已空！");
	else
		stack->sTop--;
}
