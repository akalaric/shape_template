#!/bin/bash

[ -e $PWD/src/main.cpp ]
if [[ $# -eq 0 ]]
then
	if ! command -v g++ &> /dev/null 
	then
		echo "Error: g++ is not installed."
		exit 1
	else
		g++ $PWD/src/main.cpp -o ShapeTemplate
		./ShapeTemplate
		rm ShapeTemplate
	fi
fi	

if [[ $1 == Docker ]]
then	
	if ! which docker &> /dev/null
	then
		echo "Docker not installed"
	else
		docker build . --file Dockerfile --tag image:ci_workflow || { echo "Failed to run image"; exit 1; }
		docker run --rm image:ci_workflow || { echo "Failed to run image"; exit 1; }
	fi
elif [[ $# -ne 0 ]]
then
	echo "Wrong argument"
fi

