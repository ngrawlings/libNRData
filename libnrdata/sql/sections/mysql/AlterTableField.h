//
//  AlterTableField.hpp
//  LibNrData
//
//  Created by Nyhl Rawlings on 14/05/2019.
//  Copyright © 2019 Liquidsoft Studio. All rights reserved.
//

#ifndef AlterTableField_hpp
#define AlterTableField_hpp

#include "FieldDescriptor.h"

#include <libnrcore/memory/String.h>

namespace nrcore {
    
    class AlterTableField : public FieldDescriptor {
    public:
        typedef enum {
            ADD,
            DROP,
            CHANGE
        } ACTION;
    public:
        AlterTableField(String name, FieldDescriptor::TYPE type);
        virtual ~AlterTableField();
        
        void add();
        void drop();
        void change(String new_name);
        void afterColumn(String field);
        
        String toString();
        
    protected:
        ACTION action;
        String new_name;
        String after_column;
    };
    
}

#endif /* AlterTableField_hpp */
