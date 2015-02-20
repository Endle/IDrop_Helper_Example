#pragma once
#include "stdafx.h"

class CDropTarget :
	public IDropTarget
{
public:
	CDropTarget(HWND hwnd);
	~CDropTarget();
	HRESULT STDMETHODCALLTYPE DragEnter(IDataObject*, DWORD, POINTL, DWORD*);
	HRESULT STDMETHODCALLTYPE DragLeave();
	HRESULT STDMETHODCALLTYPE DragOver(DWORD, POINTL, DWORD*);
	HRESULT STDMETHODCALLTYPE Drop(IDataObject*, DWORD, POINTL, DWORD*){ return S_FALSE; }

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
			*ppv = static_cast<IDropTarget*>(this);
			AddRef();
			return S_OK;
		}
		
		*ppv = NULL;
		return S_FALSE;
	}
private:
	IDropTargetHelper *idth;
	HWND _hwnd;
};

