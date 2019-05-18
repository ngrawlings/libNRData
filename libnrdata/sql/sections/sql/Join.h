//
//  Join.hpp
//  LibNrData
//
//  Created by Nyhl Rawlings on 02/05/2019.
//  Copyright © 2019 Liquidsoft Studio. All rights reserved.
//

#ifndef Join_hpp
#define Join_hpp

#include <stdio.h>
#include <libnrcore/memory/Ref.h>
#include <libnrcore/memory/String.h>
#include "Clause.h"

namespace nrcore {
    namespace sql {
    
        class Join {
        public:
            Join(String table, Ref<Clause> clause, String type = "INNER");
            Join(const Join& join);
            virtual ~Join();
            
            String toString();
            
        private:
            String type;
            String table;
            Ref<Clause> clause;
        };
    
    }
}

#endif /* Join_hpp */
