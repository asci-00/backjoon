#include <string>
#include <vector>

using namespace std;

vector<string> words;
string word = "", invalid = "invalid";

int countAlph['z' - 'a'] = {0};

bool upper(char ch) { return ('A' <= ch && 'Z' >= ch); }

int checkType1(string sentence, int idx) { // 1번 규칙
    char alph = sentence[idx], prev = word[0], now;
    int i;

    printf("type 1 %d[%c] start\n", idx, alph);

    for(i = idx; countAlph[alph - 'a'] > 0 && i < sentence.length(); i++) {
        now = sentence[i];

        if(upper(now) == upper(prev)) return -1;
        if(!upper(now)) {
            if(alph != now) return -1;

            countAlph[alph - 'a'] --;
        } else word += now;
        prev = now;
    }

    if(countAlph[alph - 'a'] > 0 || i == sentence.length() || !upper(sentence[i])) return -1; // 만약 alph가 남았거나 i가 끝까지 순회하였다면 오류


    word += sentence[i]; // 아니라면 마지막 단어 삽입
    return i;
}

int checkType2(string sentence, int idx) { // 2번 규칙 ( + 1번 규칙을 감싼 2번 규칙 ) - 만약 처음에 두 대문자가 연속으로 나온다면 2번규칙만 적용
    char alph = sentence[idx], now = 0;
    int i;

    printf("type 2 %d[%c] start\n", idx, alph);

    if(idx + 2 > sentence.length() - 1) return -1;

    char temp = sentence[idx + 2];

    countAlph[alph - 'a'] --;

    if(!upper(temp) && temp != alph) { // 1번 규칙을 포함한 2번 규칙
        word = sentence[idx + 1];
        if(!upper(word[0])) return -1;

        i = checkType1(sentence, idx + 2);
        if(i < 0) return -1;

        if(i + 1 > sentence.length() - 1 || sentence[i + 1] != alph) return -1;
        countAlph[alph - 'a'] --;
        return i + 1;
    } else { // 2번 규칙
        for(i = idx + 1; countAlph[alph - 'a'] > 0 && i < sentence.length(); i++) {
            now = sentence[i];

            if(!upper(now)) {
                if(now != alph) return -1;
                countAlph[alph - 'a'] --;
                break; // break를 만나면 i는 sentence.length() 가 될 수 없음
            } else word += now;
        }
    }

    if(countAlph[alph - 'a'] > 0 || i == sentence.length() || word.length() == 0) return -1;
    return i;
}

// 내부적으로 사용하는 alph 사용 횟수가 남으면 안됨 - 모두 소진
// 마지막에 탐색한 곳의 index를 반환

string solution(string sentence) {
    string answer = "";
    char nowAlph;

    for(char ch: sentence) {
        if(ch == ' ') return invalid;
        if(!upper(ch)) countAlph[ch - 'a'] ++;
    }

    for(int idx = 0; idx < sentence.length(); idx++) {
        nowAlph = sentence[idx];

        if (upper(nowAlph)) word += sentence[idx];
        else {
            if(idx == sentence.length() - 1) return invalid;

            if(countAlph[nowAlph - 'a'] == 2) {
                if(word.length() > 0) words.push_back(word);
                word = "";

                idx = checkType2(sentence, idx);
            } else {
                if(word.length() == 0) return invalid;

                if(word.length() > 1) words.push_back(word.substr(0, word.length() - 1));
                word = word[word.length() - 1];

                idx = checkType1(sentence, idx);
            }

            if(idx < 0) return invalid;

            words.push_back(word);  // 작업된 word push
            word = "";
        }
    }

    if(word.length()) words.push_back(word);
    for(string w : words) answer += (w + " ");

    return answer.substr(0, answer.length() - 1);
}
