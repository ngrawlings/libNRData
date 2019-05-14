//
//  Result.hpp
//  LibNrData
//
//  Created by Nyhl Rawlings on 01/05/2019.
//  Copyright © 2019 Liquidsoft Studio. All rights reserved.
//

#ifndef Result_hpp
#define Result_hpp

#include <libnrcore/memory/Array.h>
#include <libnrcore/memory/Memory.h>
#include <libnrcore/memory/String.h>

#include "../connectors/ConnectorBase.h"

namespace nrcore {
    
    class ResultSet;
    
    class Result {
    public:
        Result(ResultSet *result_set, Array<Memory> values);
        Result(const Result &result);
        virtual ~Result();
        
        String getString(int index);
        String getString(String name);
        
        int getInteger(int index);
        int getInteger(String name);
        
        unsigned long getUnsignedInteger(int index);
        unsigned long getUnsignedInteger(String name);
        
        double getDouble(int index);
        double getDouble(String name);
        
        Memory getBlob(int index);
        Memory getBlob(String name);
        
    protected:
        ResultSet *result_set;
        Array<Memory> values;
    };
    
}

#endif /* Result_hpp */
