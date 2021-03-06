
// Cube_Prj_2017305045View.h: CCubePrj2017305045View 클래스의 인터페이스
//

#pragma once

class CCubePrj2017305045View : public CView
{
protected: // serialization에서만 만들어집니다.
	CCubePrj2017305045View() noexcept;
	DECLARE_DYNCREATE(CCubePrj2017305045View)

// 특성입니다.
public:
	CCubePrj2017305045Doc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~CCubePrj2017305045View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	char cube[6][3][3] = {
		{						// 정면 빨강
			{'r', 'r', 'r'},	// cube[0][0][0] ~ cube[0][0][2]
			{'r', 'r', 'r'},	// cube[0][1][0] ~ cube[0][1][2]
			{'r', 'r', 'r'},	// cube[0][2][0] ~ cube[0][2][2]
		},
		{						// 우측면 노랑
			{'y', 'y', 'y'},	// cube[1][0][0] ~ cube[1][0][2]
			{'y', 'y', 'y'},	// cube[1][1][0] ~ cube[1][1][2]
			{'y', 'y', 'y'}		// cube[1][2][0] ~ cube[1][2][2]
		},
		{						// 상단 초록
			{'g', 'g', 'g'},	// cube[2][0][0] ~ cube[2][0][2]
			{'g', 'g', 'g'},	// cube[2][1][0] ~ cube[2][1][2]
			{'g', 'g', 'g'}		// cube[2][2][0] ~ cube[2][2][2]
		},
		{						// 하단 검정
			{'b', 'b', 'b'},	// cube[3][0][0] ~ cube[3][0][2]
			{'b', 'b', 'b'},	// cube[3][1][0] ~ cube[3][1][2]
			{'b', 'b', 'b'}		// cube[3][2][0] ~ cube[3][2][2]
		},
		{						// 좌측면 파랑
			{'s', 's', 's'},	// cube[4][0][0] ~ cube[4][0][2]
			{'s', 's', 's'},	// cube[4][1][0] ~ cube[4][1][2]
			{'s', 's', 's'}		// cube[4][2][0] ~ cube[4][2][2]
		},
		{						// 뒷면 하양
			{'w', 'w', 'w'},	// cube[5][0][0] ~ cube[5][0][2]
			{'w', 'w', 'w'},	// cube[5][1][0] ~ cube[5][1][2]
			{'w', 'w', 'w'}		// cube[5][2][0] ~ cube[5][2][2]
		}
	};
	// 큐브 조작 함수원형 선언
	afx_msg void OnCubeDown1();
	afx_msg void OnCubeDown2();
	afx_msg void OnCubeDown3();
	afx_msg void OnCubeUp1();
	afx_msg void OnCubeUp2();
	afx_msg void OnCubeUp3();
	afx_msg void OnCubeLeft1();
	afx_msg void OnCubeLeft2();
	afx_msg void OnCubeLeft3();
	afx_msg void OnCubeRight1();
	afx_msg void OnCubeRight2();
	afx_msg void OnCubeRight3();
	// 큐브 섞는 함수원형 선언
	afx_msg void OnCubeTen();
	afx_msg void OnCubeTwe();
	afx_msg void OnCubeTest();
	// 큐브 리셋 함수원형 선언
	afx_msg void OnCubeReset();
	// 큐브 리모컨 함수원형 선언
	afx_msg void OnCubeRemote();
	// 게임 시작 함수원형 선언
	void GameStart();
	// 리모컨에 값을 보내주는 함수 선언
	void SetRemote(int input);
	// 카운트값과 리모컨조작용 멤버변수
	int cube_count = 0;
	int cube_remote = 0;
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
};

#ifndef _DEBUG  // Cube_Prj_2017305045View.cpp의 디버그 버전
inline CCubePrj2017305045Doc* CCubePrj2017305045View::GetDocument() const
   { return reinterpret_cast<CCubePrj2017305045Doc*>(m_pDocument); }
#endif

