#include "DropSource.h"

HRESULT CDropSource::GiveFeedback(DWORD dwEffect)
{
	//MessageBoxA(NULL, "Feedback", NULL, MB_OK);
	return S_OK; 
}

HRESULT CDropSource::QueryContinueDrag(BOOL escPressed, DWORD keyState)
{
	//if (keyState & MK_CONTROL)
	//	MessageBoxA(NULL, "Query, Control pressed", NULL, MB_OK);

	if (keyState & MK_CONTROL)
		return S_OK;
	else
		return DRAGDROP_S_DROP;
}

CDropSource::CDropSource()
{
}


CDropSource::~CDropSource()
{
}
