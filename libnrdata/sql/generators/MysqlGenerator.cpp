//
//  MysqlGenerator.cpp
//  LibNrData
//
//  Created by Nyhl Rawlings on 01/05/2019.
//  Copyright © 2019 Liquidsoft Studio. All rights reserved.
//

#include "MysqlGenerator.h"

#include <libnrcore/exception/Exception.h>


namespace nrcore {
    
    MysqlGenerator::MysqlGenerator(MYSQL *mysql, String name) : GeneratorBase(name), mysql(mysql) {
        
    }
    
    MysqlGenerator::MysqlGenerator(const MysqlGenerator& gen) : GeneratorBase(gen), mysql(gen.mysql) {
        
    }
    
    MysqlGenerator::~MysqlGenerator() {
        
    }
    
    String MysqlGenerator::escape(String str) {
        char *to = new char[(str.length()*2)+1];
        unsigned long len = mysql_real_escape_string(mysql, to, str.operator char *(), str.length());
        
        String ret(to, len);
        
        delete [] to;
        return ret;
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
                
            case CREATE:
                return create();
                
            case DROP:
                return drop();
        }
        
        throw Exception(-1,  "Reached non executable point");
    }
    
    String MysqlGenerator::select() {
        String fields = this->fields.toString();
        String joins = this->getJoins();
        String where = this->clause.getPtr() ? this->clause.getPtr()->toString() : "";
        String order = this->_order.toString();
        String group = this->_group.toString();
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
    
    String MysqlGenerator::create() {
        int len = (int)field_descriptors.length();
        if (len) {
            String fields = field_descriptors[0].getPtr()->toString();
            String indexes = field_descriptors[0].getPtr()->getIndex();
            
            for (int i=1; i<len; i++) {
                fields += String(", ")+field_descriptors[i].getPtr()->toString();
                
                String index = field_descriptors[i].getPtr()->getIndex();
                if (index.length())
                    indexes += String(", ")+index;
            }
            
            return String("CREATE TABLE `%` (%, %) ENGINE=% DEFAULT CHARSET=% COLLATE=%;")
                    .arg(table).arg(fields).arg(indexes).arg(engine).arg(charset).arg(collate);
        }
        
        throw Exception(-1, "No field descriptors");
    }
    
    String MysqlGenerator::drop() {
        return String("DROP TABLE `%`;").arg(table);
    }
    
}
