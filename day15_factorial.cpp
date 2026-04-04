#include <iostream>

int factorial(int n){

    if(n==1 || n==0){
        return 1;
    }
    else{
        return n*factorial(n-1);
    }
}

int main(){
    int number;
    std::cout<<"Enter a number to get the factorial of: ";
    std::cin>>number;
    int result =factorial(number);
    std::cout<<result<<std::endl;
    return 0;
}