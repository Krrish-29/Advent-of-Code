#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    FILE*ptr;
    ptr=fopen("Day_5.txt","r");
    int num1,num2;
    char *waste;
    vector<int>arr;
    for(int i=0;i<1;i++){
        fscanf(ptr,"%d",&num1);
        fscanf(ptr,"%c",&waste);
        fscanf(ptr,"%d",&num2);
        auto x=find(arr.begin(),arr.end(),num1);
        auto y=find(arr.begin(),arr.end(),num2);
        if (x != arr.end()||y!=arr.end()) {
            if(x != arr.end()&&y== arr.end()){
                int dist=distance(arr.begin(),x);
                arr.insert(arr.begin()+dist+1,num2);
            }
            else if(x == arr.end()&&y != arr.end()){
                int dist=distance(arr.begin(),y);
                if(dist==0){
                    arr.insert(arr.begin(),num1);
                    continue;
                }
                arr.insert(arr.begin()+dist-1,num1);
            }
            else if(x != arr.end()&&y != arr.end()){
                int dist1=distance(arr.begin(),x);
                int dist2=distance(arr.begin(),y);
                if(dist1>dist2){
                    printf("error");
                }
            }
        } 
        else {
            arr.push_back(num1);
            arr.push_back(num2);
        }
        arr.insert(arr.begin(),num1);
    }
    for(int i=0;i<1;i++){
        std::cout<<arr[i]<<"\n";
    }
}