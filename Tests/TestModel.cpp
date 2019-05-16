//
//  TestModel.cpp
//  Tests
//
//  Created by Nyhl Rawlings on 15/05/2019.
//  Copyright © 2019 Liquidsoft Studio. All rights reserved.
//

#include "TestModel.h"
#include <libnrdata/sql/sections/mysql/AlterTableField.h>

TestModel::TestModel(Connector* con) : Model(con, "test_table") {
    runMigration();
}

TestModel::~TestModel() {
    
}

int TestModel::revision() {
    return 2;
}

bool TestModel::migrate(int revision) {
    Ref<Builder> _mb = con->getBuilder("test_table");
    Builder *mb = _mb.getPtr();
    
    switch (revision) {
        case 1:
            {
                FieldDescriptor f1("id", FieldDescriptor::INT);
                f1.setUnsigned(true);
                f1.setIndex(FieldDescriptor::PRIMARY);
                f1.setAutoIncrement();
                
                FieldDescriptor f2("email", FieldDescriptor::VARCHAR);
                f2.setParameter("64");
                f2.notNull(true);
                
                mb->fieldDescriptor(Ref<FieldDescriptor>(new FieldDescriptor(f1)));
                mb->fieldDescriptor(Ref<FieldDescriptor>(new FieldDescriptor(f2)));
                mb->setEngine("InnoDB");
                mb->setCharset("utf8mb4");
                mb->setCollate("utf8mb4_0900_ai_ci");
                
                con->execute(mb->sql(Builder::CREATE));
            }
            return true;
        
        case 2:
            {
                AlterTableField f1("description", FieldDescriptor::VARCHAR);
                f1.add();
                f1.setParameter("64");
                f1.notNull(true);
                f1.afterColumn("email");
                
                mb->fieldDescriptor(Ref<FieldDescriptor>(new AlterTableField(f1)));
                
                con->execute(mb->sql(Builder::ALTER));
            }
            return true;
    }
    
    return false;
}
