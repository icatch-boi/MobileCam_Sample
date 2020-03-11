#ifndef __CredentialSDK__
#define __CredentialSDK__

/* -----------------------------------------------------------------------------
 * Header files, namespace references.
 */
#include <string>

/* -----------------------------------------------------------------------------
 * class &namespace definitions
 */
namespace com{ namespace icatchtek{ namespace pancam {

class CredentialSDK
{
public:
   std::string access_token;
   std::string refresh_token;
   std::string client_id;
   std::string client_secret;
};

}}}

#endif
