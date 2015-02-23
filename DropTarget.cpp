#include "DropTarget.h"


CDropTarget::CDropTarget(HWND hwnd) :ido(NULL)
{
	HRESULT hres;

	idth = NULL;
	hres = CoCreateInstance(CLSID_DragDropHelper, NULL, CLSCTX_INPROC_SERVER, IID_IDropTargetHelper, (void**)&idth);
	printf("CoCreateInstance IDropTargetHelper: hres = %08x, got %p\n", hres, idth);

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
HRESULT CDropTarget::DragEnter(IDataObject* pdo, DWORD keys, POINTL pointl, DWORD* effect)
{
	POINT pt = { pointl.x, pointl.y };
	HRESULT hres = 0xdeadbeef;
	printf("CDropTarget Enter (%d, %d)\n", pointl.x, pointl.y);

	hres = idth->DragEnter(_hwnd+1, pdo, &pt, *effect);
	printf("IDropTaretHelper::DragEnter %08x\n", hres);
	return S_OK;
}

HRESULT CDropTarget::DragLeave()
{
	printf("CDropTarget Leave\n");
	HRESULT hres = 0xdeadbeef;

	hres = idth->DragLeave();
	if(FAILED(hres)) printf("IDropTaretHelper::DragLeave %08x\n", hres);
	return S_OK;
}

HRESULT CDropTarget::DragOver(DWORD, POINTL pointl, DWORD* effect)
{
	POINT pt = { pointl.x, pointl.y };
	printf("CDropTarget Over (%d, %d)\n",  pointl.x, pointl.y);

	HRESULT hres = 0xdeadbeef;

	hres = idth->DragOver(&pt, *effect);
	if (FAILED(hres))  printf("IDropTaretHelper::DragOver %08x\n", hres);
	return S_OK;
}

HRESULT CDropTarget::Drop(IDataObject*, DWORD, POINTL point, DWORD*)
{
	printf("CDropTarget Drop (%d, %d)\n", point.x, point.y);
	return S_OK;
}