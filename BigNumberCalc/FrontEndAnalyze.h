#pragma once
#include "BigNumber.h"

// 判斷輸入的運算式是否合法
bool inputIsValid(std::string);

// check the char is Symbol of operation or not
bool isSymbol(char);

// 對字串格式化，避免+跟-一元的狀況 Ex. 1+++++1 => 1 + 1
std::string format(std::string);

// replace any op to " op "
std::string replace(std::string);

// 判斷運算符號的優先順序
int priority(std::string alpha);

// 把數值運算式算出答案
BigNumber convert(std::string);

// 判斷輸入的字串是否為BigNumber的格式
bool isBigNumber(std::string);

// 計算兩數和一個運算符號
BigNumber Caculate(const BigNumber&, const BigNumber&, std::string symbol);