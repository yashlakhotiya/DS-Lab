# include <stdio.h>
# include <stdlib.h>

///***********************     INSERTION SORT    *******************//////////

void insertSort(int arr[],int n){
	int i = 1,j;
	int curr;
	while(i < n){
		curr = arr[i];
		j = i-1;
		while(j >= 0){
			if(curr < arr[j]){
				arr[j+1] = arr[j];
				j--;
			}
			else break; //This break Statement is necessary
		}
		arr[j+1] = curr;
		i++;
	}
}

///////*****************************************************///////////////

////******************  MERGE SORT  ***************///////////

void merge(int arr[],int s,int e){
	int mid = (s+e)/2;
	int i = s;
	int j = mid+1;
	int k = s;
	int temp[100];
	while(i <= mid && j <= e){
		if(arr[i] < arr[j]){
			temp[k++] = arr[i++];
		}
		else if(arr[i] > arr[j]){
			temp[k++] = arr[j++];
		}
	}
	while(i <= mid){
		temp[k++] = arr[i++];
	}

	while(j <= e){
		temp[k++] = arr[j++];
	}
	for(k = s;k <=e; k++){
		arr[k] = temp[k];
	}
}

void mergesort(int arr[],int s,int e){
	if(s >= e) return;
	int mid = (s+e)/2;
	mergesort(arr,s,mid);
	mergesort(arr,mid+1,e);
	merge(arr,s,e);
}

/////////****************************************************////////

////////*********QUICK SORT***********////////////////////////

int getpartitionIndex(int arr[],int s,int e){
	int i;
	int partitionIndex = s;
	int pivot = arr[e];
	for(i = s;i <= e-1; i++){
		if(arr[i] <= pivot){
			int temp = arr[i];
			arr[i] = arr[partitionIndex];
			arr[partitionIndex] = temp;
			partitionIndex++;
		}
	}
	int temp = arr[e];
	arr[e] = arr[partitionIndex];
	arr[partitionIndex] = temp;
	return partitionIndex;
}

void quickSort(int arr[],int s,int e){
	if(s < e){
		int partitionIndex = getpartitionIndex(arr,s,e);
		quickSort(arr,s,partitionIndex-1);
		quickSort(arr,partitionIndex+1,e);
	}
}


void main(){
	int i;
	int arr[5] = {5,3,4,2,6};
	int brr[5] = {8,5,6,4,9};
	int crr[5] = {7,4,2,6,9};
	insertSort(arr,5);
	for(i = 0;i < 5;i ++){
		printf("%d\t",arr[i]);
	}
	mergesort(brr,0,4);
	printf("\n\n");
	for(i = 0;i < 5;i ++){
		printf("%d\t",brr[i]);
	}
	printf("\n\n");
	quickSort(crr,0,4);
	for(i = 0;i < 5;i ++){
		printf("%d\t",crr[i]);
	}
}