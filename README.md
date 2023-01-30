# Assignment #1: DECIDE

## Summary
DECIDE() will generate a boolean signal which determines whether an interceptor should be launched based upon input radar tracking information. This radar tracking information is available at the instant the function is called.
DECIDE() determines which combination of the several possible Launch Interceptor Conditions (LIC’s) are relevant to the immediate situation. The interceptor launch button is normally considered locked; only if all relevant combinations of launch conditions are met will the launchunlock signal be issued.
DECIDE() determines whether each of fifteen LIC’s is true for an input set of up to 100 planar data points representing radar echoes. The fifteen elements of a Conditions Met Vector (CMV) will be assigned boolean values true or false; each element of the CMV corresponds to one LIC’s condition.

## Compilation and testing
In order to compile an executable for running the tests, the following command can be executed in the /src directory:
gcc test/decideTest.c test/LICsTest.c test/test.c decide.c LICs.c helper.c -o test_decide

Then, to run the tests, simply execute the test_decide.exe executable in your terminal.