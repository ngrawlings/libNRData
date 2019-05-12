//
//  GeneratorFactory.cpp
//  LibNrData
//
//  Created by Nyhl Rawlings on 07/05/2019.
//  Copyright © 2019 Liquidsoft Studio. All rights reserved.
//

#include "GeneratorFactory.h"

#include <mysql.h>
#include "./generators/MysqlGenerator.h"

namespace nrcore {
    
    Ref<GeneratorBase> GeneratorFactory::create(TYPE type, void *handle, String database_name) {
        switch(type) {
            case MYSQL:
                return Ref<GeneratorBase>(new MysqlGenerator((::MYSQL*)handle, database_name));
        }
        return Ref<GeneratorBase>(0);
    }
    
}
