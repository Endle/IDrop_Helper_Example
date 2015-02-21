#include "DropTarget.h"


CDropTarget::CDropTarget(HWND hwnd)
{
	HRESULT hres;

	CoCreateInstance(CLSID_DragDropHelper, NULL, CLSCTX_INPROC_SERVER, IID_IDropTargetHelper, (void**)&idth);

	_hwnd = hwnd;

	hres = RegisterDragDrop(hwnd, this);
	if (FAILED(hres)) MessageBoxA(NULL, "CDropTarget Contructor FAIL", NULL, MB_OK);
}


CDropTarget::~CDropTarget()
{
	RevokeDragDrop(_hwnd);
	idth->Release();
}
HRESULT CDropTarget::DragEnter(IDataObject*, DWORD, POINTL, DWORD*)
{
	printf("CDropTarget Enter\n");
	return S_OK;
}

HRESULT CDropTarget::DragLeave()
{
	printf("CDropTarget Leave\n");
	return S_OK;
}

HRESULT CDropTarget::DragOver(DWORD, POINTL point, DWORD*)
{ 
	printf("CDropTarget Over (%d, %d)\n",  point.x, point.y);
	return S_OK;
}