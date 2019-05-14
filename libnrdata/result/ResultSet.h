//
//  ResultSet.hpp
//  LibNrData
//
//  Created by Nyhl Rawlings on 01/05/2019.
//  Copyright © 2019 Liquidsoft Studio. All rights reserved.
//

#ifndef ResultSet_hpp
#define ResultSet_hpp

#include "../connectors/ConnectorBase.h"
#include "Result.h"

#include <libnrcore/memory/Ref.h>
#include <libnrcore/memory/Array.h>

namespace nrcore {
    
    class ResultSet {
    public:
        ResultSet(ConnectorBase *con, Array<String> columns);
        virtual ~ResultSet();
        
        void addRow(Array<Memory> fields);
        Result row();
        
        int getColumnIndex(String name);
        
    protected:
        ConnectorBase *con;
        Array<String> columns;
        Array< Ref<Result> > rows;
        
        unsigned long cursor_offset;
        
    };
    
}


#endif /* ResultSet_hpp */
