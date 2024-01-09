mkdir bin obj       # Create the bin and obj directories
make                # Build the project
chmod +x bin/Pong   # Make the executable executable
./bin/Pong          # Run the executable
rm -r bin           # Remove the executable
rm -r obj           # Remove the object files
clear               # Clear the terminal

cpp_files=$(find . -name '*.cpp' -o -name '*.h')  # Find C++ files
file_count=$(echo "$cpp_files" | wc -l)          # Count the number of files
line_count=$(echo "$cpp_files" | xargs wc -l | tail -n 1 | awk '{print $1}')  # Count the lines of code

echo "Pong has $file_count files and $line_count lines of C++ code!"  # Print the result