// dc290View.cpp : implementation of the CDc290View class
//



#include "stdafx.h"
#include "dc290.h"
#include "DlgHistogram.h"
#include "dc290Doc.h"
#include "dc290View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDc290View

IMPLEMENT_DYNCREATE(CDc290View, CScrollView)

BEGIN_MESSAGE_MAP(CDc290View, CScrollView)
	//{{AFX_MSG_MAP(CDc290View)
	ON_WM_LBUTTONDOWN()
	ON_COMMAND(ID_GRAY, OnGray)
	ON_UPDATE_COMMAND_UI(ID_GRAY, OnUpdateGray)
	ON_COMMAND(ID_HISTOGRAM, OnHistogram)
	ON_COMMAND(ID_LINETRANS, OnLinetrans)
	ON_UPDATE_COMMAND_UI(ID_LINETRANS, OnUpdateLinetrans)
	ON_COMMAND(ID_EQUALIZE, OnEqualize)
	ON_UPDATE_COMMAND_UI(ID_EQUALIZE, OnUpdateEqualize)
	ON_UPDATE_COMMAND_UI(ID_FOURIER, OnUpdateFourier)
	ON_COMMAND(ID_FOURIER, OnFourier)
	ON_COMMAND(ID_IFOURIER, OnIFourier)
	ON_UPDATE_COMMAND_UI(ID_IFOURIER, OnUpdateIFourier)
	ON_COMMAND(ID_FFT, OnFft)
	ON_UPDATE_COMMAND_UI(ID_FFT, OnUpdateFft)
	ON_COMMAND(ID_IFFT, OnIfft)
	ON_UPDATE_COMMAND_UI(ID_IFFT, OnUpdateIfft)
	ON_COMMAND(ID_AVERAGE_FILTER, OnAverageFilter)
	ON_UPDATE_COMMAND_UI(ID_AVERAGE_FILTER, OnUpdateAverageFilter)
	ON_COMMAND(ID_MEDIAN_FILTER, OnMedianFilter)
	ON_UPDATE_COMMAND_UI(ID_MEDIAN_FILTER, OnUpdateMedianFilter)
	ON_COMMAND(ID_GRAD_SHARP, OnGradSharp)
	ON_UPDATE_COMMAND_UI(ID_GRAD_SHARP, OnUpdateGradSharp)
	ON_COMMAND(ID_RAPLAS_SHARP, OnRaplasSharp)
	ON_UPDATE_COMMAND_UI(ID_RAPLAS_SHARP, OnUpdateRaplasSharp)
	ON_COMMAND(ID_IDEAL_FILTER, OnIdealFilter)
	ON_UPDATE_COMMAND_UI(ID_IDEAL_FILTER, OnUpdateIdealFilter)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CScrollView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDc290View construction/destruction

CDc290View::CDc290View()
{
	// TODO: add construction code here

}

CDc290View::~CDc290View()
{
}

BOOL CDc290View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CScrollView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CDc290View drawing

extern BITMAPINFO *lpBitsInfo;
extern BITMAPINFO *lpDIB_FFT;
extern BITMAPINFO *lpDIB_IFFT;
void CDc290View::OnDraw(CDC* pDC)
{
	CDc290Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	if (NULL == lpBitsInfo)
		return;
	LPVOID lpBits = (LPVOID)&lpBitsInfo -> bmiColors[lpBitsInfo->bmiHeader.biClrUsed];
	StretchDIBits(
		pDC->GetSafeHdc(),
		0, 0,
		lpBitsInfo->bmiHeader.biWidth,
		lpBitsInfo->bmiHeader.biHeight,
		0, 0,
		lpBitsInfo->bmiHeader.biWidth,
		lpBitsInfo->bmiHeader.biHeight,
		lpBits,
		lpBitsInfo,
		DIB_RGB_COLORS,
		SRCCOPY);
	// TODO: add draw code for native data here
	if (lpDIB_FFT)
	{
		lpBits = (LPVOID)&lpDIB_FFT->bmiColors[lpDIB_FFT->bmiHeader.biClrUsed];
		StretchDIBits( 
			pDC->GetSafeHdc(),
			600,0,
			lpDIB_FFT->bmiHeader.biWidth,
			lpDIB_FFT->bmiHeader.biHeight,
			0,0,
			lpDIB_FFT->bmiHeader.biWidth,
			lpDIB_FFT->bmiHeader.biHeight,
			lpBits,
			lpDIB_FFT, // bitmap data 
			DIB_RGB_COLORS,
			SRCCOPY);
	}
	
	if (lpDIB_IFFT)
	{
		lpBits = (LPVOID)&lpDIB_IFFT->bmiColors[lpDIB_IFFT->bmiHeader.biClrUsed];
		StretchDIBits( 
			pDC->GetSafeHdc(),
			0,600,
			lpDIB_IFFT->bmiHeader.biWidth,
			lpDIB_IFFT->bmiHeader.biHeight,
			0,0,
			lpDIB_IFFT->bmiHeader.biWidth,
			lpDIB_IFFT->bmiHeader.biHeight,
			lpBits,
			lpDIB_IFFT, // bitmap data 
			DIB_RGB_COLORS,
			SRCCOPY);
	}

}

void CDc290View::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();
/*
	CSize sizeTotal;
	// TODO: calculate the total size of this view
	sizeTotal.cx = sizeTotal.cy = 100;
	SetScrollSizes(MM_TEXT, sizeTotal);
*/
	CSize sizeTotal;
	sizeTotal.cx=10000;
	sizeTotal.cy=10000;
	SetScrollSizes(MM_TEXT,sizeTotal);
}

/////////////////////////////////////////////////////////////////////////////
// CDc290View printing

BOOL CDc290View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CDc290View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CDc290View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CDc290View diagnostics

#ifdef _DEBUG
void CDc290View::AssertValid() const
{
	CScrollView::AssertValid();
}

void CDc290View::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CDc290Doc* CDc290View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDc290Doc)));
	return (CDc290Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDc290View message handlers
void pixel(int i, int j);
void CDc290View::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	pixel(point.y, point.x);
	CScrollView::OnLButtonDown(nFlags, point);
}

void gray();
void CDc290View::OnGray() 
{
	// TODO: Add your command handler code here
	gray();
	Invalidate();

}

void CDc290View::OnUpdateGray(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(lpBitsInfo != NULL && lpBitsInfo->bmiHeader.biBitCount == 24);
}

void CDc290View::OnHistogram() 
{
	// TODO: Add your command handler code here
	CDlgHistogram dlg;
	dlg.DoModal();
}

void LinerTrans(float, float);
void CDc290View::OnLinetrans() 
{
	// TODO: Add your command handler code here
	LinerTrans(2, -100);
	Invalidate();

}

void CDc290View::OnUpdateLinetrans(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(lpBitsInfo != NULL && lpBitsInfo->bmiHeader.biBitCount == 8);
}
void Equalize();
void CDc290View::OnEqualize() 
{
	// TODO: Add your command handler code here
	Equalize();
	Invalidate();

}

void CDc290View::OnUpdateEqualize(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(lpBitsInfo != NULL && lpBitsInfo->bmiHeader.biBitCount == 8);
}


void Fourier();
void CDc290View::OnFourier() 
{
	// TODO: Add your command handler code here
	Fourier();
	Invalidate();

}

void CDc290View::OnUpdateFourier(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(lpBitsInfo != NULL && lpBitsInfo->bmiHeader.biBitCount == 8);
}

void IFourier();
void CDc290View::OnIFourier() 
{
	// TODO: Add your command handler code here
	IFourier();
	Invalidate();

}

void CDc290View::OnUpdateIFourier(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(lpBitsInfo != NULL && lpBitsInfo->bmiHeader.biBitCount == 8);
}

void FFourier();
void CDc290View::OnFft() 
{
	// TODO: Add your command handler code here
	if (lpDIB_FFT)
		free(lpDIB_FFT);

	FFourier();
	Invalidate();

}

void CDc290View::OnUpdateFft(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(lpBitsInfo != NULL && lpBitsInfo->bmiHeader.biBitCount == 8);
}

void IFFourier();
void CDc290View::OnIfft() 
{
	// TODO: Add your command handler code here
	if (lpDIB_IFFT)
		free(lpDIB_IFFT);

	IFFourier();
	Invalidate();

}

void CDc290View::OnUpdateIfft(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(lpDIB_FFT != NULL);
}

void AverageFilter();
void CDc290View::OnAverageFilter() 
{
	// TODO: Add your command handler code here
	AverageFilter();
	Invalidate();
}

void CDc290View::OnUpdateAverageFilter(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(lpBitsInfo != NULL);
}

void MedianFilter();
void CDc290View::OnMedianFilter() 
{
	// TODO: Add your command handler code here
	MedianFilter();
	Invalidate();
}

void CDc290View::OnUpdateMedianFilter(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(lpBitsInfo != NULL);
}

void GradSharp();
void CDc290View::OnGradSharp() 
{
	// TODO: Add your command handler code here
	GradSharp();
	Invalidate();
}

void CDc290View::OnUpdateGradSharp(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(lpBitsInfo != NULL);
}

void RaplasSharp();
void CDc290View::OnRaplasSharp() 
{
	// TODO: Add your command handler code here
	RaplasSharp();
	Invalidate();
}

void CDc290View::OnUpdateRaplasSharp(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(lpBitsInfo != NULL);
}

void Ideal_Filter_FFT(int D);
void CDc290View::OnIdealFilter() 
{
	// TODO: Add your command handler code here
	Ideal_Filter_FFT(66);
	Invalidate();
}

void CDc290View::OnUpdateIdealFilter(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(lpBitsInfo != NULL);
}
