#include <iostream>

using namespace std;

void insert_sorting(int A[],int length){
	for(int i=1;i<length;i++){
		int temp = A[i];
		int j=i-1;
		while(j >= 0){
			if(A[j] >= temp){
				A[j+1] = A[j];
				j--;
			}else{
				break;
			}
		}
		A[j+1] = temp;
	}
}


int main(){
	int A[] = {1,6,4,3,7,5,2,9,8};
	int length = sizeof(A)/sizeof(A[0]);
	insert_sorting(A,length);
	for(int i=0;i<length;i++){
		cout<<A[i]<<endl;
	}
}