
void FUN_007b6770(void *param_1)

{
  if ((DAT_00d63c70 == (HANDLE)0xffffffff) && (DAT_00fba834 == 0)) {
    DAT_00d63c70 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
    DAT_00fba834 = 1;
    __beginthread(FUN_007b65b0,0,param_1);
    return;
  }
  MessageBoxW((HWND)0x0,L"애니메이션 로드 스레드를 중복 실행하려고 했습니다.",
              L"Error",0x30);
  return;
}

