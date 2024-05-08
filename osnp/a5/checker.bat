@echo off

D:
cd \workspace\cp\competition\osnp\a5

g++ -std=c++17 soln.cpp -o soln
g++ -std=c++17 brute.cpp -o brute
g++ -std=c++17 test.cpp -o test

for /l %%x in (1, 1, 100) do (
	test > inp.in
	soln < inp.in > out1.out
	brute < inp.in > out2.out
	fc (out2.out out1.out > diagnostic) || (
		type inp.in
		echo,
		type out1.out
		echo,
		type out2.out
		exit /b
	)
)

echo done