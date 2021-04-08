//
// Created by dcl on 4/8/2021.
//

#include "insufficientbalanceexception.h"

banking::InsufficientBalanceException::InsufficientBalanceException(const std::string& reason)  : reason(reason) {}

const std::string &banking::InsufficientBalanceException::getReason() const {
    return reason;
}
