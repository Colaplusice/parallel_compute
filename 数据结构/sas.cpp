#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<duizhan.h>
#define ERR -1
#define MAX 100 /*�����ջ�Ĵ�С*/
int stack[MAX]; /*��һά���鶨���ջ*/
int top=0; /*�����ջָʾ*/

int push(int i) /*�洢������,��ջ����*/
{
if(top<MAX)
{
stack[++top]=i; /*��ջ���пռ䣬ջ��ָʾ����һ��λ��*/
return 0;
}
else
{
printf("The stack is full");
return ERR;
}
}
int pop() /*ȡ������������ջ����*/
{
int var; /*��������ص�ջ��Ԫ��*/
if(top!=NULL) /*��ջ������Ԫ��*/
{
var=stack[top--]; /*��ջָʾ����һ��λ��*/
return var; /*����ջ��Ԫ��*/
}
else
printf("The stack is empty!\n");
return ERR;
}
int  main(void )
{
int m,n;
char l;
int a,b,c;
int k;
do{
printf("\tAriothmatic Operate simulator\n"); /*������ʾ��Ϣ*/
printf("\n\tPlease input first number:"); /*�����һ��������*/
scanf("%d",&m);
push(m); /*��һ����������ջ*/
printf("\n\tPlease input second number:"); /*����ڶ���������*/
scanf("%d",&n);
push(n); /*�ڶ�����������ջ*/
printf("\n\tChoose operator(+/-/*//):");
l=getche(); /*���������*/
switch(l) /*�ж��������ת��ִ����Ӧ����*/
{
case '+':
b=pop();
a=pop();
c=a+b;
printf("\n\n\tThe result is %d\n",c);
printf("\n");
break;
case '-':
b=pop();
a=pop();
c=a-b;
printf("\n\n\tThe result is %d\n",c);
printf("\n");
break;
case '*':
b=pop();
a=pop();
c=a*b;
printf("\n\n\tThe result is %d\n",c);
printf("\n");
break;
case '/':
b=pop();
a=pop();
c=a/b;
printf("\n\n\tThe result is %d\n",c);
printf("\n");
break;
}
printf("\tContinue?(y/n):"); /*��ʾ�û��Ƿ��������*/
l=getche();
if(l=='n')
exit(0);
}while(1);
}
