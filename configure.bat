@echo off

setlocal
    set "ErrorText="
    set "ErrorCode=0"
    set "Platform=x64"
    set "Toolset=v141"
    set "CMakeGeneratorName=Visual Studio 15 2017 Win64"
    
    if "%Platform%"=="x86" (
        if "%Toolset%"=="v140" set "CMakeGeneratorName=Visual Studio 14 2015"
        if "%Toolset%"=="v141" set "CMakeGeneratorName=Visual Studio 15 2017"
    )
    
    if "%Platform%"=="x64" (
        if "%Toolset%"=="v140" set "CMakeGeneratorName=Visual Studio 14 2015 Win64"
        if "%Toolset%"=="v141" set "CMakeGeneratorName=Visual Studio 15 2017 Win64"
    )

    set "BuildDir=%~dp0products\%Platform%-windows"
    set "InstallDir=%~dp0installed\%Platform%-windows"

    if not exist "%BuildDir%" mkdir "%BuildDir%

    ( pushd "%BuildDir%" ^
   && call cmake.exe -G "%CMakeGeneratorName%" ^
    -DCMAKE_INSTALL_PREFIX="%InstallDir%" ^
    -DBUILD_TESTING=ON ^
    "%~dp0" ^
   && popd ) || (set ErrorCode=%errorlevel% & goto :ErrorLabel)

    goto :OKLabel
:ErrorLabel

:OKLabel
endlocal & exit /b %ErrorCode%