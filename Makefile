build:
	mkdir bin/
	g++ -fdiagnostics-color=always -g -O3 -std=c++17 -lmbedtls -lmbedx509 -lmbedcrypto skymake.cpp -o bin/skymake

clean:
	rm -r bin/

install:
	cp bin/skymake /usr/local/bin/

remove: 
	rm /usr/local/bin/skymake