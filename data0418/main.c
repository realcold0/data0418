#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100

typedef char element;
typedef struct {
	element* data;		// data�� �����ͷ� ���ǵȴ�. 
	int capacity;		// ���� ũ��
	int top;
} StackType;

// ���� ���� �Լ�
void init_stack(StackType* s)
{
	s->top = -1;
	s->capacity = 1;
	s->data = (element*)malloc(s->capacity * sizeof(element));
}

// ���� ���� ���� �Լ�
int is_empty(StackType* s)
{
	return (s->top == -1);
}
// ��ȭ ���� ���� �Լ�
int is_full(StackType* s)
{
	return (s->top == (MAX_STACK_SIZE - 1));
}
void push(StackType* s, element item)
{
	if (is_full(s)) {
		s->capacity *= 2;
		s->data =
			(element*)realloc(s->data, s->capacity * sizeof(element));
	}
	s->data[++(s->top)] = item;
}
// �����Լ�
element pop(StackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else return s->data[(s->top)--];
}
int main()
{
	StackType stack;
	init_stack(&stack);
	char s[100];
	printf("���ڿ��� �Է��Ͻÿ� : ");
	scanf_s("%[^\n]s", s,sizeof(s));
	int len = strlen(s);
	//Ȧ���϶��� ¦���϶�
	StackType stack2;

	StackType stack4;
	init_stack(&stack2);


	for (int i = 0; i < len; i++)
	{
		if (s[i] >= 'a' && s[i] <= 'z')
		{
			push(&stack, s[i]);
		}
		else if (s[i] >= 'A' && s[i] <= 'Z')
		{
			s[i] = s[i] + 32;
			push(&stack, s[i]);
		}
		
	} //���ڸ� �Է�

	stack4 = stack; //�̸� ����


	int stackLength = stack.top + 1;


	for (int i = 0; i < stackLength; i++)
	{
		char tmp = pop(&stack);
		push(&stack2, tmp);
	}  //���� 2�� ���� 1�� �ִ´�.
	

	
	//������ ��
	int check = 0;
	for (int i = 0; i < stackLength; i++)
	{
		char tmp1 = pop(&stack4);
		char tmp2 = pop(&stack2);

		if (tmp1 == tmp2)
		{
			check++;
		}
		else {
			check = 0;
			break;
		}
	}
	if (check > 0)
	{
		printf("ȸ���Դϴ�.");
	}
	else {
		printf("ȸ���� �ƴմϴ�.");
	}

	return 0;
}