#ifndef FileReferenceMacros_Header

//Generating Precompiled header name based on Macro based on code from
//https://stackoverflow.com/questions/30438911/how-to-get-a-visual-studio-macro-value-into-a-pre-processor-directive
#define MacroToStringify(x) #x
#define MacroToString(x) MacroToStringify(x)

//#define MacroToIncludedFile(x)\
//#include MacroToStringify(x)

#endif