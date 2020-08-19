//بسم الله الرحمن الرحيم
//اللہ کے نام سے شروع جو بڑا مہربان اور نہایت رحم والا ہے
//Allah in the name of The Most Affectionate, the Merciful
//अल्लाह के नाम से जो दयालु और कृपाशील है

//Merge sort algo

//step 1 : we will divide the array , left part= 0 to mid-1 , right part= mid to end-1
//step 2 : By recursion further we will divide the array 
//step 3 : We will merge the divided array in the original array , left to right


#include<bits/stdc++.h>

using namespace std;
#define fastio ios::sync_with_stdio(0); cin.tie(0)
#define ll long long
#define ull unsigned ll
#define pb push_back

#define endl '\n'
#define mod 1000000007

#define FOR(i,k,n) for(int i=k; i<n; i++)
#define ROF(i,k,n) for(int i=k; i>=n; i--)
#define MEMSET(t) memset(t,0,sizeof(t));
#define time clock_t tStart
#define Start clock()
#define Time printf("Time taken: %.3fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC)

//this functon merges two sorted array in the main array
void merge(int L[], int nL, int R[], int nR, int A[], int n)
{
    int i=0,j=0,k=0;
    while(i<nL && j<nR) //loop will terminate if we successfully merge all the element of left[] or right[] into main array
    {
        if(L[i]<=R[j]) //if left[] have less value then it comes first, so it will store in the main array first and we move on by i++
        {
            A[k]=L[i];   //merging
            i++; //move on
        }

        else { // if right[] have less value then it will store first
            A[k]=R[j];
            j++;        //move on    
        }

        k++; //we have merged arr[k] now will go for arr[k+1] by k++
    }

    //after merging some element will remains untouched in left[] or right[], we have to merge them also
    while(i<nL) { // for left[]
        A[k]=L[i];
        i++;
        k++;
    }
    while(j<nR) //for right[]
    {
        A[k]=R[j];
        j++;
        k++;
    }

    return;
}

//2
//Merge main function
//Divide the array into two equal parts ie 0 to mid-1 & mid to end-1

void MergeSort(int A[], int n)
{
    //int n=sizeof(A)/sizeof(A[0]); //it is wrong because array passed pointer not the whole array so sizeof(A) will be size of pointer=8
    
    if(n<2) return; // base condition, array of one element is already sorted
    int mid= n/2; //mid point of array 
    int left[mid]; //left part of array
    int right[n-mid]; //right part of array

    for(int i=0; i<mid; i++)
    {
        left[i]=A[i];
        //storing left part of array in left[] array
        //we have to divide  the array into 2 parts
    }
    for(int i=mid; i<n; i++ )
    {
        right[i-mid]=A[i];
        //storing right part of the array in right[] array
        //now we have divided the array into two parts ie, left[] & right[]
    }

    MergeSort(left,mid); //also divide the left[] into further pieces
    MergeSort(right,n-mid); //right array will be divided further
    
    //we have divided array into 2 parts, both the parts are sorted by calling the above function
    //ie MergeSort()
    //now we have to merge the two array into the main array, we are calling merge()
    merge(left,mid,right,n-mid,A,n);
    return ;
}

//1

int main()
{
    fastio;
    int t=1; 
    while(t--)
    {
        int n;
        cin>>n;
        int A[n];
        for(int i=0; i<n; i++) cin>>A[i]; //input array
        MergeSort(A,n); //merge function call
        for(int i=0; i<n; i++) cout<<A[i]<<" "; // display

    }
    return 0;
}   