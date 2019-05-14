//
//  MysqlGenerator.hpp
//  LibNrData
//
//  Created by Nyhl Rawlings on 01/05/2019.
//  Copyright © 2019 Liquidsoft Studio. All rights reserved.
//

#ifndef MysqlGenerator_hpp
#define MysqlGenerator_hpp

#include <stdio.h>
#include <mysql.h>

#include "BuilderBase.h"

namespace nrcore {
    
    class MysqlBuilder : public BuilderBase {
    public:
        MysqlBuilder(MYSQL *mysql, String name);
        MysqlBuilder(const MysqlBuilder& gen);
        virtual ~MysqlBuilder();
        
        String escape(String str);
        String sql(TYPE type);
        
    protected:
        String select();
        String insert();
        String update();
        String _delete();
        String create();
        String alter();
        String drop();
        
    private:
        MYSQL *mysql;
    };
    
}

#endif /* MysqlGenerator_hpp */
