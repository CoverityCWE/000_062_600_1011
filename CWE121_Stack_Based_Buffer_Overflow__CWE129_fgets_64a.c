/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE121_Stack_Based_Buffer_Overflow__CWE129_fgets_64a.c
Label Definition File: CWE121_Stack_Based_Buffer_Overflow__CWE129.label.xml
Template File: sources-sinks-64a.tmpl.c
*/
/*
 * @description
 * CWE: 121 Stack Based Buffer Overflow
 * BadSource: fgets Read data from the console using fgets()
 * GoodSource: Larger than zero but less than 10
 * Sinks:
 *    GoodSink: Ensure the array index is valid
 *    BadSink : Improperly check the array index by not checking the upper bound
 * Flow Variant: 64 Data flow: void pointer to data passed from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#define CHAR_ARRAY_SIZE (3 * sizeof(data) + 2)

#ifndef OMITBAD

/* bad function declaration */
void CWE121_Stack_Based_Buffer_Overflow__CWE129_fgets_64b_badSink(void * dataVoidPtr);

void CWE121_Stack_Based_Buffer_Overflow__CWE129_fgets_64_bad()
{
    int data;
    /* Initialize data */
    data = -1;
    {
        char inputBuffer[CHAR_ARRAY_SIZE] = "";
        /* POTENTIAL FLAW: Read data from the console using fgets() */
        if (fgets(inputBuffer, CHAR_ARRAY_SIZE, stdin) != NULL)//SLIVER_SOURCE
        {
            /* Convert to int */
            data = atoi(inputBuffer);
        }
        else
        {
            printLine("fgets() failed.");
        }
    }
    CWE121_Stack_Based_Buffer_Overflow__CWE129_fgets_64b_badSink(&data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE121_Stack_Based_Buffer_Overflow__CWE129_fgets_64b_goodG2BSink(void * dataVoidPtr);

static void goodG2B()
{
    int data;
    /* Initialize data */
    data = -1;
    /* FIX: Use a value greater than 0, but less than 10 to avoid attempting to
     * access an index of the array in the sink that is out-of-bounds */
    data = 7;
    CWE121_Stack_Based_Buffer_Overflow__CWE129_fgets_64b_goodG2BSink(&data);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE121_Stack_Based_Buffer_Overflow__CWE129_fgets_64b_goodB2GSink(void * dataVoidPtr);

static void goodB2G()
{
    int data;
    /* Initialize data */
    data = -1;
    {
        char inputBuffer[CHAR_ARRAY_SIZE] = "";
        /* POTENTIAL FLAW: Read data from the console using fgets() */
        if (fgets(inputBuffer, CHAR_ARRAY_SIZE, stdin) != NULL)//SLIVER_SOURCE
        {
            /* Convert to int */
            data = atoi(inputBuffer);
        }
        else
        {
            printLine("fgets() failed.");
        }
    }
    CWE121_Stack_Based_Buffer_Overflow__CWE129_fgets_64b_goodB2GSink(&data);
}

void CWE121_Stack_Based_Buffer_Overflow__CWE129_fgets_64_good()
{
    goodG2B();
    goodB2G();
}

#endif /* OMITGOOD */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITGOOD
    printLine("Calling good()...");
    CWE121_Stack_Based_Buffer_Overflow__CWE129_fgets_64_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE121_Stack_Based_Buffer_Overflow__CWE129_fgets_64_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif

//SLIVER_SOURCE:CWE121_Stack_Based_Buffer_Overflow__CWE129_fgets_64a.c:35--->SLIVER_SINK:CWE121_Stack_Based_Buffer_Overflow__CWE129_fgets_64b.c:37 YES
//SLIVER_SOURCE:CWE121_Stack_Based_Buffer_Overflow__CWE129_fgets_64a.c:35--->SLIVER_SINK:CWE121_Stack_Based_Buffer_Overflow__CWE129_fgets_64b.c:69 NO
//SLIVER_SOURCE:CWE121_Stack_Based_Buffer_Overflow__CWE129_fgets_64a.c:35--->SLIVER_SINK:CWE121_Stack_Based_Buffer_Overflow__CWE129_fgets_64b.c:96 NO
//SLIVER_SOURCE:CWE121_Stack_Based_Buffer_Overflow__CWE129_fgets_64a.c:77--->SLIVER_SINK:CWE121_Stack_Based_Buffer_Overflow__CWE129_fgets_64b.c:37 NO
//SLIVER_SOURCE:CWE121_Stack_Based_Buffer_Overflow__CWE129_fgets_64a.c:77--->SLIVER_SINK:CWE121_Stack_Based_Buffer_Overflow__CWE129_fgets_64b.c:69 NO
//SLIVER_SOURCE:CWE121_Stack_Based_Buffer_Overflow__CWE129_fgets_64a.c:77--->SLIVER_SINK:CWE121_Stack_Based_Buffer_Overflow__CWE129_fgets_64b.c:96 YES