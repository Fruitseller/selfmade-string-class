
all:
	g++ -o runner main.cpp TString.cpp
	./runner

clean:
	rm runner