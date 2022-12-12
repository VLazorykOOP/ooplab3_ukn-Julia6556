class MVector{
	private:
		char *arr;
		int size;
	public:
		//constr
		MVector(){
			//dafault
			arr = new char[5];
			for(int i = 0; i < 5; i++) arr[i] = ' ';
			size = 5;
		}
		MVector(int ssize){
			//one parametr (size)
			arr = new char[ssize];
			size = ssize;
			for(int i = 0; i < ssize; i++) arr[i] = ' ';
		}
		MVector(unsigned int n, unsigned int m, char value){
			//3 parametrs
			arr = new char[n];
			for(int i = 0; i < n; i++) arr[i] = value;
			size = n;
		}
		MVector(const MVector &A){
			//copy
			this->size = A.GetSize();
			this->arr = new char[size];
			for(int i = 0; i < size; i++) arr[i] = A.GetFromInd(i);
		}
		
		
		//funcs
		char GetFromInd(int i) const{
			if(i<size && i>=0)
				return arr[i];
			else{
				cout<<"\nNo such index!\n";
				return ' ';
			}
		}
		int GetSize() const{
			return size;
		}
		void SetByInd(int ind, char value){
			arr[ind] = value;
		}
		void Show(){
			for(int i = 0; i < size; i++) cout<<arr[i];
		}
		void BitMask(unsigned char a){
			if(a == 0x0) return;
			for(int i = 0; i < size; i++) arr[i] = arr[i] xor a;
		}
		
		//operators
		MVector& operator=(const MVector &V){
			size = V.GetSize();
			arr = new char[size];
			for(int i = 0; i < size; i++) arr[i] = V.GetFromInd(i);
			return *this;
		}
		bool operator==(const MVector &V2){
			bool flag = true;
			if(GetSize()!=V2.GetSize()) return false;
			else{
				for(int i = 0; i < GetSize(); i++){
					if(GetFromInd(i)!=V2.GetFromInd(i)){
						flag = false;
						break;
					}
				}
				return flag;
			}
		}
		bool operator!=(const MVector &V2){
			bool flag = false;
			if(GetSize()!=V2.GetSize()) return true;
			else{
				for(int i = 0; i < GetSize(); i++){
					if(GetFromInd(i)!=V2.GetFromInd(i)){
						flag = true;
						break;
					}
				}
				return flag;
			}
		}
		bool operator>(const MVector &V2){
			if(size > V2.GetSize()) return true;
			else return false;
		}
		bool operator<(const MVector &V2){
			if(size < V2.GetSize()) return true;
			else return false;
		}
};