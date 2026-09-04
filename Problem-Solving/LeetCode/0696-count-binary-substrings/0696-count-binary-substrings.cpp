/*
    1. 0과 1로 이루어진 문자열이 주어짐
    2. 0과 1이 각각 연속적으로 이루어지면서, 0과 1의 개수가 같은 substring이 존재. 그 substring들의 개수를 구하여라.
    3. 여러 번 발생해도 카운트된다.

    ex1) 00110011
    -> 0011, 01, 1100, 10, 0011, 01 -> 6개
    ex2) 10101
    -> 10, 01, 10, 01 -> 4개

    아이디어)
    1. 연속된 0또는 1이 대칭의 구조를 이루고 있다.
    2. 연속된 각각의 길이가 짧은 문자열에서 연속된 substring이 등장하게 된다.
        -> 0001111 -> 000111 로부터 추출할 수 있는 substring이 존재 -> 000111, 0011, 01
    3. 결과적으로 짧은 쪽의 개수만큼 substring을 추출할 수 있음을 의미한다.

    해결 방향)
    1. 빈 배열을 생성. 이 배열은 0->1, 1->0으로 토글되는 위치. 그리고 마지막 인덱스+1.
    2. 예를들어, 001100 에서 [0, 2, 4, 6]
    3. 0011 에서 (0, 2, 4)에서 연속된 0과 1의 개수를 구한다. 각각 2, 2. 둘의 Min 값이 2. -> 0011, 01 -> 2개
    4. (2, 4, 6) 마찬가지로 1100, 10 이 등장. 2개
    5. 총 2+2=4

    다른 예시)
    1. 0011101
    2. [0, 2, 5, 6, 7]
    3. (2, 3)의 min 값 -> 2... 0011, 01
    4. (3, 1)의 min -> 1... 10
    5. (1, 1)의 min -> 1... 01
    6. 모두 더하면 2+1+1=4
*/

class Solution {
public:
    int countBinarySubstrings(string s) {
        // 1. 빈 배열을 생성. 이 배열은 0->1, 1->0으로 토글되는 위치. 그리고 마지막 인덱스+1
        vector<int> toggleIdxs(1);
        toggleIdxs[0] = 0;
        char curCh = s[0];
        for(int i=1;i<s.length();i++) {
            char ch = s[i];
            if(ch == curCh) continue;
            toggleIdxs.push_back(i);
            curCh = ch;
        }
        toggleIdxs.push_back(s.length());

        // 1. 0011101
        // 2. [0, 2, 5, 6, 7]
        int sum = 0;
        for(int i=1;i<toggleIdxs.size()-1;i++) {
            sum += min(toggleIdxs[i]-toggleIdxs[i-1], toggleIdxs[i+1]-toggleIdxs[i]);
        }

        return sum;
    }
};