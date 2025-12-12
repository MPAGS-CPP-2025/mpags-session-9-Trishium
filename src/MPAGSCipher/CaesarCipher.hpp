#include <string>
#include <vector>
#include "CipherMode.hpp"

/**
 * \file CaesarCipher.hpp
 * \brief Contains the declaration of the CasaarCipher class
 * 
 */

 /**
  * \brief The declaration of the Caesar Cipher class
  * 
  */
class CaesarCipher{
    
    public:
        /**
        * \brief The class constructor that takes an integer
        * \param key The key of the Ceasar Cipher
        * 
        * 
        */
        explicit CaesarCipher(const std::size_t& cipherKey);

        /**
         * \brief The class constructor that takes a string
         * \param key The key of the Ceasar Cipher
         */
        explicit CaesarCipher(const std::string& cipherKey);

        /**
         * \brief The method that applies the cipher to a given string
         * 
         * \param inputText The text to be ciphered
         * \param encrypt The CipherMode that tells the method whether it should encrypt or decrypt
         * 
         * \return The ciphered output text as a string
         */
        std::string applyCipher(const std::string& inputText, const CipherMode encrypt) const;

    private:
        const std::vector<char> alphabet_ = {
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
        'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
        const std::size_t alphabetSize_{alphabet_.size()};
        std::size_t key_{0};
};

