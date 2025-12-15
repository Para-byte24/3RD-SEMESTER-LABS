#include<iostream>
#define MAX 15
using namespace std;

class Stack{
	private:
		int arr[MAX];
		int top;
		
	public:
		Stack(){
			top = -1;
		}
		
		bool overflow(){
			return top==MAX-1;
		}
		
		bool underflow(){
			return top<0;
		}
		
		void push(int a){
			if(overflow()){
				cout<<"Stack is full"<<endl;
			}else{
				top++;
				arr[top]=a;
				cout<<a<<"is pushed"<<endl;
			}
		}
		
		void pop(){
			if(underflow()){
				cout<<"Stack is empty"<<endl;
			}else{
				cout<<arr[top]<<"is popped"<<endl;
				top--;
			}
		}
		
		void traverse(){
			if(underflow()){
				cout<<"Stack is empty"<<endl;
			}else{
				cout<<"Stack elements:"<<endl;
				for(int i=top;i>=0;i--){
					cout<<arr[i]<<" ";
				}
				cout<<endl;
			}
		}
		
		int Top(){
			if(underflow()){
				cout<<"Stack is empty"<<endl;
				return -1;
			}else{
				return arr[top];
			}
		}
};

int main(){
	Stack s;
	
	int choice, value;
	
	do{
		cout<<"----------Aashika Thapa----------"<<endl;
		cout<<"----------Stack Operations----------"<<endl;
		cout<<"1.Push"<<endl;
		cout<<"2.Pop"<<endl;
		cout<<"3.Traverse"<<endl;
		cout<<"4.Top"<<endl;
		cout<<"5.Exit"<<endl;
		cout<<"Enter your choice"<<endl;
		cin>>choice;
		
		switch(choice){
			case 1:
				cout<<"Enter value: "<<endl;
				cin>>value;
				s.push(value);
				break;
			
			case 2:
				s.pop();
				break;
			
			case 3:
				s.traverse();
				break;
			
			case 4:
				cout<<"Top Element: "<<s.Top()<<endl;
				break;
			
			case 5:
			    cout<<"Exit..."<<endl;
				break;
				
			default:
				cout<<"Invalid Choice!"<<endl;
		}    
	}
	while(choice != 5);
	
	return 0;
}











