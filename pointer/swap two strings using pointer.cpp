#include<stdio.h>
#include<string.h>
void swap(char *p,char *p1)
{
	int i=0;
	char t;
	while(*(p+i)!='\0' && *(p1+i)!='\0')
	{
		t=*(p+i);
		*(p+i)=*(p1+i);
		*(p1+i)=t;
		i++;
	}
	
}
int main()
{
	char string1[10],string2[10];
	printf("enter the 1st string: ");
    gets(string1);
    printf("enter the 2nd string: ");
    gets(string2);
    printf(" \n before swapping the 1st string is: %s \n 2nd string is: %s \n",string1,string2);
    swap(string1,string2);
    printf("after swapping: \n");
    printf("the 1st string is: %s \n2nd string is : %s",string1,string2);
    
}
