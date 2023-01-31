# Assignment #1: DECIDE

## Summary
DECIDE() will generate a boolean signal which determines whether an interceptor should be launched based upon input radar tracking information. This radar tracking information is available at the instant the function is called.
DECIDE() determines which combination of the several possible Launch Interceptor Conditions (LIC’s) are relevant to the immediate situation. The interceptor launch button is normally considered locked; only if all relevant combinations of launch conditions are met will the launchunlock signal be issued.
DECIDE() determines whether each of fifteen LIC’s is true for an input set of up to 100 planar data points representing radar echoes. The fifteen elements of a Conditions Met Vector (CMV) will be assigned boolean values true or false; each element of the CMV corresponds to one LIC’s condition.

## Compilation and testing
In order to compile an executable for running the tests, the following command can be executed in the /src directory:
gcc test/decideTest.c test/LICsTest.c test/test.c decide.c LICs.c helper.c -o test_decide

Then, to run the tests, simply execute the test_decide.exe executable in your terminal.
### Compilation with Makefile
In src directory, execute:
```
make
```
run tests:
```
./test_decide
```

# Essence standard assessment
According to the Essence standard there are six states which describe the progress of adapting a way-of-working within a team, in order: Principles Established, Foundation Established, In Use, In Place, Working well, and Retired. We have fullfilled the state "Principles Established" by committing to and understanding the principles and constraints as required by the stakeholders, i.e. by understanding the assignment and the stated required properties. The tools needed are agreed upon as well. We have fullfilled the "Foundation Established" state by selecting key practices and tools of the way-of-working, which allow for the work to start. For instance, we have agreed to split the work needed into issues which represent atomic bug fixes or features, and agreed to assign these evenly between the group members. We have also agreed upon how to document the code, how to write issues, etc. We have a usable way-of-working. We have also fullfilled the "In Use" state, by applying the practices and tools agreed upon to do real work, and making progress with the work. The practices in place support collaboration, communication and feedback, for instance we have created a channel for communication with some rules, and require reviews of pull requests from each other before pushing. Every team member has been assigned a number of features to implement, which can be worked on at the same time. Finally, we are currently in the "In Place" state, since each team member is using the practices and tools which have been adapted, and is involved in the inspection, adaptation and improvement of the way-of-working. We actively discuss our method choices, and reflect on what works and what could be changed. We have not yet reached the "Working well" state, since our team does not naturally apply these principles without thinking about them. There are still some inconsistencies between team members, for instance regarding how the code is documented and the commits are worded. To reach the next state, we need more time to familiarise ourselves with the chosen practices, by performing more work and reflecting more on the way of working.

## Statement of contributions
In the first step of the project, we created a code skeleton for the entire project and the test suite. This was done by pair programming while in a Discord meeting, so that all project members were involved in the project setup and the decision making process.

The 15 LIC-functions and their tests were then divided equaly amongs the three project members, where Marcus implemented LICs 0, 3, 6, 9 and 12, Daniel implemented LICs 1, 4, 7, 10, and 13, and Siyang implemented LICs 2, 5, 8, 11 and 14.

The three functions calculatePUM, calculateFUV, and decideLaunch were also split amongst the members, where each member implemented one of the functions along with their tests.

The three test cases for the DECIDE function, a positive problem instance, a negative one and an invalid one, were also split equally amongst the members where each member implemented one of the test cases.

Finally, all members contributed with different parts of the documentation.

We are very proud of the work we have done, especially considering we were 2 team members short, and we have learned a lot about the process of working simultaneously on a project together with other developers. While the initial project setup was a bit tough, the process of writing issues and creating branches for each issue, was quickly discovered to be extremely efficient, and a fantastic and well structured way of working.

In addition to the aforementioned conditions, we believe that we have fullfilled the "valuable and remarkable" criteria by implementing a build automation tool (make) in our project, as well as applying thorough unit testing for all LIC conditions, performing tests for each LIC that check positive, negative, and invalid cases.


