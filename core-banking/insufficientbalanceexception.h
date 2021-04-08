//
// Created by dcl on 4/8/2021.
//

#ifndef STUDY_EXCEPTION_INSUFFICIENTBALANCEEXCEPTION_H
#define STUDY_EXCEPTION_INSUFFICIENTBALANCEEXCEPTION_H


#include <exception>
#include <string>

namespace banking {

    class InsufficientBalanceException : std::exception {
        const std::string reason;
    public:
        InsufficientBalanceException(const std::string &);

        const std::string &getReason() const;
    };

}

#endif //STUDY_EXCEPTION_INSUFFICIENTBALANCEEXCEPTION_H
