#include<stdio.h>
#include<conio.h>
int linearSearch(int arr[],int n,int key){
int i;
for(i=0;i<n;i++){
if(arr[i]==key)
return i;
}
return -1;
}
int binarySearch(int arr[],int low,int high,int key){
while(low<=high){
int mid=low+(high-low)/2;
if(arr[mid]==key)
return mid;
else if(arr[mid]<key)
low=mid+1;
else
high=mid-1;
}
return -1;
}
void main(){
int arr[]={2,5,8,12,16,23,38,56,72,91};
int n=sizeof(arr)/sizeof(arr[0]);
int key=23,linearIndex,binaryIndex;
clrscr();
linearIndex=linearSearch(arr,n,key);
if(linearIndex!=-1)
printf("linear search : Element %d found at index %d.\n",key,linearIndex);
else
printf("linear search : Element %d not found in the array \n",key);
binaryIndex=binarySearch(arr,0,n-1,key);
if(binaryIndex!=-1)
printf("Binary Search : Element %d found at index %d .\n",key,binaryIndex);
else
printf("Binary search : Element %d not found in the array.\n",key);
getch();
}
