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

#include "../sql/FieldDescriptor.h"

namespace nrcore {
    
    namespace mysql {
        
        class FieldDescriptor : public sql::FieldDescriptor {
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
                TINYINT             = 0,
                SMALLINT            = 1,
                MEDIUMINT           = 2,
                INT                 = 4,
                BIGINT              = 5,
                FLOAT               = 6,
                DOUBLE              = 7,
                DOUBLE_PRECISION    = 8,
                REAL                = 9,
                DECIMAL             = 10,
                BIT                 = 11,
                SERIAL              = 12,
                BOOL                = 13,
                BOOLEAN             = 14,
                DEC                 = 15,
                FIXED               = 16,
                NUMERIC             = 17,
                CHAR                = 18,
                VARCHAR             = 19,
                TINYTEXT            = 20,
                TEXT                = 21,
                MEDIUMTEXT          = 22,
                LONGTEXT            = 23,
                TINYBLOB            = 24,
                MEDIUMBLOB          = 25,
                BLOB                = 26,
                LONGBLOB            = 27,
                BINARY              = 28,
                VARBINARY           = 29,
                JSON                = 30,
                ENUM                = 31,
                SET                 = 32,
                DATE                = 33,
                DATETIME            = 34,
                TIMESTAMP           = 35,
                TIME                = 36,
                YEAR                = 37,
                GEOMETRY            = 38,
                POINT               = 39,
                LINESTRING          = 40,
                POLYGON             = 41,
                MULTIPOINT          = 42,
                MULTILINESTRING     = 43,
                MULTIPOLYGON        = 44,
                GEOMETRYCOLLECTION  = 45
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
            
            FieldDescriptor& setIndex(String type);
            
            static String getTypeString(TYPE type);
            static TYPE getTypeByString(String type);
            
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
            
            static const char* field_types[];
        };
    
    }
    
}

#endif /* FieldDescriptor_hpp */
