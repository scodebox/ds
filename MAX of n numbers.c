#include<stdio.h>
#include<conio.h>

int main()
{
	int i,n,data[50];
	
	printf("Give the value of n : ");
	scanf("%d",&n);
	printf("Enter %d number : ",n);
	
	for(i=n; i<=2*n-1; i++){
		scanf("%d",&data[i]);
	}
		
	for(i=2*n-2;i>1;i=i-2){
		data[i/2]=  swap(data[i], data[i+1]);
	}
		
	for(i=1;i<=2*n-1;i++){
		printf("%2d  ",data[i]);
	}
		
		
	getch();
	return 0;
}

int swap(int a,int b)
{
	if(a>b){
		return a;
	}
	else{
		return b;
	}
}
