# How I got it to work

Install RooUnfold:
```
git clone https://gitlab.cern.ch/RooUnfold/RooUnfold.git
cd RooUnfold
mkdir build
cd build
cmake ..
make -j4
```

Install CATS, see `README.md` in https://github.com/lvermunt/DLM/tree/branch_Luuk

Set all the paths. I used an alias, which also loads a virtualenvironment I am using:
```
alias start_femto='source /home/lvermunt/.virtualenvs/venv_femto/bin/activate; source /home/lvermunt/alice/sw/ubuntu1804_x86-64/ROOT/latest/bin/thisroot.sh; export CATS="/home/lvermunt/FemtoAnalysis/CATS"; export LD_LIBRARY_PATH=$(/home/lvermunt/FemtoAnalysis/CATS/bin/cats-config --libdir)${LD_LIBRARY_PATH:+:$LD_LIBRARY_PATH}; export ROOUNFOLD_ROOT="/home/lvermunt/FemtoAnalysis/RooUnfold/build/"; export LD_LIBRARY_PATH="${ROOUNFOLD_ROOT}:$LD_LIBRARY_PATH"; cd /home/lvermunt/FemtoAnalysis/GentleFemto;'
```

Build and install this repo
```
git clone https://github.com/lvermunt/GentleFemto
cd GentleFemto
cmake .
make
```

However, for my case, I had to change the paths to GSL first:
``` diff
diff --git a/GentleKitty/CMakeLists.txt b/GentleKitty/CMakeLists.txt
index 7f176c9..60b5ff6 100644
--- a/GentleKitty/CMakeLists.txt
+++ b/GentleKitty/CMakeLists.txt
@@ -8,13 +8,15 @@ endif()
 project(GentleKitty)
 # SET PATHS #
 SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
-if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
-  SET(GSL_INCLUDE "/usr/local/Cellar/gsl/2.6/include")#where are all GSL related .h files
-  SET(GSL_LIB "/usr/local/Cellar/gsl/2.6/lib")#where are the GSL .a and .so files
-else()
-  SET(GSL_INCLUDE "/usr/include/gsl")#where are all GSL related .h files
-  SET(GSL_LIB "/usr/lib/x86_64-linux-gnu/")#where are the GSL .a and .so files
-endif()
+#if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
+#  SET(GSL_INCLUDE "/usr/local/Cellar/gsl/2.6/include")#where are all GSL related .h files
+#  SET(GSL_LIB "/usr/local/Cellar/gsl/2.6/lib")#where are the GSL .a and .so files
+#else()
+#  SET(GSL_INCLUDE "/usr/include/gsl")#where are all GSL related .h files
+#  SET(GSL_LIB "/usr/lib/x86_64-linux-gnu/")#where are the GSL .a and .so files
+#endif()
+SET(GSL_INCLUDE "/cvmfs/sft.cern.ch/lcg/releases/GSL/2.6-ecdfc/x86_64-ubuntu1804-gcc7-opt/include/")#where are all GSL related .h files
+SET(GSL_LIB "/cvmfs/sft.cern.ch/lcg/releases/GSL/2.6-ecdfc/x86_64-ubuntu1804-gcc7-opt/lib")#where are the GSL .a and .so files
 SET(CATS_INCLUDE "$ENV{CATS}/include")#where are all CATS related .h files
 SET(CATS_LIB "$ENV{CATS}/lib")#where are the CATS related .a files
 SET(DREAM_PATH "${CMAKE_SOURCE_DIR}/DreamFunction")#where are all CATS related .h files
```
and moved the install directory here in the main directory
```diff
diff --git a/CMakeLists.txt b/CMakeLists.txt
index bcfcab0..aa9d2f0 100644
--- a/CMakeLists.txt
+++ b/CMakeLists.txt
@@ -1,5 +1,5 @@
 cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
-set(binFolder "${CMAKE_CURRENT_BINARY_DIR}/../install")
+set(binFolder "${CMAKE_CURRENT_BINARY_DIR}/install")
 set(CMAKE_LIBRARY_OUTPUT_DIRECTORY  ${binFolder}/lib)
 project(GentleFemto CXX C)
 enable_testing()
```

The macros to run are in this `install/*/` directories. Just run the executable and hope for the best :)

# GentleFemto

This repository contains software to compute correlation functions from experimental data and theory using CATS

Befor the installation make sure
- to have ROOT6 installed (you can use the version that comes with AliROOT just do not enter the environment, see below for workaround) 
- to have CATS installed (https://github.com/dimihayl/DLM)
- to have RooUnfold installed (the AliROOT version is too old and not sufficient - https://gitlab.cern.ch/RooUnfold/RooUnfold) 

Global Variables best defined bashrc/bash_alias/profile:
- It is important to follow the naming scheme since these will be resolved by the CMake of GentleFemto
- CATS Related: have a global variable pointing to your CATS install directory (where the subfolder bin, include and lib is)
  - export CATS=/path/to/CATS_INSTALL/
  - append the CATS libraries to your LD_LIBRARY_PATH, i.e.

    export LD_LIBRARY_PATH="/path/to/CATS_INSTALL/lib:$LD_LIBRARY_PATH" or

    export LD_LIBRARY_PATH="${CATS}/lib:$LD_LIBRARY_PATH"

- RooUnfold related: have a global variable pointing to your RooUnfold install directory (libraries and includes should end up in one directory)
  - export ROOUNFOLD_ROOT="/path/to/RooUnfold_buildorinstall/"
  - append the RooUnfold libraries to your LD_LIBRARY_PATH, i.e.

    export LD_LIBRARY_PATH="/path/to/RooUnfold_buildorinstall/:$LD_LIBRARY_PATH" or

    export LD_LIBRARY_PATH="${ROOUNFOLD_ROOT}:$LD_LIBRARY_PATH"

# Read before installing anything with ROOT

Unfortunately the RooUnfold in AliROOT is missing several methods and is diverged from the actual RooUnfold master for quite a while. If you enter the AliROOT environment you will automatically load this version and paths will be fixed and set. Therefore we cannot do that and we need a 'clean' shell. In principal one can install a standalone version of ROOT, the installation that comes with AliROOT, however, is also fine and most probably already accessible to most users.
Independent of which way you choose, before using ROOT the 'thisroot.sh' of the corresponding installation needs to be loaded. In case of an AliROOT installation, the location of this file varies a bit depending on which system you have, the times you updated your alidist, the weather and the general mood of aliBuild. You should try to look for something like this: 

alice/sw/ubuntu1804_x86-64/ROOT/v6-18-04-1/bin/thisroot.sh

Else you can just briefly enter your AliROOT environment (make sure to not use this terminal to compile anything) and just 'echo ${ROOTSYS}'. It is recommended to define a seperate alias to load ROOT e.g.

alias justROOT='. /alice/sw/ubuntu1804_x86-64/ROOT/v6-18-04-1/bin/thisroot.sh'

In order to avoid conflicts with AliROOT it can then be used to load ROOT alone in case it is needed.

