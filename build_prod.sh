mkdir bin obj       # Create the bin and obj directories
make                # Build the project
mv bin/Pong Pong    # Copy the executable to the root directory
chmod +x Pong       # Make the executable executable
rm -r bin           # Remove the executable
rm -r obj           # Remove the object files
clear               # Clear the terminal