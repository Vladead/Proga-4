//
// Created by vladead on 09.04.19.
//

#include <iostream>
#include <fstream>
#include "Processing.h"
#include "List1.h"
#include "BlocksList.h"
#include "LineWithMarker.h"
#include "Form.h"
#include "FormBlock.h"
using namespace std;

List1* Intersection(Form &form1, Form &form2, FormBlock &formBlock) {
    Form result_list;
    int max_steps_in_for = 0; // Списки отсортированы по убыванию, max_steps_in_for будет хранить меньшее число строк
    if(LineCount1() > LineCount2()) {
        max_steps_in_for = LineCount2();
    } else {
        max_steps_in_for = LineCount1();
    }

    int k1 = 0, k2 = 0;
    form1.current = form1.head;
    form2.current = form2.head;
    for(int i = 0; i < max_steps_in_for; i++)
    {
        if(form1.current->symbols_in_line == form2.current->symbols_in_line)
        {
            CopyNodeFromList(result_list, form1);
            CopyNodeFromList(result_list, form2);
            k1++;
            k2++;
            form1.current = form1.current->next;
            form2.current = form2.current->next;
        } else {
            if(form1.current->symbols_in_line < form2.current->symbols_in_line)
            {
                k2++; // Счетчик второго списка
                form2.current = form2.current->next;
            } else {
                k1++; // Счетчик первого списка
                form1.current = form1.current->next;
            }
        }
    }

    return result_list.head;
}

void CopyNodeFromList(Form &result_list, Form &list_form_file) {
    FormBlock tempFormBlock;
    tempFormBlock.current = list_form_file.current->line;
    auto temp = new List1;
    int j = 0, k = 0, m = 0;
    for(int i = 0; i < BlocksInLine(list_form_file.current->symbols_in_line); i++) {
        auto temp1 = new BlocksList;
        temp1->block = new LineWithMarker;
        temp1->block->symbols = new char[temp1->max_symbols_in_block];
        for(int h = 0; h <= temp1->max_symbols_in_block; h++)
            temp1->block->symbols[h] = 0;
        k = 0;
        m = 0;
        if(list_form_file.current->symbols_in_line - j == 1 &&
        list_form_file.current->symbols_in_line % 5 == 0) { // Для записи только одного маркер
            j += 2;
        }
        for(; k < temp1->max_symbols_in_block && j < list_form_file.current->symbols_in_line; j++) {
            temp1->block->symbols[k] = tempFormBlock.current->block->symbols[m];
            k++;
            m++;
            if(m >= 5) {
                tempFormBlock.current = tempFormBlock.current->next;
            }
            if(j + 1 >= list_form_file.current->symbols_in_line) {
                break;
            }
        }
        if(tempFormBlock.head != nullptr) {
            tempFormBlock.last->next = temp1;
            tempFormBlock.last = tempFormBlock.last->next;
        } else {
            tempFormBlock.head = temp1;
            temp->line = temp1;
            tempFormBlock.last = tempFormBlock.head;
        }
    }
    tempFormBlock.last->block->symbols[k] = tempFormBlock.last->block->Marker;
    tempFormBlock.head = nullptr;
    tempFormBlock.last = nullptr;

    if(result_list.head != nullptr) {
        result_list.last->next = temp;
        result_list.last = result_list.last->next;
    } else {
        result_list.head = temp;
        result_list.last = result_list.head;
    }
}

void getting_info_from_file1(Form &form, FormBlock &formBlock, int lineCountFromInput) {
    //--------------------------------------------------------------------------------------------Чтение данных из файла
    fstream input_file;
    char temp = 0;
    int symbols_count = 0, blocks_count = 0;
    input_file.open("../cmake-build-debug/InputFile1.txt", ios::in);
    input_file.unsetf(ios::skipws);

    int position = 0;
    for(int i = 0; i < lineCountFromInput; i++) {
        position = input_file.tellg();
        symbols_count = SymbolsCount(input_file, temp);
        blocks_count = BlocksInLine(symbols_count);
        auto transit_line = new char[symbols_count + 1];
        input_file.clear();
        input_file.seekg(position);
        for (int j = 0; j < symbols_count; j++)
            input_file >> transit_line[j];
        input_file >> temp;
        InputOneLine(form, formBlock, symbols_count, blocks_count, transit_line);
        form.last->symbols_in_line = symbols_count;
        delete[] transit_line;
    }

    input_file.setf(ios::skipws);
    input_file.close();
}

void getting_info_from_file2(Form &form, FormBlock &formBlock, int lineCountFromInput) {
    //--------------------------------------------------------------------------------------------Чтение данных из файла
    fstream input_file;
    char temp = 0;
    int symbols_count = 0, blocks_count = 0;
    input_file.open("../cmake-build-debug/InputFile2.txt", ios::in);
    input_file.unsetf(ios::skipws);

    int position = 0;
    for(int i = 0; i < lineCountFromInput; i++) {
        position = input_file.tellg();
        symbols_count = SymbolsCount(input_file, temp);
        blocks_count = BlocksInLine(symbols_count);
        auto transit_line = new char[symbols_count + 1];
        input_file.clear();
        input_file.seekg(position);
        for (int j = 0; j < symbols_count; j++)
            input_file >> transit_line[j];
        input_file >> temp;
        InputOneLine(form, formBlock, symbols_count, blocks_count, transit_line);
        form.last->symbols_in_line = symbols_count;
        delete[] transit_line;
    }

    input_file.setf(ios::skipws);
    input_file.close();
}

void InputOneLine(Form &form, FormBlock &formBlock, int symbols_count, int blocks_count, const char* transit_line) {
    //--------------------------------------------------------------------------Записывает в список одну строку из файла
    auto *temp = new List1;

    int j = 0;
    int k = 0;
    for(int i = 0; i < blocks_count; i++) {
        auto *temp1 = new BlocksList;
        temp1->block = new LineWithMarker;
        temp1->block->symbols = new char[temp1->max_symbols_in_block];
        k = 0;
        if(symbols_count - j == 1 && symbols_count % 5 == 0) { // Для записи толлько одного маркер
            j += 2;
        }
        for(; k < temp1->max_symbols_in_block && j < symbols_count; j++) {
            temp1->block->symbols[k] = transit_line[j];
            k++;
            if(j + 1 >= symbols_count) {
                break;
            }
        }
        if(formBlock.head != nullptr) {
            formBlock.last->next = temp1;
            formBlock.last = formBlock.last->next;
        } else {
            formBlock.head = temp1;
            temp->line = temp1;
            formBlock.last = formBlock.head;
        }

    }
    formBlock.last->block->symbols[k] = formBlock.last->block->Marker;
    formBlock.head = nullptr;
    formBlock.last = nullptr;

    if(form.head != nullptr) {
        form.last->next = temp;
        form.last = form.last->next;
    } else {
        form.head = temp;
        form.last = form.head;
    }
}

int LineCount1() {
    //----------------------------------------------------------------------------------Находит количество строк в файле
    fstream input_file;
    char trash = 0;
    int line_count = 0;
    input_file.open("../cmake-build-debug/InputFile1.txt", ios::in);
    input_file.unsetf(ios::skipws);

    while(!input_file.eof()) {
        input_file >> trash;
        if(trash == '\n')
            line_count++;
    }
    input_file.setf(ios::skipws);
    line_count++;

    input_file.close();
    return line_count;
}

int LineCount2() {
    //----------------------------------------------------------------------------------Находит количество строк в файле
    fstream input_file;
    char trash = 0;
    int line_count = 0;
    input_file.open("../cmake-build-debug/InputFile2.txt", ios::in);
    input_file.unsetf(ios::skipws);

    while(!input_file.eof()) {
        input_file >> trash;
        if(trash == '\n')
            line_count++;
    }
    input_file.setf(ios::skipws);
    line_count++;

    input_file.close();
    return line_count;
}

int BlocksInLine(int symbols_count) {
    //------------------------------------------------------------Находит количество блоков, в которое поместится строка
    int should_be_blocks = 0;
    bool is_odd = false;
    const unsigned size_of_block = 5;
    symbols_count++;
    if(symbols_count % 5 != 0) {
        is_odd = true;
    }
    should_be_blocks = symbols_count / size_of_block;
    if(is_odd) {
        should_be_blocks++;
    }

    return  should_be_blocks;
}

int SymbolsCount(fstream &input_file, char temp) {
    //------------------------------------------------------------------------Находит количество символов в строке файла
    char symbols_count = 0;
    do
    {
        input_file >> temp;
        if(input_file.eof() || (temp == '\n'))
            break;
        symbols_count++;
    } while (true);

    return symbols_count;
}



bool CheckFile() {
    //----------------------------------------------------------------------------------------------------Проверка файла
    fstream InputFile1;
    int count = 0;
    char trash = 0;
    InputFile1.open("../cmake-build-debug/InputFile1.txt", ios::in);
    if(InputFile1.bad() != 0) {
        cout << "Произошла ошибка открытия файла" << endl;
        return true;
    } else {
        InputFile1.unsetf(ios::skipws);
        while(InputFile1.eof()) {
            InputFile1 >> trash;
            if(trash == '\n') {
                count++;
            }
        }
        long file_size;
        InputFile1.seekg(0, ios::end);
        file_size = InputFile1.tellg();
        if (file_size == 0) {
            cout << "А файл то пуст :D" << endl;
            return true;
        }
    }
    InputFile1.close();

    fstream InputFile2;
    count = 0;
    trash = 0;
    InputFile2.open("../cmake-build-debug/InputFile2.txt", ios::in);
    if(InputFile2.bad() != 0) {
        cout << "Произошла ошибка открытия файла" << endl;
        return true;
    } else {
        InputFile2.unsetf(ios::skipws);
        while(InputFile2.eof()) {
            InputFile2 >> trash;
            if(trash == '\n') {
                count++;
            }
        }
        long file_size;
        InputFile2.seekg(0, ios::end);
        file_size = InputFile2.tellg();
        if (file_size == 0) {
            cout << "А файл то пуст :D" << endl;
            return true;
        }
    }
    InputFile2.close();

    return false;
}

void PrintForm(Form &form) { // Надо дописать
    std::fstream output_file;
    output_file.open("output_file.txt", std::ios::out);

//    auto temp = form.head;
//    while(temp != nullptr) {
//        for(int i = 0; temp->Inf.symbols[i] != temp->Inf.Marker; i++) {
//            output_file << temp->Inf.symbols[i];
//        }
//        temp = temp->next;
//        if(temp != nullptr)
//            output_file << "  --->" << std::endl;
//        else
//            output_file << "  --->nullptr";
//    }
    output_file.close();
}