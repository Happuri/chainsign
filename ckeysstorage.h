#ifndef CKEYSSTORAGE_H
#define CKEYSSTORAGE_H

#include <string>
#include <vector>
#include <map>

#include <crypto++/rsa.h>
#include <crypto++/osrng.h>

class cKeysStorage
{
public:
    cKeysStorage();
    void RSASignFile(const std::string& messageFilename, const std::string& signatureFilename, bool signKey);
    bool RSAVerifyFile(const std::string &fileName, const std::string &instance);
    void GenerateRSAKey(unsigned int keyLength, std::string fileName);
    unsigned int getCurrentKey() { return mCurrentKey; }
    void RemoveRSAKey();
private:
    std::map <int, CryptoPP::RSA::PrivateKey> mPrvKeys;
    void savePubFile(unsigned int numberOfKey, const CryptoPP::RSA::PublicKey& pPubKey, std::string fileName);
    CryptoPP::RSA::PublicKey loadPubFile(std::string pubKey);
	
	unsigned int mCurrentKey;
};

#endif // CKEYSSTORAGE_H
