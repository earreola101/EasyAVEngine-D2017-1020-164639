Set Project=EasyVideoBayer3
Set Project1=EasyVideoBayer3
set ProjectFolder=m:\video\Tools\Windows\VideoOnly\DirectShowDLL-Multiple\EasyVideoCOM\Samples\EasyVideoBayer3\Build\
Set ProjectFile="%ProjectFolder%\%Project%X86.iss"
echo =========================================================================================
echo This library is created by Juiwen_Hsu@ap.Logitech.com Since 2011 
echo =========================================================================================
echo Clear folder
echo =========================================================================================
rem del /S /Q /F "%Project%\*.*"
del /S /Q /F "%Project%-Setup\%Project%X86.exe" 
"C:\Program Files (x86)\Inno Setup 5\iscc.exe" /cc %ProjectFile%
"C:\Program Files\Inno Setup 5\iscc.exe" /cc %ProjectFile%
echo =========================================================================================
echo Create sub folder
echo =========================================================================================
mkdir %ProjectFolder%-Setup
echo =========================================================================================
echo Copy %Project% module files...
echo =========================================================================================
call M:\video\Tools\Windows\Release\AutoVersion.exe
call M:\video\Tools\Windows\Release\AutoVersion.bat
zip.exe  %Project%X86-%BUILD_AUTO_VERSION%.ZIP  ".\%Project%-Setup\*.*" -D -r -9  -x*.zip
Xcopy  /y %ProjectFolder%\%Project%X86-%BUILD_AUTO_VERSION%.ZIP  %ProjectFolder%\%Project%-Setup\
Xcopy  /y %ProjectFolder%\%Project%X86-%BUILD_AUTO_VERSION%.ZIP  %ProjectFolder%\%Project%-Setup-Latest-One\
Xcopy  /y %ProjectFolder%\%Project%-Setup\*.exe  %ProjectFolder%\%Project%-Setup-Latest-One\
