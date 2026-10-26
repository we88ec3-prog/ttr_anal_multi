
int FUN_00440130(LPCSTR param_1)

{
  LPWSTR in_EAX;
  LPCSTR lpMultiByteStr;
  int iVar1;
  uint cchWideChar;
  
  if (*(int *)(param_1 + 0x10) == 0) {
    FUN_00402160(&DAT_00bed1fc,0);
    return 0;
  }
  lpMultiByteStr = param_1;
  if (0xf < *(uint *)(param_1 + 0x14)) {
    lpMultiByteStr = *(LPCSTR *)param_1;
  }
  iVar1 = MultiByteToWideChar(0xfde9,0,lpMultiByteStr,-1,(LPWSTR)0x0,0);
  if (iVar1 != 0) {
    cchWideChar = iVar1 - 1;
    if (*(uint *)(in_EAX + 8) < cchWideChar) {
      FUN_00440010(cchWideChar - *(uint *)(in_EAX + 8),0);
    }
    else {
      FUN_00402400(cchWideChar,0xffffffff);
    }
    if (7 < *(uint *)(in_EAX + 10)) {
      in_EAX = *(LPWSTR *)in_EAX;
    }
    if (0xf < *(uint *)(param_1 + 0x14)) {
      param_1 = *(LPCSTR *)param_1;
    }
    iVar1 = MultiByteToWideChar(0xfde9,0,param_1,-1,in_EAX,cchWideChar);
    return iVar1;
  }
  FUN_00402160(&DAT_00bed1fc,0);
  return 0;
}

