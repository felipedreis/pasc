#include <iostream>
#include <exception>
#include <fstream>
#include <unistd.h>

#include "test/TestCase.h"
#include "test/ScannerTest.h"
#include "test/ScopeTest.h"
#include "test/SyntaxTest.h"
#include "test/TokenTypeTest.h"

#include "exception/InvalidOperation.h"
#include "exception/MalformedIdentifier.h"
#include "exception/SyntaxError.h"
#include "exception/SymbolAlreadyInstalled.h"
#include "exception/SymbolNotFound.h"
#include "exception/TypeMismatch.h"
#include "exception/UnknownOperator.h"


#include "frontend/Scanner.h"
#include "frontend/Syntax.h"


using std::cout;
using std::endl;
using std::exception;
using std::fstream;

int main(int argc, char** argv) {
	Scanner::init();

#ifdef RUN_TESTS
	TEST(Scanner)
	TEST(Scope)
	TEST(Syntax)
	TEST(TokenType)
#endif

	fstream code;
	code.open("tests/test1.psc");
	Scanner scan(code);
	CodeGenerator *generator = new CodeGenerator;
	Syntax parser(&scan, generator);

	Token t;

	cout << "Opening file " << argv[1] << "..." << endl;
	try {
		parser.analyse();
		generator->generate();

		cout << "compilation finished with success" << endl;

	} catch (MalformedIdentifier& ex) {
		cout << "ERROR in line " << scan.getLineCount()+1
			 << ", column " << scan.getColumnCount()-t.getValue().size()+1
			 << ": " << ex.what() << endl;		
	} catch(UnknownOperator& ex) {
		cout << "ERROR in line " << scan.getLineCount()+1
			 << ", column " << scan.getColumnCount()-t.getValue().size()+1
			 << ": " << ex.what() << endl;	
	} catch (SyntaxError& ex) {
		cout << "ERROR in line " << scan.getLineCount()+1
			 << ", column " << scan.getColumnCount()-t.getValue().size()+1
			 << ": " << ex.what() << endl;
	} catch (SymbolAlreadyInstalled& ex) {
		cout << "ERROR in line " << scan.getLineCount()+1
			 << ", column " << scan.getColumnCount()-t.getValue().size()+1
			 << ": " << ex.what() << endl;
	} catch (SymbolNotFound& ex) {
		cout << "ERROR in line " << scan.getLineCount()+1
			 << ", column " << scan.getColumnCount()-t.getValue().size()+1
			 << ": " << ex.what() << endl;
	} catch (TypeMismatch& ex) {
		cout << "ERROR in line " << scan.getLineCount()+1
			 << ", column " << scan.getColumnCount()-t.getValue().size()+1
			 << ": " << ex.what() << endl;
	} catch (InvalidOperation& ex) {
		cout << "ERROR in line " << scan.getLineCount()+1
			 << ", column " << scan.getColumnCount()-t.getValue().size()+1
			 << ": " << ex.what() << endl;
	} catch (const char* s) {
        cout << s << endl;
    }

	return 0;
}