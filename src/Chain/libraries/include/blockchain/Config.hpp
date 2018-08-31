#pragma onceclient_

#include <stdint.h>

/* XXX: Comment out this line for a non-test network */
//#define ALP_TEST_NETWORK

#define ALP_TEST_NETWORK_VERSION                            83 // autogenerated

#define ALP_BLOCKCHAIN_DATABASE_VERSION                     uint64_t( 201 )

/**
 *  The address prepended to string representation of
 *  addresses.
 *
 *  Changing these parameters will result in a hard fork.
 */
/*
#define ALP_ADDRESS_PREFIX                                  "ALP"
#define ALP_BLOCKCHAIN_SYMBOL                               "ALP"
#define ALP_BLOCKCHAIN_NAME                                 "ALP"
*/
#define ALP_ADDRESS_PREFIX                                  "TTC"
#define ALP_BLOCKCHAIN_SYMBOL                               "TTCOIN"
#define ALP_BLOCKCHAIN_NAME                                 "TTCHAIN"

#define ALP_BLOCKCHAIN_DESCRIPTION                          "Crypto, Blockchain and More"
			
#define ALP_BLOCKCHAIN_PRECISION                            100000

#define ALP_BLOCKCHAIN_MAX_UIA_MARKET_FEE                   10000
#define ALP_BLOCKCHAIN_BLOCK_INTERVAL_SEC                   int64_t(6)
#define ALP_BLOCKCHAIN_BLOCKS_PER_HOUR                      ((60*60)/ALP_BLOCKCHAIN_BLOCK_INTERVAL_SEC)
#define ALP_BLOCKCHAIN_BLOCKS_PER_DAY                       (ALP_BLOCKCHAIN_BLOCKS_PER_HOUR*int64_t(24))
#define ALP_BLOCKCHAIN_BLOCKS_PER_YEAR                      (ALP_BLOCKCHAIN_BLOCKS_PER_DAY*int64_t(365))

#define ALP_BLOCKCHAIN_NUM_DELEGATES                        uint32_t(99)
#define ALP_DELEGATE_PAY_PER_BLOCK_TIMES                    0.002
#define ALP_MAX_DELEGATE_PAY_PER_BLOCK                      int64_t( 1 * ALP_BLOCKCHAIN_PRECISION * ALP_DELEGATE_PAY_PER_BLOCK_TIMES )
#define ALP_BLOCKCHAIN_MAX_UNDO_HISTORY                     ALP_BLOCKCHAIN_BLOCKS_PER_HOUR

#define ALP_BLOCKCHAIN_REGISTER_ACCOUNT_FEE                 int64_t( 10 * ALP_BLOCKCHAIN_PRECISION ) 

#define ALP_BLOCKCHAIN_MAX_SLATE_SIZE                       (ALP_BLOCKCHAIN_NUM_DELEGATES + (ALP_BLOCKCHAIN_NUM_DELEGATES/10))
#define ALP_BLOCKCHAIN_MAX_MESSAGE_SIZE                     2048
#define ALP_BLOCKCHAIN_MAX_FREE_MESSAGE_SIZE                1024
#define ALP_BLOCKCHAIN_MAX_SOFT_MAX_MESSAGE_SIZE            40
#define ALP_BLOCKCHAIN_MIN_MESSAGE_FEE_COE                  100
#define ALP_BLOCKCHAIN_MAX_TRANSACTION_EXPIRATION_SEC       (60*60*24*2)
#define ALP_BLOCKCHAIN_MAX_MEMO_SIZE                        19 // bytes
#define ALP_BLOCKCHAIN_EXTENDED_MEMO_SIZE                   32 // bytes
#define ALP_BLOCKCHAIN_MAX_EXTENDED_MEMO_SIZE               (ALP_BLOCKCHAIN_MAX_MEMO_SIZE + ALP_BLOCKCHAIN_EXTENDED_MEMO_SIZE)

#define ALP_DEFAULT_TRANSACTION_FEE                         1000
#define ALP_DEFAULT_MIN_TRANSACTION_AMOUNT                  10 // 设置最低手续费为0.00001
#define ALP_DEFAULT_MIN_TRANSACTION_FEE                     1 // 设置最低手续费为0.00001
//#define ALP_DEFAULT_MAX_TRANSACTION_FEE                     30000000 // 设置最高手续费为1000
#define ALP_DEFAULT_MAX_TRANSACTION_FEE                     300000 // 设置最高手续费为1000
#define ALP_DEFAULT_TRANSACTION_FEE_RATIO					double(0.00300) //手续费比例0.003
#define ALP_DEFAULT_TRANSACTION_EXPIRATION_SEC              (60*60)
#define ALP_DEFAULT_CONTRACT_MARGIN                         10 * ALP_BLOCKCHAIN_PRECISION 
#define TRANSACTION_CONFIGURATION_FILENAME      "transaction_config.json"

/**
 *  The maximum amount that can be issued for user assets.
 *
 *  10^18 / 2^63 < 1  however, to support representing all share values as a double in
 *  languages like java script, we must stay within the epsilon so
 *
 *  10^15 / 2^53 < 1 allows all values to be represented as a double or an int64
 */
#define ALP_BLOCKCHAIN_MAX_SHARES                           (1000*1000*int64_t(1000)*1000*int64_t(10000)) //100亿

#define ALP_BLOCKCHAIN_MIN_NAME_SIZE                        1
#define ALP_BLOCKCHAIN_MAX_NAME_SIZE                        63
#define ALP_BLOCKCHAIN_MAX_NAME_DATA_SIZE                   (1024*64)

#define ALP_BLOCKCHAIN_MAX_SUB_SYMBOL_SIZE                  16 // characters
#define ALP_BLOCKCHAIN_MIN_SYMBOL_SIZE                      3 // characters
#define ALP_BLOCKCHAIN_MAX_SYMBOL_SIZE                      16 // characters

#define ALP_BLOCKCHAIN_MIN_BURN_FEE                         ALP_BLOCKCHAIN_PRECISION * 1 // 1 XTS

#ifdef ALP_TEST_NETWORK
#define ALP_BLOCKCHAIN_VOTE_UPDATE_PERIOD_SEC               10
#else
#define ALP_BLOCKCHAIN_VOTE_UPDATE_PERIOD_SEC               (60*60) // 1 hour
#endif

#define ALP_BLOCKCHAIN_MIN_FEEDS                            ((ALP_BLOCKCHAIN_NUM_DELEGATES/2) + 1)
#define ALP_BLOCKCHAIN_MINIMUM_SHORT_ORDER_SIZE             (ALP_BLOCKCHAIN_PRECISION*100)
#define ALP_BLOCKCHAIN_MIN_YIELD_PERIOD_SEC                 (60*60*24) // 24 hours
#define ALP_BLOCKCHAIN_MAX_YIELD_PERIOD_SEC                 (ALP_BLOCKCHAIN_BLOCKS_PER_YEAR * ALP_BLOCKCHAIN_BLOCK_INTERVAL_SEC) // 1 year

#ifdef ALP_TEST_NETWORK
#define ALP_BLOCKCHAIN_MAX_SHORT_PERIOD_SEC                 (2*60*60) // 2 hours
#else
#define ALP_BLOCKCHAIN_MAX_SHORT_PERIOD_SEC                 (30*24*60*60) // 1 month
#endif
#define ALP_BLOCKCHAIN_MAX_SHORT_APR_PCT                    (uint64_t(50))

#define ALP_BLOCKCHAIN_MCALL_D2C_NUMERATOR                  1
#define ALP_BLOCKCHAIN_MCALL_D2C_DENOMINATOR                2

// TODO: This stuff only matters for propagation throttling; should go somewhere else
#define ALP_BLOCKCHAIN_DEFAULT_RELAY_FEE                    1 // XTS //mod zxj  1000 ->1
#define ALP_BLOCKCHAIN_MAX_TRX_PER_SECOND                   1000  // (1000)
#define ALP_BLOCKCHAIN_MAX_PENDING_QUEUE_SIZE               10000 // (ALP_BLOCKCHAIN_MAX_TRX_PER_SECOND * ALP_BLOCKCHAIN_BLOCK_INTERVAL_SEC)

#define ALP_BLOCKCHAIN_REVALIDATE_MAX_TRX_COUNT             (ALP_BLOCKCHAIN_MAX_TRX_PER_SECOND * ALP_BLOCKCHAIN_BLOCK_INTERVAL_SEC)


// for contract
#define  CONTRACT_ADDRESS_PREFIX "CON" 
#define  SCRIPT_ID_PREFIX "SCR" 

#define  CONTRACT_MAX_BYTECODE_SIZE   (1 * 1024 * 1024)  //just set to the limit of block size
#define  CONTRACT_MAX_NAME_SIZE  32 
#define  CONTRACT_MAX_DESCRIPTION_SIZE  256
#define  LIMIT_PRICE 1
#define  CONTRACT_PARAM_MAX_LEN  1024

#define  CONTRACT_OFFLINE_LIMIT_MAX     (1024*1024*1024) 
#define  CONTRACT_TESTING_LIMIT_MAX     (1024*1024*1024) 

// for event
#define  EVENT_PARAM_MAX_LEN  1024
#define  EVENT_TYPE_MAX_LEN   256

#define ALP_BLOCKCHAIN_FREESIGNATURE_LIMIT	10
#define ALP_BLOCKCHAIN_MAX_SIGNAGTURE_NUM   1000
#define ALP_BLOCKCHAIN_EXTRA_SIGNATURE_FEE  1000
#define ALP_BLOCKCHAIN_TRANSACTION_MAX_DEPOSIT_NUM 100

