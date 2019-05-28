#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

//���ͤ����ƶü� 
void randomArray(int arr[], int size){
	
	for(int i=0 ; i<size ; i++)
		arr[i] = i;
	
	for(int i=size-1 ; i>0 ; i--){
		
		int j = rand()%(i+1);
		int temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}
}

void printArray(int arr[], int size){
		
		for(int i=0 ; i<size ; i++){
			
			cout<<setw(8)<<arr[i];
		}
		
		cout<<endl;
}

//�®���ߤ������ 
void printCards(int  arr[], int size){
	
	for(int i=0 ; i<size ; i++){
		
		cout<<setw(6);
		switch(arr[i]/13){
			case 0: cout<<"�®�";break;
			case 1: cout<<"����";break;
			case 2: cout<<"���";break;
			case 3: cout<<"����";break;
		}
		
		cout<<setw(2);
		switch(arr[i]%13){
			case 0: cout<<"A";break;
			case 10: cout<<"J";break;
			case 11: cout<<"Q";break;
			case 12: cout<<"K";break;
			default : cout<<arr[i]%13+1;
		}
	}
	cout<<endl;
}

void sortArray(int arr[], int size){
	
	for(int next=1;next<size;next++){
		
		int insert = arr[next];
		int moveItem=next;
		
		while (  (moveItem>0)&&(arr[moveItem-1]>insert)){
			
			arr[moveItem]=arr[moveItem-1];
			moveItem--;
		}
		
		arr[moveItem]=insert;		
	}
}

int main(){
	
	const int arraySize = 52;
	int array[arraySize] = {};
	
	srand(time(0));
	
	randomArray(array, arraySize);
	
	cout<<"���a1:"<<endl; 
	printCards(array, 13);
	cout<<"���a2:"<<endl; 
	printCards(array+13, 13);
	cout<<"���a3:"<<endl; 
	printCards(array+26, 13);
	cout<<"���a4:"<<endl; 
	printCards(array+39, 13);
	
}

