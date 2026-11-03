// Fibonacci Series

#include<iostream>
using namespace std;
int steps = 0;

void fibonacci_iterative(int num){
    if(num < 0){
        cout<<"Num Should be Greater than 0"<<endl;
        return;
    }else if(num == 0){
        cout<<0<<endl;
        return;
    }
    cout<<0<<"  "<<1<<"  ";

    int prev = 0;
    int curr = 1;
    int next; int step = 0;
    while(num >= 2){
        step ++;
        next = prev + curr;
        cout<<next<<"  ";
        prev = curr;
        curr = next;
        num --;
    }
    cout<<endl<<step<<endl;
}

int fibonacci_recursive(int num){
    steps ++;
    if(num<0) return -1;
    if(num == 0) return 0;
    if(num == 1) return 1;

    return fibonacci_recursive(num-1) + fibonacci_recursive(num-2);
}

void fibonacci_recursive_call(int num){
    if(fibonacci_recursive(num) == -1){
        cout<<"Invalid Input!!"<<endl;
    }else{
        for(int i=0; i<=num; i++){
            cout<<fibonacci_recursive(i)<<"  ";
        }
        cout<<endl<<"steps: "<<steps<<endl;
    }
}

int main(){
    int num = 20;
    fibonacci_iterative(num);
    cout<<endl;
    fibonacci_recursive_call(num);

    return 0;
}