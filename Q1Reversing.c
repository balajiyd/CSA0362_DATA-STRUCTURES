#include<stdio.h>
int main(){
	int n,reversed=0,digit;
	printf("enter the number: ");
	scanf("%d", &n);
	while(n!=0){
		digit = n%10;
		reversed=reversed*10+digit;
		n /= 10;
	}
	printf("%d is reversewd number", reversed);
	return 0;
}









