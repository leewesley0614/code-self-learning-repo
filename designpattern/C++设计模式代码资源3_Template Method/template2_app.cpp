//Ӧ�ó��򿪷���Ա
class Application : public Library {
protected:
	virtual bool Step2(){
		//... ������дʵ��
    }

    virtual void Step4() {
		//... ������дʵ��
    }
};




int main()
	{
	    Library* pLib=new Application();
	    pLib->Run();

		delete pLib;
	}
}




