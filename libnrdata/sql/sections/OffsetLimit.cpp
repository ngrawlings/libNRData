//
//  OffsetLimit.cpp
//  LibNrData
//
//  Created by Nyhl Rawlings on 03/05/2019.
//  Copyright © 2019 Liquidsoft Studio. All rights reserved.
//

#include "OffsetLimit.h"

namespace nrcore {
    
    OffsetLimit::OffsetLimit() {
        this->offset = -1;
        this->limit = -1;
    }
    
    OffsetLimit::OffsetLimit(int limit) {
        this->offset = -1;
        this->limit = limit;
    }
 
    OffsetLimit::OffsetLimit(long long offset, int limit) {
        this->offset = offset;
        this->limit = limit;
    }
    
    OffsetLimit::~OffsetLimit() {
        
    }
    
    String OffsetLimit::toString() {
        if (offset == -1 && limit == -1)
            return String("");
        
        if (offset == -1)
            return String("LIMIT %").arg(limit);
        
        return String("LIMIT %, %").arg(offset).arg(limit);
    }
    
}
