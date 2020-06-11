#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

class BigInt {
    private:
        string number;
    public:
        BigInt() {
            number = "";
        }

        BigInt(const char arr[]) {
            number = arr;
        }

        BigInt(string s) {
            number = s;
        } 

        BigInt(int i) {
            number = to_string(i);
        }


        friend istream& operator>> (istream& stream, BigInt& obj);
        friend ostream& operator<< (ostream& stream, BigInt& obj);

        BigInt operator+ (BigInt& other) {
            BigInt revResult;
            int carry = 0, sum = 0, temp;

            string::reverse_iterator iterFirst = this->number.rbegin();
            string::reverse_iterator iterSecond = other.number.rbegin();
            
            for(; iterFirst != this->number.rend() && iterSecond != other.number.rend(); iterFirst++, iterSecond++) {
                temp = *iterFirst + *iterSecond - 96 + carry;
                sum = temp % 10;
                carry = temp / 10;
                revResult.number.push_back(sum + 48);
            }

            if(iterFirst != this->number.rend()) {
                while(iterFirst != this->number.rend()) {
                    temp = *iterFirst - 48 + carry;
                    sum = temp % 10;
                    carry = temp / 10;
                    revResult.number.push_back(sum + 48);
                    iterFirst++;
                }
            }
            else {
                while(iterSecond != other.number.rend()) {
                    temp = *iterSecond - 48 + carry;
                    sum = temp % 10;
                    carry = temp / 10;
                    revResult.number.push_back(sum + 48);
                    iterSecond++;
                }
            }
    
            if(carry != 0) {
                revResult.number.push_back(carry + 48);
            }

            std::reverse(revResult.number.begin(), revResult.number.end());
            return revResult;
        }

        BigInt operator+ (int i) {
            BigInt temp = i;
            return *this + temp;
        }

        BigInt operator* (BigInt& other) {
            BigInt temp, partialSum;
            int n, count = 0, carry, mul;
            partialSum.number.insert(partialSum.number.begin(), this->number.size(), '0');
            
            string::reverse_iterator iter1 = other.number.rbegin();

            for(; iter1 != other.number.rend(); iter1++) {
                string::reverse_iterator iter2 = this->number.rbegin();
                temp.number = "";
                carry = 0;
                
                for(; iter2 != this->number.rend(); iter2++) {
                    n = (*iter2 - 48) * (*iter1 - 48) + carry;
                    mul = n % 10;
                    carry = n / 10;
                    temp.number.push_back(mul + 48);
                }

                if(carry != 0) {
                    temp.number.push_back(carry + 48);
                }

                std::reverse(temp.number.begin(), temp.number.end());
                temp.number.append(count, '0');
                partialSum = partialSum + temp;
                count += 1;
            }

            return partialSum;
        }

        BigInt operator* (int i) {
            BigInt temp = i;
            return *this * temp;
        }

        bool operator<= (BigInt& other) {
            if(this->number.size() == other.number.size()) {
                if(this->number <= other.number) {
                    return true;
                }
                return false;
            }
            if(this->number.size() < other.number.size()) {
                return true;
            }
            return false;
        }
};

istream& operator>> (istream& stream, BigInt& obj) {
    stream>>obj.number;
    return stream;
}

ostream& operator<< (ostream& stream, BigInt& obj) {
    stream<<obj.number;
    return stream;
}

int main() {
    int num;
    BigInt temp;
    cout<<"Enter a number: ";
    cin>>num;
    BigInt result = 1;

    for(int i = 1; i <= num; i++) {
        result = result * i;
    }

    cout<<"The factorial is: "<<endl;
    cout<<result;

    return 0;
}

/*
    Output:
    Enter a number: 1000
    The factorial is:
    402387260077093773543702433923003985719374864210714632543799910429938512398629020592044208
    486969404800479988610197196058631666872994808558901323829669944590997424504087073759918823
    627727188732519779505950995276120874975462497043601418278094646496291056393887437886487337
    119181045825783647849977012476632889835955735432513185323958463075557409114262417474349347
    553428646576611667797396668820291207379143853719588249808126867838374559731746136085379534
    524221586593201928090878297308431392844403281231558611036976801357304216168747609675871348
    312025478589320767169132448426236131412508780208000261683151027341827977704784635868170164
    365024153691398281264810213092761244896359928705114964975419909342221566832572080821333186
    116811553615836546984046708975602900950537616475847728421889679646244945160765353408198901
    385442487984959953319101723355556602139450399736280750137837615307127761926849034352625200
    015888535147331611702103968175921510907788019393178114194545257223865541461062892187960223
    838971476088506276862967146674697562911234082439208160153780889893964518263243671616762179
    168909779911903754031274622289988005195444414282012187361745992642956581746628302955570299
    024324153181617210465832036786906117260158783520751516284225540265170483304226143974286933
    061690897968482590125458327168226458066526769958652682272807075781391858178889652208164348
    344825993266043367660176999612831860788386150279465955131156552036093988180612138558600301
    435694527224206344631797460594682573103790084024432438465657245014402821885252470935190620
    929023136493273497565513958720559654228749774011413346962715422845862377387538230483865688
    976461927383814900140767310446640259899490222221765904339901886018566526485061799702356193
    897017860040811889729918311021171229845901641921068884387121855646124960798722908519296819
    372388642614839657382291123125024186649353143970137428531926649875337218940694281434118520
    158014123344828015051399694290153483077644569099073152433278288269864602789864321139083506
    217095002597389863554277196742822248757586765752344220207573630569498825087968928162753848
    863396909959826280956121450994871701244516461260379029309120889086942028510640182154399457
    156805941872748998094254742173582401063677404595741785160829230135358081840096996372524230
    560855903700624271243416909004153690105933983835777939410970027753472000000000000000000000
    000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
    000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
    000000000000000000000000000000000000000000000000
*/