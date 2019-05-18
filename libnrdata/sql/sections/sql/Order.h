//
//  Order.hpp
//  LibNrData
//
//  Created by Nyhl Rawlings on 02/05/2019.
//  Copyright © 2019 Liquidsoft Studio. All rights reserved.
//

#ifndef Order_hpp
#define Order_hpp

#include <stdio.h>
#include <libnrcore/memory/Ref.h>
#include <libnrcore/memory/Array.h>
#include <libnrcore/memory/String.h>

namespace nrcore {
    namespace sql {
        
        class Order {
        public:
            typedef enum {
                ASC,
                DESC
            } DIRECTION;
            
        public:
            Order();
            Order(const Order &order);
            virtual ~Order();
            
            void add(String field, DIRECTION direction);
            void clear();
            
            String toString();
            
        protected:
            typedef struct {
                String field;
                DIRECTION direction;
            } ORDER;
            
            Array< Ref<ORDER> > orders;
        };
    
    }
}

#endif /* Order_hpp */
