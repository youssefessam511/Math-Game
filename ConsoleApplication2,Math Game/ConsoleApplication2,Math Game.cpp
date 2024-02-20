#include <iostream>
#include <cmath>
#include<string>
#include<cstdlib>
using namespace std;

enum enQuestionLevel { Easy = 1, Med = 2, Hard = 3, MixOfQlevel = 4 };

enum enOPtype { Add = 1, Sub = 2, Multplication = 3, Div = 4, MixOfOT = 5 };

struct stFinalGameResault
{

    short NumOfQuestion = 0;
    string QuestionLevel;
    string Optype ;
    short NumOfRightAnswer = 0; 
    short NumOfWrongAnswer = 0; 
    short RightAnswer = 0;

};

int RandomNumber(int From, int To)
{
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

short HowManyQuestion(stFinalGameResault &NumOfQuestions) {

    short Num = 0;

    cout << "How Many Question Do You Want To Answer ?  >> ";
    cin >> Num;

    NumOfQuestions.NumOfQuestion = Num;
    return Num;

}

enQuestionLevel EnterQuestionLevel(stFinalGameResault& FinalResaults)
{

    short Qlvl = 0;

    do {

        cout << "Question Level : [1] Easy , [2] Med , [3] Hard , [4] Mix ?  >>  ";
        cin >> Qlvl;

    } while (Qlvl < 1 || Qlvl > 4);

    FinalResaults.QuestionLevel = enQuestionLevel(Qlvl); 
    return enQuestionLevel(Qlvl);

}



enOPtype EnterOPtype(stFinalGameResault& FinalResaults) {

    short OT = 0;

    do {

        cout << "Operation Type : [1] Add , [2] Sub , [3] Multiplication , [4] Div ,[5] Mix ?  >>  ";
        cin >> OT;

    } while (OT < 1 || OT > 5);

   
    return enOPtype(OT);

}


void QuestionLevel(enQuestionLevel QLevel,stFinalGameResault& FinalResaults, short& num1, short& num2)
{

    if (QLevel == enQuestionLevel::MixOfQlevel) {

        QLevel = enQuestionLevel(RandomNumber(1, 3));

    }

    switch (QLevel)
    {

    case enQuestionLevel::Easy:
        FinalResaults.QuestionLevel = "Easy";
        num1 = RandomNumber(1, 10);
        num2 = RandomNumber(1, 10);
        break;

    case enQuestionLevel::Med:
        FinalResaults.QuestionLevel = "Med";
        num1 = RandomNumber(1, 50);
        num2 = RandomNumber(1, 50);
        break;

    case enQuestionLevel::Hard:
        FinalResaults.QuestionLevel = "Hard";
        num1 = RandomNumber(50, 99);
        num2 = RandomNumber(50, 99);
        break;

    default:
        break;
    }

   

}


short OperationType(enOPtype OT, stFinalGameResault& FinalResaults, short Num1, short Num2) {

    if (OT == enOPtype::MixOfOT) {

        OT = enOPtype(RandomNumber(1, 4));

    }

    switch (OT)
    {

    case enOPtype::Add:
        FinalResaults.Optype = "+";
        FinalResaults.RightAnswer = Num1 + Num2;
        return Num1 + Num2;

    case enOPtype::Sub:
        FinalResaults.Optype = '-';
        FinalResaults.RightAnswer = Num1 - Num2;
        return Num1 - Num2;

    case enOPtype::Multplication:
        FinalResaults.Optype = '*';
        FinalResaults.RightAnswer = Num1 * Num2;
        return Num1 * Num2;

    case enOPtype::Div:
        FinalResaults.Optype = '/';
       // return Num1 / Num2;
        if (Num2 == 0) {
            cout << "not available"; 
            return 0; 
        }
        else {

            FinalResaults.RightAnswer = Num1 / Num2;
            return Num1 / Num2;
        }

    default:
        return Num1 + Num2;
        break;
    }



}

short Question(stFinalGameResault& FinalResaults,short Num1, short Num2) {

    short Answer = 0;

    cout << Num1 << "\n";
    cout << Num2 << "   " << FinalResaults.Optype << endl;
    cout << "____________________\n";
    cin >> Answer;

    return Answer;
}



void IsAnswerIsRightOrWrong(stFinalGameResault& FinalResaults,short Answer) {

    if (FinalResaults.RightAnswer==Answer) {

        system("color 2F");
        cout << "Right Answer :-)";
        FinalResaults.NumOfRightAnswer += 1;

    }
    else {

        system("color 4F");
        cout << "Wrong Answer :-(\n";
        cout << "The Right Answer is : " << FinalResaults.RightAnswer;
        FinalResaults.NumOfWrongAnswer += 1;

    }
}

//void QuestionResault() {
//
//    if (IsAnswerIsRightOrWrong) {
//
//        system("color 2F");
//        cout << "Right Answer :-)";
//
//    }
//    else {
//
//        system("color 4F");
//        cout << "Wrong Answer :-(\n";
//
//    }
//
//}


void ShowGameResault(stFinalGameResault& FinalResaults) {

    system("cls");

    if (FinalResaults.NumOfRightAnswer > FinalResaults.NumOfWrongAnswer) {

        system("color 2F");
        cout << "\n\n\t\t\t\t\t\t     PASS ! \n";

    }
    else {

        system("color 4F");
        cout << "\n\n\t\t\t\t\t\t     FAIL ! \n";

    }

   

    cout << "\t___________________________________________________________________________________________\n\n\n";
    cout << "\t\tNumber Of Questions     :" << FinalResaults.NumOfQuestion <<"\n\n";
    cout << "\t\tQuestions level         :" << FinalResaults.QuestionLevel <<"\n\n";
    cout << "\t\tOperation Type          :" << FinalResaults.Optype << "\n\n";
    cout << "\t\tNumber Of Right Answers :" << FinalResaults.NumOfRightAnswer << "\n\n";
    cout << "\t\tNumber Of Wrong Answers :" << FinalResaults.NumOfWrongAnswer << "\n\n";
    cout << "\n\t___________________________________________________________________________________________";
}

void Tab(stFinalGameResault& FinalResaults, short& NumOfQuestions, short& Num1, short& Num2)

{
    short RealAnswer = 0;
    short Answer = 0;
    enQuestionLevel Qlevel;
    enOPtype Optype;

    NumOfQuestions = HowManyQuestion(FinalResaults);

    Optype = EnterOPtype(FinalResaults);
    Qlevel = EnterQuestionLevel(FinalResaults);

    for (int i = 1; i <= NumOfQuestions; i++)
    {

        QuestionLevel(Qlevel, FinalResaults, Num1, Num2);
        RealAnswer = OperationType(Optype, FinalResaults, Num1, Num2);

        

        cout << "\nQuestion [" << i << " / " << NumOfQuestions << "]\n\n";

        Answer = Question(FinalResaults, Num1, Num2);

        cout << endl;
        IsAnswerIsRightOrWrong(FinalResaults, Answer);

    }

    ShowGameResault(FinalResaults);

}
    int main()
{

    srand((unsigned)time(NULL));

    short NumOfQuestions = 0 , Num1 = 0, Num2 = 0;

    stFinalGameResault FinalResaults;

    Tab( FinalResaults, NumOfQuestions, Num1, Num2);
    cout << "\n\n";


    return 0;

}