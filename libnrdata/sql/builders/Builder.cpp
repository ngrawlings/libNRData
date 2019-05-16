//
//  Generator.cpp
//  LibNrData
//
//  Created by Nyhl Rawlings on 01/05/2019.
//  Copyright © 2019 Liquidsoft Studio. All rights reserved.
//

#include "Builder.h"

namespace nrcore {
 
    Builder::Builder(String table) : table(table) {
        
    }
    
    Builder::Builder(const Builder& genbase) {
        table               = genbase.table;
        fields              = genbase.fields;
        joins               = genbase.joins;
        values              = genbase.values;
        clause              = genbase.clause;
        _order              = genbase._order;
        _group              = genbase._group;
        offset_limit        = genbase.offset_limit;
        
        field_descriptors   = genbase.field_descriptors;
        engine              = genbase.engine;
        charset             = genbase.charset;
        collate             = genbase.collate;
    }
    
    Builder::~Builder() {
        
    }
    
    Builder* Builder::clear() {
        fields.clear();
        joins.clear();
        values.clear();
        clause = Ref<Clause>();
        _order.clear();
        _group.clear();
        offset_limit = OffsetLimit();
        
        field_descriptors.clear();
        
        return this;
    }
    
    String Builder::getJoins() {
        String ret;
        
        int len = (int)this->joins.length();
        if (len) {
            ret = this->joins[0].getPtr()->toString()+" ";
            for(int i=1; i<len; i++) {
                ret += this->joins[i].getPtr()->toString()+" ";
            }
        }
        
        return ret;
    }
    
    void Builder::select(String field) {
        fields.addField(escape(field));
    }
    
    void Builder::join(String table, Ref<Clause> clause) {
        joins.push(Ref<Join>(new Join(escape(table), clause)));
    }
    
    void Builder::leftJoin(String table, Ref<Clause> clause) {
        joins.push(Ref<Join>(new Join(escape(table), clause, "LEFT")));
    }
    
    void Builder::rightJoin(String table, Ref<Clause> clause) {
        joins.push(Ref<Join>(new Join(escape(table), clause, "RIGHT")));
    }
                           
    void Builder::outerJoin(String table, Ref<Clause> clause) {
        joins.push(Ref<Join>(new Join(escape(table), clause, "OUTER")));
    }
    
    void Builder::value(String name, String value) {
        values.add(escape(name), escape(value));
    }
    
    void Builder::setClause(Ref<Clause> clause) {
        this->clause = clause;
    }
    
    void Builder::order(String field, Order::DIRECTION direction) {
        _order.add(escape(field), direction);
    }
    
    void Builder::group(String field) {
        _group.addField(escape(field));
    }
    
    void Builder::offset(long long offset) {
        offset_limit.offset(offset);
    }
    
    void Builder::limit(int limit) {
        offset_limit.limit(limit);
    }
    
    void Builder::fieldDescriptor(Ref<FieldDescriptor> fd) {
        field_descriptors.push(fd);
    }
    
    Builder& Builder::setEngine(String engine) {
        this->engine = escape(engine);
        return *this;
    }
    
    Builder& Builder::setCharset(String charset) {
        this->charset = escape(charset);
        return *this;
    }
    
    Builder& Builder::setCollate(String collate) {
        this->collate = escape(collate);
        return *this;
    }
    
}
