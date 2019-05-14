//
//  Result.cpp
//  LibNrData
//
//  Created by Nyhl Rawlings on 01/05/2019.
//  Copyright © 2019 Liquidsoft Studio. All rights reserved.
//

#include "Row.h"
#include "ResultSet.h"
#include <libnrcore/exception/Exception.h>

#include <string>

namespace nrcore {
    
    Row::Row(ResultSet *result_set, Array<Memory> values) : result_set(result_set), values(values) {
        
    }
    
    Row::Row(const Row &row) : result_set(row.result_set), values(row.values){
        
    }
    
    Row::~Row() {
        
    }
    
    String Row::getString(int index) {
        return values[index];
    }
    
    String Row::getString(String name) {
        int index = result_set->getColumnIndex(name);
        if (index == -1)
            throw Exception(-1, "Field not found");
        
        return getString(index);
    }
    
    int Row::getInteger(int index) {
        String v = getString(index);
        return atoi(v.operator char *());
    }
    
    int Row::getInteger(String name) {
        int index = result_set->getColumnIndex(name);
        if (index == -1)
            throw Exception(-1, "Field not found");
        
        return getInteger(index);
    }
    
    unsigned long Row::getUnsignedInteger(int index) {
        return std::stoul(getString(index).operator char *());
    }
    
    unsigned long Row::getUnsignedInteger(String name) {
        int index = result_set->getColumnIndex(name);
        if (index == -1)
            throw Exception(-1, "Field not found");
        
        return getUnsignedInteger(index);
    }
    
    double Row::getDouble(int index) {
        return atof(getString(index).operator char *());
    }
    
    double Row::getDouble(String name) {
        int index = result_set->getColumnIndex(name);
        if (index == -1)
            throw Exception(-1, "Field not found");
        
        return getDouble(index);
    }
    
    Memory Row::getBlob(int index) {
        return values[index];
    }
    
    Memory Row::getBlob(String name) {
        int index = result_set->getColumnIndex(name);
        if (index == -1)
            throw Exception(-1, "Field not found");
        
        return getBlob(index);
    }
 
}
