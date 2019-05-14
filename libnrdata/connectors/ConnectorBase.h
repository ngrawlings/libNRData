//
//  ConnectorBase.hpp
//  LibNrData
//
//  Created by Nyhl Rawlings on 01/05/2019.
//  Copyright © 2019 Liquidsoft Studio. All rights reserved.
//

#ifndef ConnectorBase_hpp
#define ConnectorBase_hpp

#include <libnrdata/sql/generators/GeneratorBase.h>


namespace nrcore {
    
    class ConnectorBase {
    public:
        ConnectorBase();
        virtual ~ConnectorBase();
        
        void getConnection(void* connection);
        void* getConnection();
        
        //void* getConnection();
        
    protected:
        void *connection_instance;
    };
    
}

#endif /* ConnectorBase_hpp */
