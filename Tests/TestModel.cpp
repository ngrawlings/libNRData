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

bool TestModel::emailExists(String email) {
    return false;
}

void TestModel::insert(String email, String description) {
    
}

int TestModel::revision() {
    return 2;
}

bool TestModel::migrate(int revision) {
    Builder* b = getBuilder()->clear();
    
    switch (revision) {
        case 1:
            {
                FieldDescriptor f1("id", FieldDescriptor::INT);
                f1.setUnsigned(true).setIndex(FieldDescriptor::PRIMARY).setAutoIncrement();
                
                FieldDescriptor f2("email", FieldDescriptor::VARCHAR);
                f2.setParameter("64").notNull(true);
                
                b->fieldDescriptor(Ref<FieldDescriptor>(new FieldDescriptor(f1)));
                b->fieldDescriptor(Ref<FieldDescriptor>(new FieldDescriptor(f2)));
                b->setEngine("InnoDB").setCharset("utf8mb4").setCollate("utf8mb4_0900_ai_ci");
                
                con->execute(b->sql(Builder::CREATE));
            }
            return true;
        
        case 2:
            {
                AlterTableField f1("description", FieldDescriptor::VARCHAR);
                f1.add().afterColumn("email").setParameter("64").notNull(true);
                
                b->fieldDescriptor(Ref<FieldDescriptor>(new AlterTableField(f1)));
                
                con->execute(b->sql(Builder::ALTER));
            }
            return true;
        
    }
    
    return false;
}
