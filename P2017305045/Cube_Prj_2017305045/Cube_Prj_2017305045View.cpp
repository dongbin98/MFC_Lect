
// Cube_Prj_2017305045View.cpp: CCubePrj2017305045View 클래스의 구현
//
#pragma once
#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "Cube_Prj_2017305045.h"
#endif
int game = 0;
#include "Cube_Prj_2017305045Doc.h"
#include "Cube_Prj_2017305045View.h"
// 음악 재생을 위한 라이브러리 파일
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")
// 음악 파일 경로를 선언하는 부분
#define CUBEMUSIC "C:\\Users\\profe\\Desktop\\P2017305045 염동빈\\cube.wav"			// 큐브조작시 음악
#define RESETMUSIC "C:\\Users\\profe\\Desktop\\P2017305045 염동빈\\reset.wav"		// 큐브리셋시 음악
#define VICTORYMUSIC "C:\\Users\\profe\\Desktop\\P2017305045 염동빈\\victory.wav"	// 큐브맞출시 음악
#define FAILEDMUSIC "C:\\Users\\profe\\Desktop\\P2017305045 염동빈\\failed.wav"		// 큐브못맞춤 음악
#include "CRemoteDlg.h"
// 랜덤 함수를 위한 time 라이브러리 파일
#include <time.h>
#ifdef _DEBUG
#define new DEBUG_NEW
#endif
// 각종 색값을 선언하는 부분
#define BLACK RGB(93,93,93)
#define RED RGB(255,0,0)
#define BLUE RGB(51,51,255)
#define YELLOW RGB(255,204,51)
#define WHITE RGB(255,255,255)
#define GREEN RGB(0,255,0)
#define LINE RGB(0,0,0)
// CCubePrj2017305045View
IMPLEMENT_DYNCREATE(CCubePrj2017305045View, CView)

BEGIN_MESSAGE_MAP(CCubePrj2017305045View, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_CUBE_DOWN_1, &CCubePrj2017305045View::OnCubeDown1)
	ON_COMMAND(ID_CUBE_DOWN_2, &CCubePrj2017305045View::OnCubeDown2)
	ON_COMMAND(ID_CUBE_DOWN_3, &CCubePrj2017305045View::OnCubeDown3)
	ON_COMMAND(ID_CUBE_UP_1, &CCubePrj2017305045View::OnCubeUp1)
	ON_COMMAND(ID_CUBE_UP_2, &CCubePrj2017305045View::OnCubeUp2)
	ON_COMMAND(ID_CUBE_UP_3, &CCubePrj2017305045View::OnCubeUp3)
	ON_COMMAND(ID_CUBE_TEN, &CCubePrj2017305045View::OnCubeTen)
	ON_COMMAND(ID_CUBE_TWE, &CCubePrj2017305045View::OnCubeTwe)
	ON_COMMAND(ID_CUBE_RESET, &CCubePrj2017305045View::OnCubeReset)
	ON_COMMAND(ID_CUBE_LEFT_1, &CCubePrj2017305045View::OnCubeLeft1)
	ON_COMMAND(ID_CUBE_LEFT_2, &CCubePrj2017305045View::OnCubeLeft2)
	ON_COMMAND(ID_CUBE_LEFT_3, &CCubePrj2017305045View::OnCubeLeft3)
	ON_COMMAND(ID_CUBE_RIGHT_1, &CCubePrj2017305045View::OnCubeRight1)
	ON_COMMAND(ID_CUBE_RIGHT_2, &CCubePrj2017305045View::OnCubeRight2)
	ON_COMMAND(ID_CUBE_RIGHT_3, &CCubePrj2017305045View::OnCubeRight3)
	ON_COMMAND(ID_CUBE_REMOTE, &CCubePrj2017305045View::OnCubeRemote)
	ON_WM_KEYDOWN()
END_MESSAGE_MAP()

// CCubePrj2017305045View 생성/소멸

CCubePrj2017305045View::CCubePrj2017305045View() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CCubePrj2017305045View::~CCubePrj2017305045View()
{
}

BOOL CCubePrj2017305045View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}
// CCubePrj2017305045View 그리기
void CCubePrj2017305045View::OnDraw(CDC* pDC)
{
	CCubePrj2017305045Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	// 기본적인 폰트와 크기 설정 및 글자 설정
	CFont font, *pOldFont;
	font.CreatePointFont(300, _T("돋움"));
	pOldFont = (CFont*)pDC->SelectObject(&font);
	CString name = _T("2017305045 염동빈");
	CString work = _T("큐브 게임");
	CString leftside = _T("<왼쪽면>");
	CString bottomside = _T("<아랫면>");
	CString backside = _T("<뒷면>");
	pDC->SetTextColor(BLACK);
	pDC->TextOut(20, 20, name);
	pDC->TextOut(20, 60, work);
	pDC->TextOut(1070, 450, leftside);
	pDC->TextOut(1470, 450, bottomside);
	pDC->TextOut(1490, 50, backside);
	CString remote_ctrl;
	CString count_str;
	// 리모컨에 입력된 값을 명령어로 표현
	switch (cube_remote)
	{
	case 1:
		remote_ctrl = _T("입력값 : 왼쪽라인 아래");
		break;
	case 2:
		remote_ctrl = _T("입력값 : 중간라인 아래");
		break;
	case 3:
		remote_ctrl = _T("입력값 : 오른쪽라인 아래");
		break;
	case 4:
		remote_ctrl = _T("입력값 : 상단라인 왼쪽");
		break;
	case 5:
		remote_ctrl = _T("입력값 : 중간라인 왼쪽");
		break;
	case 6:
		remote_ctrl = _T("입력값 : 하단라인 왼쪽");
		break;
	case 7:
		remote_ctrl = _T("입력값 : 상단라인 오른쪽");
		break;
	case 8:
		remote_ctrl = _T("입력값 : 중간라인 오른쪽");
		break;
	case 9:
		remote_ctrl = _T("입력값 : 하단라인 오른쪽");
		break;
	case 10:
		remote_ctrl = _T("입력값 : 왼쪽라인 위");
		break;
	case 11:
		remote_ctrl = _T("입력값 : 중간라인 위");
		break;
	case 12:
		remote_ctrl = _T("입력값 : 오른쪽라인 위");
		break;
	case 13:
		remote_ctrl = _T("입력값 : 초기화");
		break;
	case 14:
		remote_ctrl = _T("입력값 : 이지모드 선택");
		break;
	case 15:
		remote_ctrl = _T("입력값 : 하드모드 선택");
		break;
	case 16:
		remote_ctrl = _T("입력값 : 게임 시작"); 
		break;
	case 17:
		remote_ctrl = _T("입력값 : 테스트용");
		break;
	case -1:
		remote_ctrl = _T("입력값 : 게임 종료");
		break;
	}
	pDC->TextOut(20, 100, remote_ctrl);
	// 남은 횟수를 표시
	count_str.Format(_T("남은기회:%d"), cube_count);
	pDC->TextOut(600, 850, count_str);
	// 큐브의 정면을 색칠하는 코드
	for (int j = 0; j <= 2; j++)
	{ 
		for (int i = 0; i <= 2; i++)
		{
			if (cube[0][i][j] == 'r')
			{
				CBrush brush(RED);
				CBrush *pOldBrush = pDC->SelectObject(&brush);
				pDC->Rectangle(500 + (j * 100), 500 + (i * 100), 600 + (j * 100), 600 + (i * 100));
				brush.DeleteObject();
			}
			else if (cube[0][i][j] == 'y')
			{
				CBrush brush(YELLOW);
				CBrush *pOldBrush = pDC->SelectObject(&brush);
				pDC->Rectangle(500 + (j * 100), 500 + (i * 100), 600 + (j * 100), 600 + (i * 100));
				brush.DeleteObject();
			}
			else if (cube[0][i][j] == 'g')
			{
				CBrush brush(GREEN);
				CBrush *pOldBrush = pDC->SelectObject(&brush);
				pDC->Rectangle(500 + (j * 100), 500 + (i * 100), 600 + (j * 100), 600 + (i * 100));
				brush.DeleteObject();
			}
			else if (cube[0][i][j] == 'b')
			{
				CBrush brush(BLACK);
				CBrush *pOldBrush = pDC->SelectObject(&brush);
				pDC->Rectangle(500 + (j * 100), 500 + (i * 100), 600 + (j * 100), 600 + (i * 100));
				brush.DeleteObject();
			}
			else if (cube[0][i][j] == 's')
			{
				CBrush brush(BLUE);
				CBrush *pOldBrush = pDC->SelectObject(&brush);
				pDC->Rectangle(500 + (j * 100), 500 + (i * 100), 600 + (j * 100), 600 + (i * 100));
				brush.DeleteObject();
			}
			else if (cube[0][i][j] == 'w')
			{
				CBrush brush(WHITE);
				CBrush *pOldBrush = pDC->SelectObject(&brush);
				pDC->Rectangle(500 + (j * 100), 500 + (i * 100), 600 + (j * 100), 600 + (i * 100));
				brush.DeleteObject();
			}
		}
	}
	// 큐브의 오른면을 색칠하는 코드
	for (int j = 0; j <= 2; j++)
	{
		for (int i = 0; i <= 2; i++)
		{
			if (cube[1][j][i] == 'r')
			{
				CPen ColorPen1(PS_SOLID, 1, RED);
				pDC->SelectObject(&ColorPen1);
				for (int k = 0; k <= 49; k++)
				{
					if (k == 0 || k == 1 || k == 48 || k == 49)
						continue;
					pDC->MoveTo(800 + (i * 50) + k, 500 - (i * 50) + (j * 100) - k);
					pDC->LineTo(800 + (i * 50) + k, 600 - (i * 50) + (j * 100) - k);
				}
			}
			else if (cube[1][j][i] == 'y')
			{
				CPen ColorPen1(PS_SOLID, 1, YELLOW);
				pDC->SelectObject(&ColorPen1);
				for (int k = 0; k <= 49; k++)
				{
					if (k == 0 || k == 1 || k == 48 || k == 49)
						continue;
					pDC->MoveTo(800 + (i * 50) + k, 500 - (i * 50) + (j * 100) - k);
					pDC->LineTo(800 + (i * 50) + k, 600 - (i * 50) + (j * 100) - k);
				}
			}
			else if (cube[1][j][i] == 'g')
			{
				CPen ColorPen1(PS_SOLID, 1, GREEN);
				pDC->SelectObject(&ColorPen1);
				for (int k = 0; k <= 49; k++)
				{
					if (k == 0 || k == 1 || k == 48 || k == 49)
						continue;
					pDC->MoveTo(800 + (i * 50) + k, 500 - (i * 50) + (j * 100) - k);
					pDC->LineTo(800 + (i * 50) + k, 600 - (i * 50) + (j * 100) - k);
				}
			}
			else if (cube[1][j][i] == 'b')
			{
				CPen ColorPen1(PS_SOLID, 1, BLACK);
				pDC->SelectObject(&ColorPen1);
				for (int k = 0; k <= 49; k++)
				{
					if (k == 0 || k == 1 || k == 48 || k == 49)
						continue;
					pDC->MoveTo(800 + (i * 50) + k, 500 - (i * 50) + (j * 100) - k);
					pDC->LineTo(800 + (i * 50) + k, 600 - (i * 50) + (j * 100) - k);
				}
			}
			else if (cube[1][j][i] == 's')
			{
				CPen ColorPen1(PS_SOLID, 1, BLUE);
				pDC->SelectObject(&ColorPen1);
				for (int k = 0; k <= 49; k++)
				{
					if (k == 0 || k == 1 || k == 48 || k == 49)
						continue;
					pDC->MoveTo(800 + (i * 50) + k, 500 - (i * 50) + (j * 100) - k);
					pDC->LineTo(800 + (i * 50) + k, 600 - (i * 50) + (j * 100) - k);
				}
			}
			else if (cube[1][j][i] == 'w')
			{
				CPen ColorPen1(PS_SOLID, 1, WHITE);
				pDC->SelectObject(&ColorPen1);
				for (int k = 0; k <= 49; k++)
				{
					if (k == 0 || k == 1 || k == 48 || k == 49)
						continue;
					pDC->MoveTo(800 + (i * 50) + k, 500 - (i * 50) + (j * 100) - k);
					pDC->LineTo(800 + (i * 50) + k, 600 - (i * 50) + (j * 100) - k);
				}
			}
		}
	}
	// 큐브의 윗면을 색칠하는 코드
	for (int j = 0; j <= 2; j++)
	{
		for (int i = 0; i <= 2; i++)
		{
			if (cube[2][j][i] == 'r')
			{
				CPen ColorPen1(PS_SOLID, 1, RED);
				pDC->SelectObject(&ColorPen1);
				for (int k = 0; k <= 99; k++)
				{
					if (k == 0 || k == 1 || k == 98 || k == 99)
						continue;
					pDC->MoveTo(650 + (i * 100) - (j * 50) + k, 350 + (j * 50));
					pDC->LineTo(600 + (i * 100) - (j * 50) + k, 400 + (j * 50));
				}
			}
			else if (cube[2][j][i] == 'y')
			{
				CPen ColorPen1(PS_SOLID, 1, YELLOW);
				pDC->SelectObject(&ColorPen1);
				for (int k = 0; k <= 99; k++)
				{
					if (k == 0 || k == 1 || k == 98 || k == 99)
						continue;
					pDC->MoveTo(650 + (i * 100) - (j * 50) + k, 350 + (j * 50));
					pDC->LineTo(600 + (i * 100) - (j * 50) + k, 400 + (j * 50));
				}
			}
			else if (cube[2][j][i] == 'g')
			{
				CPen ColorPen1(PS_SOLID, 1, GREEN);
				pDC->SelectObject(&ColorPen1);
				for (int k = 0; k <= 99; k++)
				{
					if (k == 0 || k == 1 || k == 98 || k == 99)
						continue;
					pDC->MoveTo(650 + (i * 100) - (j * 50) + k, 350 + (j * 50));
					pDC->LineTo(600 + (i * 100) - (j * 50) + k, 400 + (j * 50));
				}
			}
			else if (cube[2][j][i] == 'b')
			{
				CPen ColorPen1(PS_SOLID, 1, BLACK);
				pDC->SelectObject(&ColorPen1);
				for (int k = 0; k <= 99; k++)
				{
					if (k == 0 || k == 1 || k == 98 || k == 99)
						continue;
					pDC->MoveTo(650 + (i * 100) - (j * 50) + k, 350 + (j * 50));
					pDC->LineTo(600 + (i * 100) - (j * 50) + k, 400 + (j * 50));
				}
			}
			else if (cube[2][j][i] == 's')
			{
				CPen ColorPen1(PS_SOLID, 1, BLUE);
				pDC->SelectObject(&ColorPen1);
				for (int k = 0; k <= 99; k++)
				{
					if (k == 0 || k == 1 || k == 98 || k == 99)
						continue;
					pDC->MoveTo(650 + (i * 100) - (j * 50) + k, 350 + (j * 50));
					pDC->LineTo(600 + (i * 100) - (j * 50) + k, 400 + (j * 50));
				}
			}
			else if (cube[2][j][i] == 'w')
			{
				CPen ColorPen1(PS_SOLID, 1, WHITE);
				pDC->SelectObject(&ColorPen1);
				for (int k = 0; k <= 99; k++)
				{
					if (k == 0 || k == 1 || k == 98 || k == 99)
						continue;
					pDC->MoveTo(650 + (i * 100) - (j * 50) + k, 350 + (j * 50));
					pDC->LineTo(600 + (i * 100) - (j * 50) + k, 400 + (j * 50));
				}
			}
		}
	}
	// 큐브의 왼쪽면을 색칠하는 코드
	for (int j = 0; j <= 2; j++)
	{
		for (int i = 0; i <= 2; i++)
		{
			if (cube[4][i][j] == 'r')
			{
				CBrush brush(RED);
				CBrush *pOldBrush = pDC->SelectObject(&brush);
				pDC->Rectangle(1000 + (j * 100), 500 + (i * 100), 1100 + (j * 100), 600 + (i * 100));
				brush.DeleteObject();
			}
			else if (cube[4][i][j] == 'y')
			{
				CBrush brush(YELLOW);
				CBrush *pOldBrush = pDC->SelectObject(&brush);
				pDC->Rectangle(1000 + (j * 100), 500 + (i * 100), 1100 + (j * 100), 600 + (i * 100));
				brush.DeleteObject();
			}
			else if (cube[4][i][j] == 'g')
			{
				CBrush brush(GREEN);
				CBrush *pOldBrush = pDC->SelectObject(&brush);
				pDC->Rectangle(1000 + (j * 100), 500 + (i * 100), 1100 + (j * 100), 600 + (i * 100));
				brush.DeleteObject();
			}
			else if (cube[4][i][j] == 'b')
			{
				CBrush brush(BLACK);
				CBrush *pOldBrush = pDC->SelectObject(&brush);
				pDC->Rectangle(1000 + (j * 100), 500 + (i * 100), 1100 + (j * 100), 600 + (i * 100));
				brush.DeleteObject();
			}
			else if (cube[4][i][j] == 's')
			{
				CBrush brush(BLUE);
				CBrush *pOldBrush = pDC->SelectObject(&brush);
				pDC->Rectangle(1000 + (j * 100), 500 + (i * 100), 1100 + (j * 100), 600 + (i * 100));
				brush.DeleteObject();
			}
			else if (cube[4][i][j] == 'w')
			{
				CBrush brush(WHITE);
				CBrush *pOldBrush = pDC->SelectObject(&brush);
				pDC->Rectangle(1000 + (j * 100), 500 + (i * 100), 1100 + (j * 100), 600 + (i * 100));
				brush.DeleteObject();
			}
		}
	}
	// 큐브의 아랫면을 색칠하는 코드
	for (int j = 0; j <= 2; j++)
	{
		for (int i = 0; i <= 2; i++)
		{
			if (cube[3][i][j] == 'r')
			{
				CBrush brush(RED);
				CBrush *pOldBrush = pDC->SelectObject(&brush);
				pDC->Rectangle(1400 + (j * 100), 500 + (i * 100), 1500 + (j * 100), 600 + (i * 100));
				brush.DeleteObject();
			}
			else if (cube[3][i][j] == 'y')
			{
				CBrush brush(YELLOW);
				CBrush *pOldBrush = pDC->SelectObject(&brush);
				pDC->Rectangle(1400 + (j * 100), 500 + (i * 100), 1500 + (j * 100), 600 + (i * 100));
				brush.DeleteObject();
			}
			else if (cube[3][i][j] == 'g')
			{
				CBrush brush(GREEN);
				CBrush *pOldBrush = pDC->SelectObject(&brush);
				pDC->Rectangle(1400 + (j * 100), 500 + (i * 100), 1500 + (j * 100), 600 + (i * 100));
				brush.DeleteObject();
			}
			else if (cube[3][i][j] == 'b')
			{
				CBrush brush(BLACK);
				CBrush *pOldBrush = pDC->SelectObject(&brush);
				pDC->Rectangle(1400 + (j * 100), 500 + (i * 100), 1500 + (j * 100), 600 + (i * 100));
				brush.DeleteObject();
			}
			else if (cube[3][i][j] == 's')
			{
				CBrush brush(BLUE);
				CBrush *pOldBrush = pDC->SelectObject(&brush);
				pDC->Rectangle(1400 + (j * 100), 500 + (i * 100), 1500 + (j * 100), 600 + (i * 100));
				brush.DeleteObject();
			}
			else if (cube[3][i][j] == 'w')
			{
				CBrush brush(WHITE);
				CBrush *pOldBrush = pDC->SelectObject(&brush);
				pDC->Rectangle(1400 + (j * 100), 500 + (i * 100), 1500 + (j * 100), 600 + (i * 100));
				brush.DeleteObject();
			}
		}
	}
	// 큐브의 뒷면을 색칠하는 코드
	for (int j = 0; j <= 2; j++)
	{
		for (int i = 0; i <= 2; i++)
		{
			if (cube[5][i][j] == 'r')
			{
				CBrush brush(RED);
				CBrush *pOldBrush = pDC->SelectObject(&brush);
				pDC->Rectangle(1400 + (j * 100), 100 + (i * 100), 1500 + (j * 100), 200 + (i * 100));
				brush.DeleteObject();
			}
			else if (cube[5][i][j] == 'y')
			{
				CBrush brush(YELLOW);
				CBrush *pOldBrush = pDC->SelectObject(&brush);
				pDC->Rectangle(1400 + (j * 100), 100 + (i * 100), 1500 + (j * 100), 200 + (i * 100));
				brush.DeleteObject();
			}
			else if (cube[5][i][j] == 'g')
			{
				CBrush brush(GREEN);
				CBrush *pOldBrush = pDC->SelectObject(&brush);
				pDC->Rectangle(1400 + (j * 100), 100 + (i * 100), 1500 + (j * 100), 200 + (i * 100));
				brush.DeleteObject();
			}
			else if (cube[5][i][j] == 'b')
			{
				CBrush brush(BLACK);
				CBrush *pOldBrush = pDC->SelectObject(&brush);
				pDC->Rectangle(1400 + (j * 100), 100 + (i * 100), 1500 + (j * 100), 200 + (i * 100));
				brush.DeleteObject();
			}
			else if (cube[5][i][j] == 's')
			{
				CBrush brush(BLUE);
				CBrush *pOldBrush = pDC->SelectObject(&brush);
				pDC->Rectangle(1400 + (j * 100), 100 + (i * 100), 1500 + (j * 100), 200 + (i * 100));
				brush.DeleteObject();
			}
			else if (cube[5][i][j] == 'w')
			{
				CBrush brush(WHITE);
				CBrush *pOldBrush = pDC->SelectObject(&brush);
				pDC->Rectangle(1400 + (j * 100), 100 + (i * 100), 1500 + (j * 100), 200 + (i * 100));
				brush.DeleteObject();
			}
		}
	}
	// 큐브의 정면을 그리는 코드
	CPen LinePen(PS_SOLID, 5, LINE);
	pDC->SelectObject(&LinePen);
	pDC->MoveTo(500, 500);
	pDC->LineTo(500, 800);
	pDC->MoveTo(500, 800);
	pDC->LineTo(800, 800);
	pDC->MoveTo(800, 800);
	pDC->LineTo(800, 500);
	pDC->MoveTo(800, 500);
	pDC->LineTo(500, 500);
	pDC->MoveTo(600, 500);
	pDC->LineTo(600, 800);
	pDC->MoveTo(700, 500);
	pDC->LineTo(700, 800);
	pDC->MoveTo(500, 600);
	pDC->LineTo(800, 600);
	pDC->MoveTo(500, 700);
	pDC->LineTo(800, 700);
	// 큐브의 윗면을 그리는 코드
	pDC->MoveTo(500, 500);
	pDC->LineTo(650, 350);
	pDC->MoveTo(600, 500);
	pDC->LineTo(750, 350);
	pDC->MoveTo(700, 500);
	pDC->LineTo(850, 350);
	pDC->MoveTo(800, 500);
	pDC->LineTo(950, 350);
	pDC->MoveTo(650, 350);
	pDC->LineTo(950, 350);
	pDC->MoveTo(600, 400);
	pDC->LineTo(900, 400);
	pDC->MoveTo(550, 450);
	pDC->LineTo(850, 450);
	// 큐브의 오른쪽면을 그리는 코드
	pDC->MoveTo(850, 450);
	pDC->LineTo(850, 750);
	pDC->MoveTo(900, 400);
	pDC->LineTo(900, 700);
	pDC->MoveTo(950, 350);
	pDC->LineTo(950, 650);
	pDC->MoveTo(800, 800);
	pDC->LineTo(950, 650);
	pDC->MoveTo(800, 600);
	pDC->LineTo(950, 450);
	pDC->MoveTo(800, 700);
	pDC->LineTo(950, 550);
	// 큐브의 왼쪽면을 그리는 코드
	pDC->MoveTo(1000, 500);
	pDC->LineTo(1000, 800);
	pDC->MoveTo(1000, 800);
	pDC->LineTo(1300, 800);
	pDC->MoveTo(1300, 800);
	pDC->LineTo(1300, 500);
	pDC->MoveTo(1300, 500);
	pDC->LineTo(1000, 500);
	pDC->MoveTo(1100, 500);
	pDC->LineTo(1100, 800);
	pDC->MoveTo(1200, 500);
	pDC->LineTo(1200, 800);
	pDC->MoveTo(1000, 600);
	pDC->LineTo(1300, 600);
	pDC->MoveTo(1000, 700);
	pDC->LineTo(1300, 700);
	// 큐브의 아랫면을 그리는 코드
	pDC->MoveTo(1400, 500);
	pDC->LineTo(1400, 800);
	pDC->MoveTo(1400, 800);
	pDC->LineTo(1700, 800);
	pDC->MoveTo(1700, 800);
	pDC->LineTo(1700, 500);
	pDC->MoveTo(1700, 500);
	pDC->LineTo(1400, 500);
	pDC->MoveTo(1500, 500);
	pDC->LineTo(1500, 800);
	pDC->MoveTo(1600, 500);
	pDC->LineTo(1600, 800);
	pDC->MoveTo(1400, 600);
	pDC->LineTo(1700, 600);
	pDC->MoveTo(1400, 700);
	pDC->LineTo(1700, 700);
	// 큐브의 아랫면을 그리는 코드
	pDC->MoveTo(1400, 100);
	pDC->LineTo(1400, 400);
	pDC->MoveTo(1400, 400);
	pDC->LineTo(1700, 400);
	pDC->MoveTo(1700, 400);
	pDC->LineTo(1700, 100);
	pDC->MoveTo(1700, 100);
	pDC->LineTo(1400, 100);
	pDC->MoveTo(1500, 100);
	pDC->LineTo(1500, 400);
	pDC->MoveTo(1600, 100);
	pDC->LineTo(1600, 400);
	pDC->MoveTo(1400, 200);
	pDC->LineTo(1700, 200);
	pDC->MoveTo(1400, 300);
	pDC->LineTo(1700, 300);
	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CCubePrj2017305045View 인쇄

BOOL CCubePrj2017305045View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CCubePrj2017305045View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CCubePrj2017305045View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CCubePrj2017305045View 진단

#ifdef _DEBUG
void CCubePrj2017305045View::AssertValid() const
{
	CView::AssertValid();
}

void CCubePrj2017305045View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCubePrj2017305045Doc* CCubePrj2017305045View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCubePrj2017305045Doc)));
	return (CCubePrj2017305045Doc*)m_pDocument;
}
#endif //_DEBUG


// CCubePrj2017305045View 메시지 처리기


void CCubePrj2017305045View::OnCubeDown1()
{
	char cube_tmp[6][3][3];
	for (int i = 0; i <= 5; i++)
	{
		for (int j = 0; j <= 2; j++)
		{
			for (int k = 0; k <= 2; k++)
			{
				cube_tmp[i][j][k] = cube[i][j][k];
			}
		}
	}
	cube[3][0][0] = cube_tmp[0][0][0];
	cube[5][0][0] = cube_tmp[3][0][0];
	cube[2][0][0] = cube_tmp[5][0][0];
	cube[0][0][0] = cube_tmp[2][0][0];

	cube[3][1][0] = cube_tmp[0][1][0];
	cube[5][1][0] = cube_tmp[3][1][0];
	cube[2][1][0] = cube_tmp[5][1][0];
	cube[0][1][0] = cube_tmp[2][1][0];

	cube[3][2][0] = cube_tmp[0][2][0];
	cube[5][2][0] = cube_tmp[3][2][0];
	cube[2][2][0] = cube_tmp[5][2][0];
	cube[0][2][0] = cube_tmp[2][2][0];

	cube[4][0][2] = cube_tmp[4][0][0];
	cube[4][1][2] = cube_tmp[4][0][1];
	cube[4][2][2] = cube_tmp[4][0][2];
	cube[4][0][1] = cube_tmp[4][1][0];
	cube[4][1][1] = cube_tmp[4][1][1];
	cube[4][2][1] = cube_tmp[4][1][2];
	cube[4][0][0] = cube_tmp[4][2][0];
	cube[4][1][0] = cube_tmp[4][2][1];
	cube[4][2][0] = cube_tmp[4][2][2];

	if (cube_count > 0)
		cube_count--;
	sndPlaySound(TEXT(CUBEMUSIC), SND_ASYNC);
	Invalidate();
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}


void CCubePrj2017305045View::OnCubeDown2()
{
	char cube_tmp[6][3][3];
	for (int i = 0; i <= 5; i++)
	{
		for (int j = 0; j <= 2; j++)
		{
			for (int k = 0; k <= 2; k++)
			{
				cube_tmp[i][j][k] = cube[i][j][k];
			}
		}
	}
	cube[3][0][1] = cube_tmp[0][0][1];
	cube[5][0][1] = cube_tmp[3][0][1];
	cube[2][0][1] = cube_tmp[5][0][1];
	cube[0][0][1] = cube_tmp[2][0][1];

	cube[3][1][1] = cube_tmp[0][1][1];
	cube[5][1][1] = cube_tmp[3][1][1];
	cube[2][1][1] = cube_tmp[5][1][1];
	cube[0][1][1] = cube_tmp[2][1][1];

	cube[3][2][1] = cube_tmp[0][2][1];
	cube[5][2][1] = cube_tmp[3][2][1];
	cube[2][2][1] = cube_tmp[5][2][1];
	cube[0][2][1] = cube_tmp[2][2][1];

	if (cube_count > 0)
		cube_count--;
	sndPlaySound(TEXT(CUBEMUSIC), SND_ASYNC);
	Invalidate();
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}


void CCubePrj2017305045View::OnCubeDown3()
{
	char cube_tmp[6][3][3];
	for (int i = 0; i <= 5; i++)
	{
		for (int j = 0; j <= 2; j++)
		{
			for (int k = 0; k <= 2; k++)
			{
				cube_tmp[i][j][k] = cube[i][j][k];
			}
		}
	}
	cube[3][0][2] = cube_tmp[0][0][2];
	cube[5][0][2] = cube_tmp[3][0][2];
	cube[2][0][2] = cube_tmp[5][0][2];
	cube[0][0][2] = cube_tmp[2][0][2];

	cube[3][1][2] = cube_tmp[0][1][2];
	cube[5][1][2] = cube_tmp[3][1][2];
	cube[2][1][2] = cube_tmp[5][1][2];
	cube[0][1][2] = cube_tmp[2][1][2];

	cube[3][2][2] = cube_tmp[0][2][2];
	cube[5][2][2] = cube_tmp[3][2][2];
	cube[2][2][2] = cube_tmp[5][2][2];
	cube[0][2][2] = cube_tmp[2][2][2];

	cube[1][2][0] = cube_tmp[1][0][0];
	cube[1][1][0] = cube_tmp[1][0][1];
	cube[1][0][0] = cube_tmp[1][0][2];
	cube[1][2][1] = cube_tmp[1][1][0];
	cube[1][1][1] = cube_tmp[1][1][1];
	cube[1][0][1] = cube_tmp[1][1][2];
	cube[1][2][2] = cube_tmp[1][2][0];
	cube[1][1][2] = cube_tmp[1][2][1];
	cube[1][0][2] = cube_tmp[1][2][2];

	if (cube_count > 0)
		cube_count--;
	sndPlaySound(TEXT(CUBEMUSIC), SND_ASYNC);
	Invalidate();
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}

void CCubePrj2017305045View::OnCubeUp1()
{
	char cube_tmp[6][3][3];
	for (int i = 0; i <= 5; i++)
	{
		for (int j = 0; j <= 2; j++)
		{
			for (int k = 0; k <= 2; k++)
			{
				cube_tmp[i][j][k] = cube[i][j][k];
			}
		}
	}
	cube[0][0][0] = cube_tmp[3][0][0];
	cube[3][0][0] = cube_tmp[5][0][0];
	cube[5][0][0] = cube_tmp[2][0][0];
	cube[2][0][0] = cube_tmp[0][0][0];

	cube[0][1][0] = cube_tmp[3][1][0];
	cube[3][1][0] = cube_tmp[5][1][0];
	cube[5][1][0] = cube_tmp[2][1][0];
	cube[2][1][0] = cube_tmp[0][1][0];

	cube[0][2][0] = cube_tmp[3][2][0];
	cube[3][2][0] = cube_tmp[5][2][0];
	cube[5][2][0] = cube_tmp[2][2][0];
	cube[2][2][0] = cube_tmp[0][2][0];

	cube[4][0][0] = cube_tmp[4][0][2];
	cube[4][0][1] = cube_tmp[4][1][2];
	cube[4][0][2] = cube_tmp[4][2][2];
	cube[4][1][0] = cube_tmp[4][0][1];
	cube[4][1][1] = cube_tmp[4][1][1];
	cube[4][1][2] = cube_tmp[4][2][1];
	cube[4][2][0] = cube_tmp[4][0][0];
	cube[4][2][1] = cube_tmp[4][1][0];
	cube[4][2][2] = cube_tmp[4][2][0];

	if (cube_count > 0)
		cube_count--;
	sndPlaySound(TEXT(CUBEMUSIC), SND_ASYNC);
	Invalidate();
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}


void CCubePrj2017305045View::OnCubeUp2()
{
	char cube_tmp[6][3][3];
	for (int i = 0; i <= 5; i++)
	{
		for (int j = 0; j <= 2; j++)
		{
			for (int k = 0; k <= 2; k++)
			{
				cube_tmp[i][j][k] = cube[i][j][k];
			}
		}
	}
	cube[0][0][1] = cube_tmp[3][0][1];
	cube[3][0][1] = cube_tmp[5][0][1];
	cube[5][0][1] = cube_tmp[2][0][1];
	cube[2][0][1] = cube_tmp[0][0][1];

	cube[0][1][1] = cube_tmp[3][1][1];
	cube[3][1][1] = cube_tmp[5][1][1];
	cube[5][1][1] = cube_tmp[2][1][1];
	cube[2][1][1] = cube_tmp[0][1][1];

	cube[0][2][1] = cube_tmp[3][2][1];
	cube[3][2][1] = cube_tmp[5][2][1];
	cube[5][2][1] = cube_tmp[2][2][1];
	cube[2][2][1] = cube_tmp[0][2][1];

	if (cube_count > 0)
		cube_count--;
	sndPlaySound(TEXT(CUBEMUSIC), SND_ASYNC);
	Invalidate();
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}


void CCubePrj2017305045View::OnCubeUp3()
{
	char cube_tmp[6][3][3];
	for (int i = 0; i <= 5; i++)
	{
		for (int j = 0; j <= 2; j++)
		{
			for (int k = 0; k <= 2; k++)
			{
				cube_tmp[i][j][k] = cube[i][j][k];
			}
		}
	}
	cube[0][0][2] = cube_tmp[3][0][2];
	cube[3][0][2] = cube_tmp[5][0][2];
	cube[5][0][2] = cube_tmp[2][0][2];
	cube[2][0][2] = cube_tmp[0][0][2];

	cube[0][1][2] = cube_tmp[3][1][2];
	cube[3][1][2] = cube_tmp[5][1][2];
	cube[5][1][2] = cube_tmp[2][1][2];
	cube[2][1][2] = cube_tmp[0][1][2];

	cube[0][2][2] = cube_tmp[3][2][2];
	cube[3][2][2] = cube_tmp[5][2][2];
	cube[5][2][2] = cube_tmp[2][2][2];
	cube[2][2][2] = cube_tmp[0][2][2];

	cube[1][0][0] = cube_tmp[1][2][0];
	cube[1][0][1] = cube_tmp[1][1][0];
	cube[1][0][2] = cube_tmp[1][0][0];
	cube[1][1][0] = cube_tmp[1][2][1];
	cube[1][1][1] = cube_tmp[1][1][1];
	cube[1][1][2] = cube_tmp[1][0][1];
	cube[1][2][0] = cube_tmp[1][2][2];
	cube[1][2][1] = cube_tmp[1][1][2];
	cube[1][2][2] = cube_tmp[1][0][2];

	if (cube_count > 0)
		cube_count--;
	sndPlaySound(TEXT(CUBEMUSIC), SND_ASYNC);
	Invalidate();
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}


void CCubePrj2017305045View::OnCubeTen()
{
	OnCubeReset();
	
	int select;
	srand(time(NULL));
	for (int i = 0; i <= 4; i++)
	{
		select = rand() % 12;
		switch (select) {
			case 0:
				OnCubeDown1();
				Invalidate();
				break;
			case 1:
				OnCubeDown2();
				Invalidate();
				break;
			case 2:
				OnCubeDown3();
				Invalidate();
				break;
			case 3:
				OnCubeUp1();
				Invalidate();
				break;
			case 4:
				OnCubeUp2();
				Invalidate();
				break;
			case 5:
				OnCubeUp3();
				Invalidate();
				break;
			case 6:
				OnCubeLeft1();
				Invalidate();
				break;
			case 7:
				OnCubeLeft2();
				Invalidate();
				break;
			case 8:
				OnCubeLeft3();
				Invalidate();
				break;
			case 9:
				OnCubeRight1();
				Invalidate();
				break;
			case 10:
				OnCubeRight2();
				Invalidate();
				break;
			case 11:
				OnCubeRight3();
				Invalidate();
				break;
		}
	}
	cube_count = 20;
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}


void CCubePrj2017305045View::OnCubeTwe()
{
	OnCubeReset();
	int select;
	srand(time(NULL));
	for (int i = 0; i <= 19; i++)
	{
		select = rand() % 12;
		switch (select) {
		case 0:
			OnCubeDown1();
			Invalidate();
			break;
		case 1:
			OnCubeDown2();
			Invalidate();
			break;
		case 2:
			OnCubeDown3();
			Invalidate();
			break;
		case 3:
			OnCubeUp1();
			Invalidate();
			break;
		case 4:
			OnCubeUp2();
			Invalidate();
			break;
		case 5:
			OnCubeUp3();
			Invalidate();
			break;
		case 6:
			OnCubeLeft1();
			Invalidate();
			break;
		case 7:
			OnCubeLeft2();
			Invalidate();
			break;
		case 8:
			OnCubeLeft3();
			Invalidate();
			break;
		case 9:
			OnCubeRight1();
			Invalidate();
			break;
		case 10:
			OnCubeRight2();
			Invalidate();
			break;
		case 11:
			OnCubeRight3();
			Invalidate();
			break;
		}
	}
	cube_count = 40;
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}

void CCubePrj2017305045View::OnCubeTest()
{
	OnCubeReset();
	cube_count = 3;
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}

void CCubePrj2017305045View::OnCubeReset()
{
	for (int i = 0; i <= 2; i++)
	{
		for (int j = 0; j <= 2; j++)
		{
			cube[0][i][j] = 'r';
		}
	}
	for (int i = 0; i <= 2; i++)
	{
		for (int j = 0; j <= 2; j++)
		{
			cube[1][i][j] = 'y';
		}
	}
	for (int i = 0; i <= 2; i++)
	{
		for (int j = 0; j <= 2; j++)
		{
			cube[2][i][j] = 'g';
		}
	}
	for (int i = 0; i <= 2; i++)
	{
		for (int j = 0; j <= 2; j++)
		{
			cube[3][i][j] = 'b';
		}
	}
	for (int i = 0; i <= 2; i++)
	{
		for (int j = 0; j <= 2; j++)
		{
			cube[4][i][j] = 's';
		}
	}
	for (int i = 0; i <= 2; i++)
	{
		for (int j = 0; j <= 2; j++)
		{
			cube[5][i][j] = 'w';
		}
	}
	sndPlaySound(TEXT(RESETMUSIC), SND_ASYNC);
	cube_count = 0;
	Invalidate();
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}


void CCubePrj2017305045View::OnCubeLeft1()
{
	char cube_tmp[6][3][3];
	for (int i = 0; i <= 5; i++)
	{
		for (int j = 0; j <= 2; j++)
		{
			for (int k = 0; k <= 2; k++)
			{
				cube_tmp[i][j][k] = cube[i][j][k];
			}
		}
	}
	cube[4][0][0] = cube_tmp[0][0][0];
	cube[5][0][0] = cube_tmp[4][0][0];
	cube[1][0][0] = cube_tmp[5][0][0];
	cube[0][0][0] = cube_tmp[1][0][0];

	cube[4][0][1] = cube_tmp[0][0][1];
	cube[5][0][1] = cube_tmp[4][0][1];
	cube[1][0][1] = cube_tmp[5][0][1];
	cube[0][0][1] = cube_tmp[1][0][1];

	cube[4][0][2] = cube_tmp[0][0][2];
	cube[5][0][2] = cube_tmp[4][0][2];
	cube[1][0][2] = cube_tmp[5][0][2];
	cube[0][0][2] = cube_tmp[1][0][2];

	cube[2][0][2] = cube_tmp[2][0][0];
	cube[2][1][2] = cube_tmp[2][0][1];
	cube[2][2][2] = cube_tmp[2][0][2];
	cube[2][0][1] = cube_tmp[2][1][0];
	cube[2][1][1] = cube_tmp[2][1][1];
	cube[2][2][1] = cube_tmp[2][1][2];
	cube[2][0][0] = cube_tmp[2][2][0];
	cube[2][1][0] = cube_tmp[2][2][1];
	cube[2][2][0] = cube_tmp[2][2][2];

	if (cube_count > 0)
		cube_count--;
	sndPlaySound(TEXT(CUBEMUSIC), SND_ASYNC);
	Invalidate();
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}


void CCubePrj2017305045View::OnCubeLeft2()
{
	char cube_tmp[6][3][3];
	for (int i = 0; i <= 5; i++)
	{
		for (int j = 0; j <= 2; j++)
		{
			for (int k = 0; k <= 2; k++)
			{
				cube_tmp[i][j][k] = cube[i][j][k];
			}
		}
	}
	cube[4][1][0] = cube_tmp[0][1][0];
	cube[5][1][0] = cube_tmp[4][1][0];
	cube[1][1][0] = cube_tmp[5][1][0];
	cube[0][1][0] = cube_tmp[1][1][0];

	cube[4][1][1] = cube_tmp[0][1][1];
	cube[5][1][1] = cube_tmp[4][1][1];
	cube[1][1][1] = cube_tmp[5][1][1];
	cube[0][1][1] = cube_tmp[1][1][1];

	cube[4][1][2] = cube_tmp[0][1][2];
	cube[5][1][2] = cube_tmp[4][1][2];
	cube[1][1][2] = cube_tmp[5][1][2];
	cube[0][1][2] = cube_tmp[1][1][2];

	if (cube_count > 0)
		cube_count--;
	sndPlaySound(TEXT(CUBEMUSIC), SND_ASYNC);
	Invalidate();
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}


void CCubePrj2017305045View::OnCubeLeft3()
{
	char cube_tmp[6][3][3];
	for (int i = 0; i <= 5; i++)
	{
		for (int j = 0; j <= 2; j++)
		{
			for (int k = 0; k <= 2; k++)
			{
				cube_tmp[i][j][k] = cube[i][j][k];
			}
		}
	}
	cube[4][2][0] = cube_tmp[0][2][0];
	cube[5][2][0] = cube_tmp[4][2][0];
	cube[1][2][0] = cube_tmp[5][2][0];
	cube[0][2][0] = cube_tmp[1][2][0];

	cube[4][2][1] = cube_tmp[0][2][1];
	cube[5][2][1] = cube_tmp[4][2][1];
	cube[1][2][1] = cube_tmp[5][2][1];
	cube[0][2][1] = cube_tmp[1][2][1];

	cube[4][2][2] = cube_tmp[0][2][2];
	cube[5][2][2] = cube_tmp[4][2][2];
	cube[1][2][2] = cube_tmp[5][2][2];
	cube[0][2][2] = cube_tmp[1][2][2];

	cube[3][2][0] = cube_tmp[3][0][0];
	cube[3][1][0] = cube_tmp[3][0][1];
	cube[3][0][0] = cube_tmp[3][0][2];
	cube[3][2][1] = cube_tmp[3][1][0];
	cube[3][1][1] = cube_tmp[3][1][1];
	cube[3][0][1] = cube_tmp[3][1][2];
	cube[3][2][2] = cube_tmp[3][2][0];
	cube[3][1][2] = cube_tmp[3][2][1];
	cube[3][0][2] = cube_tmp[3][2][2];

	if (cube_count > 0)
		cube_count--;
	sndPlaySound(TEXT(CUBEMUSIC), SND_ASYNC);
	Invalidate();
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}


void CCubePrj2017305045View::OnCubeRight1()
{
	char cube_tmp[6][3][3];
	for (int i = 0; i <= 5; i++)
	{
		for (int j = 0; j <= 2; j++)
		{
			for (int k = 0; k <= 2; k++)
			{
				cube_tmp[i][j][k] = cube[i][j][k];
			}
		}
	}
	cube[0][0][0] = cube_tmp[4][0][0];
	cube[4][0][0] = cube_tmp[5][0][0];
	cube[5][0][0] = cube_tmp[1][0][0];
	cube[1][0][0] = cube_tmp[0][0][0];

	cube[0][0][1] = cube_tmp[4][0][1];
	cube[4][0][1] = cube_tmp[5][0][1];
	cube[5][0][1] = cube_tmp[1][0][1];
	cube[1][0][1] = cube_tmp[0][0][1];

	cube[0][0][2] = cube_tmp[4][0][2];
	cube[4][0][2] = cube_tmp[5][0][2];
	cube[5][0][2] = cube_tmp[1][0][2];
	cube[1][0][2] = cube_tmp[0][0][2];

	cube[2][2][0] = cube_tmp[2][0][0];
	cube[2][1][0] = cube_tmp[2][0][1];
	cube[2][0][0] = cube_tmp[2][0][2];
	cube[2][2][1] = cube_tmp[2][1][0];
	cube[2][1][1] = cube_tmp[2][1][1];
	cube[2][0][1] = cube_tmp[2][1][2];
	cube[2][2][2] = cube_tmp[2][2][0];
	cube[2][1][2] = cube_tmp[2][2][1];
	cube[2][0][2] = cube_tmp[2][2][2];

	if (cube_count > 0)
		cube_count--;
	sndPlaySound(TEXT(CUBEMUSIC), SND_ASYNC);
	Invalidate();
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}


void CCubePrj2017305045View::OnCubeRight2()
{
	char cube_tmp[6][3][3];
	for (int i = 0; i <= 5; i++)
	{
		for (int j = 0; j <= 2; j++)
		{
			for (int k = 0; k <= 2; k++)
			{
				cube_tmp[i][j][k] = cube[i][j][k];
			}
		}
	}
	cube[0][1][0] = cube_tmp[4][1][0];
	cube[4][1][0] = cube_tmp[5][1][0];
	cube[5][1][0] = cube_tmp[1][1][0];
	cube[1][1][0] = cube_tmp[0][1][0];
	
	cube[0][1][1] = cube_tmp[4][1][1];
	cube[4][1][1] = cube_tmp[5][1][1];
	cube[5][1][1] = cube_tmp[1][1][1];
	cube[1][1][1] = cube_tmp[0][1][1];

	cube[0][1][2] = cube_tmp[4][1][2];
	cube[4][1][2] = cube_tmp[5][1][2];
	cube[5][1][2] = cube_tmp[1][1][2];
	cube[1][1][2] = cube_tmp[0][1][2];

	if (cube_count > 0)
		cube_count--;
	sndPlaySound(TEXT(CUBEMUSIC), SND_ASYNC);
	Invalidate();
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}


void CCubePrj2017305045View::OnCubeRight3()
{
	char cube_tmp[6][3][3];
	for (int i = 0; i <= 5; i++)
	{
		for (int j = 0; j <= 2; j++)
		{
			for (int k = 0; k <= 2; k++)
			{
				cube_tmp[i][j][k] = cube[i][j][k];
			}
		}
	}
	cube[0][2][0] = cube_tmp[4][2][0];
	cube[4][2][0] = cube_tmp[5][2][0];
	cube[5][2][0] = cube_tmp[1][2][0];
	cube[1][2][0] = cube_tmp[0][2][0];

	cube[0][2][1] = cube_tmp[4][2][1];
	cube[4][2][1] = cube_tmp[5][2][1];
	cube[5][2][1] = cube_tmp[1][2][1];
	cube[1][2][1] = cube_tmp[0][2][1];

	cube[0][2][2] = cube_tmp[4][2][2];
	cube[4][2][2] = cube_tmp[5][2][2];
	cube[5][2][2] = cube_tmp[1][2][2];
	cube[1][2][2] = cube_tmp[0][2][2];

	cube[3][0][2] = cube_tmp[3][0][0];
	cube[3][1][2] = cube_tmp[3][0][1];
	cube[3][2][2] = cube_tmp[3][0][2];
	cube[3][0][1] = cube_tmp[3][1][0];
	cube[3][1][1] = cube_tmp[3][1][1];
	cube[3][2][1] = cube_tmp[3][1][2];
	cube[3][0][0] = cube_tmp[3][2][0];
	cube[3][1][0] = cube_tmp[3][2][1];
	cube[3][2][0] = cube_tmp[3][2][2];

	if (cube_count > 0)
		cube_count--;
	sndPlaySound(TEXT(CUBEMUSIC), SND_ASYNC);
	Invalidate();
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}

void CCubePrj2017305045View::OnCubeRemote()
{
	CRemoteDlg m_CubeDlg;
	while (1)
	{
		m_CubeDlg.DoModal();
		SetRemote(m_CubeDlg.m_remote);	// Dlg 내의 m_remote 멤버변수를 SetRemote를 통해 cube_remote 값에 넣어준다.
		if (cube_remote == -1)
		{
			game = 0;
			break;
		}
		switch (cube_remote)
		{
		case 1:
			OnCubeDown1();
			if (game == 1)
				GameStart();
			Invalidate();
			break;
		case 2:
			OnCubeDown2();
			if (game == 1)
				GameStart();
			Invalidate();
			break;
		case 3:
			OnCubeDown3();
			if (game == 1)
				GameStart();
			Invalidate();
			break;
		case 4:
			OnCubeLeft1();
			if (game == 1)
				GameStart();
			Invalidate();
			break;
		case 5:
			OnCubeLeft2();
			if (game == 1)
				GameStart();
			Invalidate();
			break;
		case 6:
			OnCubeLeft3();
			if (game == 1)
				GameStart();
			Invalidate();
			break;
		case 7:
			OnCubeRight1();
			if (game == 1)
				GameStart();
			Invalidate();
			break;
		case 8:
			OnCubeRight2();
			if (game == 1)
				GameStart();
			Invalidate();
			break;
		case 9:
			OnCubeRight3();
			if (game == 1)
				GameStart();
			Invalidate();
			break;
		case 10:
			OnCubeUp1();
			if (game == 1)
				GameStart();
			Invalidate();
			break;
		case 11:
			OnCubeUp2();
			if (game == 1)
				GameStart();
			Invalidate();
			break;
		case 12:
			OnCubeUp3();
			if (game == 1)
				GameStart();
			Invalidate();
			break;
		case 13:
			OnCubeReset();
			game = 0;
			Invalidate();
			break;
		case 14:
			OnCubeTen();
			Invalidate();
			break;
		case 15:
			OnCubeTwe();
			Invalidate();
			break;
		case 16:
			game = 1;
			break;
		case 17:
			OnCubeTest();
			Invalidate();
		}
	}
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}

void CCubePrj2017305045View::SetRemote(int input)
{
	// 리모컨 값 받아오는 함수
	cube_remote = input;	// Dlg의 멤버변수 m_remote를 cube_remote에 대입
	Invalidate();
}

void CCubePrj2017305045View::GameStart()
{
	// 게임시작 후 큐브가 원래대로 돌아왔는지 확인해서 정답 및 실패 확인
	int answer_count = 0;
	if (cube_count > 0)
	{
		for (int i = 0; i <= 5; i++)
		{
			if (cube[i][0][0] == cube[i][0][1] && cube[i][0][0] == cube[i][0][2] && cube[i][0][0] == cube[i][1][0])
			{
				if (cube[i][1][0] == cube[i][1][1] && cube[i][1][0] == cube[i][1][2] && cube[i][1][0] == cube[i][2][0])
				{
					if (cube[i][2][0] == cube[i][2][1] && cube[i][2][0] == cube[i][2][2])
					{
						answer_count++;
					}
				}
			}
		}
		if (answer_count == 6)
		{
			sndPlaySound(TEXT(VICTORYMUSIC), SND_ASYNC);
			AfxMessageBox(_T("축하드립니다! 주어진 기회안에 정답을 맞추셨습니다. 게임이 종료됩니다."));
			game = 0;
		}
	}
	answer_count = 0;
	if (cube_count == 0)
	{
		for (int i = 0; i <= 5; i++)
		{
			if (cube[i][0][0] == cube[i][0][1] && cube[i][0][0] == cube[i][0][2] && cube[i][0][0] == cube[i][1][0])
			{
				if (cube[i][1][0] == cube[i][1][1] && cube[i][1][0] == cube[i][1][2] && cube[i][1][0] == cube[i][2][0])
				{
					if (cube[i][2][0] == cube[i][2][1] && cube[i][2][0] == cube[i][2][2])
					{
						answer_count++;
					}
				}
			}
		}
		if (answer_count == 6)
		{
			sndPlaySound(TEXT(VICTORYMUSIC), SND_ASYNC);
			AfxMessageBox(_T("축하드립니다! 주어진 기회안에 정답을 맞추셨습니다. 게임이 종료됩니다."));
			game = 0;
		}
		if (answer_count != 6)
		{
			sndPlaySound(TEXT(FAILEDMUSIC), SND_ASYNC);
			AfxMessageBox(_T("안타깝습니다. 주어진 기회안에 정답을 맞추지 못하셨습니다. 게임이 종료됩니다."));
			game = 0;
		}
	}
}

void CCubePrj2017305045View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	CView::OnKeyDown(nChar, nRepCnt, nFlags);
	if (nChar == VK_UP)
		MessageBox(_T("UP키를 누르셨습니다"));
	else if (nChar == VK_DOWN)
		MessageBox(_T("DOWN키를 누르셨습니다"));
	else if (nChar == VK_LEFT)
		MessageBox(_T("LEFT키를 누르셨습니다"));
	else if (nChar == VK_RIGHT)
		MessageBox(_T("RIGHT키를 누르셨습니다"));
	else if (WM_KEYDOWN)
	{
		CString msg;
		msg.Format(_T("값 : %d"), nChar);
		MessageBox(msg);
	}
}
