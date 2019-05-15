//
//  MysqlConnector.hpp
//  LibNrData
//
//  Created by Nyhl Rawlings on 07/05/2019.
//  Copyright © 2019 Liquidsoft Studio. All rights reserved.
//

#ifndef MysqlConnector_hpp
#define MysqlConnector_hpp

#include <stdio.h>
#include "Connector.h"
#include <libnrdata/sql/builders/MysqlBuilder.h>

#include <mysql.h>

#include <libnrcore/memory/Ref.h>
#include <libnrcore/memory/Array.h>
#include <libnrcore/memory/String.h>

#include "../result/ResultSet.h"

namespace nrcore {
    
    class MysqlConnector : public Connector {
    public:
        MysqlConnector(const char* host, int port, const char* username, const char* password, const char* database);
        virtual ~MysqlConnector();
        
        Ref<Builder> getBuilder(String table);
        
        void execute(String sql);
        ResultSet query(String sql);
        bool exists(String table);
        
    protected:
        MYSQL *con;
        
    };
    
}

#endif /* MysqlConnector_hpp */
