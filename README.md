# OpenGL
Lab works for Computer Graphics

1. Download latest GLFW binaries from the link.
https://www.glfw.org/download.html

2. Copy the code snippet to create a simple window from the link.
https://www.glfw.org/documentation.html

3. Copy the include and lib_vc2019 directories from downloaded binaries and paste it into
the Dependencies folder of your project. (Dependencies folder should be created in solution
directory of your project).

4. Select Debug->Debug Properties-> C/C++ and give the path of include directory in
Additional Include Directories.

5. Select Debug->Debug Properties-> Linker and give the path of lib_vc2019 in Additional
Library Directories.

6. Add glfw3.lib; opengl32.lib; User32.lib; Gdi32.lib; Shell32.lib inside Debug->Debug
Properties->Linker->Input->Additional Dependencies.

7. This should give you a window to start writing OpenGL.

I have included the dependencies in here but you need to create an empty C++ project and do the necessary setup as mentioned above.
