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

    if not match():
        print('\n' + "output MisMatch")
        sys.exit()
    else:
        print('\n' + "Output Match")

    os.system("python " + "specs.py")
