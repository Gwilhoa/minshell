import os
import sys
from pathlib import Path
name = "header.py"
def find_headers(file): 
    headers = ["/********    " + os.path.basename(file) + "    ********/"]
    infile = open(file, "r")
    content = infile.readlines()
    infile.close()
    for line in content:
        if line[0].isalpha() and line[len(line) - 1] != ';':
            headers.append(line.strip() + ';')
    return headers
def tab_len(str):
    i = 0
    for char in str:
        if char == '\t':
            i += 4 - (i % 4)
            continue
        i += 1
    return i
def align_headers(headers):
    strlen = 0
    ret = []
    for header in headers:
        if header[0] == '/':
            continue
        if len(header.split('\t')[0]) > strlen:
            strlen = len(header.split('\t')[0])
    strlen += 4 - (strlen % 4)
    for header in headers:
        if (header[0] == '/'):
            ret.append(header)
            continue
        splitted = header.split('\t')
        while tab_len(splitted[0]) != strlen:
            splitted[0] = splitted[0] + '\t'
        ret.append(splitted[0] + splitted[1])
    return ret
def write_to_header(headers, header_name, dir_name):
    outfile = open(dir_name + '/' + header_name, "w")
    define_name = header_name.upper().replace('.', '_')
    outfile.write("\n#ifndef " +  define_name + '\n') 
    outfile.write("# define " +  define_name + '\n\n')
    for header in headers:
        if (header[0] == '/'):
            outfile.write('\n' + header + '\n\n')
            continue
        splitted = header.split('\t')[1][0 : 5]
        if (splitted == "main(" or header.split(' ')[0] == "static"):
            continue
        outfile.write(header + '\n')
    outfile.write("\n#endif")
    outfile.close()
def main(dir_name, header_name):
    files = []
    headers = []
    for (root, dirs, file) in os.walk(dir_name):
        for f in file:
            if '.c' in f:
                files.append(os.path.join(root, f))
    print("files = ",  files, "in ", dir_name)
    for path in Path(dir_name).rglob('*.c'):
        files.append(str(path)) 
    for file in files:
        headers += find_headers(file)
    headers = align_headers(headers)
    write_to_header(headers, header_name, dir_name)
if len(sys.argv) != 3:
    print("usage : python3 header.py <dir_name> <output_name>")
else:
    main(sys.argv[1], sys.argv[2])