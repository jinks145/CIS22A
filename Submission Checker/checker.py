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

    os.system("cd C:/CIS22A/Assignments/")
    os.system("g++ " + "C:/CIS22A/Assignments/" + filename)
    os.system("cd C:/CIS22A/Assignments/")
    os.system(" C:/CIS22A/Assignments/" + filename.strip('.cpp') + ".exe > results.txt")

    if not match():
        print('\n' + "output MisMatch")
        sys.exit()
    else:
        print('\n' + "Output Match")

    os.system("python " + "specs.py")
