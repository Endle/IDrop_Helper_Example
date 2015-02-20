#pragma once
#include "oleidl.h"
class CDropSource :
	public IDropSource
{
public:
	CDropSource();
	~CDropSource();

	HRESULT STDMETHODCALLTYPE QueryContinueDrag(BOOL, DWORD);
	HRESULT STDMETHODCALLTYPE GiveFeedback(DWORD);

	//---------IUnknown------
	//Hack, only for test
	ULONG STDMETHODCALLTYPE AddRef() { return 2; }
	ULONG STDMETHODCALLTYPE Release() { return 1; }

	HRESULT STDMETHODCALLTYPE QueryInterface(const IID &riid, void **ppv) {
		if (riid == IID_IUnknown) {
			*ppv = static_cast<IUnknown*>(this);
			AddRef();
			return S_OK;
		}
		else if (riid == IID_IDropTarget) {
			*ppv = static_cast<IDropSource*>(this);
			AddRef();
			return S_OK;
		}

		*ppv = NULL;
		return S_FALSE;
	}
};
