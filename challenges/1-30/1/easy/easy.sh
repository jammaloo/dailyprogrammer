#!/bin/bash
#
# create a program that will ask the users name, age, and reddit username. have it tell them the information back, in the format:
# your name is (blank), you are (blank) years old, and your username is (blank)
# for extra credit, have the program log this information in a file to be accessed later.
#

echo "What is your name?"
read name
echo "What is your age?"
read age
echo "What is your Reddit username?"
read username

output="Your name is $name, you are $age years old, and your username is $username"
echo $output
echo $output >> logfile
