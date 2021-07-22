
/*Program to compute the square root without the inbuilt function
 *
 * Compilation: gcc -o square_root assignment1.c
 * execution: ./square_root
 *
 * @Harsh Sandhu , 1911981371 , 22/07/2021*/

#include <stdio.h>

//Declaring the function for finding the square root
float square_root(int number,int precision);

int main(){
	//Number and Precision
        int number,precision;
	
	//Input for the number and precision
	printf("Enter the Number\n");
        scanf("%d",&number);

	printf("Enter the Precision\n");
	scanf("%d",&precision);

        //using the square_root function
	float root=square_root(number,precision);

        printf("Square Root of %d is\n%g\n",number,root);
}


//the square root function with precision using binary search
float square_root(int number,int precision){

	//declaring the start,end and mid
	int start=0,end=number,mid;

	//declaring variable for answer
	float root=0;
	
	//Logic of binary search
	while(start<=end){
		mid=(end+start)/2;
		if(mid*mid==number){
			root=number;
			break;
		}
		if(mid*mid<number){
			start=mid+1;
			root=mid;
		}else{
			end=mid-1;
		}

	}
	
	//Adding the precision 
	float value=0.1;
	for(int i=0;i<precision;i++){
		while(root*root<=number){
			root+=value;
		}
		root-=value;
		value/=10;
	}
	
	//returning the square root value
	return root;
}
