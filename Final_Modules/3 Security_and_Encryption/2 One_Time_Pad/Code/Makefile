#Windows Makefile for use with Microsoft C/C++ compiler
#define macros
EXECUTABLE = OTP.exe

OTP.obj : OTP.cpp
 cl /c /EHsc OTP.cpp

programops.obj : programops.cpp
 cl /c /EHsc programops.cpp

printgraphics.obj : printgraphics.cpp
 cl /c /EHsc printgraphics.cpp
 
encryption.obj : encryption.cpp
 cl /c /EHsc encryption.cpp

decryption.obj : decryption.cpp
 cl /c /EHsc decryption.cpp

custom.obj : custom.cpp
 cl /c /EHsc custom.cpp

keygen.obj : keygen.cpp
 cl /c /EHsc keygen.cpp


$(EXECUTABLE) : OTP.obj programops.obj printgraphics.obj encryption.obj decryption.obj custom.obj keygen.obj
 @echo.
 @echo Linking...
 link /out:$(EXECUTABLE) OTP.obj programops.obj printgraphics.obj encryption.obj decryption.obj custom.obj keygen.obj
 @echo Linking done!

clean:
 @echo.
 @echo Cleanup...
 del OTP.obj
 del programops.obj
 del printgraphics.obj
 del encryption.obj
 del decryption.obj
 del custom.obj
 del keygen.obj
 del $(EXECUTABLE)
 @echo Cleanup done!

all: $(EXECUTABLE)