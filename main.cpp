#include <iostream>
#include <string>
#include <vector>

class solution
{
  public:
    std::string numberToWords(int num) {
        std::vector<std::pair<int, std::string>> triples;
        int count = 0;
        while (num > 0) {
            std::string unit;
            switch(count) {
              case 1:
                unit = "Thousand";
                break;
              case 2:
                unit = "Million";
                break;
              case 3:
                unit = "Billion";
                break;
              default:
                unit = "";
                break;
            }
            triples.push_back(std::make_pair(num%1000, unit));
            num /= 1000;
            count++;
        }

        std::string numStr;
        for (auto it = triples.rbegin(); it != triples.rend(); ++it) {
            numStr.append(tripleToWords(*it));
            numStr.append(" ");
        }

        return numStr;
    }

  private:
    std::string tripleToWords(const std::pair<int, std::string> & pr) {
        std::string result;
        if (pr.first == 0)
            result = "";
        else {
            result = toWords(pr.first);
            if (!pr.second.empty()) {
                result.append(" ");
                result.append(pr.second);
            }
        }
        return result;
    }

    std::string toWords(int threeDigitNum) {
        int hundred = threeDigitNum/100;
        int rest = threeDigitNum%100;

        std::string numStr;
        if (hundred > 0) {
            numStr.append(digitToWord(hundred));
            numStr.append(" Hundred ");
            if (rest > 0)
                numStr.append("and ");
            else
                return numStr;
        }
        
        if (rest < 10)
            numStr.append(digitToWord(rest));
        else if (rest >= 10 && rest < 20)
            numStr.append(teenToWord(rest));
        else {
            int tens = rest/10;
            int ones = rest%10;
            if (tens > 0) {
                numStr.append(tenthToWord(tens));
                if (ones > 0) {
                    numStr.append(" ");
                    numStr.append(digitToWord(ones));
                }
            }
            else
                if (ones > 0)
                    numStr.append(digitToWord(ones));
        }
        
        return numStr;
    }

    std::string digitToWord(int n) {
        switch(n) {
          case 1:
            return "one";
          case 2:
            return "two";
          case 3:
            return "three";
          case 4:
            return "four";
          case 5:
            return "five";
          case 6:
            return "six";
          case 7:
            return "seven";
          case 8:
            return "eight";
          case 9:
            return "nine";
        }
    }

    std::string teenToWord(int n) {
        switch(n) {
          case 10:
            return "ten";
          case 11:
            return "eleven";
          case 12:
            return "tweleve";
          case 13:
            return "thirteen";
          case 14:
            return "fourteen";
          case 15:
            return "fifteen";
          case 16:
            return "sixteen";
          case 17:
            return "seventeen";
          case 18:
            return "eighteen";
          case 19:
            return "nineteen";
        }
    }

    std::string tenthToWord(int n) {
        switch(n) {
          case 2:
            return "twenty";
          case 3:
            return "thirty";
          case 4:
            return "fourty";
          case 5:
            return "fifty";
          case 6:
            return "sixty";
          case 7:
            return "seventy";
          case 8:
            return "eighty";
          case 9:
            return "ninety";
        }
    }
};

int main()
{
    int num = 1234567;

    solution soln;
    std::string numStr = soln.numberToWords(num);

    std::cout << num << " --> " << numStr << std::endl;
}
