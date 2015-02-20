#include "DropTarget.h"


CDropTarget::CDropTarget(HWND hwnd)
{
	HRESULT hres;

	CoCreateInstance(CLSID_DragDropHelper, NULL, CLSCTX_INPROC_SERVER, IID_IDropTargetHelper, (void**)&idth);

	_hwnd = hwnd;

	hres = RegisterDragDrop(hwnd, this);
	if (FAILED(hres)) MessageBoxA(NULL, "FAIL", NULL, MB_OK);
}


CDropTarget::~CDropTarget()
{
	RevokeDragDrop(_hwnd);
	idth->Release();
}
HRESULT CDropTarget::DragEnter(IDataObject*, DWORD, POINTL, DWORD*)
{
	//MessageBoxA(NULL, "Enter", NULL, MB_OK);
	return S_OK;
}

HRESULT CDropTarget::DragLeave()
{
	//exit(0);
	//MessageBoxA(NULL, "Leave", NULL, MB_OK);
	//abort();
	return S_OK;
}

HRESULT CDropTarget::DragOver(DWORD, POINTL, DWORD*)
{ 
	//MessageBoxA(NULL, "DragOver", NULL, MB_OK);
	return S_OK;
	//return 0xdeadbeef; 
}