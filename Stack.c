#include <stdio.h>
#include <stdlib.h>

typedef struct Stack
{
	int *p_Stack;
	int sSize;      // ջ����
	int sTop;       // ջ����ջ��Ԫ�ظ���};
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
	printf("������ջ��������");
	scanf_s("%d", &size);
	stack = initStack(size);

	int data;
	while (size--)
	{
		printf("������Ҫ��ջ�Ľڵ�:");
		scanf_s("%d", &data);
		push(stack, data);
	}
	outputStack(stack);

	int position;
	printf("������Ҫ��ѯ��ջ�ڵ�λ�ã�");
	scanf_s("%d", &position);
	inquireStackNode(stack, position);

	printf("������Ҫ�޸ĵ�λ�ü��޸ĵĽڵ�(�ո����):");
	scanf_s("%d %d", &position, &data);
	changeStackNode(stack, position, data);
	outputStack(stack);

	int times;
	printf("������Ҫ��ջ�ĸ�����");
	scanf_s("%d", &times);
	while (times--)
		pop(stack);
	outputStack(stack);
	system("pause");
	return 0;
}

// ջ�ĳ�ʼ��
stack *initStack(int size)
{
	stack *sk;
	sk = (struct Stack *)malloc(sizeof(stack));
	sk->p_Stack = (int *)malloc(size * sizeof(int));
	if (sk->p_Stack == NULL)
	{
		printf("ջ�ڴ����ʧ��");
		return NULL;
	}
	else
	{
		sk->sSize = size;
		sk->sTop = 0;
		return sk;
	}
}

// ��ѯջ�ڵ�
void inquireStackNode(stack *stack, int position)
{
	printf("%d\n", stack->p_Stack[position - 1]);
}

// �޸�ջ�ڵ�
void changeStackNode(stack *stack, int position, int data)
{
	stack->p_Stack[position - 1] = data;
}

// ���ջ���нڵ���Ϣ
void outputStack(stack *stack)
{
	for (int i = 0; i < stack->sTop; i++)
		printf("%d ", stack->p_Stack[i]);
	printf("\n");
}

// ��ջ
void push(stack *stack, int data)
{
	if (stack->sTop == stack->sSize)
		printf("ջ������");
	else
	{
		stack->p_Stack[stack->sTop] = data;
		stack->sTop++;
	}
}

// ��ջ
void pop(stack *stack)
{

	if (stack->sTop == 0)
		printf("ջ�ѿգ�");
	else
		stack->sTop--;
}
