#include <iostream>
#include "Processing.h"

int main() {
    int lineCountFromInput = 0;
    Form form;
    FormBlock formBlock;

    lineCountFromInput = LineCount();
    getting_info_from_file(form, formBlock, lineCountFromInput);

    return 0;
}