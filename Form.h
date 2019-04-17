//
// Created by vladead on 09.04.19.
//

#ifndef PROGA_4_FORM_H
#define PROGA_4_FORM_H


#include "List1.h"

class Form {
public:
    List1 *head, *current, *last;

    Form() : head(nullptr), current(nullptr), last(nullptr) {

    }
    ~Form() = default;
};


#endif //PROGA_4_FORM_H
