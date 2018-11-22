#include "business.hpp"

void business :: createb(std::string businessName ,name businessOwner){
    require_auth(businessOwner);
    
    _bt.emplace(get_self(), [&](auto& p){
        p.id = _bt.available_primary_key();
        p.businessName = businessName;
        p.businessOwner = businessOwner;
    });
}