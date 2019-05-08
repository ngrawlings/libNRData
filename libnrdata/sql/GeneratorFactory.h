//
//  GeneratorFactory.hpp
//  LibNrData
//
//  Created by Nyhl Rawlings on 07/05/2019.
//  Copyright © 2019 Liquidsoft Studio. All rights reserved.
//

#ifndef GeneratorFactory_hpp
#define GeneratorFactory_hpp

#include <libnrcore/memory/Ref.h>
#include <libnrcore/memory/String.h>

#include "./generators/GeneratorBase.h"
#include "./generators/MysqlGenerator.h"

namespace nrcore {
    
    class GeneratorFactory {
    public:
        typedef enum {
            MYSQL
        } TYPE;
    public:
        virtual ~GeneratorFactory() {}
        
        static Ref<GeneratorBase> create(TYPE type, void *handle, String database_name);
        
    private:
        GeneratorFactory() {}
    };
    
}

#endif /* GeneratorFactory_hpp */
