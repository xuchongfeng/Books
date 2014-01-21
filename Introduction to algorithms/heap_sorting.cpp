#include <iostream>
using namespace std;

int length;

//O(lgn)
void max_heapify(int A[],int i){
	int largest = i;
	int left = 2*i;
	int right = 2*i+1;
	
	if(left <= length && A[largest] < A[left]){
		largest = left;
	}
	
	if(right <= length && A[largest] < A[right]){
		largest = right;
	}
	
	if(largest != i){
		int temp = A[i];
		A[i] = A[largest];
		A[largest] = temp;
		max_heapify(A,largest);
	}
	
	return;
}

//O(n)
void build_max_heap(int A[]){
	for(int i=length/2;i>=1;i--){
		max_heapify(A,i);
	}
}
//O(n*lgn)
void heap_sorting(int A[]){
	for(int i=length;i>=2;i--){
		int temp = A[i];
		A[i] = A[1];
		A[1] = temp;
		length--;
		max_heapify(A,1);
	}
}

int main(){
	int A[] = {0,1,4,2,7,6,3,9,8,0};
	length = (sizeof(A)/sizeof(A[0]))-1;
	int tLength = length;
	build_max_heap(A);
	heap_sorting(A);
	
	for(int i=1;i<=tLength;i++){
		cout<<A[i]<<endl;
	}
	return 0;
}