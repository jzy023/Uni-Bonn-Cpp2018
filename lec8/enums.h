

enum class Channel {STDOUT, STDERR};
void print(Channel print_style, const std::string& msg){
	switch (print_style) {
		case Channel::STDOUT:
			cout << msg << endl;
			break;
		case Channel::STDERR:
			cerr << msg << endl;
			break;
		default:
			cerr << "skipping\n"; 
	}
}