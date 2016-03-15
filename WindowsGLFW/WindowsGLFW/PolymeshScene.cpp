//
//  PolymeshScene.cpp
//  Lab4-PolymeshScene
//
//  Created by David Reed on 12/24/15.
//  Copyright © 2015 David M Reed. All rights reserved.
//

#include <fstream>
#include <string>
using std::string;
using std::ifstream;
using std::getline;

#include "Utils.h"

#include "PolymeshScene.hpp"

//----------------------------------------------------------------------

PolymeshScene::PolymeshScene(GLFWwindow *window) : GLFWBase(window)
{
	glfwGetWindowSize(window, &_windowWidth, &_windowHeight);
	_arrayOfPolymesh = NULL;
}

//----------------------------------------------------------------------

PolymeshScene::~PolymeshScene()
{
	if (_arrayOfPolymesh) {
		delete[] _arrayOfPolymesh;
	}
}

//----------------------------------------------------------------------

void PolymeshScene::render()
{

}

//----------------------------------------------------------------------

void PolymeshScene::keyboardCallback(GLFWwindow *window, int key, int scancode, int action, int mods)
{

}

//----------------------------------------------------------------------

void PolymeshScene::setup(std::string filename)
{
	glClearColor(0.39, 0.56, 0.85, 1);
	glEnable(GL_DEPTH_TEST);

	// read and compile shaders
	string vshaderPath = "vshader.txt";
	string fshaderPath = "fshader.txt";
	vshaderPath = pathUsingEnvironmentVariable(vshaderPath, "GL_SHADER_DIR");
	fshaderPath = pathUsingEnvironmentVariable(fshaderPath, "GL_SHADER_DIR");
	_shaderProgram.makeProgramFromShaderFiles(vshaderPath, fshaderPath);
	_shaderProgram.useProgram();

	_eyeInc = vec4(0, 0, 0, 0);
	_rotateCW = _rotateCCW = false;

	readFile(filename);
}

//----------------------------------------------------------------------

void PolymeshScene::readFile(std::string filename)
{
	ifstream ifs;

}

//----------------------------------------------------------------------

void PolymeshScene::windowSizeCallback(GLFWwindow *window, int width, int height)
{
	_windowWidth = width;
	_windowHeight = height;
	glViewport(0, 0, width, height);
}

//----------------------------------------------------------------------