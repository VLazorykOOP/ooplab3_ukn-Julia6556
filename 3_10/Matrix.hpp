class MMatrix{
	private:
		MVector **arr;
		int size;
		mutable bool error;
	public:
		MMatrix(){
			//default
			error = false;
			arr = new MVector*[5];
			size = 5;
			for(int i = 0; i < size; i++) arr[i] = new MVector();
		}
		MMatrix(int ssize){
			//one parametr (size)
			error = false;
			arr = new MVector*[ssize];
			size = ssize;
			for(int i = 0; i < size; i++) arr[i] = new MVector(ssize);
		}
		MMatrix(unsigned int n, unsigned int m, char value){
			//3 parametrs
			error = false;
			arr = new MVector*[m];
			size = m;
			for(int i = 0; i < size; i++) arr[i] = new MVector(n,m,value);
		}
		MMatrix(const MMatrix &A){
			//copy
			error = false;
			arr = new MVector*[A.GetSize()];
			size = A.GetSize();
			for(int i = 0; i < size; i++){
				arr[i] = A.GetFromInd(i);
			}
		}
		
		
		
		//funcs
		char GetFromInd(int i, int j) const{
			if(i>=size || i<0 || j >= arr[0]->GetSize() || j<0){
				error = true;
				if(i>=size || i<0) cout<<"\n\nWrong matrix main index!\n\n";
				if(j<0 || j>=arr[0]->GetSize()) cout<<"\n\nWrong matrix`s vectors index!\n\n";
				return 0x0;
			}
			else{
				error = false;
				return arr[i]->GetFromInd(j);
			}
		}
		MVector *GetFromInd(int i) const{
			if(i>=size || i < 0){
				cout<<"\n\nWrong matrix element index! Returned 0'st element\n\n";
				error = true;
				return arr[0];
			}
			else{
				error = false;
				return arr[i];
			}
		}
		void SetByInd(int indm, int indv, char value){
			if(indm>=size || indm<0 || indv >= arr[0]->GetSize() || indv<0){
				error = true;
				if(indm>=size || indm<0) cout<<"\n\nWrong matrix main index!\n\n";
				if(indv<0 || indv>=arr[0]->GetSize()) cout<<"\n\nWrong matrix`s vectors index!\n\n";
			}
			else{
				error = false;
				arr[indm]->SetByInd(indv,value);
			}
		}
		int GetSize() const{
			return size;
		}
		void Show(){
			for(int i = 0; i < size; i++){
				cout<<i+1<<". ";
				for(int j = 0; j < arr[i]->GetSize(); j++){
					cout<<arr[i]->GetFromInd(j);
				}
				cout<<"\n";
			}
		}
		void BitMask(unsigned char a){
			if(a==0x0){
				error = true;
				cout<<"\n\nOOps! (En-)Codind with NUL mask!\n\n";
				return;
			}
			error = false;
			for(int i = 0; i < size; i++) arr[i]->BitMask(a);
		}
		
		
		//operators
		MMatrix& operator=(const MMatrix &A){
			arr = new MVector*[A.GetSize()];
			size = A.GetSize();
			for(int i = 0; i < size; i++){
				arr[i] = A.GetFromInd(i);
			}
			return *this;
		}
		bool operator==(const MMatrix &M2){
			bool flag = true;
			if(size != M2.GetSize()) return false;
			else if(arr[0]->GetSize() != M2.GetFromInd(0)->GetSize()) return false;
			else{
				for(int i = 0; i < size; i++){
					if(arr[i]!=M2.GetFromInd(i)){
						flag = false;
						break;
					}
				}
				return flag;
			}
		}
		bool operator!=(const MMatrix &M2){
			bool flag = false;
			if(size != M2.GetSize()) return true;
			else if(arr[0]->GetSize() != M2.GetFromInd(0)->GetSize()) return true;
			else{
				for(int i = 0; i < size; i++){
					if(arr[i]!=M2.GetFromInd(i)){
						flag = true;
						break;
					}
				}
				return flag;
			}
		}
		bool operator>(const MMatrix &M2){
			if(size*arr[0]->GetSize() > M2.GetSize()*M2.GetFromInd(0)->GetSize()) return true;
			else return false;
		}
		bool operator<(const MMatrix &M2){
			if(size*arr[0]->GetSize() < M2.GetSize()*M2.GetFromInd(0)->GetSize()) return true;
			else return false;
		}
};