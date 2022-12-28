CC  = gcc
CXX = g++
G = Unix Makefiles
J = 10
LT = SHARED
BT = Release

usual: build-usual
	cmake --build ./build -j $(J)
build-usual:
	cmake -B ./build -DCMAKE_EXPORT_COMPILE_COMMANDS=1 "-DCMAKE_C_COMPILER:FILEPATH=$(CC)" "-DCMAKE_CXX_COMPILER:FILEPATH=$(CXX)" "-DCMAKE_BUILD_TYPE=$(BT)" "-DLIBTYPE=$(LT)" -G "$(G)"

test:
	echo "Temporarily not running any Tests."

doc:
	doxygen

clean:
	git clean -d -f -x ./build ./docs