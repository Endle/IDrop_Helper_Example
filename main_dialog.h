#pragma once
#include "DropTarget.h"
#include "DropSource.h"
#include "DataObject.h"

// {CD766F91-7468-4186-A8CA-532D501411CA}
static const GUID GUID_ISimpleDrag =
{ 0xcd766f91, 0x7468, 0x4186, { 0xa8, 0xca, 0x53, 0x2d, 0x50, 0x14, 0x11, 0xca } };

class ISimpleDrag : public IDropTargetHelper
{
	//IUnknown
	//Hack, only for test
	ULONG STDMETHODCALLTYPE AddRef() { return 2; }
	ULONG STDMETHODCALLTYPE Release() { return 1; }

	HRESULT STDMETHODCALLTYPE QueryInterface(const IID &riid, void **ppv) {
		if (riid == IID_IUnknown) {
			*ppv = static_cast<IUnknown*>(this);
			AddRef();
			return S_OK;
		}
		else if (riid == IID_IDropTargetHelper) {
			*ppv = static_cast<IDropTargetHelper*>(this);
			AddRef();
			return S_OK;
		}
		else if (riid == GUID_ISimpleDrag) {
			*ppv = this;
			AddRef();
			return S_OK;
		}
		*ppv = NULL;
		return S_FALSE;
	}

	// ------- IDropTargetHelper -------
	HRESULT STDMETHODCALLTYPE DragEnter(HWND, IDataObject *, POINT *, DWORD);
	HRESULT STDMETHODCALLTYPE DragLeave();
	HRESULT STDMETHODCALLTYPE DragOver(POINT*, DWORD);
	HRESULT STDMETHODCALLTYPE Drop(IDataObject*, POINT*, DWORD){ return S_FALSE; }
	HRESULT STDMETHODCALLTYPE Show(BOOL){ return S_FALSE; }
};

class main_dialog
{
public:
	main_dialog(HWND);
	~main_dialog();
	INT_PTR handle(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);

private:
	HWND _hwnd;
	CDropTarget		  *pcdt;
	CDropSource		  *pcds;
	CDataObject		  *pdo;
};

inline POINT lp2p(LPARAM lParam)
{
	POINT p;
	p.x = LOWORD(lParam);
	p.y = HIWORD(lParam);
	return p;
}
