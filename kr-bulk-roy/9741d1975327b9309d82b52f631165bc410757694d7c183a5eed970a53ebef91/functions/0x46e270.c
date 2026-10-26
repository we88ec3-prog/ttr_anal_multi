
void FUN_0046e270(LPCSTR param_1)

{
  WCHAR WVar1;
  UINT CodePage;
  uint cchWideChar;
  LPWSTR lpWideCharStr;
  LPWSTR pWVar2;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 extraout_EDX_01;
  undefined4 extraout_EDX_02;
  undefined4 uVar3;
  undefined2 *unaff_EDI;
  undefined4 uVar4;
  undefined4 local_30;
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092e238;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  uVar4 = 0;
  if (param_1 == (LPCSTR)0x0) {
    *(undefined4 *)(unaff_EDI + 10) = 7;
    *(undefined4 *)(unaff_EDI + 8) = 0;
    *unaff_EDI = 0;
    FUN_00402160(&DAT_00bed1fc,0);
    uVar3 = extraout_EDX;
  }
  else {
    cchWideChar = MultiByteToWideChar(DAT_00fba808,0,param_1,-1,(LPWSTR)0x0,0);
    if (cchWideChar == 0) {
      *(undefined4 *)(unaff_EDI + 10) = 7;
      *(undefined4 *)(unaff_EDI + 8) = 0;
      *unaff_EDI = 0;
      FUN_00402160(&DAT_00bed1fc,0);
      uVar3 = extraout_EDX_00;
    }
    else {
      lpWideCharStr =
           (LPWSTR)FUN_0087dc3d(-(uint)((int)((ulonglong)cchWideChar * 2 >> 0x20) != 0) |
                                (uint)((ulonglong)cchWideChar * 2));
      CodePage = DAT_00fba808;
      *lpWideCharStr = L'\0';
      MultiByteToWideChar(CodePage,0,param_1,-1,lpWideCharStr,cchWideChar);
      local_30 = (uint)local_30._2_2_ << 0x10;
      local_1c = 7;
      local_20 = 0;
      pWVar2 = lpWideCharStr;
      do {
        WVar1 = *pWVar2;
        pWVar2 = pWVar2 + 1;
      } while (WVar1 != L'\0');
      FUN_00402160(lpWideCharStr,(int)pWVar2 - (int)(lpWideCharStr + 1) >> 1);
      local_8 = 0;
      FUN_00891d3d(lpWideCharStr);
      *(undefined4 *)(unaff_EDI + 10) = 7;
      *(undefined4 *)(unaff_EDI + 8) = 0;
      *unaff_EDI = 0;
      FUN_00402800(&local_30);
      uVar3 = extraout_EDX_01;
      if (7 < local_1c) {
        FUN_0089120c(local_30);
        uVar3 = extraout_EDX_02;
      }
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc,uVar3,uVar4);
  return;
}

