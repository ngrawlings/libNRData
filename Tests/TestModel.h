//
//  TestModel.hpp
//  Tests
//
//  Created by Nyhl Rawlings on 15/05/2019.
//  Copyright © 2019 Liquidsoft Studio. All rights reserved.
//

#ifndef TestModel_hpp
#define TestModel_hpp

#include <stdio.h>
#include <libnrdata/models/Model.h>

using namespace nrcore;

class TestModel : public Model {
public:
    TestModel(Connector* con);
    virtual ~TestModel();
    
protected:
    int revision();
    bool migrate(int revision);
    
};

#endif /* TestModel_hpp */
