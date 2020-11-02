#include<stdio.h>
//#include<conio.h>


int main()
{
    int i, n,a=1;
    static int  x[50];

    printf("Enter the value of N : ");
    scanf("%d",&n);

    printf("Enter %d values : ",n);

	for(i=n; i<=2*n-1; i++){
        scanf("%d",&x[i]);
    }

    setup(x,n);

//    for(i=n; i<=2*n-1; i++){
//        printf("%2d",x[i]);
//    }

    printf("MAX : %d",x[1]);
    printf("       NEXT MAX : %d",nextmax(x,n));

//    getch();
	return 0;

}




setup(int x[], int n)
{
	int i;

	for(i=2*n-2; i>1; i=i-2){

		x[i/2]=max(x[i],x[i+1]);

    }
}



int nextmax(int x[], int n)
{
	int i=2,next;

	next=min(x[2],x[3]) ;

	while(i<= 2*n-1){

		if(x[i]>x[i+1]){

			next=max(x[i+1], next);
			i=i*2;

		}else{

			next=max(x[i],next);

			i=2*(i+1);
		}

	}
	return next;
}



int max(int a, int b)
{
    if(a>b){
		return a;
	}
    else{
	return b;
	}
}



int min(int a, int b)
{
    if(a>b){
		return b;
	}
    else{
		return a;
	}
}
