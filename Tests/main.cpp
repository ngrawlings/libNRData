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

using namespace nrcore;

int main(int argc, const char * argv[]) {
    try {
        MysqlConnector con("127.0.0.1", 3306, "root", "MovingOn", "test");
        printf("%s\n", "Connected");
    } catch (Exception e) {
        printf("%s\n", e.getMessage());
    }
    
    
    return 0;
}
