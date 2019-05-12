//
//  ResultSet.cpp
//  LibNrData
//
//  Created by Nyhl Rawlings on 01/05/2019.
//  Copyright © 2019 Liquidsoft Studio. All rights reserved.
//

#include "ResultSet.h"

namespace nrcore {
    
    ResultSet::ResultSet(ConnectorBase *con, Array<String> columns) : con(con), columns(columns) {
        
    }
    
    ResultSet::~ResultSet() {
        
    }
    
    Result ResultSet::row() {
        return Result(con, Array<String>());
    }
    
}
