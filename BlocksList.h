//
// Created by vladead on 07.04.19.
//

#ifndef PROGA_4_BLOCKSLIST_H
#define PROGA_4_BLOCKSLIST_H

#include "LineWithMarker.h"

class BlocksList {
public:
    unsigned max_symbols_in_block;
    LineWithMarker *block;
    BlocksList *next;

    BlocksList() : max_symbols_in_block(5), block(nullptr), next(nullptr) {

    }
    ~BlocksList() {
        delete block;
    }
};


#endif //PROGA_4_BLOCKSLIST_H
