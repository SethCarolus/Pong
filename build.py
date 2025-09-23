import subprocess
import os


subprocess.run([os.getcwd() + "/vendor/premake/linux/premake5", "gmake"])
subprocess.run("make")
subprocess.run(os.getcwd() +  "/bin/Debug/Pong")