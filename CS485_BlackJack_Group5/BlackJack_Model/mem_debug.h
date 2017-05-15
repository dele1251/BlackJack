//https://msdn.microsoft.com/en-us/library/x98tx3cf(v=vs.140).aspx

//https://msdn.microsoft.com/en-us/cc300389.aspx#D

// compile by using: cl /EHsc /W4 /D_DEBUG /MDd testDriver.cpp

#ifdef MEM_DEBUG

#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>


#ifdef _DEBUG
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
// Replace _NORMAL_BLOCK with _CLIENT_BLOCK if you want the
// allocations to be of _CLIENT_BLOCK type

// the following line comes from the Visual Studio 2010
// documentation.  This following line seems to be necessary
// to generate line number results.
#define new DBG_NEW
#else
#define DBG_NEW new
#endif

#endif
