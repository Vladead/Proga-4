#include <iostream>
#include "Processing.h"
using namespace std;

int main() {
    int lineCountFromInput1 = 0, lineCountFromInput2 = 0;
    Form form1, form2, result_list;
    FormBlock formBlock;

    if(CheckFile()) {
        return 666;
    }

    lineCountFromInput1 = LineCount1();
    lineCountFromInput2 = LineCount2();
    getting_info_from_file1(form1, formBlock, lineCountFromInput1);
    getting_info_from_file2(form2, formBlock, lineCountFromInput2);
    result_list.head = Intersection(form1, form2, formBlock);

    return 0;
}