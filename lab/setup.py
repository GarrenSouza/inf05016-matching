import subprocess

bin_file_name = "minPerfMatchWeight"
destination_bin_folder = "bin"
build_folder = "build"
build_type = "Release"

print(f"[Generating binaries from source at '{build_folder+'/'+build_type}']")
command = f"cmake ../ -DCMAKE_BUILD_TYPE={build_type} -B{build_folder+'/'+build_type} && cmake --build {build_folder+'/'+build_type}"
process = subprocess.Popen(command, shell=True)
process.wait()

print(f"[Moving the binaries to '{destination_bin_folder}']")
command = f"cp {build_folder+'/'+build_type}/{bin_file_name} {destination_bin_folder}"
process = subprocess.Popen(command, shell=True)
process.wait()

