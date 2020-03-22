# BWE
## BlackWindowEngine
## 검은 창 엔진

## 사용 방법 

### LifeCycle

Main

EngineManager

SceneManager

### SceneManager LifeCycle

Create

Render


#### How to use
```
class MyScene : public SceneManager
{
public:
    TestScene() : SceneManager()
	{
		mapPointer = new Map(30, 30);
	};

	void Create() {}

	void Resize(int x, int y) {}

	void Input(float dt) {}

	void Pause() {}
    
    ~MyScene() {}
}
```
### Object 

Constructor 

Work

#### How to use

```
class Canon : public Object
{
public:
    Canon(FPosition p, string name, string shape, Area area) : Object(p,name,shape,area) {}

    virtual void Work() {}

    virtual void OnCollision(Object* other) {}
}
```