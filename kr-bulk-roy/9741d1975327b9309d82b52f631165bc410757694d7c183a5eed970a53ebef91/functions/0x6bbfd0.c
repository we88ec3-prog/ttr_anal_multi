
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006bbfd0(int param_1)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  uint uVar3;
  int in_ECX;
  uint uVar4;
  undefined1 *puVar5;
  undefined2 local_24;
  undefined2 local_22;
  undefined4 local_20;
  undefined4 local_1c;
  undefined1 local_18;
  undefined4 local_14;
  undefined4 uStack_10;
  undefined1 uStack_c;
  undefined1 local_b;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  if (*(int *)(param_1 + 0x10) == 0x387) {
    puVar2 = (undefined4 *)FUN_00891268(0x18);
    if (puVar2 != (undefined4 *)0x0) {
      puVar2[1] = 0xffffffff;
      puVar2[2] = 0xffffffff;
      puVar2[3] = 0;
      puVar2[4] = 0xf4350;
      *puVar2 = FoxUI::FXUIEventP1::vftable;
      puVar2[5] = in_ECX;
    }
    FUN_004072a0();
  }
  if (*(int *)(param_1 + 0x10) == 0x70a) {
    if (*(int *)(param_1 + 8) == *(int *)(*(int *)(in_ECX + 0x90) + 0x20)) {
      FUN_006bc7b0();
      __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
      return;
    }
    if (*(int *)(param_1 + 8) == *(int *)(*(int *)(in_ECX + 0xbc) + 0x20)) {
      FUN_006bc7f0();
      __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
      return;
    }
  }
  else if (*(int *)(param_1 + 0x10) == 0x578) {
    if (*(int *)(param_1 + 8) == *(int *)(*(int *)(in_ECX + 0x88) + 0x20)) {
      uVar4 = *(int *)(in_ECX + 0xf8) - *(int *)(in_ECX + 0xf4) >> 2;
      if (uVar4 != 0) {
        FUN_004054c0();
        FUN_0058aad0(0xf4356);
        uVar3 = 0;
        local_14 = 0;
        uStack_10 = 0;
        uStack_c = 0;
        local_b = 0;
        if (uVar4 != 0) {
          puVar5 = *(undefined1 **)(in_ECX + 0xf4);
          do {
            *(undefined1 *)((int)&local_14 + uVar3) = *puVar5;
            uVar3 = uVar3 + 1;
            puVar5 = puVar5 + 4;
          } while (uVar3 < uVar4);
        }
        uVar1 = *(undefined4 *)(DAT_00fe18f8 + 8);
        if ((_DAT_00fb1314 & 1) == 0) {
          _DAT_00fb1314 = _DAT_00fb1314 | 1;
          _atexit((_func_4879 *)&DAT_00bccf10);
        }
        local_24 = 0x28;
        local_22 = (undefined2)uVar1;
        local_20 = local_14;
        local_1c = uStack_10;
        local_18 = uStack_c;
        if (DAT_00fba798 == 0) {
          (**(code **)(*DAT_00fba854 + 0x10))(0,&local_24,0xd);
          __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
          return;
        }
      }
    }
    else if (*(int *)(param_1 + 8) == *(int *)(*(int *)(in_ECX + 0x8c) + 0x20)) {
      FUN_004054c0();
      FUN_0058aad0(0xf4356);
    }
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

