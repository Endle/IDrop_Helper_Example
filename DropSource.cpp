#include "DropSource.h"

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

CDropSource::CDropSource()
{
	HRESULT hres;
	hres = CoCreateInstance(CLSID_DragDropHelper, NULL, CLSCTX_INPROC_SERVER,
		IID_IDragSourceHelper, (LPVOID*)&m_pdsh);

	printf("CoCreateInstance IDragSourceHelper hres: %08x, got %p\n", hres, m_pdsh);

}


CDropSource::~CDropSource()
{
}
