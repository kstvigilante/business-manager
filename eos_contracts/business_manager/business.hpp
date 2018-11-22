#include <eosiolib/eosio.hpp>
#include <eosiolib/print.hpp>

using namespace eosio;

class [[eosio::contract]] business : public eosio::contract{
    public:

        business(eosio::name receiver, eosio::name code, eosio::datastream<const char*> ds)
        : eosio::contract(receiver, code, ds), _bt(receiver, code.value)
        {
            
        }
        
        [[eosio::action]]
        void createb(std::string businessName, name businessOwner);

        struct[[eosio :: table]] businessSt{
            uint64_t id;
            std::string businessName;
            name businessOwner;
            uint64_t marketCap;
            uint64_t totalShares;
            uint64_t sharePrice;
            uint64_t primary_key() const { return id; }
        };

        typedef eosio::multi_index<"busi"_n, businessSt> businesstb;
        businesstb _bt;
};

EOSIO_DISPATCH(business, (createb))