//
// Created by vladead on 09.04.19.
//

#ifndef PROGA_4_PROCESSING_H
#define PROGA_4_PROCESSING_H

#include "Form.h"
#include "FormBlock.h"

List1* Intersection(Form &form1, Form &form2, FormBlock &formBlock);
void CopyNodeFromList(Form &result_list, Form &list_form_file);
void getting_info_from_file1(Form &form, FormBlock &formBlock, int lineCountFromInput);
void getting_info_from_file2(Form &form, FormBlock &formBlock, int lineCountFromInput);
void InputOneLine(Form &form, FormBlock &formBlock, int symbols_count, int blocks_count, const char* transit_line);
int LineCount1();
int LineCount2();
int BlocksInLine(int symbols_count);
int SymbolsCount(std::fstream &input_file, char temp);
bool CheckFile();
void PrintForm(Form &form1, Form &form2, Form &result_list);
void DeleteList(Form &form);

#endif //PROGA_4_PROCESSING_H
