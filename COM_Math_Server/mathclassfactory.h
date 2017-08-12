#ifndef MATHCLASSFACTORY_H
#define MATHCLASSFACTORY_H
#include <windows.h>
#include <oleauto.h>

extern long g_lLocks;

class MathClassFactory : public IClassFactory
{
protected:
    long m_lRef;
public:
    MathClassFactory();
    ~MathClassFactory();

    // реализация интерфейса IUnknown
    STDMETHOD( QueryInterface (REFIID riid, void** ppv));
    STDMETHOD_( ULONG, AddRef());
    STDMETHOD_( ULONG, Release());

    // реализация интерфеса  IClassFactory
    STDMETHOD( CreateInstance(LPUNKNOWN pUnk, REFIID riid, void** ppv));
    STDMETHOD( LockServer(BOOL));

};

#endif // MATHCLASSFACTORY_H
