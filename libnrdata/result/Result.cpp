//
//  Result.cpp
//  LibNrData
//
//  Created by Nyhl Rawlings on 01/05/2019.
//  Copyright © 2019 Liquidsoft Studio. All rights reserved.
//

#include "Result.h"

namespace nrcore {
    
    Result::Field::Field(String name, String value) {
        _name = name;
        _value = value;
    }
    
    Result::Field::~Field() {
        
    }
    
    String Result::Field::name() {
        return _name;
    }
    
    String Result::Field::stringValue() {
        return _value;
    }
    
    Result::Result(ConnectorBase *con, Array<String> values) : con(con), values(values) {
        
    }
    
    Result::~Result() {
        
    }
    
}
