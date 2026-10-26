
void FUN_00429710(void)

{
  LPCWSTR in_EAX;
  LPSTR pCVar1;
  int iVar2;
  LPSTR in_ECX;
  uint cbMultiByte;
  
  if (*(int *)(in_EAX + 8) != 0) {
    if (7 < *(uint *)(in_EAX + 10)) {
      in_EAX = *(LPCWSTR *)in_EAX;
    }
    in_ECX[0x10] = '\0';
    in_ECX[0x11] = '\0';
    in_ECX[0x12] = '\0';
    in_ECX[0x13] = '\0';
    pCVar1 = in_ECX;
    if (0xf < *(uint *)(in_ECX + 0x14)) {
      pCVar1 = *(LPSTR *)in_ECX;
    }
    *pCVar1 = '\0';
    iVar2 = WideCharToMultiByte(0xfde9,0,in_EAX,-1,(LPSTR)0x0,0,(LPCSTR)0x0,(LPBOOL)0x0);
    if (iVar2 != 0) {
      cbMultiByte = iVar2 - 1;
      if (*(uint *)(in_ECX + 0x10) < cbMultiByte) {
        FUN_00429630(cbMultiByte - *(uint *)(in_ECX + 0x10),0);
      }
      else {
        FUN_00402c80(cbMultiByte,0xffffffff);
      }
      if (0xf < *(uint *)(in_ECX + 0x14)) {
        in_ECX = *(LPSTR *)in_ECX;
      }
      WideCharToMultiByte(0xfde9,0,in_EAX,-1,in_ECX,cbMultiByte,(LPCSTR)0x0,(LPBOOL)0x0);
    }
    return;
  }
  FUN_00402a70(&DAT_00bf2375,0);
  return;
}

