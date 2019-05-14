//
//  ConnectorBase.cpp
//  LibNrData
//
//  Created by Nyhl Rawlings on 01/05/2019.
//  Copyright © 2019 Liquidsoft Studio. All rights reserved.
//

#include "Connector.h"
#include <libnrdata/sql/builders/Builder.h>

namespace nrcore {
    
    Connector::Connector() {
        connection_instance = 0;
    }
    
    Connector::~Connector() {
        
    }
    
    void Connector::setConnection(void* connection) {
        connection_instance = connection;
        _schemas = Ref<Schemas>(new Schemas(this));
    }
    
    void* Connector::getConnection() {
        return connection_instance;
    }
    
    Ref<Schemas> Connector::schemas() {
        return _schemas;
    }
    
}
