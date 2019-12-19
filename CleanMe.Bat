REM
REM Keenan's Hack to remove intermediate files
REM If you find a way to enhance, please return updates to
REM ekeenan2@cdm.depaul.edu
REM

REM cleanup root director

    rmdir /S /Q Logs
    rmdir /S /Q Debug
    rmdir /S /Q Release
    rmdir /S /Q x64
    rmdir /S /Q ipch
    rmdir /S /Q .vs
	rmdir /S /Q bin
    rmdir /S /Q Xj\bin
    rmdir /S /Q bin-int
	rmdir /S /Q Xj\obj
    del /F /S /A:H *.suo
    del /F /S *.sdf
    del /F /S *.suo
    del /F *.db
    del /F *.sln
REM walk through subdirectories delete Release & Debug subs

for /d %%D in (*) do (
	echo %%~fD
	del /F %%~D\*.bin
	del /F %%~D\*.vcxproj*
	rmdir /S /Q %%~D\Debug
	rmdir /S /Q %%~D\Release
	rmdir /S /Q %%~D\x64
)
REM pause

cd Xj/vender
for /d %%D in (*) do (
	echo %%~fD
	del /F %%~D\*.vcxproj*

    rmdir /S /Q %%~D\bin
    rmdir /S /Q %%~D\bin-int
	rmdir /S /Q %%~D\obj
)
REM pause