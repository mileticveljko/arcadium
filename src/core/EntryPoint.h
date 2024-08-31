#ifndef ENTRY_POINT_H__
#define ENTRY_POINT_H__

#include <Application.h>
#include <UserApplication.h>

extern ar::UserApplication* ar::CreateUserApplication();

int main()
{
    ar::Application::GetInstance()->SetUserApplication(ar::CreateUserApplication());
    ar::Application::GetInstance()->Run();
    delete ar::Application::GetInstance();

    return 0;
}

#endif