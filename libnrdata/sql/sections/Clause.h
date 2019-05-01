//
//  Clause.hpp
//  LibNrData
//
//  Created by Nyhl Rawlings on 01/05/2019.
//  Copyright © 2019 Liquidsoft Studio. All rights reserved.
//

#ifndef Clause_hpp
#define Clause_hpp

#include <stdio.h>
#include <libnrcore/memory/String.h>

namespace nrcore {
    
    class Clause {
    public:
        typedef enum {
            STRING,
            FIELD,
            RAW
        } TYPE;
        
        class Value {
        public:
            Value(TYPE type, String value);
            Value(const Value &value);
            virtual ~Value();
            
            TYPE type();
            String value();
            
            String toString();
            
        protected:
            TYPE _type;
            String _value;
        };
        
    public:
        Clause(String f1, String comparitor, String f2);
        Clause(Value f1, String comparitor, Value f2);
        Clause(const Clause &clause);
        virtual ~Clause();
        
        String toString();
        
    protected:
        Value field1, field2;
        String comparitor;
    };
    
}

#endif /* Clause_hpp */
