class ArrayList {
	private:
		int *arrayList;
		int size;
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
};
