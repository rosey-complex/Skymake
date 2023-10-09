build:
	mkdir bin/
	/usr/bin/g++ -fdiagnostics-color=always -g -lmbedtls -lmbedx509 -lmbedcrypto skymake.cpp -o bin/skymake

clean:
	rm -r bin/

install:
	cp bin/skymake /usr/local/bin/

remove: 
	rm /usr/local/bin/skymake