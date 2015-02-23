#include "DataObject.h"

HRESULT CDataObject::GetData(FORMATETC *, STGMEDIUM *)
{
	printf("GetData stub\n");
	return S_OK;
}

HRESULT CDataObject::SetData(FORMATETC *, STGMEDIUM *, BOOL)
{
	printf("SetData stub\n");
	return S_OK;
}

CDataObject::CDataObject()
{
}


CDataObject::~CDataObject()
{
}
