class ArrayList {
	private:
		int *arrayList;
		int size;
		int len;
	public:
		ArrayList();
		ArrayList(int size);
		ArrayList(ArrayList &);
		ArrayList(ArrayList &&);
		~ArrayList();


		int& getArray() const;
		int length();
		void resize(int newSize);


		int operator[] (int index);
		ArrayList& operator= (const ArrayList &Arr);
		bool operator== (const ArrayList &Arr);
		ArrayList& operator+ (const ArrayList &Arr);
};
