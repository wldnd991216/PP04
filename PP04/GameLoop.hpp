#include <iostream>
#include <chrono>
#include <thread>
#include <windows.h>
#include "MconsolUtil.hpp"
#include <string>
using namespace std;

namespace MuSeoun_Engine {




	class MGameLoop {

	private:
		bool _isGameRinning;
		MConsolRenderer cRenderer;

	public:
		MGameLoop() {
			_isGameRinning = false;
		}
		~MGameLoop() {}

		void Run()
		{
			_isGameRinning = true;

			Initialize();

			while (_isGameRinning) {
				Input(); // 입력
				Update(); //고침 (계속실행)
				Render(); //화면 표시
			}

			
		}

		void Stop() {
			_isGameRinning = false;
		}

	private :

		

		void Initialize()
		{
			//SetCursorState(false);
		}

		void Input() {
			if (GetAsyncKeyState(VK_SPACE) == -0x8000 || GetAsyncKeyState(VK_SPACE) == -0x8001)
			{
				
			}
			else
			{

			}
			
		}
		void Update() {

		}
		void Render() {

			chrono::system_clock::time_point startRenderTimePoint = chrono::system_clock::now();
			chrono::system_clock::time_point startRenderTimePoint = chrono::system_clock::
			//system("cls");
			//cout << "Rendering...";

			cRenderer.Clear();
			cRenderer.MoveCursor(10, 20);
			cRenderer.DrawString("test");

			chrono::duration<double> renderDuration = chrono::system_clock::now() - startRenderTimePoint;

			string fps = "FPS(milliseconds) : " + to_string(renderDuration.count());
			cRenderer.DrawString(fps);

			//cout << "Rendering speed : " << renderDuration.count() << "sec" << endl;

			//int remainingFrameTime = 100 - (int)(renderDuration.count() * 1000.0); //100초 넘어가면 그만하라는 뜻

			//if (remainingFrameTime > 0)
			//	this_thread::sleep_for(chrono::milliseconds(remainingFrameTime)); 
		}

		/*void Release(){}

	private :
		void MoveCursor(short x, short y) {
			COORD position = { x , y };
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
		}
		void SetCursorState(bool visible) {
			CONSOLE_CURSOR_INFO consoleCursorInfo;
			consoleCursorInfo.bVisible = visible;
			consoleCursorInfo.dwSize = 1;
			SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &consoleCursorInfo);

		}*/
	};
}

