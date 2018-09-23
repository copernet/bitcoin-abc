//
// Created by Bitmain on 2018/9/18.
//

#ifndef WORMHOLE_ERC721_H
#define WORMHOLE_ERC721_H

#include <stdint.h>
#include <stdio.h>
#include <string>
#include <vector>
#include <map>

enum ERC721REASON{
    OK,
    ERC721_PROPERTY_EXSIT,
    ERC721_MINT_BURNADDR
};

class ERC721Token{
public:
    struct approvalNews{
        std::string  approvalAddress;
        bool        approval;
    };

private:
    //  Mapping from token ID to owner
    std::map<uint256, std::string>  tokenOwner;

    //  Mapping from token ID to owner
    std::map<uint256, std::string> tokenApprovals;

    //  Mapping from owner to number of owned token
    std::map<std::string, uint256> ownedTokenCount;

    //  Mapping from owner to operator approvals
    std::map<std::string, approvalNews> operatorApprovals;

    std::string     issuer;
    std::string     name;
    std::string     symbol;
    uint256         max_tokens;

    //  Mapping from owner to list of owned token IDs
    std::map<std::string, std::vector<uint256>> ownedTokens;

    //  Mapping from token ID to index of the owner tokens list
    std::map<uint256, uint256>  ownedTokensIndex;

    //  Array with all token ids, used for enumeration
    std::vector<uint256>    allTokens;

    //  Mapping from token id to position in the allTokens array
    std::map<uint256, uint256>  allTokensIndex;

    //  Optional mapping for token URIs
    std::map<uint256, std::string>  tokenURIs;

public:
    std::string getPropertyName(){
        return name;
    }
    std::string getPropertySymbol(){
        return symbol;
    }
    std::string getPropertyIssuer(){
        return issuer;
    }
    uint256 getMaxIssueTokens(){
        return max_tokens;
    }

    ERC721REASON mint(std::string toAddr, uint256 tokenID){
        return OK;
    }

    uint256 balanceOf(std::string addr){
        if(addr == burnwhc_address){
            return -1;
        }
        auto iter = ownedTokenCount.find(addr);
        if (iter != ownedTokenCount.end()){
            return iter->second;
        }
        return 0;
    }

    bool ownerOf(uint256 tokenID, std::string& addr){
        auto iter = tokenOwner.find(tokenID);
        if (iter != tokenOwner.end()){
            if (iter->second != burnwhc_address){
                addr = iter;
                return true;
            }
        }
        return false;
    }

    bool approve(std::string txsender, std::string to, uint256 tokenID){
        return true;
    }

    bool getApproved(uint256 tokenID){
        return true;
    }

    bool setApprovalForAll(std::string txsender, std::string to, bool approved){
        return true;
    }

    bool isApprovedForAll(std::string owner, std::string operatorAddr){
        return true;
    }

    bool transferFrom(std::string txsender, std::string from, std::string to, uint256 tokenID){
        return true;
    }

    bool exists(uint256 tokenID){
        return true;
    }

    bool isApprovedOrOwner(std::string spender, uint256 tokenID){
        return true;
    }

    bool burn(std::string owner, uint256 tokenID){
        return true;
    }

    bool clearApproval(std::string owner, uint256 tokenID){
        return true;
    }

    bool addTokenTo(std::string to, uint256 tokenID){
        return true;
    }

    bool removeTokenFrom(std::string from, uint256 tokenID){
        return true;
    }
    
};

class CMPSPERC721Info : public CDBBase {
public:

};

#endif //WORMHOLE_ERC721_H
