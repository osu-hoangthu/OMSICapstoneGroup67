#Windows Makefile for use with Microsoft C/C++ compiler
#define macros
EXECUTABLE = Mastermind.exe

mastermind.obj : mastermind.cpp
 cl /c /EHsc mastermind.cpp

programoperations.obj : programoperations.cpp
 cl /c /EHsc programoperations.cpp

printgraphics.obj : printgraphics.cpp
 cl /c /EHsc printgraphics.cpp

game.obj : game.cpp
 cl /c /EHsc game.cpp

settingsoperation.obj : settingsoperation.cpp
 cl /c /EHsc settingsoperation.cpp


$(EXECUTABLE) : mastermind.obj programoperations.obj printgraphics.obj game.obj settingsoperation.obj
 @echo.
 @echo Linking...
 link /out:$(EXECUTABLE) mastermind.obj programoperations.obj printgraphics.obj game.obj settingsoperation.obj
 @echo Linking done!

clean:
 @echo.
 @echo Cleanup...
 del mastermind.obj
 del programoperations.obj
 del printgraphics.obj
 del game.obj
 del settingsoperation.obj
 del $(EXECUTABLE)
 @echo Cleanup done!

all: $(EXECUTABLE)