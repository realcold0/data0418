#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 10000

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
	char s2[100];
	printf("문자열을 입력하시오 : ");
	scanf_s("%[^\n]s", s,sizeof(s));
	
	int len = strlen(s);
	//홀수일때랑 짝수일때
	StackType stack2;

	StackType stack4;
	init_stack(&stack2);

	int k = 0;
	for (int i = 0; i < len; i++)
	{
		if (s[i] >= 'a' && s[i] <= 'z')
		{
			//s2[k++] = s[i];
			push(&stack, s[i]);
		}
		else if (s[i] >= 'A' && s[i] <= 'Z')
		{
			s[i] = s[i] + 32;
			//s2[k++] = s[i];
			push(&stack, s[i]);
		}
		
	} //문자만 입력

	int check = 0;

	for (int i = 0; i < strlen(s); i++)
	{
		if (s[i] >= 'a' && s[i] <= 'z')
	{
		char tmp = pop(&stack);
			if (s[i] == tmp)
		{
			check++;
		}
		else {
			check = 0;
			break;
		}
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