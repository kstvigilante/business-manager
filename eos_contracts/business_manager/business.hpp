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

        [[eosio::action]]
        void makepublic(uint64_t id, double marketCap, double totalShares);

        [[eosio::action]]
        void deletedata();

        [[eosio::action]]
        void newsharec(uint64_t id, double newshareprice);

        [[eosio::action]]
        void newtshare(uint64_t id, double newtotalshare);

        [[eosio::action]]
        void newbname(uint64_t id, std::string newbusinessname);

        [[eosio::action]]
        void totalb();

        [[eosio::action]]
        void hi(name user);

        struct[[eosio :: table]] businessSt{
            uint64_t id;
            std::string businessName;
            name businessOwner;
            double marketCap;
            double totalShares;
            double sharePrice;
            uint64_t primary_key() const { return id; }
        };

        typedef eosio::multi_index<"busi"_n, businessSt> businesstb;
        businesstb _bt;
};

EOSIO_DISPATCH(business, (createb)(makepublic)(deletedata)(newsharec)(newtshare)(newbname)
              (totalb)(hi))