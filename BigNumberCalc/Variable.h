#pragma once
#include <iostream>
#include <string>
#include <map>

#include "BigNumber.h"

extern std::map<std::string, BigNumber> stores;

bool nameIsValid(const std::string&);