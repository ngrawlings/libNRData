//
//  Generator.cpp
//  LibNrData
//
//  Created by Nyhl Rawlings on 01/05/2019.
//  Copyright © 2019 Liquidsoft Studio. All rights reserved.
//

#include "GeneratorBase.h"

namespace nrcore {
 
    GeneratorBase::GeneratorBase() {
        
    }
    
    GeneratorBase::~GeneratorBase() {
        
    }
    
    String GeneratorBase::getJoins() {
        String ret;
        
        int len = (int)this->joins.length();
        if (len) {
            ret = this->joins[0].getPtr()->toString()+" ";
            for(int i=1; i<len; i++) {
                ret += this->joins[i].getPtr()->toString()+" ";
            }
        }
        
        return ret;
    }
    
}
