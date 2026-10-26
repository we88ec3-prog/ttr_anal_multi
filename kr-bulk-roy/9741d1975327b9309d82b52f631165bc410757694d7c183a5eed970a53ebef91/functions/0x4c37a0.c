
void FUN_004c37a0(int param_1)

{
  wchar_t *_Src;
  char cVar1;
  byte bVar2;
  undefined1 uVar3;
  wchar_t wVar4;
  uint uVar5;
  int iVar6;
  undefined4 uVar7;
  wchar_t *pwVar8;
  uint local_44c [4];
  undefined4 local_43c;
  uint local_438;
  uint local_430 [4];
  undefined4 local_420;
  uint local_41c;
  CHAR local_414 [1024];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0094073c;
  local_10 = ExceptionList;
  uVar5 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar5;
  if (*(LPCWSTR)(param_1 + 0x20) != L'\0') {
    WideCharToMultiByte(DAT_00fba808,0,(LPCWSTR)(param_1 + 0x20),-1,local_414,0x400,(LPCSTR)0x0,
                        (LPBOOL)0x0);
    _strncpy_s(&DAT_00fba700,0x97,local_414,0x32);
  }
  cVar1 = *(char *)(param_1 + 0x16);
  if (cVar1 == '\x05') {
    iVar6 = FUN_00891268(0x34);
    uVar7 = 0;
    local_8 = 0;
    if (iVar6 != 0) {
      local_44c[0] = local_44c[0] & 0xffff0000;
      local_438 = 7;
      local_43c = 0;
      FUN_00402160(&DAT_00bed1fc,0);
      local_8 = CONCAT31(local_8._1_3_,1);
      uVar7 = FUN_00753f00(iVar6,local_44c);
    }
    local_8 = 2;
    FUN_0058aa50(uVar7);
    local_8 = 0xffffffff;
    if (iVar6 != 0) {
      if (7 < local_438) {
        FUN_0089120c(local_44c[0]);
      }
      local_438 = 7;
      local_43c = 0;
      local_44c[0] = local_44c[0] & 0xffff0000;
    }
    if ((DAT_00fbacd0 & 1) == 0) {
      DAT_00fbacd0 = DAT_00fbacd0 | 1;
      local_8 = 3;
      DAT_00fbacd4 = (int *)0x0;
      DAT_00fbacd4 = (int *)FUN_006d6300();
      _atexit((_func_4879 *)&LAB_00bcd670);
      local_8 = 0xffffffff;
    }
    if (DAT_00fbacd4 != (int *)0x0) {
      (**(code **)(*DAT_00fbacd4 + 0x14))(0);
    }
    iVar6 = DAT_00fb1318;
    (**(code **)(*DAT_00fba854 + 0x20))(1,1);
  }
  else {
    if (cVar1 == '\0') {
      _Src = (wchar_t *)(param_1 + 2);
      pwVar8 = _Src;
      do {
        wVar4 = *pwVar8;
        pwVar8 = pwVar8 + 1;
      } while (wVar4 != L'\0');
      if ((int)pwVar8 - (param_1 + 4) >> 1 != 0) {
        uVar7 = *(undefined4 *)(param_1 + 0x18);
        iVar6 = FUN_00404ba0();
        *(undefined4 *)(iVar6 + 0x67e0) = uVar7;
        iVar6 = FUN_00404ba0();
        if (_Src != (wchar_t *)0x0) {
          _wcsncpy_s((wchar_t *)(iVar6 + 0x67e4),0xb,_Src,10);
        }
        bVar2 = *(byte *)(param_1 + 0x17);
        iVar6 = FUN_00404ba0();
        *(uint *)(iVar6 + 0x68b4) = (uint)bVar2;
        uVar3 = *(undefined1 *)(param_1 + 0x90);
        iVar6 = FUN_00404ba0();
        *(undefined1 *)(iVar6 + 0x68b0) = uVar3;
        uVar3 = *(undefined1 *)(param_1 + 0x86);
        uVar7 = *(undefined4 *)(param_1 + 0x8c);
        iVar6 = FUN_00404ba0();
        *(undefined1 *)(iVar6 + 0x6898) = uVar3;
        _strcpy_s((char *)(iVar6 + 0x6899),5,(char *)(param_1 + 0x87));
        *(undefined4 *)(iVar6 + 0x68a0) = uVar7;
        FUN_004c3080(*(undefined4 *)(param_1 + 0x1c));
        if (*(char *)(param_1 + 0x90) == '\0') {
          FUN_004c3170();
        }
        goto LAB_004c3b64;
      }
    }
    FUN_006edb60("login failed: %d\n",(int)cVar1,uVar5);
    iVar6 = FUN_00891268(0x34);
    uVar7 = 0;
    local_8 = 4;
    if (iVar6 != 0) {
      local_41c = 7;
      local_420 = 0;
      local_430[0] = local_430[0] & 0xffff0000;
      FUN_00402160(&DAT_00bed1fc,0);
      local_8 = CONCAT31(local_8._1_3_,5);
      uVar7 = FUN_00753f00(iVar6,local_430);
    }
    local_8 = 6;
    FUN_0058aa50(uVar7);
    local_8 = 0xffffffff;
    if (iVar6 != 0) {
      if (7 < local_41c) {
        FUN_0089120c(local_430[0]);
      }
      local_41c = 7;
      local_420 = 0;
      local_430[0] = local_430[0] & 0xffff0000;
    }
    if ((DAT_00fbacd0 & 1) == 0) {
      DAT_00fbacd0 = DAT_00fbacd0 | 1;
      local_8 = 7;
      DAT_00fbacd4 = (int *)0x0;
      DAT_00fbacd4 = (int *)FUN_006d6300();
      _atexit((_func_4879 *)&LAB_00bcd670);
      local_8 = 0xffffffff;
    }
    if (DAT_00fbacd4 != (int *)0x0) {
      (**(code **)(*DAT_00fbacd4 + 0x14))(0);
    }
    iVar6 = DAT_00fb1318;
    (**(code **)(*DAT_00fba854 + 0x20))(1,1);
  }
  *(undefined4 *)(iVar6 + 0xbf60) = 0;
LAB_004c3b64:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

