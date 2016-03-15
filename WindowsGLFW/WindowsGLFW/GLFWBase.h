//
//  GLFWBase.h
//  GLFWDemo
//
//  Created by David M. Reed on 2/18/15.
//  Copyright (c) 2015 David Reed. All rights reserved.
//

#ifndef __GLFWDemo__GLFWBase__
#define __GLFWDemo__GLFWBase__

#include <GLFW/glfw3.h>

class GLFWBase {

public:
    //
    GLFWBase(GLFWwindow* window);

    // should not need to overrride, but set virtual in case you do need to
    // if wait for events is true, uses glfwWaitEvents() otherwise uses glfwPollEvents
    virtual void runLoop(bool waitForEvents = true);

    // this is the method you generally override for displaying your scene
    // called by event loop to do the rendering
    virtual void render();

    // input callbacks
    // more details of parameters are here: http://www.glfw.org/docs/latest/input.html

    // override to handle keyboard input
    // default implementation quits on pressing Q or Esc
    virtual void keyboardCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

    // called whenever cursor position changes
    virtual void cursorPositionCallback(GLFWwindow* window, double xPos, double yPos);

    // called whenever cursor enters or leaves window
    virtual void cursorEnterCallback(GLFWwindow* window, int entered);

    // called when a mouse button is pressed or released
    virtual void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods, double xPos, double yPos);

    // called when mouse/trackpad is scrolled
    virtual void scrollCallback(GLFWwindow* window, double xOffset, double yOffset);

    // access the GLFWwindow
    GLFWwindow* window() { return _window; }

protected:
    GLuint _vao;

private:
    GLFWwindow *_window;
    static void staticKeyboardCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
    static void staticCursorPositionCallback(GLFWwindow* window, double xPos, double yPos);
    static void staticCursorEnterCallback(GLFWwindow* window, int entered);
    static void staticMouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
    static void staticScrollCallback(GLFWwindow* window, double xOffset, double yOffset);
};
#endif /* defined(__GLFWDemo__GLFWBase__) */
