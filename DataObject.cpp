#include "DataObject.h"

HRESULT CDataObject::GetData(FORMATETC *pf, STGMEDIUM *pm)
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
	m_data = new DATAENTRY;
	*(int*)m_data = 0;
}


CDataObject::~CDataObject()
{
}
