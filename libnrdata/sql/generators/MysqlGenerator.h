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

#include "GeneratorBase.h"

namespace nrcore {
    
    class MysqlGenerator : public GeneratorBase {
    public:
        MysqlGenerator(MYSQL *mysql, String name);
        virtual ~MysqlGenerator();
        
        String escape(String str);
        String sql(TYPE type);
        
    protected:
        String select();
        String insert();
        String update();
        String _delete();
        String create();
        String drop();
        
    private:
        MYSQL *mysql;
    };
    
}

#endif /* MysqlGenerator_hpp */
