// CRemote.cpp: 구현 파일
//

#include "stdafx.h"
#include "Cube_Prj_2017305045.h"
#include "CRemote.h"
#include "afxdialogex.h"


// CRemote 대화 상자

IMPLEMENT_DYNAMIC(CRemote, CDialogEx)

CRemote::CRemote(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

CRemote::~CRemote()
{
}

void CRemote::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CRemote, CDialogEx)
END_MESSAGE_MAP()


// CRemote 메시지 처리기
