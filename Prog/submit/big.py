
with open("bigB.txt", "w") as f:
    for j in range(5):
        for i in range(513):
            f.write(".")
        f.write("\n")
