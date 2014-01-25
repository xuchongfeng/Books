#include <iostream>
using namespace std;
inline
void swap(int &a,int &b){
	int c = a;
	a = b;
	b = c;
}

int partition(int A[],int l,int r){
	int i = l-1;
	for(int j=l;j<r;j++){
		if(A[j] <= A[r]){
			i++;
			swap(A[i],A[j]);
		}
	}
	swap(A[i+1],A[r]);
	return i+1;
}

void quickSort(int A[],int l,int r){
	if(l < r){
		int m = partition(A,l,r);
		quickSort(A,l,m-1);
		quickSort(A,m+1,r);
	}
}

int main(){
	int A[] = {1,9,2,6,3,4,7,5,0,8};
	int length = sizeof(A)/sizeof(*A);
	quickSort(A,0,length-1);
	for(int i=0;i<length;i++){
		cout<<A[i]<<endl;
	}
	return 0;
}