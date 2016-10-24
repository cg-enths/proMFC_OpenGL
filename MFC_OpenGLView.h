
// MFC_OpenGLView.h : CMFC_OpenGLView ��Ľӿ�
//

#pragma once

// GLEW
#define GLEW_STATIC
#include <GL/glew.h>

#include <GL/wglew.h>

// GLFW
#include <GLFW/glfw3.h>

// GLM
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

// GL includes
#include <learnopengl/shader.h>
#include <learnopengl/camera.h>


// #include <SOIL/SOIL.h>
#include <FreeImage.h>


class CMFC_OpenGLView : public CView
{
//openGL by proverbs
protected:
	HGLRC m_hRC;    //Rendering Context��ɫ������   
	CClientDC* m_pDC;        //Device Context�豸������   
	BOOL InitializeOpenGL();    //��ʼ�� OpenGL
	BOOL GetRenderingContext();
	virtual BOOL GetOldStyleRenderingContext();
	virtual BOOL SetupPixelFormat();	//�������ظ�ʽ  

	Shader *ourShader;
	bool InitializeShader();	//��ʼ�� shader����ɫ��

	void RenderScene();         //���Ƴ���  
	int m_wide;    //m_wideΪ��View������ӵı�ʾ�ӿڿ�ȵĳ�Ա����   
	int m_heigth;  //m_heightΪ��View������ӵı�ʾ�ӿڸ߶ȵĳ�Ա����   

	//Error Handling
	void SetError(int e);
	static const char* const ErrorStrings[];
	const char* m_ErrorString;

	// control view
	Camera *camera;

	bool keys[1024];
	int lastX, lastY;
	bool firstMouse;
	bool isPress;// �������Ƿ���

	void do_movement();
	


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
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags);
};

#ifndef _DEBUG  // MFC_OpenGLView.cpp �еĵ��԰汾
inline CMFC_OpenGLDoc* CMFC_OpenGLView::GetDocument() const
   { return reinterpret_cast<CMFC_OpenGLDoc*>(m_pDocument); }
#endif

