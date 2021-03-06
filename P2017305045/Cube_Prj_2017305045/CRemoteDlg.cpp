// CRemoteDlg.cpp: 구현 파일
//
#pragma once
#include "stdafx.h"
#include "Cube_Prj_2017305045.h"
#include "CRemoteDlg.h"
#include "afxdialogex.h"

// CRemoteDlg 대화 상자

IMPLEMENT_DYNAMIC(CRemoteDlg, CDialogEx)

CRemoteDlg::CRemoteDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_REMOTE, pParent)
{

}

CRemoteDlg::~CRemoteDlg()
{
}

void CRemoteDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CRemoteDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_DOWN1, &CRemoteDlg::OnClickedButtonDown1)
	ON_BN_CLICKED(IDC_BUTTON_DOWN2, &CRemoteDlg::OnClickedButtonDown2)
	ON_BN_CLICKED(IDC_BUTTON_DOWN3, &CRemoteDlg::OnClickedButtonDown3)
	ON_BN_CLICKED(IDC_BUTTON_EXIT, &CRemoteDlg::OnClickedButtonExit)
	ON_BN_CLICKED(IDC_BUTTON_LEFT1, &CRemoteDlg::OnClickedButtonLeft1)
	ON_BN_CLICKED(IDC_BUTTON_LEFT2, &CRemoteDlg::OnClickedButtonLeft2)
	ON_BN_CLICKED(IDC_BUTTON_LEFT3, &CRemoteDlg::OnClickedButtonLeft3)
	ON_BN_CLICKED(IDC_BUTTON_RESET, &CRemoteDlg::OnClickedButtonReset)
	ON_BN_CLICKED(IDC_BUTTON_RIGHT1, &CRemoteDlg::OnClickedButtonRight1)
	ON_BN_CLICKED(IDC_BUTTON_RIGHT2, &CRemoteDlg::OnClickedButtonRight2)
	ON_BN_CLICKED(IDC_BUTTON_RIGHT3, &CRemoteDlg::OnClickedButtonRight3)
	ON_BN_CLICKED(IDC_BUTTON_TEN, &CRemoteDlg::OnClickedButtonTen)
	ON_BN_CLICKED(IDC_BUTTON_TWE, &CRemoteDlg::OnClickedButtonTwe)
	ON_BN_CLICKED(IDC_BUTTON_UP1, &CRemoteDlg::OnClickedButtonUp1)
	ON_BN_CLICKED(IDC_BUTTON_UP2, &CRemoteDlg::OnClickedButtonUp2)
	ON_BN_CLICKED(IDC_BUTTON_UP3, &CRemoteDlg::OnClickedButtonUp3)
	ON_BN_CLICKED(IDC_BUTTON_START, &CRemoteDlg::OnBnClickedButtonStart)
	ON_BN_CLICKED(IDC_BUTTON_TEST, &CRemoteDlg::OnBnClickedButtonTest)
END_MESSAGE_MAP()


// CRemoteDlg 메시지 처리기

// m_remote의 값에 따라 리모컨 버튼의 해당되는 기능이 실행
// m_remote를 view로 보내서 view에서 해당되는 함수를 call 하여 큐브를 조작
void CRemoteDlg::OnClickedButtonDown1()
{
	m_remote = 1;
	OnOK();
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CRemoteDlg::OnClickedButtonDown2()
{
	m_remote = 2;
	OnOK();
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CRemoteDlg::OnClickedButtonDown3()
{
	m_remote = 3;
	OnOK();
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CRemoteDlg::OnClickedButtonExit()
{
	m_remote = -1;
	OnOK();
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CRemoteDlg::OnClickedButtonLeft1()
{
	m_remote = 4;
	OnOK();
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CRemoteDlg::OnClickedButtonLeft2()
{
	m_remote = 5;
	OnOK();
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CRemoteDlg::OnClickedButtonLeft3()
{
	m_remote = 6;
	OnOK();
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CRemoteDlg::OnClickedButtonReset()
{
	m_remote = 13;
	OnOK();
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CRemoteDlg::OnClickedButtonRight1()
{
	m_remote = 7;
	OnOK();
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CRemoteDlg::OnClickedButtonRight2()
{
	m_remote = 8;
	OnOK();
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CRemoteDlg::OnClickedButtonRight3()
{
	m_remote = 9;
	OnOK();
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CRemoteDlg::OnClickedButtonTen()
{
	m_remote = 14;
	OnOK();
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CRemoteDlg::OnClickedButtonTwe()
{
	m_remote = 15;
	OnOK();
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CRemoteDlg::OnClickedButtonUp1()
{
	m_remote = 10;
	OnOK();
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CRemoteDlg::OnClickedButtonUp2()
{
	m_remote = 11;
	OnOK();
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CRemoteDlg::OnClickedButtonUp3()
{
	m_remote = 12;
	OnOK();
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CRemoteDlg::OnBnClickedButtonStart()
{
	m_remote = 16;
	OnOK();
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CRemoteDlg::OnBnClickedButtonTest()
{
	m_remote = 17;
	OnOK();
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}
