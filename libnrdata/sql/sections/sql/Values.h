//
//  Values.hpp
//  LibNrData
//
//  Created by Nyhl Rawlings on 03/05/2019.
//  Copyright © 2019 Liquidsoft Studio. All rights reserved.
//

#ifndef Values_hpp
#define Values_hpp

#include <stdio.h>
#include <libnrcore/memory/Ref.h>
#include <libnrcore/memory/Array.h>
#include <libnrcore/memory/String.h>

namespace nrcore {
    namespace sql {
 
        class Values {
        public:
            Values();
            Values(const Values& values);
            virtual ~Values();
            
            void add(String field, String value);
            void clear();
            
            String toString();
            
            String getFields();
            String getValues();
            
        protected:
            typedef struct {
                String field;
                String value;
            } VALUE;
            
            Array< Ref<VALUE> > values;
        };
    
    }
}

#endif /* Values_hpp */
