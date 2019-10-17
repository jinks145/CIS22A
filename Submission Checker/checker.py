import sys
import os


def match():
    result = open('results.txt').readlines()
    original = open('original.txt').readlines()

    if original == result:
        return True
    else:
        return False


if __name__ == '__main__':
    print("run code file :")
    filename = input()

    os.system("g++ " + filename)
    os.system(filename.strip('.cpp') + ".exe > results.txt")

    if not match():
        print("output MisMatch")
        sys.exit()
    else:
        print("Output Match")

    os.system("python " + "specs.py")
