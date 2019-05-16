//
//  MysqlConnector.cpp
//  LibNrData
//
//  Created by Nyhl Rawlings on 07/05/2019.
//  Copyright © 2019 Liquidsoft Studio. All rights reserved.
//

#include "MysqlConnector.h"

#include <libnrcore/exception/Exception.h>
#include <libnrdata/sql//builders/MysqlBuilder.h>

namespace nrcore {
    
    MysqlConnector::MysqlConnector(const char* host, int port, const char* username, const char* password, const char* database) {
        con = mysql_init(NULL);
        
        if (con == NULL)
            throw Exception(-1, mysql_error(con));
        
        if (mysql_real_connect(con, host, username, password, database, port, NULL, 0) == NULL)
            throw Exception(-1, mysql_error(con));
        
        setConnection(con);
    }
    
    MysqlConnector::~MysqlConnector() {
        
    }
    
    void MysqlConnector::execute(String sql) {
        if (mysql_query(con, sql))
            throw Exception(-1, mysql_error(con));
    }
    
    ResultSet MysqlConnector::query(String sql) {
        if (mysql_query(con, sql))
            throw Exception(mysql_errno(con), mysql_error(con));
        
        if (mysql_errno(con))
            throw Exception(mysql_errno(con), mysql_error(con));
        
        MYSQL_RES *result = mysql_store_result(con);
        
        int num_fields = mysql_num_fields(result);
        Array<String> columns;
        Array<Memory> row;

        MYSQL_FIELD *field;
        while((field = mysql_fetch_field(result))) {
            columns.push(String(field->name));
            row.push(Memory());
        }
        
        ResultSet res(this, columns);
        
        MYSQL_ROW mysql_row;
        unsigned long *lengths;
        
        while ((mysql_row = mysql_fetch_row(result))) {
            lengths = mysql_fetch_lengths(result);
            
            for(int i = 0; i < num_fields; i++)
                row[i] = Memory(mysql_row[i], lengths[i]+1);
            
            res.addRow(row);
        }
        
        mysql_free_result(result);
        return res;
    }
    
    bool MysqlConnector::exists(String table) {
        try {
            query(String("SELECT 1 FROM `schemas` LIMIT 1;"));
        } catch (Exception e) {
            return false;
        }
        return true;
    }
    
    Ref<Builder> MysqlConnector::getBuilder(String table) {
        return Ref<Builder>(new MysqlBuilder(con, table));
    }
    
}
