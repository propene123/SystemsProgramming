
with open("bigB.txt", "w") as f:
    for j in range(5):
        for i in range(512):
            f.write(".")
        f.write("\n")
