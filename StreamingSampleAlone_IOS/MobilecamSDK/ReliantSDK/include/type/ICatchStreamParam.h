#ifndef __ICATCH_STREAM_PARAM_H__
#define __ICATCH_STREAM_PARAM_H__

#include <string>
#include "WindowsApi.h"

using namespace std;

namespace com{ namespace icatchtek{ namespace reliant{

class ICAT_API ICatchStreamParam
{
public:
    virtual ~ICatchStreamParam() {};

public:
    virtual int getCodec() = 0;
    virtual int getWidth() = 0;
    virtual int getHeight() = 0;
    virtual int getBitRate() = 0;
    virtual int getFrameRate() = 0;

public:
    virtual string getCmdLineParam() = 0;
};

}}}

#endif
