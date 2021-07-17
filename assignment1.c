#include <stdio.h>

float sqRoot(int num,int precision){
	int st=0,end=num,mid;
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
	printf("%f\n",root);
}
