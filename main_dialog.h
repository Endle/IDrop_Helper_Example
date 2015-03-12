#pragma once
#include "DropTarget.h"
#include "DropSource.h"
#include "DataObject.h"

class main_dialog
{
public:
	main_dialog(HWND);
	~main_dialog();
	INT_PTR handle(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);
	IDataObject * GetPDO() { return pdo; }

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
