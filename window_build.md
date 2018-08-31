Windows - Visual Studio 2013
============================
#### Prerequisites ####
* Microsoft Visual C++ 2013 Update 1 (the free Express edition will work)
* If you have multiple MSVS installation use MSVS Developer console from target version.
* You can build either Windows 64bit binaries.

#### Set up the directory structure ####
* Clone the TTCHAIN repository:
  ```
  With version 1.6.5 of Git and later, you can use:
  git clone --recursive https://github.com/tongtongchain/TTCHAIN.git
  cd TTCHAIN
  
  For already cloned repos, or older Git versions, use:
  git clone https://github.com/tongtongchain/TTCHAIN.git
  cd TTCHAIN
  git submodule update --init --recursive
  ```

#### TTCHAIN depends on some third party libraries - you could directly downloaded these prebuilt binary package(s) ####
* download the 3rd-party libraries through following command:  
`git clone #TODO`  or just download   [the lib2.0 release packages (#TODO)](#)
   
* and then unzip the files into the lib directory of TTCHAIN source code


#### Build the library dependencies - Skip if you downloaded the prebuilt binary package(s) ####
 * Download the 1.59 boost version (currently used) source from http://www.boost.org/users/download/
   Build boost libraries from boost source code(required for 64bit builds only):
    ```
    cd D:\TTCHAIN\boost
    bootstrap.bat
    b2.exe toolset=msvc-12.0 variant=debug,release link=static threading=multi runtime-link=shared address-model=32
    ```
    The file `D:\TTCHAIN\TTCHAIN\libraries\fc\CMakeLists.txt` has the
    `FIND_PACKAGE(Boost ...)`
    command that makes CMake link in Boost.  That file contains the line:
    ```
    set(Boost_USE_DEBUG_PYTHON ON)
    ```
    Edit this file and comment this line out (with a `#`).
    This line  tells CMake to look for a boost library that was built with
    `b2.exe link=shared python-debugging=on`.  That would cause debug builds to
    have `-gyd` mangled into their filename.  We don't need python debugging here,
    so we didn't give the `python-debugging` argument to `b2.exe`, and
    that causes our boost debug libraries to have `-gd` mangled into the filename
    instead.  If this option in `fc\CMakeLists.txt` doesn't match the way you
    compiled boost, CMake won't be able to find the debug version of the boost
    libraries, and you'll get some strange errors when you try to run the
    debug version of TTCHAIN.

* Download the latest OpenSSL source from http://www.openssl.org/source/
  Build OpenSSL DLLs
    ```
    cd D:\TTCHAIN\openssl-1.0.1g
    perl Configure --openssldir=D:\TTCHAIN\OpenSSL VC-WIN32
    ms\do_ms.bat
    nmake -f ms\ntdll.mak
    nmake -f ms\ntdll.mak install
    ```
  This will create the directory `D:\TTCHAIN\OpenSSL` with the libraries, DLLs,
  and header files.

#### Build TTCHAIN ####
* Launch *Visual Studio* and load `D:\TTCHAIN\TTCHAIN\TTCHAIN.sln` for 64 bit builds.

* *Build Solution*
