#include <iostream>
using namespace std;

#define SIZE 5

void divide(int*, int, int);
void merge(int*, int, int);

void divide(int* arr, int begin, int end){
	if(begin == end)
		return;

	divide(arr, begin,(begin + end)/2);
	divide(arr, (begin + end)/2 + 1, end);
	merge(arr, begin, end);
}

void merge(int* arr, int begin, int end){
	int b = begin,
	    m = (begin + end) / 2 + 1;
	int sorted[SIZE];

	for(int i=begin; i <end + 1; i++){
		if( b == ((begin +end)/ 2 + 1) ){
			sorted[i] = arr[m];
			m++;
		}
		else if( m == end + 1){
			sorted[i] = arr[b];
			b++;
		}
		else{
			if( arr[m] < arr[b] ){
				sorted[i] = arr[m];
        	                m++;
			}
			else{
                        	sorted[i] = arr[b];
                        	b++;				
			}
		}
	}
	for(int i= begin; i < end +1; i++){
		arr[i] = sorted[i];
	}
}


int main(){
	int unsorted[SIZE] = {5,4,3,2,1};

	divide(unsorted, 0, SIZE -1);

	for(int i=0; i< SIZE; i++){
		cout<<unsorted[i]<<endl;
	}

}
