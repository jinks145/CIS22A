import os

if __name__ == '__main__':
    print("run code file :")
    filename = input()

    os.system("g++ " + filename)
    os.system(filename.strip(".", len(filename).exe) + ".exe > results.txt")
    os.system("python " + "CodeTest.py")
    os.system("python " + "specs.py")

