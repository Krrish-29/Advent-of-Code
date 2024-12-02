#include <stdio.h>
#include<stdlib.h>
void merge(int *arr,int left,int middle,int right){
    int i,j,k=left,n1=middle-left+1,n2=right-middle,L[n1],R[n2];
    for(i=0;i<n1;i++){
        L[i]=arr[i+k];
    }
    for(j=0;j<n2;j++){
        R[j]=arr[middle+1+j];
    }
    for(i=0,j=0;i<n1&&j<n2;k++){
        if(L[i]<=R[j]){
            arr[k]=L[i];
            i++;
        }
        else{
            arr[k]=R[j];
            j++;
        }
    }
    while(i<n1){
        arr[k]=L[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k]=R[j];
        j++;    
        k++;
    }
}
void sort(int *arr,int left,int right){
    if(left<right){
        int middle=left+(right-left)/2;
        sort(arr,left,middle);
        sort(arr,middle+1,right);
        merge(arr,left,middle,right);
    }
}
int main(){
    FILE*ptr;
    ptr=fopen("Day_1.txt","r");
    int arr1[1000],arr2[1000];
    for(int i=0;i<1000;i++){
        fscanf(ptr,"%d",&arr1[i]);
        fscanf(ptr,"%d",&arr2[i]);
    }
    free(ptr);
    sort(arr1,0,999);
    sort(arr2,0,999);
    // int sum=0;
    // for(int i=0;i<1000;i++){
    //     sum+=abs(arr1[i]-arr2[i]);
    // }
    // printf("%d",sum);
    // int similarityscore=0,counter=0;
    // for(int i=0;i<1000;i++){
    //     for(int j=0;j<1000;j++){
    //         if(arr1[i]==arr2[j]){
    //             counter++;
    //         }
    //     }
    //     similarityscore+=(arr1[i]*counter);
    //     counter=0;
    // }
    // printf("%d",similarityscore);

    return 0;
}