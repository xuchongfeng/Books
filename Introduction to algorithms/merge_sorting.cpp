#include <iostream>
#include <cstring>
#include <cassert>

using namespace std;

void merge(int A[],int p,int mid,int q){
	cout<<p<<" "<<mid<<" "<<q<<endl;
	int length1 = mid-p+1;
	int length2 = q-mid;
	
	int *B = (int *)malloc(length1*sizeof(int));
	int *C = (int *)malloc(length2*sizeof(int));
	assert(B && C);
	
	//memcpy(B,A+p,length1);
	//memcpy(C,A+mid+1,length2);
	for(int i=0;i<length1;i++){
		B[i] = A[p+i];
	}
	for(int j=0;j<length2;j++){
		C[j] = A[mid+1+j];
	}
	
	int i,j,k;
	i = p;
	j = k = 0;
	
	while(j < length1 && k < length2){
		if(B[j] < C[k]){
			A[i++] = B[j++];
		}else{
			A[i++] = C[k++];
		}
	}
	
	while(j < length1){
		A[i++] = B[j++];
	}
	
	while(k < length2){
		A[i++] = C[k++];
	}
}


void merge_sorting(int A[],int p,int q){
	if(p < q){
		int mid = (p+q)/2;
		merge_sorting(A,p,mid);
		merge_sorting(A,mid+1,q);
		merge(A,p,mid,q);
	}
}

int main(){
	int A[] = {3,2,6,4,1,9,7,8,5};
	int length = sizeof(A)/sizeof(A[0]);
	merge_sorting(A,0,length-1);
	for(int i=0;i<length;i++){
		cout<<A[i]<<endl;
	}
	return 0;
}