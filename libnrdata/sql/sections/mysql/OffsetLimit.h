//
//  OffsetLimit.hpp
//  LibNrData
//
//  Created by Nyhl Rawlings on 03/05/2019.
//  Copyright © 2019 Liquidsoft Studio. All rights reserved.
//

#ifndef OffsetLimit_hpp
#define OffsetLimit_hpp

#include <stdio.h>
#include <libnrcore/memory/Ref.h>
#include <libnrcore/memory/Array.h>
#include <libnrcore/memory/String.h>

namespace nrcore {
    
    class OffsetLimit {
    public:
        OffsetLimit();
        OffsetLimit(int limit);
        OffsetLimit(long long offset, int limit);
        virtual ~OffsetLimit();
        
        void offset(long long offset);
        void limit(int limit);
        
        String toString();
        
        
    protected:
        long long _offset;
        int _limit;
    };
    
}

#endif /* OffsetLimit_hpp */
