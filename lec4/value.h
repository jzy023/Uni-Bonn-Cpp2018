namespace value{
void Print(const std::string& str){
	std::cout << "lvalue: " << str << std::endl;
}
void Print(std::string&& str){
	std::cout << "rvalue: " << str << std::endl;
}
}


