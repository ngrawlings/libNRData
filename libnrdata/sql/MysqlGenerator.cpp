//
//  MysqlGenerator.cpp
//  LibNrData
//
//  Created by Nyhl Rawlings on 01/05/2019.
//  Copyright © 2019 Liquidsoft Studio. All rights reserved.
//

#include "MysqlGenerator.h"

namespace nrcore {
    
    MysqlGenerator::MysqlGenerator() {
        
    }
    
    MysqlGenerator::~MysqlGenerator() {
        
    }
    
    String MysqlGenerator::sql(TYPE type) {
        switch(type) {
            case SELECT:
                return select();
                
            case INSERT:
                return insert();
                
            case UPDATE:
                return update();
                
            case DELETE:
                return _delete();
                
            case DROP:
                return drop();
        }
        return String("");
    }
    
    String MysqlGenerator::select() {
        String fields = this->fields.toString();
        String joins = this->getJoins();
        String where = this->clause.getPtr() ? this->clause.getPtr()->toString() : "";
        String order = this->order.toString();
        String group = this->group.toString();
        String limit = this->offset_limit.toString();
        
        String sql = String("SELECT % FROM `%`").arg(fields).arg(table);
        
        if (this->joins.length())
            sql += String(" %").arg(joins);
        
        if (where.length())
            sql += String(" WHERE %").arg(where);
        
        if (order.length())
            sql += String(" ORDER BY %").arg(order);
        
        if (group.length())
            sql += String(" GROUP BY %").arg(group);
        
        if (limit.length())
            sql += String(" LIMIT %").arg(limit);
        
        return sql;
    }
    
    String MysqlGenerator::insert() {
        String fields = this->values.getFields();
        String values = this->values.getValues();
        String where = this->clause.getPtr() ? this->clause.getPtr()->toString() : "";
        
        String sql = String("INSERT INTO `%` (%) VALUES (%)").arg(table).arg(fields).arg(values);
        
        if (where.length())
            sql += String(" WHERE %").arg(where);
        
        return sql;
    }
    
    String MysqlGenerator::update() {
        String values = this->values.toString();
        String where = this->clause.getPtr() ? this->clause.getPtr()->toString() : "";
        String limit = this->offset_limit.toString();
        
        String sql = String("UPDATE `%` SET %").arg(table).arg(values);
        
        if (where.length())
            sql += String(" WHERE %").arg(where);
        
        if (limit.length())
            sql += String(" LIMIT %").arg(limit);
        
        return sql;
    }
    
    String MysqlGenerator::_delete() {
        String where = this->clause.getPtr() ? this->clause.getPtr()->toString() : "";
        return String("DELETE FROM `%` WHERE %;").arg(table).arg(where);
    }
    
    String MysqlGenerator::drop() {
        return String("DROP TABLE `%`;").arg(table);
    }
    
    
    
}
