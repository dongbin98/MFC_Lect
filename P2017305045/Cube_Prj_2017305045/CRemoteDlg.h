#pragma once

// CRemoteDlg 대화 상자

class CRemoteDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CRemoteDlg)

public:
	CRemoteDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CRemoteDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_REMOTE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	int m_remote;
	afx_msg void OnClickedButtonDown1();
	afx_msg void OnClickedButtonDown2();
	afx_msg void OnClickedButtonDown3();
	afx_msg void OnClickedButtonExit();
	afx_msg void OnClickedButtonLeft1();
	afx_msg void OnClickedButtonLeft2();
	afx_msg void OnClickedButtonLeft3();
	afx_msg void OnClickedButtonReset();
	afx_msg void OnClickedButtonRight1();
	afx_msg void OnClickedButtonRight2();
	afx_msg void OnClickedButtonRight3();
	afx_msg void OnClickedButtonTen();
	afx_msg void OnClickedButtonTwe();
	afx_msg void OnClickedButtonUp1();
	afx_msg void OnClickedButtonUp2();
	afx_msg void OnClickedButtonUp3();
	afx_msg void OnBnClickedButtonStart();
	afx_msg void OnBnClickedButtonTest();
};