
void FUN_0047f540(LPCWSTR param_1)

{
  char cVar1;
  UINT CodePage;
  int cbMultiByte;
  LPSTR lpMultiByteStr;
  LPSTR pCVar2;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 extraout_EDX_01;
  undefined4 extraout_EDX_02;
  undefined4 uVar3;
  undefined1 *unaff_EDI;
  undefined4 uVar4;
  uint local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00917838;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  uVar4 = 0;
  if (param_1 == (LPCWSTR)0x0) {
    *(undefined4 *)(unaff_EDI + 0x14) = 0xf;
    *(undefined4 *)(unaff_EDI + 0x10) = 0;
    *unaff_EDI = 0;
    FUN_00402a70(&DAT_00bf2375,0);
    uVar3 = extraout_EDX;
  }
  else {
    cbMultiByte = WideCharToMultiByte(DAT_00fba808,0,param_1,-1,(LPSTR)0x0,0,(LPCSTR)0x0,(LPBOOL)0x0
                                     );
    if (cbMultiByte == 0) {
      *(undefined4 *)(unaff_EDI + 0x14) = 0xf;
      *(undefined4 *)(unaff_EDI + 0x10) = 0;
      *unaff_EDI = 0;
      FUN_00402a70(&DAT_00bf2375,0);
      uVar3 = extraout_EDX_00;
    }
    else {
      lpMultiByteStr = (LPSTR)FUN_0087dc3d(cbMultiByte);
      CodePage = DAT_00fba808;
      *lpMultiByteStr = '\0';
      WideCharToMultiByte(CodePage,0,param_1,-1,lpMultiByteStr,cbMultiByte,(LPCSTR)0x0,(LPBOOL)0x0);
      local_1c = 0xf;
      local_20 = 0;
      local_30[0] = local_30[0] & 0xffffff00;
      pCVar2 = lpMultiByteStr;
      do {
        cVar1 = *pCVar2;
        pCVar2 = pCVar2 + 1;
      } while (cVar1 != '\0');
      FUN_00402a70(lpMultiByteStr,(int)pCVar2 - (int)(lpMultiByteStr + 1));
      local_8 = 0;
      FUN_00891d3d(lpMultiByteStr);
      *(undefined4 *)(unaff_EDI + 0x14) = 0xf;
      *(undefined4 *)(unaff_EDI + 0x10) = 0;
      *unaff_EDI = 0;
      FUN_00402bb0(local_30);
      uVar3 = extraout_EDX_01;
      if (0xf < local_1c) {
        FUN_0089120c(local_30[0]);
        uVar3 = extraout_EDX_02;
      }
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc,uVar3,uVar4);
  return;
}

