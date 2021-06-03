#include<stdio.h> 
#include<string.h>
int main()
{
	int i=0,len;
	char string[25],rev[25]={0};
	printf("enter a string:");
	scanf("%s",string);
	len=strlen(string)-1;
	while(string[i]!='\0')
	{
		rev[len]=string[i];
		len--;
		i++;
	
	}printf("\n %s",rev);
}
