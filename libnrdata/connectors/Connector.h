//
//  ConnectorBase.hpp
//  LibNrData
//
//  Created by Nyhl Rawlings on 01/05/2019.
//  Copyright © 2019 Liquidsoft Studio. All rights reserved.
//

#ifndef ConnectorBase_hpp
#define ConnectorBase_hpp

#include <libnrdata/sql/builders/Builder.h>
#include "../result/ResultSet.h"
#include <libnrdata/models/Schemas.h>
#include <libnrdata/sql/sections/sql/FieldDescriptor.h>

namespace nrcore {
    
    class Connector {
    public:
        Connector();
        virtual ~Connector();
        
        void setConnection(void* connection);
        void* getConnection();
        
        Ref<Schemas> schemas();
        
        virtual Ref<Builder> getBuilder(String table) = 0;
        
        virtual void createDatabase(String name) = 0;
        virtual void dropDatabase(String name) = 0;
        virtual bool tableExists(String table) = 0;
        
        virtual void execute(String sql) = 0;
        virtual ResultSet query(String sql) = 0;
        
    protected:
        void *connection_instance;
        Ref<Schemas> _schemas;
    };
    
}

#endif /* ConnectorBase_hpp */
