#!/bin/bash

[ -e $PWD/src/main.cpp ]
if [[ $# -eq 0 ]]
then
	if ! command -v g++ &> /dev/null 
	then
		echo "Error: g++ is not installed."
		exit 1
	else
		g++ $PWD/src/main.cpp -o shapes
		echo -e "circle 5\n rectangle 5 8\n square 8\nexit" | ./shapes  
		rm shapes
	fi
fi	


