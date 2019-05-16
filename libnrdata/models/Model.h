//
//  Model.hpp
//  LibNrData
//
//  Created by Nyhl Rawlings on 14/05/2019.
//  Copyright © 2019 Liquidsoft Studio. All rights reserved.
//

#ifndef Model_hpp
#define Model_hpp

#include <libnrcore/memory/String.h>

#include <libnrdata/connectors/Connector.h>

namespace nrcore {
    
    class Model {
    public:
        Model(Connector* con, String table);
        virtual ~Model();
        
    protected:        
        Connector* con;
        String table;
        int _revision;
        
        Ref<Builder> builder;
        
        virtual int revision() = 0;
        virtual bool migrate(int revision) = 0;
        
        void loadRevision();
        void runMigration();
        
        Builder* getBuilder();
    };
    
}

#endif /* Model_hpp */
