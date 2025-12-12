#ifndef MPAGSCIPHER_CIPHERMODE_HPP
#define MPAGSCIPHER_CIPHERMODE_HPP

/**
 * \file 
 * \brief A completely useless enum that could have just been a boolean
 * 
 */
enum class CipherMode{
    Encrypt, ///< Encrypt the message
    Decrypt, ///< Decrypt the message
};

#endif