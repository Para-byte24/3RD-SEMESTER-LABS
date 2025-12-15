#include<iostream>
int main(){
	int a[MAX],n=-1,choice,position,value,i,Max,data,min;
	
	while(true) {
		cout<<"\n MENU";
		cout<<"\n 1.Insert Data";
		cout<<"\n 2.Display element";
		cout<<"\n 3.Delete element";
		cout<<"\n 4.Update element";
		cout<<"\n 5.Search";
		cout<<"\n 6.Minimum";
		cout<<"\n 7.MAximum";
		
		cout<<"Enter the choice";
		cin>>choice;
		int count=0;
		int a;
		
		switch(choice){
			case 1:
				if(count==Max-1){
					cout<<"Array is full";
				}else{
					cout<<"Enter the number of data";
					cin>>data;
					count++;
					a[count]=data;
				}
				break;
			
			case 2:
				if(count==1){
					cout<<"Array is empty";
				}else{
					cout<<"Array element";
					for(i=0;i<count;i++){
						cout<<a[i];
					}
				}
				break;
				
			case 3:
				cout<<"Enter the position to delete";
				cin>>position;
				for(i=position;i<count-1;i++){
					a[i]=a[i+1];
					count--;
					cout<<"Element is deleted";
				}
				break;
				
			case 4:
				cout<<"Enter the position to update";
				cin>>position;
				cout<<"Enter the new value";
				cin>>value;
				a[position]=value;
				cout<<"ELement is updated";
				break;
				
			case 5:{
				int found=0;
				cout<<"Enter the value to be searched";
				cin>>value;
				for(i=0;i<count;i++){
					if(a[i]==value){
						cout<<"Found at position"<<i+1;
						break;
					}
				}
				if(i==count){
					cout<<"Element is found";
				    break;
			}
			break;
		}
			case 6:{
				if(count==0){
					cout<<"Array is empty";
				}else{
					int min=a[0];
					for(i=1;i<count;i++){
						if(a[i]<min){
							min=a[i];
							cout<<"Minimum"<<min;
						}
					}
				}
				break;
			}
			case 7:
				if(count==0){
					cout<<"Array is empty";
				}else{
					int max=a[0];
					for(i=1;i<count;i++){
						if(a[i]>max){
							max=a[i];
							cout<<"Maximum"<<max;
						}
					}
				}
				break;
				
			case 8:
				return 0;
			default:
				cout<<"Invalid Choice\n";	
		}
	}
}

















