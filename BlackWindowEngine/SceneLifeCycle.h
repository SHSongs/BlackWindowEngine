#pragma once


class SceneLifeCycle
{
public:
	SceneLifeCycle() {};
	virtual void Create() = 0;			//Called when the Application is first created.
	virtual void Render(float dt) = 0;
	virtual void Resize(int x, int y) = 0;
	virtual void Input(float dt) = 0;
	virtual void Pause() = 0;			//Stop Game
	virtual ~SceneLifeCycle() {};				//Called when this Game should release all resources.
};