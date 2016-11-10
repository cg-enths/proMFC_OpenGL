
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
#include "learnopengl/shader.h"
#include "learnopengl/camera.h"
#include "learnopengl/model.h"



// #include <SOIL/SOIL.h>
#include <FreeImage.h>

#include "DrawDialog.h"


class CMFC_OpenGLView : public CView
{
private:
	enum TRANS {NONE = 0, ROTATE_X, ROTATE_Y, ROTATE_Z, MOVE_X, MOVE_Y, MOVE_Z, SCALE};
	TRANS trans_type;
	enum GRAPH_T {NONE_M = 0, XK_M, M_M, SJ_M, WL_M};
	GRAPH_T viewModel;

//openGL by proverbs
protected:
	HGLRC m_hRC;    //Rendering Context��ɫ������   
	CClientDC* m_pDC;        //Device Context�豸������   
	BOOL InitializeOpenGL();    //��ʼ�� OpenGL
	BOOL GetRenderingContext();
	virtual BOOL GetOldStyleRenderingContext();
	virtual BOOL SetupPixelFormat();	//�������ظ�ʽ  

	Shader *ourShader;

	void RenderScene();         //���Ƴ���  
	int m_wide;    //m_wideΪ��View������ӵı�ʾ�ӿڿ�ȵĳ�Ա����   
	int m_height;  //m_heightΪ��View������ӵı�ʾ�ӿڸ߶ȵĳ�Ա����   

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
	

	// ��ͼ
	GLuint VBO, containerVAO;
	GLuint cubeVAO, cubeVBO;
	GLuint cubeTexture;
	GLuint lightVAO;
	GLuint diffuseMap, specularMap, emissionMap;
	Shader *lightingShader, *lampShader, *shader;
	
	// ͸������������
	std::vector<glm::vec3> windows;

	// ����
	Model *ourModel;

	GLuint loadTexture(GLchar const * path, GLboolean alpha);

	// ����objģ�͵ı任����
	glm::mat4 *model;
	


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
	afx_msg void OnDrawOpt();
	afx_msg void OnDrawLoad();
	afx_msg void OnRotateX();
	afx_msg void OnUpdateRotateX(CCmdUI *pCmdUI);
	afx_msg void OnRotateY();
	afx_msg void OnUpdateRotateY(CCmdUI *pCmdUI);
	afx_msg void OnRotateZ();
	afx_msg void OnUpdateRotateZ(CCmdUI *pCmdUI);
	afx_msg void OnMoveX();
	afx_msg void OnUpdateMoveX(CCmdUI *pCmdUI);
	afx_msg void OnMoveY();
	afx_msg void OnUpdateMoveY(CCmdUI *pCmdUI);
	afx_msg void OnMoveZ();
	afx_msg void OnUpdateMoveZ(CCmdUI *pCmdUI);
	afx_msg void OnScale();
	afx_msg void OnUpdateScale(CCmdUI *pCmdUI);
	afx_msg void OnNone();
	afx_msg void OnUpdateNone(CCmdUI *pCmdUI);
};

#ifndef _DEBUG  // MFC_OpenGLView.cpp �еĵ��԰汾
inline CMFC_OpenGLDoc* CMFC_OpenGLView::GetDocument() const
   { return reinterpret_cast<CMFC_OpenGLDoc*>(m_pDocument); }
#endif

