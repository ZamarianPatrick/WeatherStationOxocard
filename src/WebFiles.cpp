#include "WebFiles.hpp"

WebFile WebFiles::getFile(string name){
	std::map<string, WebFile>::const_iterator pos = this->files.find(name);
	return pos->second;
}

WebFiles::WebFiles(){
	const unsigned char content1[] = {
		0x3c,0x21,0x44,0x4f,0x43,0x54,0x59,0x50,0x45,0x20,0x68,
		0x74,0x6d,0x6c,0x3e,0x3c,0x68,0x74,0x6d,0x6c,0x20,0x6c,0x61,
		0x6e,0x67,0x3d,0x22,0x65,0x6e,0x22,0x3e,0x3c,0x68,0x65,0x61,
		0x64,0x3e,0x20,0x20,0x20,0x20,0x3c,0x6d,0x65,0x74,0x61,0x20,
		0x63,0x68,0x61,0x72,0x73,0x65,0x74,0x3d,0x22,0x55,0x54,0x46,
		0x2d,0x38,0x22,0x3e,0x20,0x20,0x20,0x20,0x3c,0x6d,0x65,0x74,
		0x61,0x20,0x6e,0x61,0x6d,0x65,0x3d,0x22,0x76,0x69,0x65,0x77,
		0x70,0x6f,0x72,0x74,0x22,0x20,0x63,0x6f,0x6e,0x74,0x65,0x6e,
		0x74,0x3d,0x22,0x77,0x69,0x64,0x74,0x68,0x3d,0x64,0x65,0x76,
		0x69,0x63,0x65,0x2d,0x77,0x69,0x64,0x74,0x68,0x2c,0x20,0x69,
		0x6e,0x69,0x74,0x69,0x61,0x6c,0x2d,0x73,0x63,0x61,0x6c,0x65,
		0x3d,0x31,0x2e,0x30,0x22,0x3e,0x20,0x20,0x20,0x20,0x3c,0x74,
		0x69,0x74,0x6c,0x65,0x3e,0x57,0x65,0x74,0x74,0x65,0x72,0x73,
		0x74,0x61,0x74,0x69,0x6f,0x6e,0x20,0x2d,0x20,0x53,0x65,0x69,
		0x74,0x65,0x20,0x6e,0x69,0x63,0x68,0x74,0x20,0x67,0x65,0x66,
		0x75,0x6e,0x64,0x65,0x6e,0x3c,0x2f,0x74,0x69,0x74,0x6c,0x65,
		0x3e,0x20,0x20,0x20,0x20,0x3c,0x73,0x74,0x79,0x6c,0x65,0x20,
		0x74,0x79,0x70,0x65,0x3d,0x22,0x74,0x65,0x78,0x74,0x2f,0x63,
		0x73,0x73,0x22,0x3e,0x2e,0x68,0x65,0x61,0x64,0x7b,0x20,0x20,
		0x20,0x20,0x77,0x69,0x64,0x74,0x68,0x3a,0x20,0x31,0x30,0x30,
		0x25,0x3b,0x20,0x20,0x20,0x20,0x6d,0x69,0x6e,0x2d,0x68,0x65,
		0x69,0x67,0x68,0x74,0x3a,0x20,0x38,0x30,0x70,0x78,0x3b,0x20,
		0x20,0x20,0x20,0x68,0x65,0x69,0x67,0x68,0x74,0x3a,0x20,0x31,
		0x30,0x76,0x68,0x3b,0x20,0x20,0x20,0x20,0x62,0x6f,0x72,0x64,
		0x65,0x72,0x2d,0x72,0x61,0x64,0x69,0x75,0x73,0x3a,0x20,0x31,
		0x30,0x70,0x78,0x3b,0x20,0x20,0x20,0x20,0x62,0x6f,0x72,0x64,
		0x65,0x72,0x2d,0x73,0x74,0x79,0x6c,0x65,0x3a,0x20,0x73,0x6f,
		0x6c,0x69,0x64,0x3b,0x20,0x20,0x20,0x20,0x62,0x6f,0x72,0x64,
		0x65,0x72,0x2d,0x77,0x69,0x64,0x74,0x68,0x3a,0x20,0x31,0x70,
		0x78,0x3b,0x20,0x20,0x20,0x20,0x62,0x6f,0x72,0x64,0x65,0x72,
		0x2d,0x63,0x6f,0x6c,0x6f,0x72,0x3a,0x20,0x62,0x6c,0x61,0x63,
		0x6b,0x3b,0x20,0x20,0x20,0x20,0x74,0x65,0x78,0x74,0x2d,0x61,
		0x6c,0x69,0x67,0x6e,0x3a,0x20,0x63,0x65,0x6e,0x74,0x65,0x72,
		0x3b,0x20,0x20,0x20,0x20,0x62,0x61,0x63,0x6b,0x67,0x72,0x6f,
		0x75,0x6e,0x64,0x2d,0x63,0x6f,0x6c,0x6f,0x72,0x3a,0x20,0x6f,
		0x72,0x61,0x6e,0x67,0x65,0x3b,0x7d,0x40,0x6d,0x65,0x64,0x69,
		0x61,0x28,0x6d,0x61,0x78,0x2d,0x77,0x69,0x64,0x74,0x68,0x3a,
		0x20,0x37,0x33,0x30,0x70,0x78,0x29,0x7b,0x20,0x20,0x20,0x20,
		0x2e,0x6f,0x70,0x74,0x69,0x6f,0x6e,0x61,0x6c,0x7b,0x20,0x20,
		0x20,0x20,0x20,0x20,0x20,0x20,0x64,0x69,0x73,0x70,0x6c,0x61,
		0x79,0x3a,0x20,0x6e,0x6f,0x6e,0x65,0x3b,0x20,0x20,0x20,0x20,
		0x7d,0x7d,0x2e,0x68,0x65,0x61,0x64,0x2d,0x74,0x69,0x74,0x6c,
		0x65,0x7b,0x20,0x20,0x20,0x20,0x66,0x6f,0x6e,0x74,0x2d,0x73,
		0x69,0x7a,0x65,0x3a,0x20,0x34,0x38,0x70,0x78,0x3b,0x7d,0x2e,
		0x63,0x6f,0x6e,0x74,0x65,0x6e,0x74,0x7b,0x20,0x20,0x20,0x20,
		0x77,0x69,0x64,0x74,0x68,0x3a,0x20,0x38,0x30,0x25,0x3b,0x20,
		0x20,0x20,0x20,0x6d,0x61,0x78,0x2d,0x68,0x65,0x69,0x67,0x68,
		0x74,0x3a,0x20,0x63,0x61,0x6c,0x63,0x28,0x31,0x30,0x30,0x76,
		0x68,0x20,0x2d,0x20,0x31,0x30,0x30,0x70,0x78,0x29,0x3b,0x20,
		0x20,0x20,0x20,0x68,0x65,0x69,0x67,0x68,0x74,0x3a,0x20,0x63,
		0x61,0x6c,0x63,0x28,0x39,0x30,0x76,0x68,0x20,0x2d,0x20,0x35,
		0x30,0x70,0x78,0x29,0x3b,0x20,0x20,0x20,0x20,0x6d,0x61,0x72,
		0x67,0x69,0x6e,0x3a,0x20,0x61,0x75,0x74,0x6f,0x3b,0x20,0x20,
		0x20,0x20,0x62,0x61,0x63,0x6b,0x67,0x72,0x6f,0x75,0x6e,0x64,
		0x2d,0x63,0x6f,0x6c,0x6f,0x72,0x3a,0x20,0x72,0x67,0x62,0x28,
		0x31,0x38,0x35,0x2c,0x20,0x31,0x38,0x35,0x2c,0x20,0x31,0x38,
		0x35,0x29,0x3b,0x20,0x20,0x20,0x20,0x62,0x6f,0x72,0x64,0x65,
		0x72,0x2d,0x72,0x61,0x64,0x69,0x75,0x73,0x3a,0x20,0x31,0x30,
		0x70,0x78,0x3b,0x20,0x20,0x20,0x20,0x62,0x6f,0x72,0x64,0x65,
		0x72,0x2d,0x73,0x74,0x79,0x6c,0x65,0x3a,0x20,0x73,0x6f,0x6c,
		0x69,0x64,0x3b,0x20,0x20,0x20,0x20,0x6d,0x61,0x72,0x67,0x69,
		0x6e,0x2d,0x74,0x6f,0x70,0x3a,0x20,0x32,0x30,0x70,0x78,0x3b,
		0x20,0x20,0x20,0x20,0x70,0x61,0x64,0x64,0x69,0x6e,0x67,0x3a,
		0x20,0x30,0x70,0x78,0x20,0x32,0x30,0x70,0x78,0x3b,0x7d,0x2e,
		0x63,0x6f,0x6e,0x74,0x65,0x6e,0x74,0x20,0x68,0x31,0x7b,0x20,
		0x20,0x20,0x20,0x74,0x65,0x78,0x74,0x2d,0x61,0x6c,0x69,0x67,
		0x6e,0x3a,0x20,0x63,0x65,0x6e,0x74,0x65,0x72,0x3b,0x7d,0x23,
		0x64,0x79,0x6e,0x61,0x6d,0x69,0x63,0x7b,0x20,0x20,0x20,0x20,
		0x74,0x65,0x78,0x74,0x2d,0x61,0x6c,0x69,0x67,0x6e,0x3a,0x20,
		0x63,0x65,0x6e,0x74,0x65,0x72,0x3b,0x7d,0x23,0x64,0x79,0x6e,
		0x61,0x6d,0x69,0x63,0x20,0x69,0x6d,0x67,0x7b,0x20,0x20,0x20,
		0x20,0x6d,0x61,0x78,0x2d,0x77,0x69,0x64,0x74,0x68,0x3a,0x20,
		0x31,0x30,0x30,0x25,0x3b,0x20,0x20,0x20,0x20,0x6d,0x61,0x78,
		0x2d,0x68,0x65,0x69,0x67,0x68,0x74,0x3a,0x20,0x63,0x61,0x6c,
		0x63,0x28,0x36,0x30,0x76,0x68,0x20,0x2d,0x20,0x31,0x30,0x30,
		0x70,0x78,0x29,0x3b,0x7d,0x2e,0x64,0x79,0x6e,0x61,0x6d,0x69,
		0x63,0x2d,0x76,0x61,0x6c,0x75,0x65,0x7b,0x20,0x20,0x20,0x20,
		0x66,0x6f,0x6e,0x74,0x2d,0x73,0x69,0x7a,0x65,0x3a,0x20,0x31,
		0x30,0x76,0x77,0x3b,0x7d,0x3c,0x2f,0x73,0x74,0x79,0x6c,0x65,
		0x3e,0x3c,0x2f,0x68,0x65,0x61,0x64,0x3e,0x3c,0x62,0x6f,0x64,
		0x79,0x3e,0x20,0x20,0x20,0x20,0x3c,0x64,0x69,0x76,0x20,0x63,
		0x6c,0x61,0x73,0x73,0x3d,0x22,0x68,0x65,0x61,0x64,0x22,0x3e,
		0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x3c,0x73,0x70,0x61,
		0x6e,0x20,0x63,0x6c,0x61,0x73,0x73,0x3d,0x22,0x68,0x65,0x61,
		0x64,0x2d,0x74,0x69,0x74,0x6c,0x65,0x22,0x3e,0x47,0x72,0x75,
		0x70,0x70,0x65,0x20,0x31,0x30,0x65,0x72,0x20,0x4f,0x78,0x6f,
		0x63,0x61,0x72,0x64,0x20,0x57,0x65,0x74,0x74,0x65,0x72,0x73,
		0x74,0x61,0x74,0x69,0x6f,0x6e,0x3c,0x2f,0x73,0x70,0x61,0x6e,
		0x3e,0x20,0x20,0x20,0x20,0x3c,0x2f,0x64,0x69,0x76,0x3e,0x20,
		0x20,0x20,0x20,0x3c,0x64,0x69,0x76,0x20,0x63,0x6c,0x61,0x73,
		0x73,0x3d,0x22,0x63,0x6f,0x6e,0x74,0x65,0x6e,0x74,0x22,0x3e,
		0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x3c,0x68,0x31,0x3e,
		0x44,0x69,0x65,0x20,0x61,0x6e,0x67,0x65,0x66,0x6f,0x72,0x64,
		0x65,0x72,0x74,0x65,0x20,0x53,0x65,0x69,0x74,0x65,0x20,0x6b,
		0x6f,0x6e,0x6e,0x74,0x65,0x20,0x6e,0x69,0x63,0x68,0x74,0x20,
		0x67,0x65,0x66,0x75,0x6e,0x64,0x65,0x6e,0x20,0x77,0x65,0x72,
		0x64,0x65,0x6e,0x21,0x3c,0x2f,0x68,0x31,0x3e,0x20,0x20,0x20,
		0x20,0x3c,0x2f,0x64,0x69,0x76,0x3e,0x3c,0x2f,0x62,0x6f,0x64,
		0x79,0x3e,0x3c,0x2f,0x68,0x74,0x6d,0x6c,0x3e
	};

	WebFile f1 = WebFile("text/html", content1, 1184);
	string s1("404.html");
	this->files.insert(pair<string, WebFile>(s1, f1));
	const unsigned char content2[] = {
		0x3c,0x21,0x44,0x4f,0x43,0x54,0x59,0x50,0x45,0x20,0x68,
		0x74,0x6d,0x6c,0x3e,0x3c,0x68,0x74,0x6d,0x6c,0x20,0x6c,0x61,
		0x6e,0x67,0x3d,0x22,0x65,0x6e,0x22,0x3e,0x3c,0x68,0x65,0x61,
		0x64,0x3e,0x20,0x20,0x20,0x20,0x3c,0x6d,0x65,0x74,0x61,0x20,
		0x63,0x68,0x61,0x72,0x73,0x65,0x74,0x3d,0x22,0x55,0x54,0x46,
		0x2d,0x38,0x22,0x3e,0x20,0x20,0x20,0x20,0x3c,0x6d,0x65,0x74,
		0x61,0x20,0x6e,0x61,0x6d,0x65,0x3d,0x22,0x76,0x69,0x65,0x77,
		0x70,0x6f,0x72,0x74,0x22,0x20,0x63,0x6f,0x6e,0x74,0x65,0x6e,
		0x74,0x3d,0x22,0x77,0x69,0x64,0x74,0x68,0x3d,0x64,0x65,0x76,
		0x69,0x63,0x65,0x2d,0x77,0x69,0x64,0x74,0x68,0x2c,0x20,0x69,
		0x6e,0x69,0x74,0x69,0x61,0x6c,0x2d,0x73,0x63,0x61,0x6c,0x65,
		0x3d,0x31,0x2e,0x30,0x22,0x3e,0x20,0x20,0x20,0x20,0x3c,0x74,
		0x69,0x74,0x6c,0x65,0x3e,0x57,0x65,0x74,0x74,0x65,0x72,0x73,
		0x74,0x61,0x74,0x69,0x6f,0x6e,0x20,0x2d,0x20,0x48,0x6f,0x6d,
		0x65,0x3c,0x2f,0x74,0x69,0x74,0x6c,0x65,0x3e,0x20,0x20,0x20,
		0x20,0x3c,0x73,0x74,0x79,0x6c,0x65,0x20,0x74,0x79,0x70,0x65,
		0x3d,0x22,0x74,0x65,0x78,0x74,0x2f,0x63,0x73,0x73,0x22,0x3e,
		0x2e,0x68,0x65,0x61,0x64,0x7b,0x20,0x20,0x20,0x20,0x77,0x69,
		0x64,0x74,0x68,0x3a,0x20,0x31,0x30,0x30,0x25,0x3b,0x20,0x20,
		0x20,0x20,0x6d,0x69,0x6e,0x2d,0x68,0x65,0x69,0x67,0x68,0x74,
		0x3a,0x20,0x38,0x30,0x70,0x78,0x3b,0x20,0x20,0x20,0x20,0x68,
		0x65,0x69,0x67,0x68,0x74,0x3a,0x20,0x31,0x30,0x76,0x68,0x3b,
		0x20,0x20,0x20,0x20,0x62,0x6f,0x72,0x64,0x65,0x72,0x2d,0x72,
		0x61,0x64,0x69,0x75,0x73,0x3a,0x20,0x31,0x30,0x70,0x78,0x3b,
		0x20,0x20,0x20,0x20,0x62,0x6f,0x72,0x64,0x65,0x72,0x2d,0x73,
		0x74,0x79,0x6c,0x65,0x3a,0x20,0x73,0x6f,0x6c,0x69,0x64,0x3b,
		0x20,0x20,0x20,0x20,0x62,0x6f,0x72,0x64,0x65,0x72,0x2d,0x77,
		0x69,0x64,0x74,0x68,0x3a,0x20,0x31,0x70,0x78,0x3b,0x20,0x20,
		0x20,0x20,0x62,0x6f,0x72,0x64,0x65,0x72,0x2d,0x63,0x6f,0x6c,
		0x6f,0x72,0x3a,0x20,0x62,0x6c,0x61,0x63,0x6b,0x3b,0x20,0x20,
		0x20,0x20,0x74,0x65,0x78,0x74,0x2d,0x61,0x6c,0x69,0x67,0x6e,
		0x3a,0x20,0x63,0x65,0x6e,0x74,0x65,0x72,0x3b,0x20,0x20,0x20,
		0x20,0x62,0x61,0x63,0x6b,0x67,0x72,0x6f,0x75,0x6e,0x64,0x2d,
		0x63,0x6f,0x6c,0x6f,0x72,0x3a,0x20,0x6f,0x72,0x61,0x6e,0x67,
		0x65,0x3b,0x7d,0x40,0x6d,0x65,0x64,0x69,0x61,0x28,0x6d,0x61,
		0x78,0x2d,0x77,0x69,0x64,0x74,0x68,0x3a,0x20,0x37,0x33,0x30,
		0x70,0x78,0x29,0x7b,0x20,0x20,0x20,0x20,0x2e,0x6f,0x70,0x74,
		0x69,0x6f,0x6e,0x61,0x6c,0x7b,0x20,0x20,0x20,0x20,0x20,0x20,
		0x20,0x20,0x64,0x69,0x73,0x70,0x6c,0x61,0x79,0x3a,0x20,0x6e,
		0x6f,0x6e,0x65,0x3b,0x20,0x20,0x20,0x20,0x7d,0x7d,0x2e,0x68,
		0x65,0x61,0x64,0x2d,0x74,0x69,0x74,0x6c,0x65,0x7b,0x20,0x20,
		0x20,0x20,0x66,0x6f,0x6e,0x74,0x2d,0x73,0x69,0x7a,0x65,0x3a,
		0x20,0x34,0x38,0x70,0x78,0x3b,0x7d,0x2e,0x63,0x6f,0x6e,0x74,
		0x65,0x6e,0x74,0x7b,0x20,0x20,0x20,0x20,0x77,0x69,0x64,0x74,
		0x68,0x3a,0x20,0x38,0x30,0x25,0x3b,0x20,0x20,0x20,0x20,0x6d,
		0x61,0x78,0x2d,0x68,0x65,0x69,0x67,0x68,0x74,0x3a,0x20,0x63,
		0x61,0x6c,0x63,0x28,0x31,0x30,0x30,0x76,0x68,0x20,0x2d,0x20,
		0x31,0x30,0x30,0x70,0x78,0x29,0x3b,0x20,0x20,0x20,0x20,0x68,
		0x65,0x69,0x67,0x68,0x74,0x3a,0x20,0x63,0x61,0x6c,0x63,0x28,
		0x39,0x30,0x76,0x68,0x20,0x2d,0x20,0x35,0x30,0x70,0x78,0x29,
		0x3b,0x20,0x20,0x20,0x20,0x6d,0x61,0x72,0x67,0x69,0x6e,0x3a,
		0x20,0x61,0x75,0x74,0x6f,0x3b,0x20,0x20,0x20,0x20,0x62,0x61,
		0x63,0x6b,0x67,0x72,0x6f,0x75,0x6e,0x64,0x2d,0x63,0x6f,0x6c,
		0x6f,0x72,0x3a,0x20,0x72,0x67,0x62,0x28,0x31,0x38,0x35,0x2c,
		0x20,0x31,0x38,0x35,0x2c,0x20,0x31,0x38,0x35,0x29,0x3b,0x20,
		0x20,0x20,0x20,0x62,0x6f,0x72,0x64,0x65,0x72,0x2d,0x72,0x61,
		0x64,0x69,0x75,0x73,0x3a,0x20,0x31,0x30,0x70,0x78,0x3b,0x20,
		0x20,0x20,0x20,0x62,0x6f,0x72,0x64,0x65,0x72,0x2d,0x73,0x74,
		0x79,0x6c,0x65,0x3a,0x20,0x73,0x6f,0x6c,0x69,0x64,0x3b,0x20,
		0x20,0x20,0x20,0x6d,0x61,0x72,0x67,0x69,0x6e,0x2d,0x74,0x6f,
		0x70,0x3a,0x20,0x32,0x30,0x70,0x78,0x3b,0x20,0x20,0x20,0x20,
		0x70,0x61,0x64,0x64,0x69,0x6e,0x67,0x3a,0x20,0x30,0x70,0x78,
		0x20,0x32,0x30,0x70,0x78,0x3b,0x7d,0x2e,0x63,0x6f,0x6e,0x74,
		0x65,0x6e,0x74,0x20,0x68,0x31,0x7b,0x20,0x20,0x20,0x20,0x74,
		0x65,0x78,0x74,0x2d,0x61,0x6c,0x69,0x67,0x6e,0x3a,0x20,0x63,
		0x65,0x6e,0x74,0x65,0x72,0x3b,0x7d,0x23,0x64,0x79,0x6e,0x61,
		0x6d,0x69,0x63,0x7b,0x20,0x20,0x20,0x20,0x74,0x65,0x78,0x74,
		0x2d,0x61,0x6c,0x69,0x67,0x6e,0x3a,0x20,0x63,0x65,0x6e,0x74,
		0x65,0x72,0x3b,0x7d,0x23,0x64,0x79,0x6e,0x61,0x6d,0x69,0x63,
		0x20,0x69,0x6d,0x67,0x7b,0x20,0x20,0x20,0x20,0x6d,0x61,0x78,
		0x2d,0x77,0x69,0x64,0x74,0x68,0x3a,0x20,0x31,0x30,0x30,0x25,
		0x3b,0x20,0x20,0x20,0x20,0x6d,0x61,0x78,0x2d,0x68,0x65,0x69,
		0x67,0x68,0x74,0x3a,0x20,0x63,0x61,0x6c,0x63,0x28,0x36,0x30,
		0x76,0x68,0x20,0x2d,0x20,0x31,0x30,0x30,0x70,0x78,0x29,0x3b,
		0x7d,0x2e,0x64,0x79,0x6e,0x61,0x6d,0x69,0x63,0x2d,0x76,0x61,
		0x6c,0x75,0x65,0x7b,0x20,0x20,0x20,0x20,0x66,0x6f,0x6e,0x74,
		0x2d,0x73,0x69,0x7a,0x65,0x3a,0x20,0x31,0x30,0x76,0x77,0x3b,
		0x7d,0x3c,0x2f,0x73,0x74,0x79,0x6c,0x65,0x3e,0x3c,0x2f,0x68,
		0x65,0x61,0x64,0x3e,0x3c,0x62,0x6f,0x64,0x79,0x3e,0x20,0x20,
		0x20,0x20,0x3c,0x64,0x69,0x76,0x20,0x63,0x6c,0x61,0x73,0x73,
		0x3d,0x22,0x68,0x65,0x61,0x64,0x22,0x3e,0x20,0x20,0x20,0x20,
		0x20,0x20,0x20,0x20,0x3c,0x73,0x70,0x61,0x6e,0x20,0x63,0x6c,
		0x61,0x73,0x73,0x3d,0x22,0x68,0x65,0x61,0x64,0x2d,0x74,0x69,
		0x74,0x6c,0x65,0x22,0x3e,0x3c,0x73,0x70,0x61,0x6e,0x20,0x63,
		0x6c,0x61,0x73,0x73,0x3d,0x22,0x6f,0x70,0x74,0x69,0x6f,0x6e,
		0x61,0x6c,0x22,0x3e,0x47,0x72,0x75,0x70,0x70,0x65,0x20,0x31,
		0x30,0x65,0x72,0x20,0x4f,0x78,0x6f,0x63,0x61,0x72,0x64,0x20,
		0x3c,0x2f,0x73,0x70,0x61,0x6e,0x3e,0x57,0x65,0x74,0x74,0x65,
		0x72,0x73,0x74,0x61,0x74,0x69,0x6f,0x6e,0x3c,0x2f,0x73,0x70,
		0x61,0x6e,0x3e,0x20,0x20,0x20,0x20,0x3c,0x2f,0x64,0x69,0x76,
		0x3e,0x20,0x20,0x20,0x20,0x3c,0x64,0x69,0x76,0x20,0x63,0x6c,
		0x61,0x73,0x73,0x3d,0x22,0x63,0x6f,0x6e,0x74,0x65,0x6e,0x74,
		0x22,0x3e,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x3c,0x68,
		0x31,0x20,0x69,0x64,0x3d,0x22,0x74,0x69,0x74,0x6c,0x65,0x22,
		0x3e,0x3c,0x2f,0x68,0x31,0x3e,0x20,0x20,0x20,0x20,0x20,0x20,
		0x20,0x20,0x3c,0x64,0x69,0x76,0x20,0x69,0x64,0x3d,0x22,0x64,
		0x79,0x6e,0x61,0x6d,0x69,0x63,0x22,0x3e,0x3c,0x2f,0x64,0x69,
		0x76,0x3e,0x20,0x20,0x20,0x20,0x3c,0x2f,0x64,0x69,0x76,0x3e,
		0x20,0x20,0x20,0x20,0x3c,0x73,0x63,0x72,0x69,0x70,0x74,0x20,
		0x74,0x79,0x70,0x65,0x3d,0x22,0x74,0x65,0x78,0x74,0x2f,0x6a,
		0x61,0x76,0x61,0x73,0x63,0x72,0x69,0x70,0x74,0x22,0x3e,0x76,
		0x61,0x72,0x20,0x73,0x6f,0x63,0x6b,0x65,0x74,0x3d,0x6e,0x65,
		0x77,0x20,0x57,0x65,0x62,0x53,0x6f,0x63,0x6b,0x65,0x74,0x28,
		0x22,0x77,0x73,0x3a,0x2f,0x2f,0x22,0x2b,0x77,0x69,0x6e,0x64,
		0x6f,0x77,0x2e,0x6c,0x6f,0x63,0x61,0x74,0x69,0x6f,0x6e,0x2e,
		0x68,0x6f,0x73,0x74,0x6e,0x61,0x6d,0x65,0x2b,0x22,0x3a,0x35,
		0x35,0x36,0x37,0x22,0x29,0x2c,0x69,0x63,0x6f,0x6e,0x73,0x3d,
		0x7b,0x66,0x6f,0x67,0x67,0x79,0x3a,0x27,0x3c,0x69,0x6d,0x67,
		0x20,0x73,0x72,0x63,0x3d,0x22,0x68,0x74,0x74,0x70,0x73,0x3a,
		0x2f,0x2f,0x64,0x72,0x69,0x76,0x65,0x2e,0x67,0x6f,0x6f,0x67,
		0x6c,0x65,0x2e,0x63,0x6f,0x6d,0x2f,0x74,0x68,0x75,0x6d,0x62,
		0x6e,0x61,0x69,0x6c,0x3f,0x69,0x64,0x3d,0x31,0x31,0x44,0x48,
		0x4c,0x36,0x53,0x50,0x34,0x56,0x43,0x6f,0x42,0x79,0x5f,0x79,
		0x45,0x77,0x6f,0x6b,0x54,0x78,0x38,0x67,0x6d,0x48,0x4d,0x41,
		0x4c,0x4b,0x72,0x39,0x6d,0x22,0x20,0x61,0x6c,0x74,0x3d,0x22,
		0x22,0x3e,0x27,0x2c,0x72,0x61,0x69,0x6e,0x3a,0x27,0x3c,0x69,
		0x6d,0x67,0x20,0x73,0x72,0x63,0x3d,0x22,0x68,0x74,0x74,0x70,
		0x73,0x3a,0x2f,0x2f,0x64,0x72,0x69,0x76,0x65,0x2e,0x67,0x6f,
		0x6f,0x67,0x6c,0x65,0x2e,0x63,0x6f,0x6d,0x2f,0x74,0x68,0x75,
		0x6d,0x62,0x6e,0x61,0x69,0x6c,0x3f,0x69,0x64,0x3d,0x31,0x4d,
		0x72,0x68,0x4c,0x79,0x30,0x6d,0x31,0x61,0x59,0x46,0x35,0x59,
		0x72,0x4d,0x34,0x50,0x75,0x79,0x4c,0x52,0x36,0x36,0x44,0x39,
		0x4d,0x5f,0x44,0x58,0x56,0x47,0x61,0x22,0x20,0x61,0x6c,0x74,
		0x3d,0x22,0x22,0x3e,0x27,0x2c,0x73,0x6e,0x6f,0x77,0x3a,0x27,
		0x3c,0x69,0x6d,0x67,0x20,0x73,0x72,0x63,0x3d,0x22,0x68,0x74,
		0x74,0x70,0x73,0x3a,0x2f,0x2f,0x64,0x72,0x69,0x76,0x65,0x2e,
		0x67,0x6f,0x6f,0x67,0x6c,0x65,0x2e,0x63,0x6f,0x6d,0x2f,0x74,
		0x68,0x75,0x6d,0x62,0x6e,0x61,0x69,0x6c,0x3f,0x69,0x64,0x3d,
		0x31,0x2d,0x31,0x57,0x7a,0x64,0x62,0x4d,0x4e,0x32,0x77,0x4a,
		0x51,0x41,0x39,0x69,0x66,0x5a,0x66,0x73,0x56,0x4e,0x48,0x5f,
		0x58,0x39,0x48,0x4a,0x4f,0x44,0x6c,0x43,0x6d,0x22,0x20,0x61,
		0x6c,0x74,0x3d,0x22,0x22,0x3e,0x27,0x2c,0x73,0x75,0x6e,0x3a,
		0x27,0x3c,0x69,0x6d,0x67,0x20,0x73,0x72,0x63,0x3d,0x22,0x68,
		0x74,0x74,0x70,0x73,0x3a,0x2f,0x2f,0x64,0x72,0x69,0x76,0x65,
		0x2e,0x67,0x6f,0x6f,0x67,0x6c,0x65,0x2e,0x63,0x6f,0x6d,0x2f,
		0x74,0x68,0x75,0x6d,0x62,0x6e,0x61,0x69,0x6c,0x3f,0x69,0x64,
		0x3d,0x31,0x42,0x34,0x67,0x47,0x43,0x65,0x47,0x42,0x53,0x71,
		0x63,0x5f,0x2d,0x4d,0x6f,0x65,0x52,0x66,0x62,0x58,0x49,0x6e,
		0x6b,0x62,0x47,0x6e,0x78,0x54,0x45,0x50,0x57,0x4d,0x22,0x20,
		0x61,0x6c,0x74,0x3d,0x22,0x22,0x3e,0x27,0x2c,0x63,0x6c,0x6f,
		0x75,0x64,0x3a,0x27,0x3c,0x69,0x6d,0x67,0x20,0x73,0x72,0x63,
		0x3d,0x22,0x68,0x74,0x74,0x70,0x73,0x3a,0x2f,0x2f,0x64,0x72,
		0x69,0x76,0x65,0x2e,0x67,0x6f,0x6f,0x67,0x6c,0x65,0x2e,0x63,
		0x6f,0x6d,0x2f,0x74,0x68,0x75,0x6d,0x62,0x6e,0x61,0x69,0x6c,
		0x3f,0x69,0x64,0x3d,0x31,0x39,0x6e,0x4d,0x49,0x66,0x62,0x59,
		0x75,0x50,0x75,0x42,0x4a,0x77,0x32,0x37,0x43,0x68,0x51,0x38,
		0x37,0x37,0x74,0x69,0x45,0x58,0x6d,0x58,0x42,0x47,0x61,0x57,
		0x41,0x22,0x20,0x61,0x6c,0x74,0x3d,0x22,0x22,0x3e,0x27,0x7d,
		0x3b,0x0a,0x73,0x6f,0x63,0x6b,0x65,0x74,0x2e,0x6f,0x6e,0x6f,
		0x70,0x65,0x6e,0x3d,0x66,0x75,0x6e,0x63,0x74,0x69,0x6f,0x6e,
		0x28,0x61,0x29,0x7b,0x63,0x6f,0x6e,0x73,0x6f,0x6c,0x65,0x2e,
		0x6c,0x6f,0x67,0x28,0x22,0x6f,0x70,0x65,0x6e,0x65,0x64,0x22,
		0x29,0x7d,0x3b,0x0a,0x73,0x6f,0x63,0x6b,0x65,0x74,0x2e,0x6f,
		0x6e,0x6d,0x65,0x73,0x73,0x61,0x67,0x65,0x3d,0x66,0x75,0x6e,
		0x63,0x74,0x69,0x6f,0x6e,0x28,0x61,0x29,0x7b,0x76,0x61,0x72,
		0x20,0x62,0x3d,0x61,0x2e,0x64,0x61,0x74,0x61,0x2e,0x73,0x70,
		0x6c,0x69,0x74,0x28,0x22,0x3b,0x22,0x29,0x2c,0x64,0x3d,0x62,
		0x5b,0x30,0x5d,0x2c,0x65,0x3d,0x22,0x48,0x6f,0x6d,0x65,0x22,
		0x2c,0x63,0x3d,0x64,0x6f,0x63,0x75,0x6d,0x65,0x6e,0x74,0x2e,
		0x67,0x65,0x74,0x45,0x6c,0x65,0x6d,0x65,0x6e,0x74,0x42,0x79,
		0x49,0x64,0x28,0x22,0x64,0x79,0x6e,0x61,0x6d,0x69,0x63,0x22,
		0x29,0x3b,0x73,0x77,0x69,0x74,0x63,0x68,0x28,0x64,0x29,0x7b,
		0x63,0x61,0x73,0x65,0x20,0x22,0x30,0x22,0x3a,0x65,0x3d,0x22,
		0x54,0x65,0x6d,0x70,0x65,0x72,0x61,0x74,0x75,0x72,0x22,0x3b,
		0x64,0x3d,0x67,0x65,0x74,0x49,0x6d,0x61,0x67,0x65,0x28,0x62,
		0x5b,0x32,0x5d,0x29,0x3b,0x63,0x26,0x26,0x28,0x63,0x2e,0x69,
		0x6e,0x6e,0x65,0x72,0x48,0x54,0x4d,0x4c,0x3d,0x64,0x2b,0x27,
		0x3c,0x62,0x72,0x3e,0x3c,0x73,0x70,0x61,0x6e,0x20,0x63,0x6c,
		0x61,0x73,0x73,0x3d,0x22,0x64,0x79,0x6e,0x61,0x6d,0x69,0x63,
		0x2d,0x76,0x61,0x6c,0x75,0x65,0x22,0x3e,0x27,0x2b,0x62,0x5b,
		0x31,0x5d,0x2b,0x22,0x20,0x26,0x64,0x65,0x67,0x3b,0x43,0x3c,
		0x2f,0x73,0x70,0x61,0x6e,0x3e,0x22,0x29,0x3b,0x62,0x72,0x65,
		0x61,0x6b,0x3b,0x63,0x61,0x73,0x65,0x20,0x22,0x31,0x22,0x3a,
		0x65,0x3d,0x22,0x4c,0x75,0x66,0x74,0x66,0x65,0x75,0x63,0x68,
		0x74,0x69,0x67,0x6b,0x65,0x69,0x74,0x22,0x3b,0x64,0x3d,0x67,
		0x65,0x74,0x49,0x6d,0x61,0x67,0x65,0x28,0x62,0x5b,0x32,0x5d,
		0x29,0x3b,0x63,0x26,0x26,0x28,0x63,0x2e,0x69,0x6e,0x6e,0x65,
		0x72,0x48,0x54,0x4d,0x4c,0x3d,0x64,0x2b,0x27,0x3c,0x62,0x72,
		0x3e,0x3c,0x73,0x70,0x61,0x6e,0x20,0x63,0x6c,0x61,0x73,0x73,
		0x3d,0x22,0x64,0x79,0x6e,0x61,0x6d,0x69,0x63,0x2d,0x76,0x61,
		0x6c,0x75,0x65,0x22,0x3e,0x27,0x2b,0x62,0x5b,0x31,0x5d,0x2b,
		0x22,0x20,0x25,0x3c,0x2f,0x73,0x70,0x61,0x6e,0x3e,0x22,0x29,
		0x3b,0x62,0x72,0x65,0x61,0x6b,0x3b,0x63,0x61,0x73,0x65,0x20,
		0x22,0x32,0x22,0x3a,0x65,0x3d,0x22,0x5a,0x65,0x69,0x74,0x22,
		0x2c,0x63,0x26,0x26,0x28,0x63,0x2e,0x69,0x6e,0x6e,0x65,0x72,
		0x48,0x54,0x4d,0x4c,0x3d,0x27,0x3c,0x73,0x70,0x61,0x6e,0x20,
		0x63,0x6c,0x61,0x73,0x73,0x20,0x3d,0x22,0x64,0x79,0x6e,0x61,
		0x6d,0x69,0x63,0x2d,0x76,0x61,0x6c,0x75,0x65,0x22,0x3e,0x27,
		0x2b,0x62,0x5b,0x31,0x5d,0x2b,0x22,0x3c,0x2f,0x73,0x70,0x61,
		0x6e,0x3e,0x22,0x29,0x7d,0x69,0x66,0x28,0x62,0x3d,0x64,0x6f,
		0x63,0x75,0x6d,0x65,0x6e,0x74,0x2e,0x67,0x65,0x74,0x45,0x6c,
		0x65,0x6d,0x65,0x6e,0x74,0x42,0x79,0x49,0x64,0x28,0x22,0x74,
		0x69,0x74,0x6c,0x65,0x22,0x29,0x29,0x62,0x2e,0x69,0x6e,0x6e,
		0x65,0x72,0x48,0x54,0x4d,0x4c,0x3d,0x65,0x3b,0x63,0x6f,0x6e,
		0x73,0x6f,0x6c,0x65,0x2e,0x6c,0x6f,0x67,0x28,0x22,0x72,0x3a,
		0x20,0x22,0x2b,0x0a,0x61,0x2e,0x64,0x61,0x74,0x61,0x29,0x7d,
		0x3b,0x73,0x6f,0x63,0x6b,0x65,0x74,0x2e,0x6f,0x6e,0x63,0x6c,
		0x6f,0x73,0x65,0x3d,0x66,0x75,0x6e,0x63,0x74,0x69,0x6f,0x6e,
		0x28,0x61,0x29,0x7b,0x63,0x6f,0x6e,0x73,0x6f,0x6c,0x65,0x2e,
		0x6c,0x6f,0x67,0x28,0x22,0x63,0x6c,0x6f,0x73,0x65,0x64,0x22,
		0x29,0x7d,0x3b,0x73,0x6f,0x63,0x6b,0x65,0x74,0x2e,0x6f,0x6e,
		0x65,0x72,0x72,0x6f,0x72,0x3d,0x66,0x75,0x6e,0x63,0x74,0x69,
		0x6f,0x6e,0x28,0x61,0x29,0x7b,0x63,0x6f,0x6e,0x73,0x6f,0x6c,
		0x65,0x2e,0x6c,0x6f,0x67,0x28,0x22,0x66,0x61,0x69,0x6c,0x65,
		0x64,0x20,0x74,0x6f,0x20,0x63,0x6f,0x6e,0x6e,0x65,0x63,0x74,
		0x22,0x29,0x7d,0x3b,0x66,0x75,0x6e,0x63,0x74,0x69,0x6f,0x6e,
		0x20,0x67,0x65,0x74,0x49,0x6d,0x61,0x67,0x65,0x28,0x61,0x29,
		0x7b,0x61,0x3d,0x70,0x61,0x72,0x73,0x65,0x49,0x6e,0x74,0x28,
		0x61,0x29,0x3b,0x76,0x61,0x72,0x20,0x62,0x3d,0x22,0x22,0x3b,
		0x69,0x66,0x28,0x31,0x3d,0x3d,0x61,0x7c,0x7c,0x32,0x3d,0x3d,
		0x61,0x29,0x62,0x3d,0x69,0x63,0x6f,0x6e,0x73,0x2e,0x73,0x75,
		0x6e,0x3b,0x65,0x6c,0x73,0x65,0x20,0x69,0x66,0x28,0x33,0x3d,
		0x3d,0x61,0x7c,0x7c,0x34,0x3d,0x3d,0x61,0x7c,0x7c,0x35,0x3d,
		0x3d,0x61,0x29,0x62,0x3d,0x69,0x63,0x6f,0x6e,0x73,0x2e,0x63,
		0x6c,0x6f,0x75,0x64,0x3b,0x65,0x6c,0x73,0x65,0x20,0x69,0x66,
		0x28,0x37,0x3d,0x3d,0x61,0x7c,0x7c,0x31,0x32,0x3d,0x3d,0x61,
		0x7c,0x7c,0x31,0x35,0x3d,0x3d,0x61,0x29,0x62,0x3d,0x69,0x63,
		0x6f,0x6e,0x73,0x2e,0x73,0x6e,0x6f,0x77,0x3b,0x65,0x6c,0x73,
		0x65,0x20,0x69,0x66,0x28,0x38,0x3d,0x3d,0x61,0x7c,0x7c,0x31,
		0x34,0x3d,0x3d,0x61,0x29,0x62,0x3d,0x69,0x63,0x6f,0x6e,0x73,
		0x2e,0x66,0x6f,0x67,0x67,0x79,0x3b,0x65,0x6c,0x73,0x65,0x20,
		0x69,0x66,0x28,0x31,0x30,0x3d,0x3d,0x61,0x7c,0x7c,0x31,0x31,
		0x3d,0x3d,0x61,0x7c,0x7c,0x36,0x3d,0x3d,0x61,0x7c,0x7c,0x31,
		0x33,0x3d,0x3d,0x61,0x29,0x62,0x3d,0x69,0x63,0x6f,0x6e,0x73,
		0x2e,0x72,0x61,0x69,0x6e,0x3b,0x72,0x65,0x74,0x75,0x72,0x6e,
		0x20,0x62,0x7d,0x3b,0x0a,0x3c,0x2f,0x73,0x63,0x72,0x69,0x70,
		0x74,0x3e,0x3c,0x2f,0x62,0x6f,0x64,0x79,0x3e,0x3c,0x2f,0x68,
		0x74,0x6d,0x6c,0x3e
	};

	WebFile f2 = WebFile("text/html", content2, 2727);
	string s2("index.html");
	this->files.insert(pair<string, WebFile>(s2, f2));
}