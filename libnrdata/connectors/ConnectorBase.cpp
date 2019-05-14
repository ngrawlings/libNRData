//
//  ConnectorBase.cpp
//  LibNrData
//
//  Created by Nyhl Rawlings on 01/05/2019.
//  Copyright © 2019 Liquidsoft Studio. All rights reserved.
//

#include "ConnectorBase.h"
#include <libnrdata/sql/builders/BuilderBase.h>

namespace nrcore {
    
    ConnectorBase::ConnectorBase() {
        connection_instance = 0;
    }
    
    ConnectorBase::~ConnectorBase() {
        
    }
    
    void ConnectorBase::getConnection(void* connection) {
        connection_instance = connection;
    }
    
    void* ConnectorBase::getConnection() {
        return connection_instance;
    }
    
}
