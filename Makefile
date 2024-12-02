CombinationSum2: CombinationSum2.o
	g++ -g -o CombinationSum2.exe CombinationSum2.o -pthread    

CombinationSum2.o: CombinationSum2/CombinationSum2.cpp
	g++ -g  -c -pthread CombinationSum2/CombinationSum2.cpp
