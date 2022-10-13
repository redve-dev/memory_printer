#include <iostream>
#include <iomanip>

#define DEBUG_MEMORY(variable, offset) dbg::PrintMemoryContent(&variable, sizeof(variable), offset)

namespace dbg{
	void PrintValue(const uint8_t val){
		std::cout 
			<< std::setw(2)
			<< std::setfill('0')
			<< std::hex
			<< +val
			<< ' ';
	}

	void PrintMemoryContent(const void *start_addr, ssize_t size, ssize_t offset){
		const int8_t *base = static_cast<const int8_t *>(start_addr);
		for(ssize_t i=-offset; i<size+offset; i++){
			if( i == 0 )
				std::cout<<"|> ";
			if (i == size)
				std::cout<<"<| ";

			PrintValue(static_cast<uint8_t>(*(base+i)));
		}
		std::cout<<'\n';
	}
}

	/*
	int arr[] = {3, 4, 3, 2};
	dbg::PrintMemoryContent(&arr[0], 4*sizeof(int), 1);
	example output:
	00 |> 03 00 00 00 04 00 00 00 03 00 00 00 02 00 00 00 <| 80

	03 00 00 00 = 3
	04 00 00 00 = 4
	03 00 00 00 = 3
	02 00 00 00 = 2

	double pi=3.14159265;
	DEBUG_MEMORY(pi, 2);

	output:
	00 00 |> f1 d4 c8 53 fb 21 09 40 <| 03 00

	int gravity=10;
	DEBUG_MEMORY(gravity, 1);

	output:
	b1 |> 0a 00 00 00 <| f1
*/
