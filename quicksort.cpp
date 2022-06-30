#include<iostream>
using namespace std;
void swapping(int &a ,int &b)
{
 int temp;
 temp=a;
 a=b;
 b=temp;
}
void display(int *array, int size)
{
     for(int i=0;i< size; i++)
     cout<<array[i]<<"  ";
     cout<<endl;
}
int partition(int *array,int lower,int upper)
{
     int pivot,start,end;
     pivot=array[lower];
     start=lower;
     end=upper;
     while(start<end)
     {
          while(array[start]<=pivot&&start<end)
          { 
              start++;
          }
          while(array[end]>pivot)
          {
               end--;
          }
          if(start<end)
          {
              swap(array[start],array[end]);
          }
     }
     array[lower]=array[end];
     array[end]=pivot;
     return end;
}
void quicksort(int *array,int left,int right)
{
    int q;
    if (left<right)
    {
     q=partition(array,left,right);
     quicksort(array,left,q-1);
     quicksort(array,q+1,right);
    }
}
int main()
{ 
    int n;
    cout<<"Enetr the numbers of elements : ";
    cin>>n;
    int arr[n];
    cout<<"Enter elements : ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"Array before sorting : ";
    display(arr,n);
    quicksort(arr,0,n-1);
    cout<<"Array after sorting :";
    display(arr,n);
    return 0;
}