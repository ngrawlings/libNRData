//
//  Fields.cpp
//  LibNrData
//
//  Created by Nyhl Rawlings on 02/05/2019.
//  Copyright © 2019 Liquidsoft Studio. All rights reserved.
//

#include "Fields.h"

namespace nrcore {
    
    Fields::Fields() {
        
    }
    
    Fields::~Fields() {
        
    }
    
    void Fields::addField(String field) {
        fields.push(field);
    }
    
    String Fields::toString() {
        String ret;
        
        size_t len = fields.length();
        if (len) {
            ret = String("`%`").arg(fields[0]);
            for (int i=1; i<len; i++)
                ret += String(", `%`").arg(fields[i]);
        }
        
        return ret;
    }
    
}