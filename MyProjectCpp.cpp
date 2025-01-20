// MyProjectCpp.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <cstdio>

int main()
{
    std::cout << "Hello World!\n" << std::endl;

    std::cout << 10 << std::endl;
    std::cout << 10u << std::endl;
    std::cout << 10.5f << std::endl;
    std::cout << 10.5 << std::endl;
    std::cout << 3 + 4 << std::endl;
    // std 네임스페이스에 속한 cout 객체는 iostream 클래스의 인스턴스(혹은 객체) 입니다.

    //std : 네임스페이스
    //:: : '범위 지정 연산자' , '스코프 설정 연산자'
    //cout : 콘솔 출력을 담당하는 객체
    // << : 연산자 함수

    // => std 네임스페이스에 속한 cout다

    std::string strData = "Test String";
    std::cout << "Sample String" << std::endl;
    std::cout << strData << std::endl;

    strData = "New String";
    std::cout << "저는" << 20 << "살" << "입니다." << std::endl;

    int age;
    std::cout << "나이를 입력하세요." << std::endl;
    std::cin >> age;

    char szJob[32];
    std::cout << "직업을 입력하세요." << std::endl;
    std::cin >> szJob;

    std::string strName;
    std::cout << "이름을 입력하세요." << std::endl;
    std::cin >> strName;

    std::cout << "당신의 이름은 " << strName << "이고 " << "나이는 " << age << "살이며," << "직업은 " << szJob << "입니다." << std::endl;

    //직업은 한글로 16자 이상 입력받을 수 없음
    // 이름은 그런 제한 없음. 

    // 자료형 새로 생김
    // long long , char16_t , char32_t , auto , decltype(expr)
    // char16 과 char32 는 유니코드 처리를 위한 자료형
    // auto , decltype 은 완전히 새로운 자료형

    
    // 변수 선언
    int a(10);
    // int 자료형 인스턴스 - 10은 a 의 초깃값
    
    int b(a);
    // 이런 식으로도 선언이 된다.

    std::cout << a << "/" << b << std::endl;


    // auto 변경 사항 및 사용법 : 초깃값의 형식에 맞춰 선언하는 인스턴스의 형식이 자동으로 결정된다.

    int t = 10;
    int r(t);
    auto c(r);

    std::cout << t + r + c << std::endl;

    return 0;
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
