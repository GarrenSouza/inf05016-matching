import os, sys, subprocess

input_files_folder = "./analysis/data"
input_file_extension = "dat"
output_file_extension = "res"
output_files_folder = "./results"
binaries_folder = "./bin"
binary_name = "maxMatchWeight"

input_files = os.listdir(input_files_folder)
commands = []
input_files.sort()
for test in input_files:
    command = f"{binaries_folder}/{binary_name} {input_files_folder}/{test} >> {output_files_folder}/summary.csv"
    commands.append(command)

i = 0
while i < len(commands):
    pool = []
    jobs = 0
    while jobs < 10 and i < len(commands):
        print(f"about to run: '{commands[i]}'...")
        pool.append(subprocess.Popen(commands[i], shell=True))
        i = i + 1
        jobs = jobs + 1
    for p in pool:
        p.wait()

print("Done!")
