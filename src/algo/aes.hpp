/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
/**
 * Copyright (c) 2014-2015,  Regents of the University of California
 *
 * This file is part of gep (Group-based Encryption Protocol for NDN).
 * See AUTHORS.md for complete list of gep authors and contributors.
 *
 * gep is free software: you can redistribute it and/or modify it under the terms
 * of the GNU General Public License as published by the Free Software Foundation,
 * either version 3 of the License, or (at your option) any later version.
 *
 * gep is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
 * without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 * PURPOSE.  See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * gep, e.g., in COPYING.md file.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef NDN_GEP_ALGO_AES_HPP
#define NDN_GEP_ALGO_AES_HPP

#include "encrypt-params.hpp"
#include "../decrypt-key.hpp"
#include "../random-number-generator.hpp"
#include <ndn-cxx/security/key-params.hpp>


namespace ndn {
namespace gep {
namespace algo {

class Aes
{
public:
  static DecryptKey<Aes>
  generateKey(RandomNumberGenerator& rng, AesKeyParams& params);

  static EncryptKey<Aes>
  deriveEncryptKey(const Buffer& keyBits);

  static Buffer
  decrypt(const uint8_t* key,
          size_t keyLen,
          const uint8_t* payload,
          size_t payloadLen,
          const EncryptParams& params);

  static Buffer
  encrypt(const uint8_t* key,
          size_t keyLen,
          const uint8_t* payload,
          size_t payloadLen,
          const EncryptParams& params);
};

typedef DecryptKey<Aes> AesEncryptKey;
typedef EncryptKey<Aes> AesDecryptKey;

} // namespace algo
} // namespace gep
} // namespace ndn

#endif // NDN_GEP_ALGO_AES_ECB_HPP
