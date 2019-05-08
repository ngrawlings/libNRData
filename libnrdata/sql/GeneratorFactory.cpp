//
//  GeneratorFactory.cpp
//  LibNrData
//
//  Created by Nyhl Rawlings on 07/05/2019.
//  Copyright © 2019 Liquidsoft Studio. All rights reserved.
//

#include "GeneratorFactory.h"

namespace nrcore {
    
    Ref<GeneratorBase> GeneratorFactory::create(TYPE type, void *handle, String database_name) {
        return Ref<GeneratorBase>(0);
    }
    
}
