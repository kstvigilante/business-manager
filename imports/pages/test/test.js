import "./test.html";
import "../../templates/header/header.js";
import "../../templates/footer/footer.js";
import Eos from "eosjs";
import { get } from "https";

eosConfig = {
    chainId: "e70aaab8997e1dfce58fbfac80cbbb8fecec7b99cf982a9444273cbc64c41473", // 32 byte (64 char) hex string
    keyProvider: ['5Jur4pK1Rb8xvdfNUUZJq5JE36HQUd9PNouWwjUdbWw7cK8ZuUo'],
    // WIF string or array of keys..
    httpEndpoint: 'https://jungle2.cryptolions.io:443',
    expireInSeconds: 60,
    broadcast: true,
    verbose: false, // API activity
    sign: true
}

const eos = Eos(eosConfig);

/* async function getCompanyList(){
    let businessdata = await eos.getTableRows({
        code: "businessutop",
        scope: "businessutop",
        table: "businesstb",
        limit: "50",
        json: true,
    });

    var companyList = [];
    for(var i=0; i<businessdata.rows.length;i++){
        companyList.push(businessdata.rows[i]);
    }
    console.log("hey")
    return companyList;
} */

Template.App_test.helpers({
    async test22(){
        let businessdata = await eos.getTableRows({
            code: "businessutop",
            scope: "businessutop",
            table: "businesstb",
            limit: "50",
            json: true,
        });
    
        var companyList = [];
        for(var i=0; i<businessdata.rows.length;i++){
            companyList.push(businessdata.rows[i]);
        }
        console.log("hey")
        return companyList;
    }
});

Template.App_test.onRendered(async function(){

})