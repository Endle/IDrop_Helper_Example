#include "DropTarget.h"


CDropTarget::CDropTarget(HWND hwnd)
{
	HRESULT hres;

	CoCreateInstance(CLSID_DragDropHelper, NULL, CLSCTX_INPROC_SERVER, IID_IDropTargetHelper, (void**)&idth);

	_hwnd = hwnd;

	hres = RegisterDragDrop(hwnd, this);
	printf("CDropTarget Contructor RegisterDragDrop, hres = %08x, hwnd = %08x\n", hres, hwnd);
}


CDropTarget::~CDropTarget()
{
	printf("CDropTarget Destructor\n");
	HRESULT hres;
	//hres = RevokeDragDrop(_hwnd);
	idth->Release();
	//printf("RevokeDragDrop hres = %08x, hwnd = %08x\n", hres, _hwnd);
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

HRESULT CDropTarget::Drop(IDataObject*, DWORD, POINTL point, DWORD*)
{
	printf("CDropTarget Drop (%d, %d)\n", point.x, point.y);
	return S_OK;
}