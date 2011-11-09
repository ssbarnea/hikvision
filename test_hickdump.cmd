hikdump\release\hikdump.exe sample.264 >%~dp0result_cpp.log
hikdump\debug\hikdump.exe sample.264 >%~dp0result_cpp_debug.log
cd /D %~dp0SDK
python %~dp0hikdump.py sample.264 >%~dp0result_py.log
cd %~dp0


