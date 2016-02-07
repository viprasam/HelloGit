#include<iostream>
#include<stdio.h>
#include<string.h>
#define DP_SOLUTION 1

int MEMO[100]={-1}; //Initialize first index for array to -1 rest is zero

#if DP_SOLUTION
int getmin(int a,int b)
{
return a<b? a:b;
}

int MinimumStep(int n)
{
if(n==1) return 0;
if(MEMO[n]!=-1) return MEMO[n];

int r=1+MinimumStep(n-1);
if(n%2==0) r=getmin(r,1+MinimumStep(n/2));
if(n%3==0) r=getmin(r,1+MinimumStep(n/3));
MEMO[n]=r;
return r;

}
#else
//Normal Recursion
int MinimumStep(int n)
{
if(n==1)
	return 0;
if(n%3==0) return MinimumStep(n/3)+1;
 if(n%2==0) return MinimumStep(n/2)+1;
return MinimumStep(n-1)+1;

}
#endif

int main()
{
//Simple Recursion
int i;
memset(MEMO,-1,sizeof(MEMO));
for(i=0;i<12;i++) 
	printf("%d ",MEMO[i]); 

printf("\nMinimum Step To One from 1 = %d \n",MinimumStep(1));
printf("\nMinimum Step To One from 2 = %d \n",MinimumStep(2));
printf("\nMinimum Step To One from 3 = %d \n",MinimumStep(3));
printf("\nMinimum Step To One from 4 = %d \n",MinimumStep(4));
printf("\nMinimum Step To One from 5 = %d \n",MinimumStep(5));
printf("\nMinimum Step To One from 6 = %d \n",MinimumStep(6));
printf("\nMinimum Step To One from 7 = %d \n",MinimumStep(7));
printf("\nMinimum Step To One from 10 = %d \n",MinimumStep(10));

return 0;
}


