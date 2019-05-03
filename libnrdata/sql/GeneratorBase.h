//
//  Generator.hpp
//  LibNrData
//
//  Created by Nyhl Rawlings on 01/05/2019.
//  Copyright © 2019 Liquidsoft Studio. All rights reserved.
//

#ifndef Generator_hpp
#define Generator_hpp

#include <stdio.h>
#include <libnrcore/memory/Ref.h>
#include <libnrcore/memory/Array.h>
#include <libnrcore/memory/String.h>

#include "./sections/Fields.h"
#include "./sections/Join.h"
#include "./sections/Values.h"
#include "./sections/Clause.h"
#include "./sections/Order.h"
#include "./sections/OffsetLimit.h"

namespace nrcore {
    
    class GeneratorBase {
    public:
        typedef enum {
            SELECT,
            INSERT,
            UPDATE,
            DELETE,
            DROP
        } TYPE;
    public:
        GeneratorBase();
        virtual ~GeneratorBase();
        
        virtual String sql(TYPE type) = 0;
        
    protected:
        String table;
        Fields fields;
        Array< Ref<Join> > joins;
        Values values;
        Ref<Clause> clause;
        Order order;
        Fields group;
        OffsetLimit offset_limit;
        
        String getJoins();
    };
    
}

#endif /* Generator_hpp */
