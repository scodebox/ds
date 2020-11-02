#include<stdio.h>
#include<conio.h>

int main()
{
	int n,m,MAX,MIN,num1,num2,i;
	
	printf("Give the value of n : ");  
	scanf("%d",&n);
	
	printf("Enter %d number : ", n);
	scanf("%d",&MAX);
	
	MIN=MAX;
	m=n-1;
	
	if(n%2==0){
		scanf("%d",&MAX);
		if(MAX < MIN) swap(&MAX, &MIN);
		m=m-1;
	}
	
	for(i=1; i<=m/2; i++){
		
		scanf("%d%d",&num1,&num2);
		
		if(num1>num2)	swap(&num1, &num2);
		
		if(num1>MAX)	MAX=num1;
		if(num2<MIN)	MIN=num2;
		
	}

	printf("MAX : %d\t MIN : %d ",MAX,MIN);
	
	
	getch();
	return 0;
}

swap(int *MAX, int *MIN)
{
	int temp;
	
	temp = *MAX;
	*MAX = *MIN;
	*MIN = temp;
}
