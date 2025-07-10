#include<bits/stdc++.h>
using namespace std;
void display(vector<int>&a){
    for(int x:a)cout<<x<<" ";
    cout<<endl;
}
void bubbleSort(vector<int>&a){
    int n=a.size();
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            display(a);
            if(a[j]>a[j+1])swap(a[j],a[j+1]);
        }
    }
}
void insertionSort(vector<int>&a){
    int n=a.size();
    for(int i=1;i<n;i++){
        int key=a[i],j=i-1;
        while(j>=0&&a[j]>key){
            a[j+1]=a[j];
            j--;
            display(a);
        }
        a[j+1]=key;
        display(a);
    }
}
void selectionSort(vector<int>&a){
    int n=a.size();
    for(int i=0;i<n-1;i++){
        int minindex=i;
        for(int j=i+1;j<n;j++){
            if(a[j]<a[minindex])minindex=j;
        }
        swap(a[i],a[minindex]);
        display(a);
    }
}
void merge(vector<int>&a,int l,int m,int r){
    vector<int>ll(a.begin()+l,a.begin()+m+1),rr(a.begin()+m+1,a.begin()+r+1);
    int i=0,j=0,k=l;
    while(i<ll.size()&&j<rr.size()){
        a[k++]=(ll[i]<=rr[j])?ll[i++]:rr[j++];
        display(a);
    }
    while(i<ll.size())a[k++]=ll[i++],display(a);
    while(j<rr.size())a[k++]=rr[j++],display(a);
}
void mergeSort(vector<int>&a,int l,int r){
    if(l<r){
        int m=(l+r)/2;
        mergeSort(a,l,m);
        mergeSort(a,m+1,r);
        merge(a,l,m,r);
    }
}
int partition(vector<int>&a,int low,int high){
    int pivot=a[high],i=low-1;
    for(int j=low;j<high;j++){
        if(a[j]<pivot){
            i++;
            swap(a[i],a[j]);
            display(a);
        }
    }
    swap(a[i+1],a[high]);
    display(a);
    return i+1;
}
void quickSort(vector<int>&a,int low,int high){
    if(low<high){
        int pi=partition(a,low,high);
        quickSort(a,low,pi-1);
        quickSort(a,pi+1,high);
    }
}
int main(){
    vector<int>arr;
    cout<<"Enter the number of elements in array"<<endl;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }
    cout<<"Original:\n";display(arr);
    cout<<"Choose algorithm:\n1.Bubble\n2.Insertion\n3.Selection\n4.Merge\n5.Quick\nEnter choice:";int c;cin>>c;
    switch(c){
        case 1:bubbleSort(arr);break;
        case 2:insertionSort(arr);break;
        case 3:selectionSort(arr);break;
        case 4:mergeSort(arr,0,arr.size()-1);break;
        case 5:quickSort(arr,0,arr.size()-1);break;
        default:cout<<"Invalid\n";return 0;
    }
    cout<<"Sorted:\n";display(arr);
    return 0;
}
