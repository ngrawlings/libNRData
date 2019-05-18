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

#include "../sections/sql/Fields.h"
#include "../sections/sql/Values.h"
#include "../sections/sql/Join.h"
#include "../sections/sql/Clause.h"
#include "../sections/sql/Order.h"
#include "../sections/sql/OffsetLimit.h"
#include "../sections/sql/FieldDescriptor.h"

namespace nrcore {
    
    using namespace sql;
    
    class Builder {
    public:
        typedef enum {
            SELECT,
            INSERT,
            UPDATE,
            DELETE,
            CREATE,
            ALTER,
            DROP
        } TYPE;
    public:
        Builder(String table);
        Builder(const Builder& genbase);
        virtual ~Builder();
        
        Builder* clear();
        
        virtual String escape(String str) = 0;
        virtual String sql(TYPE type) = 0;
        
        Builder* select(String field);
        
        Builder* distinct(bool val);
        
        Builder* join(String table, Ref<Clause> clause);
        Builder* leftJoin(String table, Ref<Clause> clause);
        Builder* rightJoin(String table, Ref<Clause> clause);
        Builder* outerJoin(String table, Ref<Clause> clause);
        
        Builder* value(String name, String value);
        
        Builder* setClause(Ref<Clause> clause);
        
        Builder* order(String field, Order::DIRECTION direction);
        Builder* group(String field);
        
        Builder* offset(long long offset);
        Builder* limit(int offset);
        
        Builder* fieldDescriptor(Ref<FieldDescriptor> fd);
        
        Builder& setEngine(String engine);
        Builder& setCharset(String charset);
        Builder& setCollate(String collate);
        
    protected:
        String table;
        Fields fields;
        Array< Ref<Join> > joins;
        Values values;
        Ref<Clause> clause;
        Order _order;
        Fields _group;
        OffsetLimit offset_limit;
        
        bool _distinct;
        
        Array< Ref<FieldDescriptor> > field_descriptors;
        String engine;
        String charset;
        String collate;
        
        String getJoins();
    };
    
}

#endif /* Generator_hpp */
