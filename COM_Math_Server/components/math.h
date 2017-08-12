#ifndef MATH_H
#define MATH_H

#include <interfaces/imath.h>

extern long g_lObjs;

class Math : public IMath
{
protected:
    long m_lRef;

public:
    //IUnknown
    STDMETHOD( QueryInterface(REFIID riid, void** ppv));
    STDMETHOD_(ULONG, AddRef());
    STDMETHOD_(ULONG, Release());

    //IMath
    STDMETHOD( Add( long, long, long* ));
    STDMETHOD( Subtract( long, long, long* ));
    STDMETHOD( Multiply( long, long, long* ));
    STDMETHOD( Divide( long, long, long* ));

public:
    Math();
    ~Math();
};

#endif // MATH_H
