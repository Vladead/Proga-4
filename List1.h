//
// Created by vladead on 07.04.19.
//

#ifndef PROGA_4_LIST1_H
#define PROGA_4_LIST1_H

#include "BlocksList.h"

class List1 {
public:
    BlocksList *line;
    int symbols_in_line;
    List1 *next;

    List1() : line(nullptr), symbols_in_line(0), next(nullptr) {

    }

    ~List1() {
        delete line;
    }
};


#endif //PROGA_4_LIST1_H
