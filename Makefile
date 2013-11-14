
all:
	g++ -o runner main.cpp TString.cpp
	./runner
	rm runner

clean:
	rm runner

