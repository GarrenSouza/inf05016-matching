import subprocess

#graph_size = [16, 24, 32, 48, 64, 96, 128, 192, 256]
graph_size = [10, 20, 50, 100, 200, 500]
max_module = []

bin_folder = "./bin"
bin_name = "graph_generator"
output_folder = "./analysis/data"
output_file_extension = "dat"
output_file_prefix = "gen_graph"
commands = []
for s in graph_size:
    command = f"{bin_folder+'/'+bin_name} {s} {s**2} > {output_folder+'/'+output_file_prefix+'_'+str(s)+'_'+str(s**2)+'.'+output_file_extension}"
    commands.append(command)

for c in commands:
    print(f"about to run {c}")
    p = subprocess.Popen(c, shell=True)
    p.wait()
