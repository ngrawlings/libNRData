//
//  Clause.cpp
//  LibNrData
//
//  Created by Nyhl Rawlings on 01/05/2019.
//  Copyright © 2019 Liquidsoft Studio. All rights reserved.
//

#include "Clause.h"

namespace nrcore {

    Clause::Value::Value(TYPE type, String value) {
        _type = type;
        _value = value;
    }
    
    Clause::Value::Value(const Value &value) {
        _type = value._type;
        _value = value._value;
    }
    
    Clause::Value::~Value() {
        
    }

    Clause::TYPE Clause::Value::type() {
        return _type;
    }
    
    String Clause::Value::value() {
        return _value;
    }
    
    String Clause::Value::toString() {
        switch (_type) {
            case STRING:
                return String("'%'").arg(_value);
            case FIELD:
                return String("`%`").arg(_value);
            case RAW:
                return _value;
        }
    }
    
    Clause::Clause(String _operator) {
        this->_operator = _operator;
    }
    
    Clause::~Clause() {
        
    }
    
    String Clause::getOperator() {
        return _operator;
    }

}
