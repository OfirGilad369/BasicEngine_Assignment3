#pragma once   //maybe should be static class
#include "display.h"
#include "game.h"
#include <iostream>
#include <fstream>


	void mouse_callback(GLFWwindow* window,int button, int action, int mods)
	{	
		if(action == GLFW_PRESS )
		{
			Game *scn = (Game*)glfwGetWindowUserPointer(window);
			double x2,y2;
			glfwGetCursorPos(window,&x2,&y2);
			scn->Picking((int)x2,(int)y2);
		}
	}
	
	void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
	{
		Game *scn = (Game*)glfwGetWindowUserPointer(window);
		//scn->MyTranslate(glm::vec3(0,0,xoffset),0);

		scn->MyTranslate(glm::vec3(0, 0, yoffset), 0);
	}
	
	void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		Game *scn = (Game*)glfwGetWindowUserPointer(window);

		if(action == GLFW_PRESS || action == GLFW_REPEAT)
		{
			switch (key)
			{
				case GLFW_KEY_ESCAPE:			
					glfwSetWindowShouldClose(window,GLFW_TRUE);
				break;
				//case GLFW_KEY_SPACE:
				//	if(scn->IsActive())
				//		scn->Deactivate();
				//	else
				//		scn->Activate();
				//break;

				//case GLFW_KEY_UP:
				//	scn->MoveCamera(0,scn->zTranslate,0.4f);
				//	break;
				//case GLFW_KEY_DOWN:
				//	//scn->shapeTransformation(scn->xGlobalRotate,-5.f);
				//	//cout<< "down: "<<endl;
				//	scn->MoveCamera(0,scn->zTranslate,-0.4f);
				//	break;

				// New Keys
				case GLFW_KEY_R:
					std::cout << "R Pressed" << std::endl;
					scn->rubiks_cube.CASE_R();
					break;
				case GLFW_KEY_L:
					std::cout << "L Pressed" << std::endl;
					scn->rubiks_cube.CASE_L();
					break;
				case GLFW_KEY_U:
					std::cout << "U Pressed" << std::endl;
					scn->rubiks_cube.CASE_U();
					break;
				case GLFW_KEY_D:
					std::cout << "D Pressed" << std::endl;
					scn->rubiks_cube.CASE_D();
					break;
				case GLFW_KEY_B:
					std::cout << "B Pressed" << std::endl;
					scn->rubiks_cube.CASE_B();
					break;
				case GLFW_KEY_F:
					std::cout << "F Pressed" << std::endl;
					scn->rubiks_cube.CASE_F();
					break;
				case GLFW_KEY_SPACE:
					std::cout << "Space Pressed" << std::endl;
					scn->rubiks_cube.CASE_SPACE();
					break;
				case GLFW_KEY_Z:
					std::cout << "Z Pressed" << std::endl;
					scn->rubiks_cube.CASE_Z();
					break;
				case GLFW_KEY_A:
					std::cout << "A Pressed" << std::endl;
					scn->rubiks_cube.CASE_A();
					break;
				case GLFW_KEY_UP:
					std::cout << "UP Pressed" << std::endl;
					scn->rubiks_cube.CASE_UP();
					break;
				case GLFW_KEY_DOWN:
					std::cout << "DOWN Pressed" << std::endl;
					scn->rubiks_cube.CASE_DOWN();
					break;
				case GLFW_KEY_LEFT:
					std::cout << "LEFT Pressed" << std::endl;
					scn->rubiks_cube.CASE_LEFT();
					break;
				case GLFW_KEY_RIGHT:
					std::cout << "RIGHT Pressed" << std::endl;
					scn->rubiks_cube.CASE_RIGHT();
					break;
				case GLFW_KEY_I:
					std::cout << "I Pressed" << std::endl;
					scn->rubiks_cube.CASE_I();
					break;
				case GLFW_KEY_O:
					std::cout << "O Pressed" << std::endl;
					scn->rubiks_cube.CASE_O();
					break;
				case GLFW_KEY_P:
					std::cout << "P Pressed" << std::endl;
					scn->rubiks_cube.CASE_P();
					break;
				case GLFW_KEY_M:
					std::cout << "M Pressed" << std::endl;
					scn->rubiks_cube.CASE_M();
					break;

			default:
				break;
			}
		}
	}
	
	void cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
	{
		Game *scn = (Game*)glfwGetWindowUserPointer(window);

		scn->UpdatePosition((float)xpos,(float)ypos);
		if(glfwGetMouseButton(window,GLFW_MOUSE_BUTTON_RIGHT) == GLFW_PRESS)
		{
			scn->MouseProccessing(GLFW_MOUSE_BUTTON_RIGHT);
		}
		else if(glfwGetMouseButton(window,GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS)
		{
			scn->MouseProccessing(GLFW_MOUSE_BUTTON_LEFT);
		}

	}

	void window_size_callback(GLFWwindow* window, int width, int height)
	{
		Game *scn = (Game*)glfwGetWindowUserPointer(window);

		scn->Resize(width,height);
		
	}

	void Init(Display &display)
	{
		display.AddKeyCallBack(key_callback);
		display.AddMouseCallBacks(mouse_callback,scroll_callback,cursor_position_callback);
		display.AddResizeCallBack(window_size_callback);
	}
