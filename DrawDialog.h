#pragma once


// CDrawDialog �Ի���

class CDrawDialog : public CDialog
{
	DECLARE_DYNAMIC(CDrawDialog)

public:
	CDrawDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDrawDialog();
// Opengl����
	int MyModel;

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DRAW };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
};
