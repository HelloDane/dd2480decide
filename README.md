# Assignment #1: DECIDE

## Summary
DECIDE() will generate a boolean signal which determines whether an interceptor should be launched based upon input radar tracking information. This radar tracking information is available at the instant the function is called.
DECIDE() determines which combination of the several possible Launch Interceptor Conditions (LIC’s) are relevant to the immediate situation. The interceptor launch button is normally considered locked; only if all relevant combinations of launch conditions are met will the launchunlock signal be issued.
DECIDE() determines whether each of fifteen LIC’s is true for an input set of up to 100 planar data points representing radar echoes. The fifteen elements of a Conditions Met Vector (CMV) will be assigned boolean values true or false; each element of the CMV corresponds to one LIC’s condition.

## Compilation and testing
In order to compile an executable for running the tests, the following command can be executed in the /src directory:
gcc test/decideTest.c test/LICsTest.c test/test.c decide.c LICs.c helper.c -o test_decide

Then, to run the tests, simply execute the test_decide.exe executable in your terminal.

## Statement of contributions
In the first step of the project, we created a code skeleton for the entire project and the test suite. This was done by pair programming while in a Discord meeting, so that all project members were involved in the project setup and the decision making process.

The 15 LIC-functions and their tests were then divided equaly amongs the three project members, where Marcus implemented LICs 0, 3, 6, 9 and 12, Daniel implemented LICs 1, 4, 7, 10, and 13, and Siyang implemented LICs 2, 5, 8, 11 and 14.

The three functions calculatePUM, calculateFUV, and decideLaunch were also split amongst the members, where each member implemented one of the functions along with their tests.

The three test cases for the DECIDE function, a positive problem instance, a negative one and an invalid one, were also split equally amongst the members where each member implemented one of the test cases.

Finally, all members contributed with different parts of the documentation.

We are very proud of the work we have done, especially considering we were 2 team members short, and we have learned a lot about the process of working simultaneously on a project together with other developers. While the initial project setup was a bit tough, the process of writing issues and creating branches for each issue, was quickly discovered to be extremely efficient, and a fantastic and well structured way of working.