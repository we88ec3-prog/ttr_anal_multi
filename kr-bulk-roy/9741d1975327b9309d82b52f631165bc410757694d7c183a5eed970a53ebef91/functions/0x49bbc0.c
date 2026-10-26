
void FUN_0049bbc0(int *param_1,char *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  uint uVar4;
  wchar_t ****_Str;
  wchar_t *pwVar5;
  int iVar6;
  undefined4 *puVar7;
  int local_54;
  int local_50;
  int local_4c;
  undefined4 *local_48;
  undefined4 *local_44;
  undefined4 local_40;
  wchar_t ***local_38 [5];
  uint local_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0092b21a;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&local_54;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xffffffa0;
  ExceptionList = &local_14;
  _vsprintf_s(&DAT_00fe6590,0x400,param_2,&stack0x0000000c);
  FUN_0049c3a0(uVar4);
  local_48 = (undefined4 *)0x0;
  local_44 = (undefined4 *)0x0;
  local_40 = 0;
  local_c = 1;
  _Str = (wchar_t ****)local_38[0];
  if (local_24 < 8) {
    _Str = local_38;
  }
  pwVar5 = _wcschr((wchar_t *)_Str,L'\n');
  if (pwVar5 == (wchar_t *)0x0) {
    FUN_0049c120();
  }
  else {
    FUN_0049c210(local_38,&local_48);
  }
  if ((DAT_00fb7bc8 & 1) == 0) {
    DAT_00fb7bc8 = DAT_00fb7bc8 | 1;
    local_c._0_1_ = 2;
    FUN_00734ef0();
    _atexit((_func_4879 *)&LAB_00bcd4f0);
    local_c = CONCAT31(local_c._1_3_,1);
  }
  iVar6 = DAT_00fb7b90;
  iVar1 = *param_1;
  local_50 = DAT_00fb7b90;
  local_54 = iVar1;
  FUN_00736180(&local_54);
  if ((local_4c == DAT_00fb7b80) || (DAT_00fb7b90 = iVar1, local_4c == -0x10)) {
    DAT_00fb7b90 = DAT_00fb7b8c;
  }
  iVar1 = ((int)local_44 - (int)local_48) / 0x1c;
  if (iVar1 != 0) {
    do {
      local_54 = iVar1;
      if ((DAT_00fb7bc8 & 1) == 0) {
        DAT_00fb7bc8 = DAT_00fb7bc8 | 1;
        local_c._0_1_ = 3;
        FUN_00734ef0();
        _atexit((_func_4879 *)&LAB_00bcd4f0);
        local_c = CONCAT31(local_c._1_3_,1);
      }
      FUN_00735ba0(0,param_1[1],0x100,0xffffffff,0xff000000);
      param_1[1] = param_1[1] + 0xc;
      iVar1 = local_54 + -1;
    } while (local_54 + -1 != 0);
    local_54 = 0;
    iVar6 = local_50;
  }
  puVar7 = local_48;
  if ((DAT_00fb7bc8 & 1) == 0) {
    DAT_00fb7bc8 = DAT_00fb7bc8 | 1;
    local_c = CONCAT31(local_c._1_3_,4);
    FUN_00734ef0();
    _atexit((_func_4879 *)&LAB_00bcd4f0);
  }
  local_50 = iVar6;
  FUN_00736180(&local_50);
  puVar3 = local_44;
  if ((local_4c == DAT_00fb7b80) || (DAT_00fb7b90 = iVar6, local_4c == -0x10)) {
    DAT_00fb7b90 = DAT_00fb7b8c;
  }
  puVar2 = local_48;
  if (puVar7 != (undefined4 *)0x0) {
    while (puVar2 != puVar3) {
      if (7 < (uint)puVar7[5]) {
        FUN_0089120c(*puVar7);
      }
      puVar7[5] = 7;
      puVar7[4] = 0;
      *(undefined2 *)puVar7 = 0;
      puVar7 = puVar7 + 7;
      puVar2 = puVar7;
    }
    FUN_0089120c(local_48);
  }
  if (7 < local_24) {
    FUN_0089120c(local_38[0]);
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&local_54);
  return;
}

