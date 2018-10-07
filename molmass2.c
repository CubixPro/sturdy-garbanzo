
#include<stdio.h>
#include<string.h>
char symbol[5000];
int top=-1;
int  stack_mf[5000];
int top_mf=-1;
void print_stack()
{
  for(int i=top;i>=0;i--)
  {
    printf("%c",symbol[i]);
  }
  printf("\n");
}

void print_mf()
{
  for(int i=top_mf;i>=0;i--)
  {
    printf("%d",stack_mf[i]);
  }
  printf("\n");
}
void push(char ch)
{
  if(top<4998)
  {
    symbol[++top]=ch;

  }
  else
  {
    printf("overflow");
  }

}
int mval(char ch,int i)
{
  switch(ch)
  {
    case 'C':return 12*i;break;
    case 'H':return 1*i;break;
    case 'O':return 16*i;break;
    default:return (int)ch;
  }
}

void push_mf(int  ch)
{
  if(top_mf<4998)
  {
    stack_mf[++top_mf]=ch;

  }
  else
  {
    printf("overflow");
  }

}

int  pop_mf()
{
  return (top_mf!=-1)?(stack_mf[top_mf--]):1;
}

char pop()
{
  return (top!=-1)?(symbol[top--]):'@';
}
void main()
{
  int mf=1;
  int bracket=0;
  char string[5000];
  scanf("%s",string);
  int i=0;
  while(string[i]!='\0')
  {
    push(string[i]);i++;
  }
  char ch=pop();
  push_mf(1);
  int sum=0;
  while(ch!='@')
  {
    if(ch>=48&&ch<=57)
    {
      char ch2=pop();
      if(ch2==')')
      {
        mf=mf*(ch-48);
        push_mf(mf);
      }
      else
      sum+=mval(ch2,(ch-48)*mf);
    }
    else if(ch==')')
    {
      bracket++;
      push_mf(mf);
    }
    else if(ch=='(')
    {
      bracket--;mf=pop_mf();
    }
    else
    {
      mf=stack_mf[top_mf];
      sum+=mval(ch,mf);
    }
    ch=pop();
  }
  printf("%d",sum);
}
