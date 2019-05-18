//
//  SqliteBuilder.hpp
//  LibNrData
//
//  Created by Nyhl Rawlings on 17/05/2019.
//  Copyright © 2019 Liquidsoft Studio. All rights reserved.
//

#ifndef SqliteBuilder_hpp
#define SqliteBuilder_hpp

#include "Builder.h"
#include <sqlite3.h>

namespace nrcore {
 
    class SqliteBuilder : public Builder {
    public:
        SqliteBuilder(String name);
        virtual ~SqliteBuilder();
        
        String escape(String str);
        String sql(TYPE type);
        
        String select();
        String insert();
        String update();
        String _delete();
        String create();
        String alter();
        String drop();
        
    };
    
}

#endif /* SqliteBuilder_hpp */
