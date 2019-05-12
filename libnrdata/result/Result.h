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
#include <libnrcore/memory/String.h>

#include "../connectors/ConnectorBase.h"

namespace nrcore {
    
    class Result {
    public:
        Result(ConnectorBase *con, Array<String> values);
        virtual ~Result();
        
    protected:
        ConnectorBase *con;
        Array<String> values;
    };
    
}

#endif /* Result_hpp */
