//
//
//
////////################
////bridge bitt two
//class DrawAPI
//{
//public:
//	virtual void Draw() = 0;
//};
//
//class DrawImpl : public DrawAPI
//{
//public:
//	void Draw() { cout << "draw impl" << endl; }
//};
////end abstract
//class Character
//{
//public:
//	virtual void Draw() = 0;
//};
//class Player : public Character
//{
//public:
//	Player(DrawAPI* api) {
//		this->api = api;)
//		void Draw() { api->Draw(); }
//		private
//			DrawAPI* api;
//	};
//
//
//	//end refine
//
//	////'''''''#########
//
//	//proxy 1
//#ifndef IGRAPHIC_H
//#define IGRAPHIC_H
//
//	class IGraphic
//	{
//	public:
//		virtual void Draw() = 0;
//	};
//#endif
//	//real
//
//
//
//#ifndef GRAPHIC_H
//#define GRAPHIC_H
////#include "IGraphic.h"
//
//	class Graphic : public IGraphic
//	{
//	public:
//		Graphic();
//		~Graphic();
//		void Draw();
//	};
//#endif
//	//end proxy1
//
//	//proxy 2
//#include <iostream>
////#include "Graphic.h"
//	using namespace std;
//
//	Graphic::Graphic() {
//	}
//	Graphic::~Graphic() {
//	}
//	void Graphic::Draw()
//	{
//		cout << "drawing graphic" << endl;
//	}
//	//endreal
//	//define
//#ifndef GRAPHIC_PROXY_H
//#define GRAPHIC_PROXY_H
////#include "Graphic.h"
////#include "IGraphic.h"
//	class GraphicProxy : public IGraphic
//	{
//	public:
//		GraphicProxy();
//		~GraphicProxy();
//		void Draw();
//	private:
//		Graphic* graphic;
//		Graphic* getInstance(void);
//	};
//#endif
//	//end define
//	//''##
//	//proxy 3
//#include <iostream>
////#include "Graphic.h"
////#include "GraphicProxy.h"
//	using namespace std;
//	GraphicProxy::GraphicProxy()
//	{
//		this->graphic = 0;
//	}
//	GraphicProxy::~GraphicProxy()
//	{
//		if (graphic)
//			delete graphic;
//	}
//	Graphic* GraphicProxy::getInstance(void)
//	{
//		if (!graphic)
//			graphic = new Graphic();
//		return graphic;
//	}
//	void GraphicProxy::Draw()
//	{
//		getInstance()->Draw();
//	}
//	//client
//
//#include <iostream>
////#include "GraphicProxy.h"
//	using namespace std;
//
//	int main(void)
//	{
//			DrawAPI* api = new DrawImpl();
//			Character* character = new Player(api);
//			character->Draw();
//			cin.get();
//		
//	}
//	//end
//
//
