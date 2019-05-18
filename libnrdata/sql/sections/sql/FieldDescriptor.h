//
//  FieldDescriptor.hpp
//  LibNrData
//
//  Created by Nyhl Rawlings on 04/05/2019.
//  Copyright © 2019 Liquidsoft Studio. All rights reserved.
//

#ifndef FieldDescriptor_hpp
#define FieldDescriptor_hpp

#include <stdio.h>
#include <libnrcore/memory/Ref.h>
#include <libnrcore/memory/Array.h>
#include <libnrcore/memory/String.h>

namespace nrcore {
    namespace sql {
        
        class FieldDescriptor {
        public:
            typedef enum {
                PRIMARY,
                INDEX,
                UNIQUE,
                FULLTEXT
            } INDEX_TYPE;
            
            typedef struct {
                String name;
                INDEX_TYPE type;
            } _INDEX;
            
            typedef enum {
                TINYINT,
                SMALLINT,
                MEDIUMINT,
                INT,
                BIGINT,
                FLOAT,
                DOUBLE,
                DOUBLE_PRECISION,
                REAL,
                DECIMAL,
                BIT,
                SERIAL,
                BOOL,
                BOOLEAN,
                DEC,
                FIXED,
                NUMERIC,
                CHAR,
                VARCHAR,
                TINYTEXT,
                TEXT,
                MEDIUMTEXT,
                LONGTEXT,
                TINYBLOB,
                MEDIUMBLOB,
                BLOB,
                LONGBLOB,
                BINARY,
                VARBINARY,
                JSON,
                ENUM,
                SET,
                DATE,
                DATETIME,
                TIMESTAMP,
                TIME,
                YEAR,
                GEOMETRY,
                POINT,
                LINESTRING,
                POLYGON,
                MULTIPOINT,
                MULTILINESTRING,
                MULTIPOLYGON,
                GEOMETRYCOLLECTION
            } TYPE;
            
        public:
            FieldDescriptor(String name, TYPE type);
            FieldDescriptor(const FieldDescriptor& fd);
            virtual ~FieldDescriptor();
            
            FieldDescriptor& setParameter(String param);
            FieldDescriptor& setUnsigned(bool val);
            FieldDescriptor& setZeroFill(bool val);
            FieldDescriptor& setBinary(bool val);
            FieldDescriptor& notNull(bool val);
            FieldDescriptor& setDefault(String _default);
            
            FieldDescriptor& setExtra(String extra);
            
            FieldDescriptor& setAutoIncrement();
            FieldDescriptor& setUpdateCurrentDate();
            FieldDescriptor& setSerialDefaultValue();
            
            FieldDescriptor& setEncoding(String encoding);
            FieldDescriptor& setCollation(String collation);
            FieldDescriptor& setComment(String comment);
            
            FieldDescriptor& setIndex(INDEX_TYPE type);
            
            String getTypeString();
            
            virtual String toString();
            String getIndex();
            
        protected:
            String name;
            TYPE type;
            String parameter; // tipically the length displaied within the cli client, however it can be the enum values
            bool _unsigned;
            bool zerofill;
            bool binary;
            bool notnull;
            String _default;
            String extra;
            String encoding;
            String collation;
            String comment;
            
            Ref<_INDEX> index;
        };
    
    }
}

#endif /* FieldDescriptor_hpp */
