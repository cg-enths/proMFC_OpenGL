
// MFC_OpenGLView.h : CMFC_OpenGLView ��Ľӿ�
//

#pragma once
// GLEW
#define GLEW_STATIC
#include <GL/glew.h>

#include <GL/wglew.h>

// GLFW
#include <GLFW/glfw3.h>

#include <common/shader.hpp>


class CMFC_OpenGLView : public CView
{
//openGL by proverbs
protected:
	HGLRC m_hRC;    //Rendering Context��ɫ������   
	CClientDC* m_pDC;        //Device Context�豸������   
	BOOL InitializeOpenGL();    //��ʼ�� OpenGL

	GLuint shaderProgram;
	bool InitializeShader();	//��ʼ�� shader����ɫ��

	void RenderScene();         //���Ƴ���  
	int m_wide;    //m_wideΪ��CVCOpenGL2View������ӵı�ʾ�ӿڿ�ȵĳ�Ա����   
	int m_heigth;  //m_heightΪ��CVCOpenGL2View������ӵı�ʾ�ӿڸ߶ȵĳ�Ա����   

				   //Error Handling
	void SetError(int e);
	static const char* const ErrorStrings[];
	const char* m_ErrorString;

	BOOL GetRenderingContext();

	virtual BOOL GetOldStyleRenderingContext(void);
	virtual BOOL SetupPixelFormat(void);


protected: // �������л�����
	CMFC_OpenGLView();
	DECLARE_DYNCREATE(CMFC_OpenGLView)

// ����
public:
	CMFC_OpenGLDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CMFC_OpenGLView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
//	virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext = NULL);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnDestroy();
};

#ifndef _DEBUG  // MFC_OpenGLView.cpp �еĵ��԰汾
inline CMFC_OpenGLDoc* CMFC_OpenGLView::GetDocument() const
   { return reinterpret_cast<CMFC_OpenGLDoc*>(m_pDocument); }
#endif

