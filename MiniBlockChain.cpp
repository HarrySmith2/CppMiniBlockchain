#include <map>
#include "BLOCKCHAIN_H.h"

using namespace std;

int BlockChain::blockId = 0;

struct blockData {
	string currentHash;
	string inpData;
	string dateTime;
} currentBlock;

int main() {

	map <int, blockData> blockList;


	int blockNum;
    cout << "How many blocks do you wish to create?" << endl;
	cin >> blockNum;
    
	string prevHash = genesisBlock();
	string inpData = "1234";
    
    /* Adds genesis Block's data to map */
    blockList[BlockChain::blockId].currentHash = prevHash;
    blockList[BlockChain::blockId].inpData = inpData;
    time_t result = time(nullptr);
    blockList[BlockChain::blockId].dateTime = asctime(localtime(&result));
    
    
	for (int i; i < blockNum+1; ++i) {
        
		BlockChain x (prevHash, inpData);
        
		blockList[BlockChain::blockId].currentHash = x.createHash();
		blockList[BlockChain::blockId].inpData = x.returnInputData();
		blockList[BlockChain::blockId].dateTime = x.dateTime;
        prevHash = blockList[BlockChain::blockId].currentHash;

        
	}
    cout << "What block do you wish to view?" << endl;
    cin >> blockNum;
    cout << "The hash for block " << blockNum <<" is: "<< blockList[blockNum].currentHash << endl;
    cout << "It's data is: " << blockList[blockNum].inpData << endl;
    cout << "Finally, it was created on: " << blockList[blockNum].dateTime <<endl;
    
	return 0;
}