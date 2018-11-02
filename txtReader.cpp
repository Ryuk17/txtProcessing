void getAllFiles(string path, vector<string>& files) {
	long   hFile = 0;                                           //file handle
	struct _finddata_t fileinfo;  	                            //file information  
	string p;  
	if ((hFile = _findfirst(p.assign(path).append("\\*.txt").c_str(), &fileinfo)) != -1)
	{
		do
		{
			if ((fileinfo.attrib &  _A_SUBDIR))  
			{
				if (strcmp(fileinfo.name, ".") != 0 && strcmp(fileinfo.name, "..") != 0)
				{
					files.push_back(p.assign(path).append("/").append(fileinfo.name));
					getAllFiles(p.assign(path).append("/").append(fileinfo.name), files);
				}
			}
			else
			{
				files.push_back(p.assign(fileinfo.name));             //only save filename
			}
		} while (_findnext(hFile, &fileinfo) == 0);               //read the next filename
		_findclose(hFile);
	}
 
}

void readRowInToArray(fstream &in, string FilePath, int data[ROW]) {
	in.open(FilePath, ios::in);
	if (!in.is_open()) {
		cout << "Can not find target  file." << endl;
		system("pause");
	}
	string buff;
	int i = 0;
	while (getline(in, buff)) {
		data[i++] = atof(buff.c_str());
 
	}//end while
	in.close();
	cout << "get data" << endl;
}

void readColumnInToArray(fstream &in, string FilePath, int data[COLUMN]) {
	in.open(FilePath, ios::in);
	if (!in.is_open()) {
		cout << "Can not find target  file." << endl;
		system("pause");
	}
	char buff;
	int i = 0;
	while (!in.eof()) {
		in >> buff;
		data[i++] = buff - '0';                                   //get the number
	}//end while
	in.close();
	cout << "get data" << endl;
}

void readInToMatrix(fstream &in, string FilePath, int data[ROW][COLUMN]) {
	in.open(FilePath, ios::in);
	if (!in.is_open()) {
		cout << "Can not find " << FilePath << endl;
		system("pause");
	}
	string buff;
	int i = 0;//line
	while (getline(in, buff)) {
		vector<double> nums;
		// string->char *
		char *s_input = (char *)buff.c_str();
		const char * split = "，";
		                                                          // split the string with ','
		char *p = strtok(s_input, split);
		double a;
		while (p != NULL) {
			// char * -> int
			a = atof(p);
			//cout << a << endl;
			nums.push_back(a);
			p = strtok(NULL, split);
		}//end while
		for (int b = 0; b < nums.size(); b++) {
			data[i][b] = nums[b];
		}//end for
		i++;
	}//end while
	in.close();
	cout << "get  data" << endl;
}

int main(){
  string path = "C:\\desktop\\test.txt";
  vector<string> filename;
  char data[][];
  fstream in;
  getAllFiles(path, filename);
  data = readRowInToArray(in, path, data);
  
  return 0;
}
