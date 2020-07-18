import os
import re
import sys
from subprocess import check_output

css_regex = r'^.*(<link rel="stylesheet" type="text/css" href="(.*\.css)" />).*$'
js_regex = r'^.*(<script src="(.*\.js)"></script>).*$'
svg_media_regex = r'^.*(<!--\sIMG\s([^\s]+\.svg)\s-->).*$'

file_count = 0

def ensure_dir(file_path):
	directory = os.path.dirname(file_path)
	if not os.path.exists(directory):
		os.makedirs(directory)

def whitespace(content):
	return content.replace("\t", "").replace("\n", "")

def get_css(filename):
    print(filename + " in progress")
    f = open(filename, 'r')
    output = "<style type=\"text/css\">";
    for line in f:
        output += whitespace(line)
    f.close()
    return output + "</style>"

def get_js(filename):
    print(filename + " in progress")
    import urllib.request, urllib.parse
    f = open(filename, 'r')
    js_code = f.read();
    f.close()
    data = {
        'output_format' : 'text',
        'output_info' : 'compiled_code',
        'compilation_level' : 'SIMPLE_OPTIMIZATIONS',
        'js_code' : js_code
    }
    data = bytes( urllib.parse.urlencode( data ).encode() )
    handler = urllib.request.urlopen( 'https://closure-compiler.appspot.com/compile', data );
    return "<script type=\"text/javascript\">" + handler.read().decode( 'utf-8' ) + "</script>";

def get_svg_media(filename):
	f = open(filename, 'r')
	output = ''
	for line in f:
		output += whitespace(line)
	f.close()
	return output

def compress_html(filename):
    path = os.path.dirname(filename)
    if path == '':
        path = '.'
    path = path + '/'
    f = open(filename, 'r')
    output = "";
    for line in f:
        line = whitespace(line)
        matches = re.match(css_regex, line)
        if matches is not None:
            line = line.replace(matches.group(1), get_css(path + matches.group(2)))
        matches = re.match(js_regex, line)
        if matches is not None:
            line = line.replace(matches.group(1), get_js(path + matches.group(2)))
        matches = re.match(svg_media_regex, line)
        if matches is not None:
            line = line.replace(matches.group(1), get_svg_media(path + matches.group(2)))
        output += line
    f.close()
    return output

def add_file(filename, content, content_type="text/html"):
    global file_count
    file_count += 1

    hex_values = ''
    counter = 0

    for buf in content.encode('utf8'):
        hex_values += str("0x" + ('%02x' % buf) + ",")
        counter += 1
        if counter % 12 == 11 and counter > 0:
            hex_values += '\n\t\t'

    return (
        '\tconst unsigned char content' + str(file_count) + '[] = {\n'
		'\t\t' + hex_values[:-1] + '\n'
		'\t};\n\n'
        "\tWebFile f" + str(file_count) + " = WebFile(\"" + content_type + "\", content" + str(file_count) + ", " + str(counter) + ");\n"
        "\tstring s" + str(file_count) + "(\"" + filename + "\");\n"
        "\tthis->files.insert(pair<string, WebFile>(s" + str(file_count) + ", f" + str(file_count) + "));\n"
    )

def main():
    f = open("src/WebFiles.cpp", "w+")
    f.write(
        "#include \"WebFiles.hpp\"\n"
        "\n"
        "WebFile WebFiles::getFile(string name){\n"
        "\tstd::map<string, WebFile>::const_iterator pos = this->files.find(name);\n"
        "\treturn pos->second;\n"
        "}\n"
        "\n"
        "WebFiles::WebFiles(){\n"
    )

    for fn in os.listdir("web"):

        if fn.endswith(".html"):
            print(fn + " in progress")
            compressed = compress_html("web/" + fn)
            to_write = add_file(fn, compressed)
            f.write(to_write)
    
    f.write("}")
    f.close()

if __name__ == "__main__":
    main()