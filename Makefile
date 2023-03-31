input=input.txt
output=output.txt
expected=golden.txt
result=result.txt

run:
	g++ main.cpp gaussMethod.cpp matrix.cpp  -o main
	./main < $(input) > $(output)
test:
	g++ test.cpp gaussMethod.cpp matrix.cpp  -o test
	./test < test_input.txt > test_output.txt
	

clean:
	rm -rf main $(output) test_output.txt test result
