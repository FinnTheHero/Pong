cpp_files=$(find . -name '*.cpp' -o -name '*.h')                                    # Find C++ files
file_count=$(echo "$cpp_files" | wc -l)                                             # Count the number of files
line_count=$(echo "$cpp_files" | xargs wc -l | tail -n 1 | awk '{print $1}')        # Count the lines of code
size=$(wc -c Pong | awk '{printf "%.2f", $1/1024}')                                 # Calculate size

echo "Pong has $file_count files, $line_count lines and is $size KBs!"              # Print the results