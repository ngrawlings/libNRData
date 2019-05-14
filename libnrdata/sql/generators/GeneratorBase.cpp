//
//  Generator.cpp
//  LibNrData
//
//  Created by Nyhl Rawlings on 01/05/2019.
//  Copyright © 2019 Liquidsoft Studio. All rights reserved.
//

#include "GeneratorBase.h"

namespace nrcore {
 
    GeneratorBase::GeneratorBase(String table) : table(table) {
        
    }
    
    GeneratorBase::GeneratorBase(const GeneratorBase& genbase) {
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
    
    GeneratorBase::~GeneratorBase() {
        
    }
    
    String GeneratorBase::getJoins() {
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
    
    void GeneratorBase::select(String field) {
        fields.addField(escape(field));
    }
    
    void GeneratorBase::join(String table, Ref<Clause> clause) {
        joins.push(Ref<Join>(new Join(escape(table), clause)));
    }
    
    void GeneratorBase::leftJoin(String table, Ref<Clause> clause) {
        joins.push(Ref<Join>(new Join(escape(table), clause, "LEFT")));
    }
    
    void GeneratorBase::rightJoin(String table, Ref<Clause> clause) {
        joins.push(Ref<Join>(new Join(escape(table), clause, "RIGHT")));
    }
                           
    void GeneratorBase::outerJoin(String table, Ref<Clause> clause) {
        joins.push(Ref<Join>(new Join(escape(table), clause, "OUTER")));
    }
    
    void GeneratorBase::value(String name, String value) {
        values.add(escape(name), escape(value));
    }
    
    void GeneratorBase::setClause(Ref<Clause> clause) {
        this->clause = clause;
    }
    
    void GeneratorBase::order(String field, Order::DIRECTION direction) {
        _order.add(escape(field), direction);
    }
    
    void GeneratorBase::group(String field) {
        _group.addField(escape(field));
    }
    
    void GeneratorBase::offset(long long offset) {
        offset_limit.offset(offset);
    }
    
    void GeneratorBase::limit(int limit) {
        offset_limit.limit(limit);
    }
    
    void GeneratorBase::fieldDescriptor(Ref<FieldDescriptor> fd) {
        field_descriptors.push(fd);
    }
    
    void GeneratorBase::setEngine(String engine) {
        this->engine = escape(engine);
    }
    
    void GeneratorBase::setCharset(String charset) {
        this->charset = escape(charset);
    }
    
    void GeneratorBase::setCollate(String collate) {
        this->collate = escape(collate);
    }
    
}
