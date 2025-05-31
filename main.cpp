/********************************************************************************************************************************************************
THIS PROGRAM WILL HELP SOLVE THE NEW YEARS CHALLENGES 1 THROUGH 5.
IT OUTPUTS 4 VARIATIONS OF EACH CODE, DEPENDING ON YOUR CHOICE.

1. CIPHERTEXT FORWARD, PI VALUES FORWARD
2. CIPHERTEXT BACKWARD, PI VALUES FORWARD.
3. CIPHERTEXT FORWARD, PI VALUES BACKWARD
4. CIPHERTEXT BACKWARD, PI VALUES BACKWARD

THEN EVERY RESULT IS ROTATED 25 TIMES.

WE CAN ALTER THIS CODE TO PRINT ALL RESULTS BACKWARDS AS WELL. IT'S REALLY JUST STARTING TO BE A PAIN IN THE ASS.
MIGHT HAVE TO LENGTHEN THE PI VALUES AS WELL. CURRENTLY IT'S AT ABOUT 600.
ALSO A POSSIBILITY THE CIPHER TEXT AND PI VALUES ARE ADDED INSTEAD OF SUBTRACTED.

**********************************************************************************************************************************************************/


#include <iostream>
#include<cmath>
#include <string>
#include <algorithm>
#include<fstream>
#include <iterator>
using namespace std;

// SHIFT FUNCTION TO ROTATE LETTERS

std::string rotext(const std::string& text,int shiftnum) {
    std::string result = "";
    for (char c : text) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            result += (c - base + shiftnum) % 26 + base;
        } else {
            result += c;
        }
    }
    return result;
}
//WILL USE THIS PROGRAM FOR THE OTHER PARTS, 1-4, AS WELL

int main()
{

  ofstream myfile;   // CREATE OPTIONAL OUTPUT FILE
  myfile.open ("NEWYEARSPART5-CPP.txt");


int i=0;
int j=0;

   string PIstring="";
   string tempstring="";
   int tempvar=0;
   int finalval=0;
   int direction=0;
   int pidirection=0;
   int shift=0;
   int shiftamount=0;
   string rotatedstring="";

   string alphabet1="ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    string codestring="JMXFDPYXNNVICTKKEATTVLDUSMRQFBXXDZPETBSMYLDKTQMKEAYUGFSYFLZGLCHYUGYGLUAMNPZDKJKXRHKYRXWUKFTQVFXMDNCROEMWAQZVUGVMADCUFZCHLJBIFVUCOMFZBTRRZUDAXVVQBTLSJYQZMFFPVIKXWIYKUOPBYQJFGBOXCPUNMNVXCPBBMNLTCXRJXVMMLCP";
   //string codestring="PCLMMVXJRXCTLNMBBPCXVNMNUPCXOBGFJQYBPOUKYIWXKIVPFFMZQYJSLTBQVVXADUZRRTBZFMOCUVFIBJLHCZFUCDAMVGUVZQAWMEORCNDMXFVQTFKUWXRYKHRXKJKDZPNMAULGYGUYHCLGZLFYSFGUYAEKMQTKDLYMSBTEPZDXXBFQRMSUDLVTTAEKKTCIVNNXYPDFXMJ";

  // int PIvals[]={2,1,9,4,9,1,1,0,3,8,1,8,3,9,7,2,2,1,9,8,4,2,7,2,5,7,5,8,8,1,5,3,7,6,5,9,4,7,2,6,9,9,7,3,2,6,4,4,7,0,8,4,5,8,1,1,5,0,1,3,9,7,1,1,6,2,3,9,1,8,3,7,1,1,6,8,1,2,9,0,3,5,9,1,9,5,9,5,7,5,6,3,0,7,2,7,5,0,3,3,4,9,0,6,1,1,5,1,4,9,1,5,9,6,4,1,4,8,3,1,2,5,6,6,4,0,2,8,8,4,5,0,3,5,0,3,3,1,1,0,0,6,3,0,9,5,2,9,8,7,6,3,4,6,3,5,1,7,1,9,0,4,5,2,9,2,8,2,6,9,0,2,9,0,2,5,1,8,8,4,7,1,8,8,5,5,1,3,6,0,6,6,0,0,7,8,5,4,2,7,3,7,2,1,4,1,9,4,2,0,6,2,7,0,6,3,9,3,3,1,2,8,4,6,6,2,3,4,5,4,0,1,6,8,4,3,0,6,4,3,2,9,6,6,5,8,4,6,5,4,1,9,0,9,1,0,2,1,7,2,5,6,1,3,8,7,6,8,7,3,3,2,8,4,6,5,7,4,8,2,1,6,4,4,3,3,9,5,6,6,5,7,9,0,1,8,8,2,4,4,6,9,1,8,3,0,3,9,4,5,9,8,4,9,2,2,6,4,4,6,9,5,5,5,0,1,1,2,5,8,3,9,1,0,7,2,0,1,4,8,2,0,5,4,7,1,1,1,8,4,8,2,1,8,0,4,9,5,3,5,2,7,1,3,2,2,8,5,0,5,5,9,0,6,4,4,8,3,9,0,7,4,6,6,0,3,2,8,2,3,1,5,6,8,0,8,4,1,2,8,9,7,6,0,7,1,1,2,4,3,5,2,8,4,3,0,8,2,6,8,9,9,8,0,2,6,8,2,6,0,4,6,1,8,7,0,3,2,9,5,4,4,9,4,7,9,0,2,8,5,0,1,5,7,3,9,9,3,9,6,1,7,9,1,4,8,8,2,0,5,9,7,2,3,8,3,3,4,6,2,6,4,8,3,2,3,9,7,9,8,5,3,5,6,2,9,5,1,4,1,3};
   int tempvals[]={2,1,9,4,9,1,1,0,3,8,1,8,3,9,7,2,2,1,9,8,4,2,7,2,5,7,5,8,8,1,5,3,7,6,5,9,4,7,2,6,9,9,7,3,2,6,4,4,7,0,8,4,5,8,1,1,5,0,1,3,9,7,1,1,6,2,3,9,1,8,3,7,1,1,6,8,1,2,9,0,3,5,9,1,9,5,9,5,7,5,6,3,0,7,2,7,5,0,3,3,4,9,0,6,1,1,5,1,4,9,1,5,9,6,4,1,4,8,3,1,2,5,6,6,4,0,2,8,8,4,5,0,3,5,0,3,3,1,1,0,0,6,3,0,9,5,2,9,8,7,6,3,4,6,3,5,1,7,1,9,0,4,5,2,9,2,8,2,6,9,0,2,9,0,2,5,1,8,8,4,7,1,8,8,5,5,1,3,6,0,6,6,0,0,7,8,5,4,2,7,3,7,2,1,4,1,9,4,2,0,6,2,7,0,6,3,9,3,3,1,2,8,4,6,6,2,3,4,5,4,0,1,6,8,4,3,0,6,4,3,2,9,6,6,5,8,4,6,5,4,1,9,0,9,1,0,2,1,7,2,5,6,1,3,8,7,6,8,7,3,3,2,8,4,6,5,7,4,8,2,1,6,4,4,3,3,9,5,6,6,5,7,9,0,1,8,8,2,4,4,6,9,1,8,3,0,3,9,4,5,9,8,4,9,2,2,6,4,4,6,9,5,5,5,0,1,1,2,5,8,3,9,1,0,7,2,0,1,4,8,2,0,5,4,7,1,1,1,8,4,8,2,1,8,0,4,9,5,3,5,2,7,1,3,2,2,8,5,0,5,5,9,0,6,4,4,8,3,9,0,7,4,6,6,0,3,2,8,2,3,1,5,6,8,0,8,4,1,2,8,9,7,6,0,7,1,1,2,4,3,5,2,8,4,3,0,8,2,6,8,9,9,8,0,2,6,8,2,6,0,4,6,1,8,7,0,3,2,9,5,4,4,9,4,7,9,0,2,8,5,0,1,5,7,3,9,9,3,9,6,1,7,9,1,4,8,8,2,0,5,9,7,2,3,8,3,3,4,6,2,6,4,8,3,2,3,9,7,9,8,5,3,5,6,2,9,5,1,4,1,3};
   int PIvals[]={3,1,4,1,5,9,2,6,5,3,5,8,9,7,9,3,2,3,8,4,6,2,6,4,3,3,8,3,2,7,9,5,0,2,8,8,4,1,9,7,1,6,9,3,9,9,3,7,5,1,0,5,8,2,0,9,7,4,9,4,4,5,9,2,3,0,7,8,1,6,4,0,6,2,8,6,2,0,8,9,9,8,6,2,8,0,3,4,8,2,5,3,4,2,1,1,7,0,6,7,9,8,2,1,4,8,0,8,6,5,1,3,2,8,2,3,0,6,6,4,7,0,9,3,8,4,4,6,0,9,5,5,0,5,8,2,2,3,1,7,2,5,3,5,9,4,0,8,1,2,8,4,8,1,1,1,7,4,5,0,2,8,4,1,0,2,7,0,1,9,3,8,5,2,1,1,0,5,5,5,9,6,4,4,6,2,2,9,4,8,9,5,4,9,3,0,3,8,1,9,6,4,4,2,8,8,1,0,9,7,5,6,6,5,9,3,3,4,4,6,1,2,8,4,7,5,6,4,8,2,3,3,7,8,6,7,8,3,1,6,5,2,7,1,2,0,1,9,0,9,1,4,5,6,4,8,5,6,6,9,2,3,4,6,0,3,4,8,6,1,0,4,5,4,3,2,6,6,4,8,2,1,3,3,9,3,6,0,7,2,6,0,2,4,9,1,4,1,2,7,3,7,2,4,5,8,7,0,0,6,6,0,6,3,1,5,5,8,8,1,7,4,8,8,1,5,2,0,9,2,0,9,6,2,8,2,9,2,5,4,0,9,1,7,1,5,3,6,4,3,6,7,8,9,2,5,9,0,3,6,0,0,1,1,3,3,0,5,3,0,5,4,8,8,2,0,4,6,6,5,2,1,3,8,4,1,4,6,9,5,1,9,4,1,5,1,1,6,0,9,4,3,3,0,5,7,2,7,0,3,6,5,7,5,9,5,9,1,9,5,3,0,9,2,1,8,6,1,1,7,3,8,1,9,3,2,6,1,1,7,9,3,1,0,5,1,1,8,5,4,8,0,7,4,4,6,2,3,7,9,9,6,2,7,4,9,5,6,7,3,5,1,8,8,5,7,5,2,7,2,4,8,9,1,2,2,7,9,3,8,1,8,3,0,1,1,9,4,9,1,2};           //int PIvals[45]={9,3,9,6,1,7,9,1,4,8,8,2,0,5,9,7,2,3,8,3,3,4,6,2,6,4,8,3,2,3,9,7,9,8,5,3,5,6,2,9,5,1,4,1,3};

 //cout << size(PIvals);
// system("pause");

//   USE THIS FOR USER INPUT SO WE DON'T HAVE TO KEEP CHANGING THE PROGRAM. DUH.
// YOU CAN ALSO COMMENT IT OUT IF YOU'D RATHER JUST CHANGE THE VARIALBES MANUALLY.

   cout << "Would you like the input forwards or backwards? Please choose 1 for forward, 2 for backward." << endl;
   cin >> direction;
   if(direction==2)
    codestring="PCLMMVXJRXCTLNMBBPCXVNMNUPCXOBGFJQYBPOUKYIWXKIVPFFMZQYJSLTBQVVXADUZRRTBZFMOCUVFIBJLHCZFUCDAMVGUVZQAWMEORCNDMXFVQTFKUWXRYKHRXKJKDZPNMAULGYGUYHCLGZLFYSFGUYAEKMQTKDLYMSBTEPZDXXBFQRMSUDLVTTAEKKTCIVNNXYPDFXMJ";
     cout << endl << endl;
     cout << codestring << endl << endl;
   cout << "Would you like the PI string forward or backwards? Please choose 1 for forward or 2 for backward."  << endl << endl;
   cin >> pidirection;
   cout << endl;
    if(pidirection==2)   //  IF SELECTION IS 2 FOR BACKWARDS
         for(i=0; i< size(PIvals);i++)

         {
          PIvals[i]=tempvals[i];
          cout << PIvals[i];
                //j++;
         }

            else
            {
                for(i=0;i<size(PIvals);i++)
                {
                    cout << PIvals[i];    //PRINT FORWARD - DEFAULT
                }

            }

    cout << endl << endl;
   //cout << "Shift amount:  Please enter 0 through 25.. 0 for no shift. ";
   //cin >> shift;

   cout << "See output file (NEWYEARSPART5-CPP.txt) for results and all shifts : 0 to 25"  << endl << endl;

   //cout << "Hit any key to continue."  << endl << endl;

   system("pause");
//---------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------

 // TESTING STRINGS AND PI VALUES BELOW FOR DIFFERENT PARTS OF THE NEW YEARS CHALLENGE

   //string codestring="JTXGJTBUPAKLEDOBYCGRNHYXUEMCGRMLKNQINBVHRA";   //PART 1
   //string codestring="DMNLGYXYEECZXTDKZHADVFRPMKREYGSXQCBDJKBMEYSHSXMRDJNQL";  //part 3
    //string codestring="LQNJDRMXSHSYEMBKJDBCQXSGYERKMPRFVDAHZKDTXZCEEYXYGLNMD";
  //string codestring="UWSLDWLMHMNDDNIVMAESXJKUDHBYFSDOKQAVGJTUCFSW";  //PART 2
   //string codestring="WSFCUTJGVAQKODSFYBHDUKJXSEAMVINDDNMHMLWDLSWU";


  //string codestring = "MYUCRPJYBCCMHBZOXLAQHKASDMQUZYGWNWFKWPBTGMRZXHTMBFDACCSZZEVRMXTSEODUYGJYJDLKWEJT";   //PART 4
   //string codestring ="TJEWKLDJYJGYUDOESTXMRVEZZSCCADFBMTHXZRMGTBPWKFWNWGYZUQMDSAKHQALXOZBHMCCBYJPRCUYM";  //part 4 reversed

//int PIvals[300]={8,4,1,2,8,9,7,6,0,7,1,1,2,4,3,5,2,8,4,3,0,8,2,6,8,9,9,8,0,2,6,8,2,6,0,4,6,1,8,7,0,3,2,9,5,4,4,9,4,7,9,0,2,8,5,0,1,5,7,3,9,9,3,9,6,1,7,9,1,4,8,8,2,0,5,9,7,2,3,8,3,3,4,6,2,6,4,8,3,2,3,9,7,9,8,5,3,5,6,2,9,5,1,4,1,3};

  // string codestring="JMXFDPYXNNVICTKKEATTVLDUSMRQFBXXDZPETBSMYLDKTQMKEAYUGFSYFLZGLCHYUGYGLUAMNPZDKJKXRHKYRXWUKFTQVFXMDNCROEMWAQZVUGVMADCUFZCHLJBIFVUCOMFZBTRRZUDAXVVQBTLSJYQZMFFPVIKXWIYKUOPBYQJFGBOXCPUNMNVXCPBBMNLTCXRJXVMMLCP";

   //int PIvals[152]={3,1,4,1,5,9,2,6,5,3,5,8,9,7,9,3,2,3,8,4,6,2,6,4,3,3,8,3,2,7,9,5,0,2,8,8,4,1,9,7,1,6,9,3,9,9,3,7,5,1,0,5,8,2,0,9,7,4,9,4,4,5,9,2,3,0,7,8,1,6,4,0,6,2,8,6,2,0,8,9,9,8,6,2,8,0,3,4,8,2,5,3,4,2,1,1,7,0,6,7,9,8,2,1,4,8,0,8,6,5,1,3,2,8,2,3,0,6,6,4,7,0,9,3,8,4,4,6,0,9,5,5,0,5,8,2,2,3,1,7,2,5,3,5,9,4,0,8,1,2,8};
    //int PIvals[44]={3,4,6,2,6,4,8,3,2,3,9,7,9,8,5,3,5,6,2,9,5,1,4,1,3};     // PI NUMBERS FROM POSITION 25 IN REVERSE
   //WSFCUTJGVAQKODSFYBHDUKJXSEAMVINDDNMHMLWDLSWU      CODE IN REVERSE

   //int PIvals[44]={3,8,3,2,7,9,5,0,2,8,8,4,1,9,7,1,6,9,3,9,9,3,7,5,1,0,5,8,2,0,9,7,4,9,4,4,5,9,2,3,0,7,8};      //PI NUMBERS FROM POSITION 25

   //int PIvals[44]={8,7,0,3,2,9,5,4,4,9,4,7,9,0,2,8,5,0,1,5,7,3,9,9,3,9,6,1,7,9,1,4,8,8,2,0,5,9,7,2,3,8,3};

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

for(i=0;i<(600);i++)    //THE LAST SEVERAL OUTPUTS HAVE A REPEATING END BECAUSE THEY GO BEYOND THE 600 LIMIT OF THE PI STRING, WHICH CAN BE LENGTHENED TO INFINITY IF YOU WANT

{
cout << i << "          ";   //USE THIS IS IF YOU WANT TO ADD A LINE NUMBER TO EACH OUTPUT
myfile << i << "   ";
   for(j=0;j<=codestring.length();j++)
    {

            tempvar=(alphabet1.find(codestring[j]));  // compare letter position in code to letter position in alphabet, get position number

            finalval=(tempvar - (PIvals[i+j]));   //SUBTRACT PI VALUE FROM LETTER VALUE IN ALPHABET. store that value in finalval, extra step but whatever


            //cout << PIvals[i+j];  // THESE LINES WEREJUST USED FOR MAKING SURE OUTPUT WAS WORKING CORRECTLY
            //system("pause");
           //cout << tempvar;
           //cout << finalval;
            // system("pause");

            if(finalval<0)                      //if value is negative, subtract that abs(number) from 26 to get correct letter.. WE ALSO COULD HAVE JUST USED THE ABS FUNCTION ON FINAL OUTPUT
               finalval=26-abs(finalval);
            //cout << finalval << " ";

            tempstring=tempstring+ alphabet1[finalval];  //add letter to string until complete
            PIstring=PIstring+ to_string(PIvals[i+j]);    // CREATE PI STRING TO SEE WHAT PI VALUES WERE USED FOR EACH OUTPUT


    }
    myfile<< "RESULTS SHIFTED 25 TIMES "  << endl << endl;

    for(shiftamount=0;shiftamount<26;shiftamount++){           //OUTPUT ALL 25 SHIFTS TO A FILE TO EVALUATE LATER.

        rotatedstring=rotext(tempstring,shiftamount);             //USE THIS TO SHIFT OUTPUT BY WHATEVER VALUE YOU WANT, BUT DON'T SAVE IT TO ITSELF, CAUSE THAT CAUSED PROBLEMS :)
                                                                    // COULD HAVE SKIPPED SAVING TO A VARIABLE AND JUST PRINTED OUT THE FUNCTION RESULTS. I TEND TO SAVE THINGS TO VARIABLES
                                                                    // FOR TESTING PURPOSES.

        myfile << rotatedstring << endl;    //OUTPUT ROTATED STRING TO FILE OPTIONALLY
        }

cout << rotatedstring << endl;  //OUR FINAL STRING


//cout << PIstring << endl;   // THIS OUTPUTS THE PI STRING USED FOR EACH "SOLUTION"


//RESET VARIABLES BELOW
j=0;
PIstring="";
tempstring="";
tempvar=0;
finalval=0;

}

 myfile.close();  // CLOSE OUTPUT FILE

return 0;
}

//COMMENTING SOME PI STRINGS DOWN HERE SO I DON'T HAVE TO KEEP LOOKING IT UP ON THE WEB

//3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342117067982148086513282306647093844609550582231725359408128
//PI TO THE 100TH DIGIT:   3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679



//
