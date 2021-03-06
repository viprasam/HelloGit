#include <iostream>
#include <stdlib.h>


using namespace std;

int compare(const void *a, const void *b){
	const int *arg1 = (const int *)(a);
    const int *arg2 = (const int *)(b);
 
	//cout<<"\t compare"<<endl;
	if(*arg1 < *arg2) return -1;
	if(*arg1 > *arg2) return 1;
	return 0;
}


bool check_valid(unsigned char **in_array,int len)
{
	//cout<<"\nIn check_valid \n"<<endl;
	int *temp = (int *)malloc(sizeof(int)*len);
	
	for(int j=0;j<len;j++){
		//cout<<"\n "<<j<<" ";
		for(int i=0;i<len;i++){
			temp[i] = (int)in_array[j][i];
		}
		//cout<<len;
		qsort(temp,len,sizeof(int),compare);
		//sort(temp,len);
		//for(int i=0;i<len;i++)
		//	cout<<" "<<temp[i];
		for(int i=0;i<len;i++)			
			in_array[j][i] = (unsigned char)temp[i];
	}
	//cout<<"\nRunning check_valid"<<endl;
	for(int i=0;i<len;i++)			
		for(int j=0;j<len-1;j++)
			if(in_array[j][i] > in_array[j+1][i])
				return false;
	return true;
}


int main(){
	int test_cases=1,grid_size=5;
	unsigned char **array = (unsigned char **)malloc(sizeof(unsigned char *)*grid_size);

//	cout<<"Solving hackerrank question number 1"<<endl;
	cin>>test_cases;

	for(int i=0;i<test_cases;i++){
		cin>>grid_size;
		for(int j=0;j<grid_size;j++){
			array[j] = (unsigned char *)malloc(sizeof(unsigned char )*grid_size);
			for(int k=0;k<grid_size;k++)
				cin>>array[j][k];
		}
		/*
		for(int j=0;j<grid_size;j++){
			cout<<endl;
			for(int k=0;k<grid_size;k++)
				cout<<array[j][k]<<" ";
		}
		*/
		if(check_valid(array,grid_size))
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}

	return 0;
}

