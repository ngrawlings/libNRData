//
//  Join.cpp
//  LibNrData
//
//  Created by Nyhl Rawlings on 02/05/2019.
//  Copyright © 2019 Liquidsoft Studio. All rights reserved.
//

#include "Join.h"

namespace nrcore {
    
    Join::Join(String table, Ref<Clause> clause, String type) : type(type), table(table), clause(clause) {
        
    }
    
    Join::~Join() {
        
    }
    
    String Join::toString() {
        return String("% JOIN % ON %").arg(type).arg(table).arg(clause.getPtr()->toString());
    }
    
}
