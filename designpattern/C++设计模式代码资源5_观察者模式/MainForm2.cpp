class MainForm : public Form, public IProgress
{
	TextBox* txtFilePath;
	TextBox* txtFileNumber;

	ProgressBar* progressBar; //Concrete Observer 1

public:
	void Button1_Click(){

		string filePath = txtFilePath->getText();
		int number = atoi(txtFileNumber->getText().c_str());

		ConsoleNotifier cn;

		FileSplitter splitter(filePath, number);

		splitter.addIProgress(this); //Observer1, 订阅通知
		splitter.addIProgress(&cn)�� //Observer2

		splitter.split();

		splitter.removeIProgress(this);

	}

	virtual void DoProgress(float value){
		progressBar->setValue(value);
	}
};

class ConsoleNotifier : public IProgress {  // Observer 2
public:
	virtual void DoProgress(float value){
		cout << ".";
	}
};

