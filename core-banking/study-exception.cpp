#include <iostream>
#include "account.h"
#include "insufficientbalanceexception.h"

int main(){
    banking::account acc("tr1",100'000);
    std::cout << acc << std::endl ;
    try{
        acc.withdraw(100'001); // string
        acc.withdraw(-1); // int -> 42
        acc.deposit(10);
    }catch (const banking::InsufficientBalanceException& e){
        std::cout << e.getReason() << std::endl ;
    }catch (const std::runtime_error err){
        std::cout << err.what() << std::endl ;
    }
    acc.getBalance();
    // noexcept: operator
    std::cout << (noexcept(acc.withdraw(-1)) ? "true" : "false") << std::endl;
    std::cout << (noexcept(acc.getBalance()) ? "true" : "false") << std::endl;
}

