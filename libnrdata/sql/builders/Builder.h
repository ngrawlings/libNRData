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

#include "../sections/mysql/Fields.h"
#include "../sections/mysql/Join.h"
#include "../sections/mysql/Values.h"
#include "../sections/mysql/Clause.h"
#include "../sections/mysql/Order.h"
#include "../sections/mysql/OffsetLimit.h"

#include "../sections/mysql/FieldDescriptor.h"

namespace nrcore {
    
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
        
        Array< Ref<FieldDescriptor> > field_descriptors;
        String engine;
        String charset;
        String collate;
        
        String getJoins();
    };
    
}

#endif /* Generator_hpp */
