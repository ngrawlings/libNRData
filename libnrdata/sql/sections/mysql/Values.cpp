//
//  Values.cpp
//  LibNrData
//
//  Created by Nyhl Rawlings on 03/05/2019.
//  Copyright © 2019 Liquidsoft Studio. All rights reserved.
//

#include "Values.h"

namespace nrcore {
    
    Values::Values() {
        
    }
    
    Values::Values(const Values& values) {
        this->values = values.values;
    }
    
    Values::~Values() {
        
    }
    
    void Values::add(String field, String value) {
        VALUE *_value = new VALUE;
        _value->field = field;
        _value->value = value;
        values.push(Ref<VALUE>(_value));
    }
    
    void Values::clear() {
        values.clear();
    }
    
    String Values::toString() {
        String ret;
        
        size_t len = values.length();
        if (len) {
            ret = String("`%`='%'").arg(values[0].getPtr()->field).arg(values[0].getPtr()->value);
            
            for(int i=1; i<len; i++)
                ret += String(", `%`='%'").arg(values[i].getPtr()->field).arg(values[i].getPtr()->value);
        }
        
        return ret;
    }
    
    String Values::getFields() {
        String ret;
        
        size_t len = values.length();
        if (len) {
            ret = String("`%`").arg(values[0].getPtr()->field);
            
            for(int i=1; i<len; i++)
                ret += String(", `%`").arg(values[i].getPtr()->field);
        }
        
        return ret;
    }
    
    String Values::getValues() {
        String ret;
        
        size_t len = values.length();
        if (len) {
            ret = String("'%'").arg(values[0].getPtr()->value);
            
            for(int i=1; i<len; i++)
                ret += String(", '%'").arg(values[i].getPtr()->value);
        }
        
        return ret;
    }
    
}
