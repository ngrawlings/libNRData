//
//  ResultSet.cpp
//  LibNrData
//
//  Created by Nyhl Rawlings on 01/05/2019.
//  Copyright © 2019 Liquidsoft Studio. All rights reserved.
//

#include "ResultSet.h"
#include <libnrcore/exception/Exception.h>

namespace nrcore {
    
    ResultSet::ResultSet(ConnectorBase *con, Array<String> columns) : con(con), columns(columns) {
        cursor_offset = 0;
    }
    
    ResultSet::~ResultSet() {
        
    }
    
    void ResultSet::addRow(Array<Memory> fields) {
        if (fields.length() != columns.length())
            throw Exception(-1, "Column count mis-match");
        
        rows.push(Ref<Result>(new Result(this, fields)));
    }
    
    Result ResultSet::row() {
        return Result(this, Array<Memory>());
    }
    
    int ResultSet::getColumnIndex(String name) {
        int len = (int)columns.length();
        for (int i=0; i<len; i++) {
            if (columns[i] == name)
                return i;
        }
        return -1;
    }
    
}
