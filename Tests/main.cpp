//
//  main.cpp
//  Tests
//
//  Created by Nyhl Rawlings on 14/05/2019.
//  Copyright © 2019 Liquidsoft Studio. All rights reserved.
//

#include <iostream>
#include <libnrcore/exception/Exception.h>
#include <libnrdata/connectors/MysqlConnector.h>
#include "TestModel.h"


using namespace nrcore;

int main(int argc, const char * argv[]) {

    try {
        MysqlConnector con("127.0.0.1", 3306, "root", "MovingOn", "test");
        TestModel tm(&con);
        
        if (!tm.emailExists("test@test.com"))
            tm.insert("test@test.com", "A simple test");
        
        Array<String> emails = tm.list();
        for (int i=0; i<emails.length(); i++)
            printf("%s\n", emails[i].operator char *());
        
    } catch (Exception e) {
        printf("%s\n", e.getMessage());
    }
    
    printf("Finished\n");
    
    return 0;
}
