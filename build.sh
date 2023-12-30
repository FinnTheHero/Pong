mkdir bin obj       # Create the bin and obj directories
make                # Build the project
chmod +x bin/Pong   # Make the executable executable
./bin/Pong          # Run the executable
clear               # Clear the terminal
rm -r bin           # Remove the executable
rm -r obj           # Remove the object files
find . \( -name '*.cpp' -o -name '*.h' \) | xargs wc -l | tail -n 1 | awk '{print "Pong has " $1 " lines of C++ code"}' # Count the lines of code