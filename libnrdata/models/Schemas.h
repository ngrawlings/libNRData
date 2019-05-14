//
//  Schemas.hpp
//  LibNrData
//
//  Created by Nyhl Rawlings on 14/05/2019.
//  Copyright © 2019 Liquidsoft Studio. All rights reserved.
//

#ifndef Schemas_hpp
#define Schemas_hpp

#include <libnrcore/memory/String.h>

namespace nrcore {
    
    class Connector;
    
    class Schemas {
    public:
        Schemas(Connector* con);
        virtual ~Schemas();
        
        void setConnection(Connector* con);
        
        int getRevision(String table);
        void setRevision(String table, int revision);
        
    protected:
        Connector* con;
        
        bool exists();
        void create();
    };
    
}

#endif /* Schemas_hpp */
