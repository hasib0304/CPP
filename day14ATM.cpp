#include <iostream>


void showmenu(){
    std::cout<<"1. Deposit"<<std::endl;
    std::cout<<"2. Withdraw"<<std::endl;
    std::cout<<"3. Check Balance"<<std::endl;
    std::cout<<"4. Exit"<<std::endl;
}

void deposit(float& balance){
    float amount;
    std::cout<<"Enter  a deposit: ";
    std::cin>>amount;
    balance+=amount;
}

void withdraw(float& balance){
    float amount;
    std::cout<<"Enter amount to withdraw: ";
    std::cin>>amount;

    if (amount>balance){
        std::cout<<"Insufficient balance"<<std::endl;
    }
    else{
        balance-=amount;
    }
    
}

void checkbalance(float& balance){
    std::cout<<balance<<std::endl;
}




int main(){
    int selection;
    float balance = 0;

    do{
        std::cout<<"Please select a number: "<<std::endl;
        showmenu();
        std::cin>>selection;

        if (selection==1){
            deposit(balance);
            std::cout<<"The new balance is: ";
            checkbalance(balance);
        }
        else if(selection==2){
            withdraw(balance);
            std::cout<<"The new balance is: ";
            checkbalance(balance);
        }
        else if(selection==3){
            checkbalance(balance);
        }
        else if(selection==4){
            std::cout<<"Thanks for using our service!"<<std::endl;
            return 0;
        }
        else{
            std::cout<<"invalid selection"<<std::endl;
        }
    } while (selection!=4);
 return 0;
}