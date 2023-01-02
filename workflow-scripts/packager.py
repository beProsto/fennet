#!/usr/bin/python3

# This script is used by the "release.yml" github workflow to package built binaries for releases

# This script is intended to be run from the main project directory, like this:
# python3 ./workflow-scripts/packager.py <name>

# <name> is the only argument taken by the packager, it's the name of the currently built package.


import os
import sys

packageName = sys.argv[1]

if not os.path.isdir("packaged"):
  os.makedirs("packaged")

toExport = []

examplesFolderScan = os.scandir(path="examples")
for entry in examplesFolderScan:
  if entry.is_dir():
    fname = str(entry.name)
    if os.name == 'nt':
      fname += ".exe"
    toExport.append(fname)

buildFolderScan = os.scandir(path="build")
for entry in buildFolderScan:
  if entry.is_file():
    fname = str(entry.name)
    if fname.endswith(".lib") or fname.endswith(".a") or fname.endswith(".dll") or fname.endswith(".so"):
      toExport.append(fname)

print("- Detected files to export from ./build/:")
for entry in toExport:
  print(entry)

# tar -cvzf ./packaged/packageName.zip ./build/*toExport
os.chdir("build")
cmdlinetopkg = ""
for entry in toExport:
  cmdlinetopkg += " "+entry
pre = "../packaged/"
ext = ".tar.gz"
if os.name == 'nt':
  pre = "..\\packaged\\"
  ext = ".zip"
os.system("tar -caf "+pre+packageName+ext + cmdlinetopkg)
print("- Package '"+packageName+ext+"' Generated.")