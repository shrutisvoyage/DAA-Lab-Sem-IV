#include<stdio.h>
void merge(int arr[],int l,int mid,int r){
    int i,j,k;
    int n1=mid-l+1;
    int n2=r-mid;
    L[n1],R[n2];
    for(int i=0;i<n1;i++)
      L[i]=arr[l+i];
    for(int j=0;j<n2;j++)
      R[j]=[mid+1+j];
    i=0,j=0,k=0;
    while(i<n1 && j<n2){
        if(L[i]<=R[j]){
            arr[k]=L[i];
            i++;
        }
        else{
            arr[k]=R[j];
            j++;
        }
        k++;
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
void mergeSort(int arr[],int l,int r){
    if(l<r){
        int mid=l+(r-l)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        merge(arr,l,mid,r);
    }
}
int main(){
    int a[]={67,8,22,45,0,11,1,2};
    int n=sizeof(a)/sizeof(a[0]);
    mergeSort(a,0,n-1);
    printf("sorted array:\n");
    for(int i=0;i<n;i++){
        printf("%d  ",a[i]);
    }
    return 0;
}

