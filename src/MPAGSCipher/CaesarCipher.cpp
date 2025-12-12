#include <cctype>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "CaesarCipher.hpp"
#include "CipherMode.hpp"

/**
 * \file CaesarCipher.cpp
 * \brief The definitions of the CaesarCipher class
 * 
 * 
 */


CaesarCipher::CaesarCipher(const std::size_t& cipherKey): key_{cipherKey}{

}

CaesarCipher::CaesarCipher(const std::string& cipherKey): key_{0}{
    if (!cipherKey.empty()){
        for (const auto& elem : cipherKey) {
                if (!std::isdigit(elem)) {
                    std::cerr
                        << "[error] cipher key must be an unsigned long integer for Caesar cipher,\n"
                        << "        the supplied key (" << cipherKey
                        << ") could not be successfully converted" << std::endl;
                }
        }
        key_ = std::stoul(cipherKey);
    }

}

std::string CaesarCipher::applyCipher(const std::string& inputText, const CipherMode encrypt) const{
    // Create the output string
    std::string outputText;


    // Make sure that the key is in the range 0 - 25
    const std::size_t truncatedKey{key_ % alphabetSize_};

    // Loop over the input text
    char processedChar{'x'};
    for (const auto& origChar : inputText) {
        // For each character in the input text, find the corresponding position in
        // the alphabet by using an indexed loop over the alphabet container
        for (size_t i{0}; i < alphabetSize_; ++i) {
            if (origChar == alphabet_[i]) {
                // Apply the appropriate shift (depending on whether we're encrypting
                // or decrypting) and determine the new character
                // Can then break out of the loop over the alphabet
                switch (encrypt){
                    case CipherMode::Encrypt:
                        processedChar = alphabet_[(i + truncatedKey) % alphabetSize_];
                        break;
                    case CipherMode::Decrypt:
                        processedChar = alphabet_[(i + alphabetSize_ - truncatedKey) %
                                                alphabetSize_];
                        break;
                }
            }
        }

        // Add the new character to the output text
        outputText += processedChar;
    }

    return outputText;

}