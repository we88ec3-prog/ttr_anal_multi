
int FUN_004f9cd0(LPCWSTR param_1)

{
  LPSTR in_EAX;
  LPCWSTR lpWideCharStr;
  int iVar1;
  uint cbMultiByte;
  
  if (*(int *)(param_1 + 8) == 0) {
    FUN_00402a70(&DAT_00bf2375,0);
    return 0;
  }
  lpWideCharStr = param_1;
  if (7 < *(uint *)(param_1 + 10)) {
    lpWideCharStr = *(LPCWSTR *)param_1;
  }
  iVar1 = WideCharToMultiByte(0,0,lpWideCharStr,-1,(LPSTR)0x0,0,(LPCSTR)0x0,(LPBOOL)0x0);
  if (iVar1 != 0) {
    cbMultiByte = iVar1 - 1;
    if (*(uint *)(in_EAX + 0x10) < cbMultiByte) {
      FUN_00429630(cbMultiByte - *(uint *)(in_EAX + 0x10),0);
    }
    else {
      FUN_00402c80(cbMultiByte,0xffffffff);
    }
    if (0xf < *(uint *)(in_EAX + 0x14)) {
      in_EAX = *(LPSTR *)in_EAX;
    }
    if (7 < *(uint *)(param_1 + 10)) {
      param_1 = *(LPCWSTR *)param_1;
    }
    iVar1 = WideCharToMultiByte(0,0,param_1,-1,in_EAX,cbMultiByte,(LPCSTR)0x0,(LPBOOL)0x0);
    return iVar1;
  }
  FUN_00402a70(&DAT_00bf2375,0);
  return 0;
}

