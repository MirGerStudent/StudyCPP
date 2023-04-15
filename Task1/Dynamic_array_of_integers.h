#include <iostream>

class ArrayList {
	private:
		int *arrayList;
		int size;
	public:
		ArrayList();
		ArrayList(int size);
		ArrayList(int size, int number);
		ArrayList(const ArrayList &);
		ArrayList(ArrayList &&);
		~ArrayList();


		int& getArray() const;
		int length();
		void resize(int newSize);


		int& operator[] (int index);
		int operator[] (int index) const;
		ArrayList& operator= (const ArrayList &Arr);
		ArrayList& operator= (ArrayList &&Arr);
		bool operator== (const ArrayList &Arr) const;
		bool operator!= (const ArrayList &Arr) const;
		friend ArrayList operator+ (const ArrayList &Arr1, const ArrayList &Arr2);
		bool operator>= (const ArrayList &Arr) const;
		bool operator> (const ArrayList &Arr) const;
		bool operator<= (const ArrayList &Arr) const;
		bool operator< (const ArrayList &Arr) const;
		friend std::istream& operator>> (std::istream& in, const ArrayList& Arr);
		friend std::ostream& operator<< (std::ostream& os, const ArrayList& Arr);
};