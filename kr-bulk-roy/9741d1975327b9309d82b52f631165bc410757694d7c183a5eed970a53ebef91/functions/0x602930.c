
void FUN_00602930(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int in_ECX;
  int in_EDX;
  undefined4 *puVar4;
  int local_64;
  undefined4 local_60;
  int local_5c;
  int local_58;
  undefined1 local_54 [56];
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093e756;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&local_64;
  ExceptionList = &local_14;
  local_64 = in_EDX;
  local_5c = in_ECX;
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590(DAT_00d61f20 ^ (uint)&stack0xffffff90);
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  local_c = 0xffffffff;
  if ((param_1 == 1) && (iVar2 = DAT_00f94300 + 0x16f8, iVar2 != 0)) {
    if (param_2 - 1U < 100) {
      iVar1 = param_2 * 0x20 + iVar2;
      if (((*(int *)(param_2 * 0x20 + 0xc + iVar2) != 0) && (*(int *)(iVar1 + 8) != 0)) &&
         (iVar1 != 0)) {
        if ((DAT_00f8d9a4 & 1) == 0) {
          DAT_00f8d9a4 = DAT_00f8d9a4 | 1;
          local_c = 1;
          FUN_0051c120();
          _atexit((_func_4879 *)&LAB_00bccc90);
        }
        local_c = 0xffffffff;
        local_60 = *(undefined4 *)(iVar1 + 0xc);
        FUN_008438c0();
        if ((local_58 != DAT_00f8d91c) && (iVar2 = *(int *)(local_58 + 0x10), iVar2 != 0)) {
          FUN_00759ac0();
          FUN_007597b0();
          FUN_005854b0();
          FUN_00585330();
          FUN_00759ac0();
          FUN_007599b0((longlong)*(int *)(iVar2 + 0x34) * (longlong)local_64);
          puVar3 = (undefined4 *)FUN_00891268();
          puVar4 = (undefined4 *)0x0;
          if (puVar3 != (undefined4 *)0x0) {
            puVar3[1] = 0xffffffff;
            puVar3[2] = 0xffffffff;
            puVar3[3] = 0;
            puVar3[4] = 0xf43ae;
            *puVar3 = FoxUI::FXUIEventI3::vftable;
            puVar3[5] = 1;
            puVar3[6] = param_2;
            puVar3[7] = local_64;
            puVar4 = puVar3;
          }
          FUN_005854b0();
          FUN_00585330();
          FUN_007572f0();
          local_c = 2;
          FUN_00407330(0xcf,in_ECX + 0x114,local_54,puVar4,local_5c);
          local_c = 0xffffffff;
          FUN_00757640();
        }
      }
    }
    else {
      FUN_006edb60();
    }
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&local_64);
  return;
}

