#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100

typedef char element;
typedef struct {
	element* data;		// data은 포인터로 정의된다. 
	int capacity;		// 현재 크기
	int top;
} StackType;

// 스택 생성 함수
void init_stack(StackType* s)
{
	s->top = -1;
	s->capacity = 1;
	s->data = (element*)malloc(s->capacity * sizeof(element));
}

// 공백 상태 검출 함수
int is_empty(StackType* s)
{
	return (s->top == -1);
}
// 포화 상태 검출 함수
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
// 삭제함수
element pop(StackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return s->data[(s->top)--];
}
int main()
{
	StackType stack;
	init_stack(&stack);
	char s[100];
	printf("문자열을 입력하시오 : ");
	scanf_s("%[^\n]s", s,sizeof(s));
	int len = strlen(s);
	//홀수일때랑 짝수일때
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
		
	} //문자만 입력

	stack4 = stack; //미리 복사


	int stackLength = stack.top + 1;


	for (int i = 0; i < stackLength; i++)
	{
		char tmp = pop(&stack);
		push(&stack2, tmp);
	}  //스택 2에 스택 1을 넣는다.
	

	
	//같은지 비교
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
		printf("회문입니다.");
	}
	else {
		printf("회문이 아닙니다.");
	}

	return 0;
}