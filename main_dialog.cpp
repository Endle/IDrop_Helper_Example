#include "stdafx.h"
#include "main_dialog.h"


main_dialog::main_dialog(HWND hwnd)
{
	_hwnd = hwnd;

	static WCHAR buff[1025];
	HRESULT hres;

	//hres = CoCreateInstance(CLSID_)
	hres = OleInitialize(NULL);
	//wsprintfW(buff, L"hres = %08x", hres); MessageBoxW(NULL, buff, NULL, MB_OK);

	pcdt = new CDropTarget(hwnd);
	pdo = new CDataObject;
	pcds = new CDropSource(pdo);
}


main_dialog::~main_dialog()
{
	delete pcdt;
	delete pcds;
	delete pdo;
}


INT_PTR main_dialog::handle(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	POINT p = lp2p(lParam);
	HDC hdc;
	PAINTSTRUCT ps;
	HRESULT hres;
	DWORD dresult;

	switch (message) {
	case WM_PAINT:
		hdc = BeginPaint(_hwnd, &ps);
		pcdt->Show();
		EndPaint(_hwnd, &ps);
	case WM_LBUTTONDOWN:
		dresult = 0xdeadbeef;
		wprintf(L"Click at x:%d y:%d\n", p.x, p.y);
		hres = DoDragDrop(pdo, pcds, 0, &dresult);
		wprintf(L"hres=%08x, dresult=%08x\n", hres, dresult);
		break;
	case WM_LBUTTONUP:
		break;
	}
	return (INT_PTR)TRUE;
}