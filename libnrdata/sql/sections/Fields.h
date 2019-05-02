//
//  Fields.hpp
//  LibNrData
//
//  Created by Nyhl Rawlings on 02/05/2019.
//  Copyright © 2019 Liquidsoft Studio. All rights reserved.
//

#ifndef Fields_hpp
#define Fields_hpp

#include <stdio.h>
#include <libnrcore/memory/Array.h>
#include <libnrcore/memory/String.h>

namespace nrcore {
    
    class Fields {
    public:
        Fields();
        virtual ~Fields();
        
        void addField(String field);
        
        String toString();
        
    protected:
        Array<String> fields;
    };
    
}

#endif /* Fields_hpp */
