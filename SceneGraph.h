#pragma once
#include <vector>
#include "SceneNode.h"

using namespace std;

class SceneGraph : public SceneNode
{
public:
	SceneGraph() : SceneNode(L"Root") {};
	SceneGraph(wstring name) : SceneNode(name) {};
	~SceneGraph(void) {};

	virtual bool Initialise(void);
	virtual void Update(const Matrix& worldTransformation);
	virtual void Render(void);
	virtual void Shutdown(void);

	void Add(SceneNodePointer node);
	void Remove(SceneNodePointer node);
	SceneNodePointer Find(wstring name);

private:
	vector<SceneNodePointer>		_children;
};

typedef shared_ptr<SceneGraph>			 SceneGraphPointer;
