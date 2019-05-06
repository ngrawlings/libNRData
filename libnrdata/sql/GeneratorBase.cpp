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
        fields.addField(field);
    }
    
    void GeneratorBase::join(String table, Ref<Clause> clause) {
        joins.push(Ref<Join>(new Join(table, clause)));
    }
    
    void GeneratorBase::leftJoin(String table, Ref<Clause> clause) {
        joins.push(Ref<Join>(new Join(table, clause, "LEFT")));
    }
    
    void GeneratorBase::rightJoin(String table, Ref<Clause> clause) {
        joins.push(Ref<Join>(new Join(table, clause, "RIGHT")));
    }
                           
    void GeneratorBase::outerJoin(String table, Ref<Clause> clause) {
        joins.push(Ref<Join>(new Join(table, clause, "OUTER")));
    }
    
    void GeneratorBase::value(String name, String value) {
        values.add(name, value);
    }
    
    void GeneratorBase::setClause(Ref<Clause> clause) {
        this->clause = clause;
    }
    
    void GeneratorBase::order(String field, Order::DIRECTION direction) {
        _order.add(field, direction);
    }
    
    void GeneratorBase::group(String field) {
        _group.addField(field);
    }
    
    void GeneratorBase::offset(long long offset) {
        offset_limit.offset(offset);
    }
    
    void GeneratorBase::limit(int limit) {
        offset_limit.limit(limit);
    }
    
    void GeneratorBase::setEngine(String engine) {
        this->engine = engine;
    }
    
    void GeneratorBase::setCharset(String charset) {
        this->charset = charset;
    }
    
    void GeneratorBase::setCollate(String collate) {
        this->collate = collate;
    }
    
}
