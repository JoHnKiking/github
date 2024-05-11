#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>
typedef char STDataType;

typedef struct Stack
{
    STDataType* a;
    int top;
    int capacity;
}ST;
// ��ʼ��������
void STInit(ST* pst);
void STDestroy(ST* pst);

// ��ջ  ��ջ
void STPush(ST* pst, STDataType x);
void STPop(ST* pst);

// ȡջ������
STDataType STTop(ST* pst);

// �п�
bool STEmpty(ST* pst);
// ��ȡ���ݸ���
int STSize(ST* pst);

void STInit(ST* pst)
{
    assert(pst);
    pst->a = NULL;
    pst->top = 0;
    pst->capacity = 0;
}

void STDestroy(ST* pst)
{
    assert(pst);
    free(pst->a);
    pst->a = NULL;
    pst->top = pst->capacity = 0;
}
void STPush(ST* pst, STDataType x)
{
    assert(pst);

    if (pst->top == pst->capacity)
    {
        int newcapacity = pst->capacity == 0 ? 4 : pst->capacity * 2;
        STDataType* tmp = (STDataType*)realloc(pst->a, newcapacity * sizeof(STDataType));
        if (tmp == NULL)
        {
            perror("realloc fail");
        }
        pst->a = tmp;
        pst->capacity = newcapacity;
    }
    pst->a[pst->top] = x;
    pst->top++;
}

void STPop(ST* pst)
{
    assert(pst);
    assert(pst->top > 0);
    pst->top--;
}

// ȡջ������
STDataType STTop(ST* pst)
{
    assert(pst);
    assert(pst->top > 0);

    return pst->a[pst->top - 1];
}

// �п�
bool STEmpty(ST* pst)
{
    assert(pst);
    return pst->top == 0;
}
// ��ȡ���ݸ���
int STSize(ST* pst)
{
    assert(pst);
    return pst->top;
}


bool isValid(char* s) {
    ST st;
    STInit(&st);

    
    while (*s)
    {
        if (*s == '(' || *s == '{' || *s == '[')
        {
            STPush(&st, *s);
        }
        else
        {
            if (STEmpty(&st))
            {
                STDestroy(&st);
                return false;
            }
            char tmp = STTop(&st);
            STPop(&st);
            if ((tmp == '(' && *s != ')')
                || (tmp == '{' && *s != '}')
                || (tmp == '[' && *s != ']'))
            {
                STDestroy(&st);
                return false;
            }
        }
        ++s;
    }
    bool ret = STEmpty(&st);
    STDestroy(&st);

    return ret;
}

int main()
{
    char s[] = { "()"};
    isValid(s);
    return 0;
}