// Copyright (c) 2010 Satoshi Nakamoto
// Copyright (c) 2009-2017 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <chainparams.h>
#include <consensus/merkle.h>

#include <tinyformat.h>
#include <util.h>
#include <utilstrencodings.h>

#include <assert.h>

#include <chainparamsseeds.h>

static CBlock CreateGenesisBlock(const char* pszTimestamp, const CScript& genesisOutputScript, uint32_t nTime, uint32_t nNonce, uint32_t nBits, int32_t nVersion, const CAmount& genesisReward)
{
    CMutableTransaction txNew;
    txNew.nVersion = 1;
    txNew.vin.resize(1);
    txNew.vout.resize(1);
    txNew.vin[0].scriptSig = CScript() << 486604799 << CScriptNum(4) << std::vector<unsigned char>((const unsigned char*)pszTimestamp, (const unsigned char*)pszTimestamp + strlen(pszTimestamp));
    txNew.vout[0].nValue = genesisReward;
    txNew.vout[0].scriptPubKey = genesisOutputScript;

    CBlock genesis;
    genesis.nTime    = nTime;
    genesis.nBits    = nBits;
    genesis.nNonce   = nNonce;
    genesis.nVersion = nVersion;
    genesis.vtx.push_back(MakeTransactionRef(std::move(txNew)));
    genesis.hashPrevBlock.SetNull();
    genesis.hashMerkleRoot = BlockMerkleRoot(genesis);
    return genesis;
}

/**
 * Build the genesis block. Note that the output of its generation
 * transaction cannot be spent since it did not originally exist in the
 * database.
 *
 * CBlock(hash=000000000019d6, ver=1, hashPrevBlock=00000000000000, hashMerkleRoot=4a5e1e, nTime=1231006505, nBits=1d00ffff, nNonce=2083236893, vtx=1)
 *   CTransaction(hash=4a5e1e, ver=1, vin.size=1, vout.size=1, nLockTime=0)
 *     CTxIn(COutPoint(000000, -1), coinbase 04ffff001d0104455468652054696d65732030332f4a616e2f32303039204368616e63656c6c6f72206f6e206272696e6b206f66207365636f6e64206261696c6f757420666f722062616e6b73)
 *     CTxOut(nValue=50.00000000, scriptPubKey=0x5F1DF16B2B704C8A578D0B)
 *   vMerkleTree: 4a5e1e
 */
static CBlock CreateGenesisBlock(uint32_t nTime, uint32_t nNonce, uint32_t nBits, int32_t nVersion, const CAmount& genesisReward)
{
    const char* pszTimestamp = "Visa, Mastercard Near Settlement Over Swipe Fees - WSJ 06/28/2018";
    const CScript genesisOutputScript = CScript() << ParseHex("04678afdb0fe5548271967f1a67130b7105cd6a828e03909a67962e0ea1f61deb649f6bc3f4cef38c4f35504e51ec112de5c384df7ba0b8d578a4c702b6bf11d5f") << OP_CHECKSIG;
    return CreateGenesisBlock(pszTimestamp, genesisOutputScript, nTime, nNonce, nBits, nVersion, genesisReward);
}

void CChainParams::UpdateVersionBitsParameters(Consensus::DeploymentPos d, int64_t nStartTime, int64_t nTimeout)
{
    consensus.vDeployments[d].nStartTime = nStartTime;
    consensus.vDeployments[d].nTimeout = nTimeout;
}

/**
 * Main network
 */
/**
 * What makes a good checkpoint block?
 * + Is surrounded by blocks with reasonable timestamps
 *   (no blocks before with a timestamp after, none after with
 *    timestamp before)
 * + Contains no strange transactions
 */

class CMainParams : public CChainParams {
public:
    CMainParams() {
        strNetworkID = "main";
        consensus.nSubsidyHalvingInterval = 3153600;
        consensus.BIP16Height = 0; 
        consensus.BIP34Height = 0;
        consensus.BIP34Hash = uint256S("0x3ae85767ad3ec3dc70877cef8e256fa2244f9f3de2fb8a43c5be972dc1db08a1");
        consensus.BIP65Height = 0; 
        consensus.BIP66Height = 0; 
        consensus.powLimit = uint256S("00000fffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"); 
        consensus.nPowTargetTimespan = 15 * 60; // 3.5 days
        consensus.nPowTargetSpacing = 0.5 * 60;
        consensus.fPowAllowMinDifficultyBlocks = false;
        consensus.fPowNoRetargeting = false;
        consensus.nRuleChangeActivationThreshold = 90; // 75% of 120
        consensus.nMinerConfirmationWindow = 120; // nPowTargetTimespan / nPowTargetSpacing * 4
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].bit = 28;
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].nStartTime = 1530217200; 
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].nTimeout = 1563663600; 
        
        // Deployment of BIP68, BIP112, and BIP113.
        consensus.vDeployments[Consensus::DEPLOYMENT_CSV].bit = 0;
        consensus.vDeployments[Consensus::DEPLOYMENT_CSV].nStartTime = 1530217200; 
        consensus.vDeployments[Consensus::DEPLOYMENT_CSV].nTimeout = 1563663600; 

        // Deployment of SegWit (BIP141, BIP143, and BIP147)
        consensus.vDeployments[Consensus::DEPLOYMENT_SEGWIT].bit = 1;
        consensus.vDeployments[Consensus::DEPLOYMENT_SEGWIT].nStartTime = 1530217200; 
        consensus.vDeployments[Consensus::DEPLOYMENT_SEGWIT].nTimeout = 1563663600; 

        // The best chain should have at least this much work.
        consensus.nMinimumChainWork = uint256S("0x01");

        // By default assume that the signatures in ancestors of this block are valid.
        consensus.defaultAssumeValid = uint256S("0x3ae85767ad3ec3dc70877cef8e256fa2244f9f3de2fb8a43c5be972dc1db08a1"); //genesis

        /**
         * The message start string is designed to be unlikely to occur in normal data.
         * The characters are rarely used upper ASCII, not valid as UTF-8, and produce
         * a large 32-bit integer with any alignment.
         */
        pchMessageStart[0] = 0xcd;
        pchMessageStart[1] = 0xd0;
        pchMessageStart[2] = 0xb1;
        pchMessageStart[3] = 0xdc;
        nDefaultPort = 421;
        nPruneAfterHeight = 100000;

        genesis = CreateGenesisBlock(1530217200, 4662255, 0x1e0631b5, 1, 75 * COIN);
        consensus.hashGenesisBlock = genesis.GetHash();
        assert(consensus.hashGenesisBlock == uint256S("0x3ae85767ad3ec3dc70877cef8e256fa2244f9f3de2fb8a43c5be972dc1db08a1"));
        assert(genesis.hashMerkleRoot == uint256S("0x45e37fb95121169542534355cb8b11f99cebfbe776d20154fa34ffcdfcb7510c"));

       //NO DNS SEEDS YET
        // Note that of those with the service bits flag, most only support a subset of possible options
       /* vSeeds.emplace_back("seed-a.thehashcoin.loshan.co.uk");
        vSeeds.emplace_back("dnsseed.thrasher.io");
        vSeeds.emplace_back("dnsseed.thehashcointools.com");
        vSeeds.emplace_back("dnsseed.thehashcoinpool.org");
        vSeeds.emplace_back("dnsseed.koin-project.com");
*/
        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1,51);
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1,5);
        base58Prefixes[SCRIPT_ADDRESS2] = std::vector<unsigned char>(1,65);
        base58Prefixes[SECRET_KEY] =     std::vector<unsigned char>(1,176);
        base58Prefixes[EXT_PUBLIC_KEY] = {0x01, 0x8D, 0x1E, 0x0D};
        base58Prefixes[EXT_SECRET_KEY] = {0x02, 0xE3, 0xAC, 0xD2};

        bech32_hrp = "thc";

       vFixedSeeds = std::vector<SeedSpec6>(pnSeed6_main, pnSeed6_main + ARRAYLEN(pnSeed6_main));

        fDefaultConsistencyChecks = false;
        fRequireStandard = true;
        fMineBlocksOnDemand = false;

        checkpointData = {
            {
              // these checkpoint blocks are from a previous version of TheHashCoins block chain and are no longer valid.
              /*  { 2126, uint256S("0xc1958769f60417cd6d1753fd082f2ec0489935c8e59814fb87c410c8ba02913c")},
                { 4446, uint256S("0xa66429c4b9f558f6dd3b31002d36e4c1c1fca1a85fb673d98494ccd3989c05e6")},
                { 8858, uint256S("0x7d94fde73750f40f8b74720db826134799feab16dc4a8ec5912dbc154f7d23dd")},
                { 8933, uint256S("0x8ae28ea75ae037b8875544030bc39ac26642bb03a8cb396527c51a148909563a")},
                { 8938, uint256S("0xe34f08b9e58b7b7d4cdd622fb3aa45513a23499460d58e0f53b8e58cb8a5f718")},
                { 8942, uint256S("0x602edf1859b7f9a6af809f1d9b0e6cb66fdc1d4d9dcd7a4bec03e12a1ccd153d")},
                { 8957, uint256S("0xaa56b234134edc56ff499128cfea44e82190acc3949a8333e7db420ee52a5bca")},
                { 9699, uint256S("0xd7910e1691aa1dcde5f93f2f4cba59871626abcd30d7bf886d3557de07b9c858")},
                */

            
            }

        };

        chainTxData = ChainTxData{
            // Data as of genesis
              1530217200, // * UNIX timestamp of last known number of transactions
              0,  // * total number of transactions between genesis and that timestamp
                    //   (the tx=... number in the SetBestChain debug.log lines)
              0.00001482293722014185     // * estimated number of transactions per second after that timestamp
        };
    }
};

/**
 * Testnet (NOT YET VALID)
 */
class CTestNetParams : public CChainParams {
public:
    CTestNetParams() {
        strNetworkID = "test";
        consensus.nSubsidyHalvingInterval = 840000;
        consensus.BIP16Height = 0; // always enforce P2SH BIP16 on regtest
        consensus.BIP34Height = 0;
        consensus.BIP34Hash = uint256S("0x3ae85767ad3ec3dc70877cef8e256fa2244f9f3de2fb8a43c5be972dc1db08a1");
        consensus.BIP65Height = 0; 
        consensus.BIP66Height = 0; 
        consensus.powLimit = uint256S("00000fffffffffffffffffffffffffffffffffffffffffffffffffffffffffff");
        consensus.nPowTargetTimespan = 3.5 * 24 * 60 * 60; // 3.5 days
        consensus.nPowTargetSpacing = 2.5 * 60;
        consensus.fPowAllowMinDifficultyBlocks = true;
        consensus.fPowNoRetargeting = false;
        consensus.nRuleChangeActivationThreshold = 1512; // 75% for testchains
        consensus.nMinerConfirmationWindow = 2016; // nPowTargetTimespan / nPowTargetSpacing
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].bit = 28;
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].nStartTime = 1530217200; 
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].nTimeout = 1563663600;

        // Deployment of BIP68, BIP112, and BIP113.
        consensus.vDeployments[Consensus::DEPLOYMENT_CSV].bit = 0;
        consensus.vDeployments[Consensus::DEPLOYMENT_CSV].nStartTime = 1530217200; 
        consensus.vDeployments[Consensus::DEPLOYMENT_CSV].nTimeout = 1563663600; 

        // Deployment of SegWit (BIP141, BIP143, and BIP147)
        consensus.vDeployments[Consensus::DEPLOYMENT_SEGWIT].bit = 1;
        consensus.vDeployments[Consensus::DEPLOYMENT_SEGWIT].nStartTime = 1530217200; 
        consensus.vDeployments[Consensus::DEPLOYMENT_SEGWIT].nTimeout = 1563663600; 

        // The best chain should have at least this much work.
        consensus.nMinimumChainWork = uint256S("0x01");

        // By default assume that the signatures in ancestors of this block are valid.
        consensus.defaultAssumeValid = uint256S("0x3ae85767ad3ec3dc70877cef8e256fa2244f9f3de2fb8a43c5be972dc1db08a1"); 
        // not yet unique values for testnet
        pchMessageStart[0] = 0xfd;
        pchMessageStart[1] = 0xd2;
        pchMessageStart[2] = 0xc8;
        pchMessageStart[3] = 0xf1;
        nDefaultPort = 19335;
        nPruneAfterHeight = 1000;
        // not yet unique values for testnet
        genesis = CreateGenesisBlock(1530217200, 4662255, 0x1e0631b5, 1, 75 * COIN);
        consensus.hashGenesisBlock = genesis.GetHash();
        assert(consensus.hashGenesisBlock == uint256S("0x3ae85767ad3ec3dc70877cef8e256fa2244f9f3de2fb8a43c5be972dc1db08a1"));
        assert(genesis.hashMerkleRoot == uint256S("0x45e37fb95121169542534355cb8b11f99cebfbe776d20154fa34ffcdfcb7510c"));

       // vFixedSeeds.clear();
       // vSeeds.clear();
        // nodes with support for servicebits filtering should be at the top
       // vSeeds.emplace_back("testnet-seed.thehashcointools.com");
       // vSeeds.emplace_back("seed-b.thehashcoin.loshan.co.uk");
       // vSeeds.emplace_back("dnsseed-testnet.thrasher.io");

        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1,111);
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1,196);
        base58Prefixes[SCRIPT_ADDRESS2] = std::vector<unsigned char>(1,58);
        base58Prefixes[SECRET_KEY] =     std::vector<unsigned char>(1,239);
        base58Prefixes[EXT_PUBLIC_KEY] = {0x04, 0x35, 0x87, 0xCF};
        base58Prefixes[EXT_SECRET_KEY] = {0x04, 0x35, 0x83, 0x94};

        bech32_hrp = "tthc";

        //vFixedSeeds = std::vector<SeedSpec6>(pnSeed6_test, pnSeed6_test + ARRAYLEN(pnSeed6_test));

        fDefaultConsistencyChecks = false;
        fRequireStandard = false;
        fMineBlocksOnDemand = false;

        checkpointData = (CCheckpointData) {
           // {
                //{2056, uint256S("17748a31ba97afdc9a4f86837a39d287e3e7c7290a08a1d816c5969c78a83289")},
          //  }
        };

        chainTxData = ChainTxData{
            // Data as of block a0afbded94d4be233e191525dc2d467af5c7eab3143c852c3cd549831022aad6 (height 343833)
            1530217200,
            0,
            0
        };

    }
};

/**
 * Regression test (NOT YET VALID)
 */
class CRegTestParams : public CChainParams {
public:
    CRegTestParams() {
        strNetworkID = "regtest";
        consensus.nSubsidyHalvingInterval = 150;
        consensus.BIP16Height = 0; // always enforce P2SH BIP16 on regtest
        consensus.BIP34Height = 100000000; // BIP34 has not activated on regtest (far in the future so block v1 are not rejected in tests)
        consensus.BIP34Hash = uint256();
        consensus.BIP65Height = 0; // BIP65 activated on regtest (Used in rpc activation tests)
        consensus.BIP66Height = 0; // BIP66 activated on regtest (Used in rpc activation tests)
        consensus.powLimit = uint256S("7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff");
        consensus.nPowTargetTimespan = 3.5 * 24 * 60 * 60; // two weeks
        consensus.nPowTargetSpacing = 2.5 * 60;
        consensus.fPowAllowMinDifficultyBlocks = true;
        consensus.fPowNoRetargeting = true;
        consensus.nRuleChangeActivationThreshold = 108; // 75% for testchains
        consensus.nMinerConfirmationWindow = 144; // Faster than normal for regtest (144 instead of 2016)
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].bit = 28;
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].nStartTime = 0;
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].nTimeout = Consensus::BIP9Deployment::NO_TIMEOUT;
        consensus.vDeployments[Consensus::DEPLOYMENT_CSV].bit = 0;
        consensus.vDeployments[Consensus::DEPLOYMENT_CSV].nStartTime = 0;
        consensus.vDeployments[Consensus::DEPLOYMENT_CSV].nTimeout = Consensus::BIP9Deployment::NO_TIMEOUT;
        consensus.vDeployments[Consensus::DEPLOYMENT_SEGWIT].bit = 1;
        consensus.vDeployments[Consensus::DEPLOYMENT_SEGWIT].nStartTime = Consensus::BIP9Deployment::ALWAYS_ACTIVE;
        consensus.vDeployments[Consensus::DEPLOYMENT_SEGWIT].nTimeout = Consensus::BIP9Deployment::NO_TIMEOUT;

        // The best chain should have at least this much work.
        consensus.nMinimumChainWork = uint256S("0x01");

        // By default assume that the signatures in ancestors of this block are valid.
        consensus.defaultAssumeValid = uint256S("0x3ae85767ad3ec3dc70877cef8e256fa2244f9f3de2fb8a43c5be972dc1db08a1");

        pchMessageStart[0] = 0xfa;
        pchMessageStart[1] = 0xbf;
        pchMessageStart[2] = 0xb5;
        pchMessageStart[3] = 0xda;
        nDefaultPort = 19444;
        nPruneAfterHeight = 1000;

        genesis = CreateGenesisBlock(1530217200, 4662255, 0x1e0ffff0, 1, 15 * COIN);
        consensus.hashGenesisBlock = genesis.GetHash();
        assert(consensus.hashGenesisBlock == uint256S("0x3ae85767ad3ec3dc70877cef8e256fa2244f9f3de2fb8a43c5be972dc1db08a1"));
        assert(genesis.hashMerkleRoot == uint256S("0x45e37fb95121169542534355cb8b11f99cebfbe776d20154fa34ffcdfcb7510c"));

        vFixedSeeds.clear(); //!< Regtest mode doesn't have any fixed seeds.
        vSeeds.clear();      //!< Regtest mode doesn't have any DNS seeds.

        fDefaultConsistencyChecks = true;
        fRequireStandard = false;
        fMineBlocksOnDemand = true; 

        checkpointData = {
           // {
              //  {0, uint256S("530827f38f93b43ed12af0b3ad25a288dc02ed74d6d7857862df51fc56c416f9")},
          //  }
        };

        chainTxData = ChainTxData{
            0,
            0,
            0
        };

        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1,111);
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1,196);
        base58Prefixes[SCRIPT_ADDRESS2] = std::vector<unsigned char>(1,58);
        base58Prefixes[SECRET_KEY] =     std::vector<unsigned char>(1,239);
        base58Prefixes[EXT_PUBLIC_KEY] = {0x04, 0x35, 0x87, 0xCF};
        base58Prefixes[EXT_SECRET_KEY] = {0x04, 0x35, 0x83, 0x94};

        bech32_hrp = "rthc";
    }
};

static std::unique_ptr<CChainParams> globalChainParams;

const CChainParams &Params() {
    assert(globalChainParams);
    return *globalChainParams;
}

std::unique_ptr<CChainParams> CreateChainParams(const std::string& chain)
{
    if (chain == CBaseChainParams::MAIN)
        return std::unique_ptr<CChainParams>(new CMainParams());
    else if (chain == CBaseChainParams::TESTNET)
        return std::unique_ptr<CChainParams>(new CTestNetParams());
    else if (chain == CBaseChainParams::REGTEST)
        return std::unique_ptr<CChainParams>(new CRegTestParams());
    throw std::runtime_error(strprintf("%s: Unknown chain %s.", __func__, chain));
}

void SelectParams(const std::string& network)
{
    SelectBaseParams(network);
    globalChainParams = CreateChainParams(network);
}

void UpdateVersionBitsParameters(Consensus::DeploymentPos d, int64_t nStartTime, int64_t nTimeout)
{
    globalChainParams->UpdateVersionBitsParameters(d, nStartTime, nTimeout);
}
