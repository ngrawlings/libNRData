//
//  main.cpp
//  Tests
//
//  Created by Nyhl Rawlings on 14/05/2019.
//  Copyright © 2019 Liquidsoft Studio. All rights reserved.
//

#include <iostream>
#include <libnrdata/connectors/MysqlConnector.h>
#include <libnrcore/exception/Exception.h>
#include <libnrdata/sql/builders/MysqlBuilder.h>
#include <libnrdata/sql/sections/mysql/FieldDescriptor.h>


using namespace nrcore;

int main(int argc, const char * argv[]) {
    try {
        MysqlConnector con("127.0.0.1", 3306, "root", "MovingOn", "test");
        Ref<Builder> _mb = con.getBuilder("test_table");
        Builder *mb = _mb.getPtr();
        
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
        
        String sql = mb->sql(Builder::CREATE);
        
        printf("%s\n", sql.operator char *());
    } catch (Exception e) {
        printf("%s\n", e.getMessage());
    }
    
    
    return 0;
}
