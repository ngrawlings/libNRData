//
//  AlterTableField.cpp
//  LibNrData
//
//  Created by Nyhl Rawlings on 14/05/2019.
//  Copyright © 2019 Liquidsoft Studio. All rights reserved.
//

#include "AlterTableField.h"

namespace nrcore {
    
    AlterTableField::AlterTableField(String name, FieldDescriptor::TYPE type) : FieldDescriptor(name, type) {
        
    }
    
    AlterTableField::~AlterTableField() {
        
    }
    
    void AlterTableField::add() {
        action = ADD;
    }
    
    void AlterTableField::drop() {
        action = DROP;
    }
    
    void AlterTableField::change(String new_name) {
        action = CHANGE;
        this->new_name = new_name;
    }
    
    void AlterTableField::afterColumn(String field) {
        after_column = field;
    }
    
    String AlterTableField::toString() {
        String ret;
        
        switch (action) {
            case ADD:
                ret = String("ADD COLUMN %").arg(FieldDescriptor::toString());
                break;
                
            case DROP:
                ret = String("DROP COLUMN `%`").arg(name);
                break;
                
            case CHANGE:
                ret = String("CHANGE COLUMN `%` `%` %").arg(name).arg(new_name.length() ? new_name : name).arg(FieldDescriptor::toString());
                break;
        }
        
        ret.arg(FieldDescriptor::toString());
        
        if (after_column.length())
            ret += String(" AFTER %").arg(after_column);
        else
            ret += " FIRST";
        
        return ret;
    }
    
}
