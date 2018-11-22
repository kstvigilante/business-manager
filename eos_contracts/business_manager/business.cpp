#include "business.hpp"

void business :: createb(std::string businessName ,name businessOwner){
    require_auth(businessOwner);
    
    _bt.emplace(get_self(), [&](auto& p){
        p.id = _bt.available_primary_key();
        p.businessName = businessName;
        p.businessOwner = businessOwner;
        p.marketCap = 0;
        p.totalShares = 0;
        p.sharePrice = 0;
    });
}

void business::makepublic(uint64_t id, double marketCap, double totalShares){
    auto itr = _bt.find(id);
    eosio_assert(itr != _bt.end(), "No such business exist");
    eosio_assert(marketCap >0, "market cap cannot be 0 or less");
    eosio_assert(totalShares >0, "total shares cannot be zero or less");
    eosio_assert(itr->marketCap == 0 ,"business already public");

    _bt.modify(itr, get_self(), [&](auto& p){
        p.marketCap = marketCap;
        p.totalShares = totalShares;
        p.sharePrice = marketCap/totalShares;
    });
}

void business::newsharec(uint64_t id, double newsharecost){
    auto itr = _bt.find(id);
    eosio_assert(itr != _bt.end(), "No such business exist");
    eosio_assert(itr->marketCap > 0 ,"business not public yet");
    eosio_assert(newsharecost >0 , "new share price should not be less than or equal to 0");

    require_auth(itr->businessOwner);

    _bt.modify(itr, get_self(), [&](auto& p){
        p.sharePrice = newsharecost;
        p.marketCap = newsharecost * itr->totalShares;
    });
}

void business::newtshare(uint64_t id, double newtotalshare){
    auto itr = _bt.find(id);
    eosio_assert(itr != _bt.end(), "No such business exist");
    eosio_assert(itr->marketCap > 0 ,"business not public yet");
    eosio_assert(newtotalshare >0 ,"total shares cannot be 0 or less");

    require_auth(itr->businessOwner);

    _bt.modify(itr, get_self(), [&](auto& p){
        p.totalShares = newtotalshare;
        p.sharePrice = itr->marketCap/newtotalshare;
    });
}

void business::deletedata(){
    require_auth(get_self());

    auto itr = _bt.begin();
    while(itr != _bt.end()){
        itr = _bt.erase(itr);
    }
}

void business::hi(name user){
    print("hello ", name{user});
}