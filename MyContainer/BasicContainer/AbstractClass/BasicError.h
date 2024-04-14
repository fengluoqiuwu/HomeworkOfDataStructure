//
// Created by 86133 on 2024/4/14.
//

#ifndef BASIC_LIST_TEST_BASIC_ERROR_H
#define BASIC_LIST_TEST_BASIC_ERROR_H


#include <string>
#include <utility>

class BasicError : public std::exception{
public:
    explicit BasicError(std::string& msg){
        message=msg;
    }

    [[nodiscard]] std::string getMessage() const {
        return message;
    }

    [[nodiscard]] const char* what() const noexcept override {
        return message.c_str();
    }
private:
    std::string message;
};


#endif //BASIC_LIST_TEST_BASIC_ERROR_H
