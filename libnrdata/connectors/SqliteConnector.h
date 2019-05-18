//
//  SqliteConnector.hpp
//  LibNrData
//
//  Created by Nyhl Rawlings on 17/05/2019.
//  Copyright © 2019 Liquidsoft Studio. All rights reserved.
//

#ifndef SqliteConnector_hpp
#define SqliteConnector_hpp

#include "Connector.h"
#include <sqlite3.h>

#include <libnrcore/memory/Ref.h>
#include <libnrcore/memory/Array.h>
#include <libnrcore/memory/String.h>

#include "../result/ResultSet.h"

namespace nrcore {
    
    class SqliteConnector : public Connector {
    public:
        SqliteConnector(String path);
        virtual ~SqliteConnector();
        
        Ref<Builder> getBuilder(String table);
        
        void createDatabase(String name);
        void dropDatabase(String name);
        bool tableExists(String table);
        
        void execute(String sql);
        ResultSet query(String sql);
        
    protected:
        sqlite3 *db;
    };
    
}

#endif /* SqliteConnector_hpp */
