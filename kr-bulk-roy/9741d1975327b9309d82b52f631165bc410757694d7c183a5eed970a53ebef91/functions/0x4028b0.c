
void FUN_004028b0(LPCSTR param_1)

{
  int iVar1;
  LPWSTR **lpWideCharStr;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 extraout_EDX_01;
  undefined4 extraout_EDX_02;
  undefined4 uVar2;
  undefined2 *unaff_ESI;
  undefined4 uVar3;
  LPWSTR *local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00916868;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  uVar3 = 0;
  if (*(int *)(param_1 + 0x10) == 0) {
    *(undefined4 *)(unaff_ESI + 10) = 7;
    *(undefined4 *)(unaff_ESI + 8) = 0;
    *unaff_ESI = 0;
    FUN_00402160(&DAT_00bed1fc,0);
    uVar2 = extraout_EDX;
  }
  else {
    if (0xf < *(uint *)(param_1 + 0x14)) {
      param_1 = *(LPCSTR *)param_1;
    }
    iVar1 = MultiByteToWideChar(0xfde9,0,param_1,-1,(LPWSTR)0x0,0);
    if (iVar1 == 0) {
      *(undefined4 *)(unaff_ESI + 10) = 7;
      *(undefined4 *)(unaff_ESI + 8) = 0;
      *unaff_ESI = 0;
      FUN_00402160(&DAT_00bed1fc,0);
      uVar2 = extraout_EDX_00;
    }
    else {
      local_20 = 0;
      local_1c = 7;
      local_30[0] = (LPWSTR *)((uint)local_30[0] & 0xffff0000);
      FUN_00402340(iVar1 + -1,0x20);
      local_8 = 0;
      lpWideCharStr = (LPWSTR **)local_30[0];
      if (local_1c < 8) {
        lpWideCharStr = local_30;
      }
      MultiByteToWideChar(0xfde9,0,param_1,-1,(LPWSTR)lpWideCharStr,iVar1 + -1);
      *(undefined4 *)(unaff_ESI + 10) = 7;
      *(undefined4 *)(unaff_ESI + 8) = 0;
      *unaff_ESI = 0;
      FUN_00402800(local_30);
      uVar2 = extraout_EDX_01;
      if (7 < local_1c) {
        FUN_0089120c(local_30[0]);
        uVar2 = extraout_EDX_02;
      }
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc,uVar2,uVar3);
  return;
}

