#include "lab7.h"
int main() {
	DLUL editor;
	editor.InsertItem("am");
	editor.InsertItem("Iron");
	editor.GoToTop();
	editor.InsertItem("I");
	editor.GoToBottom();
	editor.InsertItem("man");
	editor.Print();
}