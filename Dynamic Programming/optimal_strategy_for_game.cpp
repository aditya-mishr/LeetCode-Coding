#include<iostream>
#include<vector>
using namespace std;

int maximum_amount(int a[],int size)
{
    int table[size][size];
    for(int i=0;i<size;i++)
    table[i][i]=a[i];
    
    for(int i=0;i<size-1;i++)
    {
        table[i][i+1]=max(a[i],a[i+1]);
        table[i+1][i]=max(a[i],a[i+1]);
    }
    for(int length=3;length<=size;length++)
    {
        for(int i=0;i<size-length+1;i++)
        {
            int j=i+length-1;
            table[i][j]=max( a[i]+min(table[i+2][j],table[i+1][j-1]) , a[j]+min(table[i+1][j-1],table[i][j-2]) );
            table[j][i]=max(a[i]+min(table[i+2][j],table[i+1][j-1]),a[j]+min(table[i+1][j-1],table[i][j-2]));

        }
    }
    return table[0][size-1]; 
}

int main()
 {
	//code
	int t,size;
	cin>>t;
	while(t--)
	{
	    cin>>size;
	    int* a=new int[size];
	    for(int i=0;i<size;i++)
	    {
	        cin>>a[i];
	    }
	    cout<<maximum_amount(a,size)<<endl;
	}
	return 0;
}