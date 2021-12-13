//function overloading
#include<stdio.h>
	
int add(int x,int y) //x and y formal parameters
{
	return x+y;
}

float add(float x,float y)
{
	return x+y;
}



int main()
{
	int sumint=add(4,5); //actual parameters
	printf("Sum of Integers=%d\n",sumint);
	//float sumdouble=add(4.3,5.0);
	//printf("Sum of Doubles=%f\n",sumdouble);
}