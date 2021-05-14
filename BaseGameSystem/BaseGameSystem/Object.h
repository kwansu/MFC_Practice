#pragma once


class Object
{
protected:
	CPointR	m_ptPos;
	CPointR	m_ptCenterOfMass;
	CRect	m_rtRigidBody;
	CImage	m_imgPlate;

public:
	Object*	m_pNextObject;

public:
	Object();
	~Object();

	void SetPosition(CPointR);
	void DrawObject();
	BOOL SetImage(CImage*);

};

