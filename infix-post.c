#include <stdio.h>

int prec(char ch)
{
    switch(ch)
    {
        case '^':return 3;
        case '*':case'/':return 2;
        case '+':case '-':return 1;
    }
}

int main(void) {
	char *expn="a+b-c*d";
	char opst[20];int top=-1;
	for(int i=0;expn[i]!='\0';i++)
	{
	    if(isalnum(expn[i]))
	    {
	        printf("%c",expn[i]);
	    }
	    else
	    {
	        if(top==-1)
	            opst[++top]=expn[i];
	        else
	        {
	            while(prec(opst[top])>=prec(expn[i]) && top!=-1)
	            {
	                printf("%c",opst[top--]);
	            }
	            opst[++top]=expn[i];
	        }
	    }
	}
	
	while(top!=-1)
	    printf("%c",opst[top--]);
	return 0;
}

