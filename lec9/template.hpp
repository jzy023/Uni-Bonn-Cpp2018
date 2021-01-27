template<class dataType> 
void myClass<dataType>::get() const {
	std::cout << "stored data:\n";
	std::cout << "> " << data1_ << "\n" 
			  << "> " << data2_ << std::endl;
}
