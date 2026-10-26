
void FUN_00806fc0(SOCKET *param_1,undefined4 param_2)

{
  SOCKET s;
  
  if (DAT_00fba858 == 0) {
    if (DAT_00fba85c == 0) {
      FUN_0049b000();
    }
    else {
      FUN_0049af60();
    }
  }
  EnterCriticalSection(*(LPCRITICAL_SECTION *)(DAT_00fba858 + 0x34));
  s = *param_1;
  if (((param_1[0x282a] == 0) && (s != 0)) && (s != 0xffffffff)) {
    if ((char)param_2 == '\0') {
      param_2 = 1;
      setsockopt(s,0xffff,0x80,(char *)&param_2,4);
    }
    shutdown(s,2);
    closesocket(s);
    FUN_0049b070(param_1);
    FUN_00805a80(param_1);
  }
  if (DAT_00fba858 == 0) {
    if (DAT_00fba85c != 0) {
      FUN_0049af60();
      LeaveCriticalSection(*(LPCRITICAL_SECTION *)(DAT_00fba858 + 0x34));
      return;
    }
    FUN_0049b000();
  }
  LeaveCriticalSection(*(LPCRITICAL_SECTION *)(DAT_00fba858 + 0x34));
  return;
}

