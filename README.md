# OpenGL
Lab works for Computer Graphics

i.Download latest GLFW binaries from the site glfw.org/download.html
ii.Copy the code snippet to create a simple window from the link below.
https://www.glfw.org/documentation.html
iii.Copy the include and lib_vc2019 directories from downloaded binaries and paste it into
the Dependencies folder of your project. (Dependencies folder should be created in solution
directory of your project).
iv. Select Debug->Debug Properties-> C/C++ and give the path of include directory in
Additional Include Directories.
v. Select Debug->Debug Properties-> Linker and give the path of lib_vc2019 in Additional
Library Directories.
vi. Add glfw3.lib; opengl32.lib; User32.lib; Gdi32.lib; Shell32.lib inside Debug->Debug
Properties->Linker->Input->Additional Dependencies.
vii. This should give you a window to start writing OpenGL.
