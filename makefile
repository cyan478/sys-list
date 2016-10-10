listtest: list.c
	gcc list.c -o listtest

run: listtest
	./listtest

clean:
	rm *~
