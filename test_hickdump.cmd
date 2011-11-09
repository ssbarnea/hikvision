::set SAMPLE=sample.264
set SAMPLE=sample-fullres.264

hikdump\release\hikdump.exe %SAMPLE% >%~dp0result_cpp.log
hikdump\debug\hikdump.exe %SAMPLE% >%~dp0result_cpp_debug.log
cd /D %~dp0SDK
python %~dp0hikdump.py %SAMPLE% >%~dp0result_py.log
cd %~dp0


