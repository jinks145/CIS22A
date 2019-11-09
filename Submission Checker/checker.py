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

    print("CIS Assignment Check\nFilename: ")
    filename = input()

    os.system("cd c:/CIS22A/Assignments")
    os.system("g++ -o " + "c:/CIS22A/Assignments/" + filename)
    os.system(filename + "> results.txt")

    if not match():
        print('\n' + "output MisMatch")
        sys.exit()
    else:
        print('\n' + "Output Match")


