#include<iostream>
#include<cstdio>
#include<stack>
#define MAX_LEN 100

using namespace std;

int evaluateExp(char*);
void performOperation(stack<int>&,stack<char>&);
int doArithmetic(int,int,char);
bool hasPrecedence(char,char);
int getPrecedence(char);

int main()
{
	char exp[MAX_LEN];
	printf("PROGRAM TO EVALUATE INFIX EXPRESSION\n");  // Enter the expression without spaces
	//printf("Enter the expression:");
	scanf("%s",exp);
	int res=evaluateExp(exp);
	printf("%s=%d\n",exp,res);
	return 0;
}

int evaluateExp(char *exp)
{
	if(!exp)
		return -1;
	int len=strlen(exp);
	stack<int> val;
	stack<char> op;
	for(int i=0;i<len;++i)
	{
		char ch=exp[i];
		if(ch=='(')
			op.push(ch);
		else if(ch>='0' && ch<='9')
		{
			int num=0;
			for(int j=i;exp[j]>='0' && exp[j]<='9';++j)
			{
				num=num*10+(exp[j]-'0');
				i=j;
			}
			val.push(num);
		}
		else if(ch==')')
		{
			while(!op.empty() && op.top()!='(')
			{
				performOperation(val,op);
			}
			op.pop();
		}
		else{
			while(!op.empty() && hasPrecedence(op.top(),ch))
			{
				performOperation(val,op);
			}
			op.push(ch);
		}
	}
	while(!op.empty())
	{
		performOperation(val,op);
	}
	return val.top();
}

void performOperation(stack<int>& val,stack<char>& op)
{
	int num2=val.top();
	val.pop();
	int num1=val.top();
	val.pop();
	int tmpRes=doArithmetic(num1,num2,op.top());
	op.pop();
	val.push(tmpRes);
	return;
}

int doArithmetic(int num1,int num2,char op)
{
	switch(op)
	{
		case '+':
			return num1+num2;
		case '-':
			return num1-num2;
		case '*':
			return num1*num2;
		case '/':
			return num1/num2;
		default:
			return 0;
	}
}
				
bool hasPrecedence(char c1,char c2)
{
	return getPrecedence(c1)>=getPrecedence(c2);
}

int getPrecedence(char ch)
{
	switch(ch)
	{
		case '(':
			return 0;
		case '+':
		case '-':
			return 1;
		case '*':
		case '/':
			return 2;
		default:
			return 0;
	}
}