//
// Created by vladead on 14.04.19.
//

#ifndef PROGA_4_FORMBLOCK_H
#define PROGA_4_FORMBLOCK_H


#include "BlocksList.h"

class FormBlock {
public:
    BlocksList *head, *current, *last;

    FormBlock() : head(nullptr), current(nullptr), last(nullptr) {

    }
    ~FormBlock() = default;
};


#endif //PROGA_4_FORMBLOCK_H
