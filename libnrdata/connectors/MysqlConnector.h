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
#include "ConnectorBase.h"
#include <libnrdata/sql/generators/MysqlGenerator.h>

#include <mysql.h>

#include <libnrcore/memory/Ref.h>
#include <libnrcore/memory/Array.h>
#include <libnrcore/memory/String.h>

#include "../result/ResultSet.h"

namespace nrcore {
    
    class MysqlConnector : public ConnectorBase {
    public:
        MysqlConnector(const char* host, int port, const char* username, const char* password, const char* database);
        virtual ~MysqlConnector();
        
        void execute(String sql);
        ResultSet query(String sql);
        
    protected:
        MYSQL *con;
        
    };
    
}

#endif /* MysqlConnector_hpp */
