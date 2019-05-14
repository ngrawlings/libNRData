//
//  Generator.cpp
//  LibNrData
//
//  Created by Nyhl Rawlings on 01/05/2019.
//  Copyright © 2019 Liquidsoft Studio. All rights reserved.
//

#include "BuilderBase.h"

namespace nrcore {
 
    BuilderBase::BuilderBase(String table) : table(table) {
        
    }
    
    BuilderBase::BuilderBase(const BuilderBase& genbase) {
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
    
    BuilderBase::~BuilderBase() {
        
    }
    
    String BuilderBase::getJoins() {
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
    
    void BuilderBase::select(String field) {
        fields.addField(escape(field));
    }
    
    void BuilderBase::join(String table, Ref<Clause> clause) {
        joins.push(Ref<Join>(new Join(escape(table), clause)));
    }
    
    void BuilderBase::leftJoin(String table, Ref<Clause> clause) {
        joins.push(Ref<Join>(new Join(escape(table), clause, "LEFT")));
    }
    
    void BuilderBase::rightJoin(String table, Ref<Clause> clause) {
        joins.push(Ref<Join>(new Join(escape(table), clause, "RIGHT")));
    }
                           
    void BuilderBase::outerJoin(String table, Ref<Clause> clause) {
        joins.push(Ref<Join>(new Join(escape(table), clause, "OUTER")));
    }
    
    void BuilderBase::value(String name, String value) {
        values.add(escape(name), escape(value));
    }
    
    void BuilderBase::setClause(Ref<Clause> clause) {
        this->clause = clause;
    }
    
    void BuilderBase::order(String field, Order::DIRECTION direction) {
        _order.add(escape(field), direction);
    }
    
    void BuilderBase::group(String field) {
        _group.addField(escape(field));
    }
    
    void BuilderBase::offset(long long offset) {
        offset_limit.offset(offset);
    }
    
    void BuilderBase::limit(int limit) {
        offset_limit.limit(limit);
    }
    
    void BuilderBase::fieldDescriptor(Ref<FieldDescriptor> fd) {
        field_descriptors.push(fd);
    }
    
    void BuilderBase::setEngine(String engine) {
        this->engine = escape(engine);
    }
    
    void BuilderBase::setCharset(String charset) {
        this->charset = escape(charset);
    }
    
    void BuilderBase::setCollate(String collate) {
        this->collate = escape(collate);
    }
    
}
