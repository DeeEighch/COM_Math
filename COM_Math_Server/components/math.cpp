#include <windows.h>
#include "math.h"

Math::Math()
{
    m_lRef = 0;
    InterlockedIncrement(&g_lObjs);
}

Math::~Math()
{
    InterlockedDecrement(&g_lObjs);
}

STDMETHODIMP Math::QueryInterface(REFIID riid, void** ppv)
{
    *ppv = 0;

    if (riid == IID_IUnknown || riid == IID_IMath)
    {
        *ppv = this;
    }

    if(*ppv)
    {
        AddRef();
        return S_OK;
    }

    return E_NOINTERFACE;
}

STDMETHODIMP_(ULONG) Math::Release()
{
    if(InterlockedDecrement(&m_lRef) == 0)
    {
        delete this;
        return 0;
    }
        return m_lRef;
}

STDMETHODIMP_(ULONG) Math::AddRef()
{
    return InterlockedIncrement(&m_lRef);

}

STDMETHODIMP Math::Add( long lOp1, long lOp2, long* pResult )
{
   *pResult = lOp1 + lOp2;
   return S_OK;
}

STDMETHODIMP Math::Subtract( long lOp1, long lOp2, long* pResult )
{
   *pResult = lOp1 - lOp2;
   return S_OK;
}

STDMETHODIMP Math::Multiply( long lOp1, long lOp2, long* pResult )
{
   *pResult = lOp1 * lOp2;
   return S_OK;
}

STDMETHODIMP Math::Divide( long lOp1, long lOp2, long* pResult )
{
   *pResult = lOp1 / lOp2;
   return S_OK;
}
