// Harsh Sandhu- 1911981371

/*Given a positive number n and precision p, find the square root of number upto p decimal places using binary search. Do not use any existing square root function provided by the language*/

#include <stdio.h>

float sqRoot(int num,int precision){
	int st=0,end=num/2,mid;
	float root=0;

	while(st<=end){
		mid=(end+st)/2;
		if(mid*mid==num){
			root=num;
			break;
		}
		if(mid*mid<num){
			st=mid+1;
			root=mid;
		}else{
			end=mid-1;
		}

	}
	
	float value=0.1;
	for(int i=0;i<precision;i++){
		while(root*root<=num){
			root+=value;
		}
		root-=value;
		value/=10;
	}

	return root;
}


int main(){
	int num,precision;
	scanf("%d %d",&num,&precision);

	float root=sqRoot(num,precision);
	printf("%g\n",root);
}
