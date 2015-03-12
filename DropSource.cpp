#include "DropSource.h"
#include "drag.h"

HRESULT CDropSource::GiveFeedback(DWORD dwEffect)
{
	//MessageBoxA(NULL, "Feedback", NULL, MB_OK);
	return S_OK; 
}

HRESULT CDropSource::QueryContinueDrag(BOOL escPressed, DWORD keyState)
{
	if (escPressed)
		return DRAGDROP_S_CANCEL;

	if (keyState & MK_LBUTTON)
		return S_OK;
	else
		return DRAGDROP_S_DROP;
}

CDropSource::CDropSource(IDataObject* pDataObject) :pdo(pDataObject)
{
	HRESULT hres;
	hres = CoCreateInstance(CLSID_DragDropHelper, NULL, CLSCTX_INPROC_SERVER,
		IID_IDragSourceHelper, (LPVOID*)&m_pdsh);

	printf("CoCreateInstance IDragSourceHelper hres: %08x, got %p\n", hres, m_pdsh);

	GetObject(HANDLE_BITMAP, sizeof(BITMAP), &bm);
	memset(&sh, 0, sizeof(sh));
	sh.sizeDragImage.cx = bm.bmWidth;
	sh.sizeDragImage.cy = bm.bmHeight;
	sh.hbmpDragImage = HANDLE_BITMAP;
	sh.crColorKey = RGB(50, 50, 0);

	hres = m_pdsh->InitializeFromBitmap(&sh, pdo);
	printf("InitializeFromBitmap(pdo=%p) hres = %08x\n", pdo, hres);

}


CDropSource::~CDropSource()
{
}
