//
//  Schemas.cpp
//  LibNrData
//
//  Created by Nyhl Rawlings on 14/05/2019.
//  Copyright © 2019 Liquidsoft Studio. All rights reserved.
//

#include "Schemas.h"

#include <libnrcore/exception/Exception.h>

#include <libnrdata/connectors/Connector.h>

#include <libnrdata/sql/sections/mysql/ClauseValue.h>

namespace nrcore {
    
    Schemas::Schemas(Connector* con) : con(con) {
        if (!exists())
            create();
    }
    
    Schemas::~Schemas() {
        
    }
    
    void Schemas::setConnection(Connector* con) {
        this->con = con;
    }
    
    int Schemas::getRevision(String table) {
        Builder* b = con->getBuilder("schemas").getPtr();
        b->select("revision");
        b->setClause(Ref<Clause>(new ClauseValue(b, "table", "=", table)));
        
        ResultSet res = con->query(b->sql(Builder::SELECT));
        if (res.length())
            return res.row(0).getInteger(0);
        
        return 0;
    }
    
    void Schemas::setRevision(String table, int revision) {
        Builder* b = con->getBuilder("schemas").getPtr();
        
        b->value("revision", String("%").arg(revision));
        b->setClause(Ref<Clause>(new ClauseValue(b, "table", "=", table)));
        
        con->execute(b->sql(Builder::UPDATE));
    }
    
    bool Schemas::exists() {
        try {
            con->query(String("SELECT 1 FROM `schemas` LIMIT 1;"));
        } catch (Exception e) {
            return false;
        }
        return true;
    }
    
    void Schemas::create() {
        Ref<Builder> refb = con->getBuilder("schemas");
        Builder* b = refb.getPtr();
        
        FieldDescriptor f1("id", FieldDescriptor::INT);
        f1.setUnsigned(true);
        f1.setIndex(FieldDescriptor::PRIMARY);
        f1.setAutoIncrement();
        
        FieldDescriptor f2("table", FieldDescriptor::VARCHAR);
        f2.setParameter("32");
        f2.notNull(true);
        
        FieldDescriptor f3("revision", FieldDescriptor::INT);
        f3.notNull(true);
        f3.setDefault("0");
        
        b->fieldDescriptor(Ref<FieldDescriptor>(new FieldDescriptor(f1)));
        b->fieldDescriptor(Ref<FieldDescriptor>(new FieldDescriptor(f2)));
        b->fieldDescriptor(Ref<FieldDescriptor>(new FieldDescriptor(f3)));
        b->setEngine("InnoDB");
        b->setCharset("utf8mb4");
        b->setCollate("utf8mb4_0900_ai_ci");
        
        con->execute(b->sql(Builder::CREATE));
    }
    
}
