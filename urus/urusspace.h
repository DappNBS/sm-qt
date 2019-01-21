#ifndef URUSSPACE_H
#define URUSSPACE_H

#include <QtCore/qglobal.h>
#if defined(__OBJC__) && !definded(__cplusplus)
#  warning ""
#endif

URUS_BEGIN_NAMESPACE
namespace
Urus {

public:
    enum MsgType {
        SystemCTRL      = 0x0001,
        Self            = 0x0010,
        Customer        = 0x0011
    }

};

URUS_END_NAMESPACE
#endif // URUSSPACE_H
