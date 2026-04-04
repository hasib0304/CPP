#include <iostream>

float balance=0;
void showmenu(){
    std::cout<<"1. Deposit"<<std::endl;
    std::cout<<"2. Withdraw"<<std::endl;
    std::cout<<"3. Check Balance"<<std::endl;
    std::cout<<"4. Exit"<<std::endl;
}

void deposit(){
    float amount;
    std::cout<<"Deposit amount: ";
    std::cin>>amount;
    balance+=amount;
    

}

void withdraw(){
    float amount;
    std::cout<<"Withdraw amount: ";
    std::cin>>amount;

    if (amount>balance){
        std::cout<<"Not enouggh balance"<<std::endl;
    }
    else{
        balance-=amount;
    }
}

void checkBalance(){
    std::cout<<balance<<std::endl;
}

int main(){
    int selection;

    do {

    std::cout<<"Make a selection from 1 to 4: "<<std::endl;
    showmenu();
    std::cin>>selection;

    if (selection==1){
        deposit();
        std::cout<<"The new balance is: ";
        checkBalance();
    }
    else if(selection==2){
        withdraw();
        std::cout<<"The new balance is: ";
        checkBalance();
    }
    else if(selection==3){
        std::cout<<"The balance is: ";
        checkBalance();
    }
    else if(selection==4){
        std::cout<<"Thanks for banking with us"<<std::endl;
        return 0;
    }
    else{
        std::cout<<"Invalid selection"<<std::endl;
    }
} while(selection!=4);
return 0;
}