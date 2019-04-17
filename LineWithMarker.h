//
// Created by vladead on 07.04.19.
//

#ifndef PROGA_4_LINEWITHMARKER_H
#define PROGA_4_LINEWITHMARKER_H


class LineWithMarker {
public:
    char *symbols;
    char Marker;

    LineWithMarker() : symbols(nullptr), Marker('@') {

    }
    ~LineWithMarker() {
        delete[] symbols;
    }
};


#endif //PROGA_4_LINEWITHMARKER_H
