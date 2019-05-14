//
//  Result.cpp
//  LibNrData
//
//  Created by Nyhl Rawlings on 01/05/2019.
//  Copyright © 2019 Liquidsoft Studio. All rights reserved.
//

#include "Result.h"
#include "ResultSet.h"
#include <libnrcore/exception/Exception.h>

#include <string>

namespace nrcore {
    
    Result::Result(ResultSet *result_set, Array<Memory> values) : result_set(result_set), values(values) {
        
    }
    
    Result::Result(const Result &result) : result_set(result.result_set), values(result.values){
        
    }
    
    Result::~Result() {
        
    }
    
    String Result::getString(int index) {
        return values[index];
    }
    
    String Result::getString(String name) {
        int index = result_set->getColumnIndex(name);
        if (index == -1)
            throw Exception(-1, "Field not found");
        
        return getString(index);
    }
    
    int Result::getInteger(int index) {
        String v = getString(index);
        return atoi(v.operator char *());
    }
    
    int Result::getInteger(String name) {
        int index = result_set->getColumnIndex(name);
        if (index == -1)
            throw Exception(-1, "Field not found");
        
        return getInteger(index);
    }
    
    unsigned long Result::getUnsignedInteger(int index) {
        return std::stoul(getString(index).operator char *());
    }
    
    unsigned long Result::getUnsignedInteger(String name) {
        int index = result_set->getColumnIndex(name);
        if (index == -1)
            throw Exception(-1, "Field not found");
        
        return getUnsignedInteger(index);
    }
    
    double Result::getDouble(int index) {
        return atof(getString(index).operator char *());
    }
    
    double Result::getDouble(String name) {
        int index = result_set->getColumnIndex(name);
        if (index == -1)
            throw Exception(-1, "Field not found");
        
        return getDouble(index);
    }
    
    Memory Result::getBlob(int index) {
        return values[index];
    }
    
    Memory Result::getBlob(String name) {
        int index = result_set->getColumnIndex(name);
        if (index == -1)
            throw Exception(-1, "Field not found");
        
        return getBlob(index);
    }
 
}
