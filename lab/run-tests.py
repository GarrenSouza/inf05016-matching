import os, sys, subprocess

input_files_folder = "./analysis/data/"
input_file_extension = "dat"
output_file_extension = "res"
output_files_folder = "./results"
binaries_folder = "./bin"

input_files = os.listdir(input_files_folder)
commands = []

for test in input_files:
    command = f"{binaries_folder}/minPerfMatchWeight < {input_files_folder}/{test} > {output_files_folder}/{test.replace(input_file_extension, output_file_extension)}"
    commands.append(command)

i = 0
while i < len(commands):
    pool = []
    j = 0
    while j < 3 and i < len(commands):
        print(f"about to run: '{commands[i]}'...")
        pool.append(subprocess.Popen(commands[i], shell=True))
        i = i + 1
        j = j + 1
    for p in pool:
        p.wait()
print("Done!")
