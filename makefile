all: cmake

documentation:
	-@doxygen > /dev/null

cmake : DebugDir ReleaseDir
	# Genere une configuration de debug dans Debug
	cd Debug; cmake -DCMAKE_BUILD_TYPE=Debug ..
	# Genere une configuration de release dans Release
	cd Release; cmake -DCMAKE_BUILD_TYPE=Release ..

DebugDir:
	mkdir -p Debug

ReleaseDir:
	mkdir -p Release

clean:
	@rm -rf Debug
	@rm -rf Release
	@rm -rf doxygen