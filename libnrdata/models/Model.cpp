//
//  Model.cpp
//  LibNrData
//
//  Created by Nyhl Rawlings on 14/05/2019.
//  Copyright © 2019 Liquidsoft Studio. All rights reserved.
//

#include "Model.h"

#include <libnrcore/memory/Ref.h>

#include <libnrdata/sql/sections/mysql/ClauseValue.h>

namespace nrcore {
 
    Model::Model(Connector* con, String table) : con(con), table(table) {
        loadRevision();
        runMigration();
    }
    
    Model::~Model() {
        
    }
    
    void Model::loadRevision() {
        _revision = con->schemas().getPtr()->getRevision(table);
    }
    
    void Model::runMigration() {
        int current_revision = revision();
        for (int i=_revision; i<current_revision; i++) {
            if (migrate(i))
                con->schemas().getPtr()->setRevision(table, i);
        }
    }
    
}
