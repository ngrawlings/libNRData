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

#include "./sections/FieldDescriptor.h"

namespace nrcore {
    
    class GeneratorBase {
    public:
        typedef enum {
            SELECT,
            INSERT,
            UPDATE,
            DELETE,
            CREATE,
            DROP
        } TYPE;
    public:
        GeneratorBase(String table);
        virtual ~GeneratorBase();
        
        virtual String sql(TYPE type) = 0;
        
        void select(String field);
        
        void join(String table, Ref<Clause> clause);
        void leftJoin(String table, Ref<Clause> clause);
        void rightJoin(String table, Ref<Clause> clause);
        void outerJoin(String table, Ref<Clause> clause);
        
        void value(String name, String value);
        
        void setClause(Ref<Clause> clause);
        
        void order(String field, Order::DIRECTION direction);
        void group(String field);
        
        void offset(long long offset);
        void limit(int offset);
        
        void fieldDescriptor(Ref<FieldDescriptor> fd);
        
        void setEngine(String engine);
        void setCharset(String charset);
        void setCollate(String collate);
        
    protected:
        String table;
        Fields fields;
        Array< Ref<Join> > joins;
        Values values;
        Ref<Clause> clause;
        Order _order;
        Fields _group;
        OffsetLimit offset_limit;
        
        Array< Ref<FieldDescriptor> > field_descriptors;
        String engine;
        String charset;
        String collate;
        
        String getJoins();
    };
    
}

#endif /* Generator_hpp */
