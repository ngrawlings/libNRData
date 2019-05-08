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

#include <libnrcore/memory/String.h>

namespace nrcore {
    
    class MysqlConnector : public ConnectorBase {
    public:
        MysqlConnector(String host, String username, String password);
        virtual ~MysqlConnector();
        
    protected:
        
    };
    
}

#endif /* MysqlConnector_hpp */
