/*
   BAREOS® - Backup Archiving REcovery Open Sourced

   Copyright (C) 2018-2018 Bareos GmbH & Co. KG

   This program is Free Software; you can redistribute it and/or
   modify it under the terms of version three of the GNU Affero General Public
   License as published by the Free Software Foundation and included
   in the file LICENSE.

   This program is distributed in the hope that it will be useful, but
   WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
   Affero General Public License for more details.

   You should have received a copy of the GNU Affero General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
   02110-1301, USA.
*/

#ifndef BAREOS_LIB_TLS_PSK_CREDENTIALS_H_
#define BAREOS_LIB_TLS_PSK_CREDENTIALS_H_

#include "include/bareos.h"

#include <string>

class PskCredentials
{
public:
   PskCredentials() {}

   PskCredentials(const std::string &identity, const std::string &psk)
      : identity_(identity)
      , psk_(psk) {
      Dmsg2(100, "Construct PskCredentials: id=%s, passwd=%s\n", identity_.c_str(), psk_.c_str());
   }

   PskCredentials(const char *identity, const char *psk)
      : identity_(std::string(identity))
      , psk_(std::string(psk)) {
      Dmsg2(100, "Construct PskCredentials: id=%s, passwd=%s\n", identity_.c_str(), psk_.c_str());
   }

   PskCredentials &operator = (const PskCredentials &rhs) {
      identity_ = rhs.identity_;
      psk_ = rhs.identity_;
      return *this;
   }

   bool empty() const {
      return identity_.empty() && psk_.empty();
   }

   void set_identity(const char *in) { identity_ = in; }
   void set_psk(const char *in) { psk_ = in; }

   const std::string &get_identity() const { return identity_; }
   const std::string &get_psk() const { return psk_; }

   ~PskCredentials() {
      Dmsg2(100, "Destruct PskCredentials: id=%s, passwd=%s\n", identity_.c_str(), psk_.c_str());
   }

private:
   std::string identity_;
   std::string psk_;
};

#endif /* BAREOS_LIB_TLS_PSK_CREDENTIALS_H_ */
