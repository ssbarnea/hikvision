import sys, time, logging, os, tempfile
import ctypes, ctypes.wintypes
from ctypes import *
from ctypes.wintypes import DWORD

indexed = False

def pyCallbackFileRefDone(port, user_data):
    global indexed
    indexed = True
    print("Callback called, file is indexed (%s,%s)" % (port, user_data))

if len(sys.argv) != 2:
    sys.exit("Called with invalid number of parameters. You need to specify the video filename.")

MY_CALLBACK = WINFUNCTYPE(None, DWORD, DWORD)
cbFunc = MY_CALLBACK(pyCallbackFileRefDone)

try:
    dll = os.path.join(os.path.dirname(os.path.abspath(__file__)), "PlayCtrl.dll") # the directory with the .py file
    dll2 = os.path.join("PlayCtrl.dll") # currnet directory
    if not os.path.isfile(dll):
        if not os.path.isfile(dll2):
            raise Exception("File not found: %s or %s" % (dll,dll2))
        else:
            hsdk = ctypes.WinDLL(dll2) # STEP-1
    else:
        hsdk = ctypes.WinDLL(dll) # STEP-1
except Exception, e:
    print("Unable to load HISDK player library (PlayCtrl.dll).\n%s" % e)
    raise e

port = c_long(0)

version = "%.8x" % hsdk.PlayM4_GetSdkVersion()
print version, " <- PlayM4_GetSdkVersion()"

width = c_long(0)
height = c_long(0)
if not hsdk.PlayM4_GetPictureSize(port, byref(width), byref(height)):
    sys.exit("PlayM4_GetPictureSize() returned False.")
print "%sx%s <- PlayM4_GetPictureSize()" % (width.value, height.value)

port = hsdk.PlayM4_GetPort(byref(port))
print port, " <- PlayM4_GetPort()" # STEP-2

sample_video_file = os.path.join(os.path.dirname(os.path.abspath(__file__)), sys.argv[1])

ret = hsdk.PlayM4_SetFileRefCallBack(port, cbFunc, DWORD(0)) # STEP-3
print ret, " <- PlayM4_SetFileRefCallBack()"
if not ret:
    sys.exit("Unable to set callback for indexing")

ret = hsdk.PlayM4_OpenFile(port, sample_video_file) # STEP-4
print ret, " <- PlayM4_OpenFile()"
if not ret: 
    sys.exit("Unable to open video file %s" % sys.argv[1])

while not indexed:
    logging.info("Waiting for indexing to finish...") # STEP-5
    time.sleep(0.5)

total_frames = hsdk.PlayM4_GetFileTotalFrames(port) # STEP-6
print total_frames, " <- PlayM4_GetFileTotalFrames()"

print hsdk.PlayM4_Play(port, 0), " <- PlayM4_Play(port,0)" # STEP-7
print hsdk.PlayM4_Pause(port, 1), " <- PlayM4_Pause(port,1)" # STEP-8

# putting first and last 5 frames into `frames` list
limit = min(100, total_frames)
frames = range(0,limit)
#frames.extend(range(total_frames-limit, total_frames))

errors = 0
successes = 0

for i in frames:
    ret = hsdk.PlayM4_SetCurrentFrameNum (port, i) # STEP-9
    got = hsdk.PlayM4_GetCurrentFrameNum(port) # STEP-10
    if not ret or not got==i:
        print("Expect %s but got %s" % (i, got))
        errors += 1
    else:
        successes += 1

print("Test ended with %s failures and %s successes." % (errors, successes))
