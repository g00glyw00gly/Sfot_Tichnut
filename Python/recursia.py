# recursia.py
# Ori P
# 15.2.23
#
# this script recives a path to a directory
# and prints all sub-direcories and files
# using a recursive function.

# Imports
import os

# Constants

def list_files(path, all_files):
    """
    Recursivly lists all files in the path given,
    including sub-directories
    """
    current_files = os.listdir(path)

    # Goes over every file in the directory
    for file in current_files:
        file_path = os.path.join(path, file)

        # Checks if file is another directory
        if os.path.isdir(file_path):
            list_files(file_path, all_files)
        else:
            all_files[file] = path
            
    return all_files
    

def main():
    all_files = {}
    path = input('Enter directory path --> ').strip('"')
    list_files(path, all_files)

    # Prints results nicely
    for file in all_files:
        print(f'parent directory --> "{all_files[file]}" | Name --> "{file}"')

    
if __name__ == "__main__":
    main()
