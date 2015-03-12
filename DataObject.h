#pragma once
#include "ObjIdl.h"
#include "stdafx.h"

typedef struct {
	FORMATETC fe;
	STGMEDIUM stgm;
} DATAENTRY;

class CDataObject :
	public IDataObject
{
public:
	CDataObject();
	~CDataObject();

	HRESULT STDMETHODCALLTYPE GetData(FORMATETC *, STGMEDIUM *);
	HRESULT STDMETHODCALLTYPE GetDataHere(FORMATETC *, STGMEDIUM *) { return E_NOTIMPL; }
	HRESULT STDMETHODCALLTYPE QueryGetData(FORMATETC *) { return E_NOTIMPL; };
	HRESULT STDMETHODCALLTYPE GetCanonicalFormatEtc(FORMATETC *, FORMATETC *) { return E_NOTIMPL; };
	HRESULT STDMETHODCALLTYPE SetData(FORMATETC *, STGMEDIUM *, BOOL);
	HRESULT STDMETHODCALLTYPE EnumFormatEtc(DWORD, IEnumFORMATETC **) { return E_NOTIMPL; };
	HRESULT STDMETHODCALLTYPE DAdvise(FORMATETC *, DWORD, IAdviseSink *, DWORD *) { return E_NOTIMPL; };
	HRESULT STDMETHODCALLTYPE DUnadvise(DWORD) { return E_NOTIMPL; };
	HRESULT STDMETHODCALLTYPE EnumDAdvise(IEnumSTATDATA **) { return E_NOTIMPL; };
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
		else if (riid == IID_IDataObject) {
			*ppv = static_cast<IDataObject*>(this);
			AddRef();
			return S_OK;
		}

		*ppv = NULL;
		return E_NOTIMPL;
	}

private:
	DATAENTRY *m_data; // A hacky solution
};

