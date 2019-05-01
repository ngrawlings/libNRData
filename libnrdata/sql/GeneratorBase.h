//
//  Generator.hpp
//  LibNrData
//
//  Created by Nyhl Rawlings on 01/05/2019.
//  Copyright © 2019 Liquidsoft Studio. All rights reserved.
//

#ifndef Generator_hpp
#define Generator_hpp

#include <stdio.h>
#include <libnrcore/memory/Array.h>
#include <libnrcore/memory/String.h>

namespace nrcore {
    
    class GeneratorBase {
    public:
        class Join {
        public:
            Join();
            virtual ~Join();
            
        protected:
            String table;
            String field1;
            String compritor;
            String field2;
        };
        
    public:
        GeneratorBase();
        virtual ~GeneratorBase();
        
    protected:
        String table;
        Array<String> select;
        
        unsigned long long offset;
        unsigned int limit;
    };
    
}

#endif /* Generator_hpp */
