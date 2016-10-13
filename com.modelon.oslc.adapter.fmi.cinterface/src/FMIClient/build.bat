
SET FMILIB="../../fmi/FMILibrary-2.0.2b3-win32"
SET INCLUDE=%INCLUDE%;"../../fmi/FMILibrary-2.0.2b3-win32/include"
SET LIB=%LIB%;"../../fmi/FMILibrary-2.0.2b3-win32/lib"

del FMIClient.obj
del FMIClient.exe

cl src/FMIClient.c  /DYNAMICBASE "kernel32.lib" "user32.lib" "gdi32.lib" "winspool.lib" "shell32.lib" "ole32.lib" "oleaut32.lib" "uuid.lib" "comdlg32.lib" "advapi32.lib" "%FMILIB%/lib/fmilib_shared.lib"
