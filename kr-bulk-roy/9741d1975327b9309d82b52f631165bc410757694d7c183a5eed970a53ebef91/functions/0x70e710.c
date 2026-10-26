
void FUN_0070e710(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  int in_ECX;
  int local_5c;
  undefined4 local_58;
  int local_54;
  undefined4 auStack_50 [2];
  undefined4 uStack_48;
  undefined4 local_40;
  undefined4 uStack_38;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined1 auStack_28 [28];
  uint local_c;
  
  local_c = DAT_00d61f20 ^ (uint)&local_5c;
  local_5c = *(int *)(param_1 + 0x30);
  local_58 = *(undefined4 *)(local_5c + 0x24);
  local_54 = in_ECX;
  if (*(int *)(param_1 + 0x10) == 0x11d) {
    if (0x7ffffffd < *(int *)(in_ECX + 0x1c)) {
      FUN_0070d7c0();
    }
    auStack_50[0] = FUN_0070d950();
    uStack_48 = 4;
    uStack_38 = FUN_00712090(*(undefined4 *)(param_1 + 0x30),auStack_50);
    local_40 = 4;
    uStack_30 = 0xffffffff;
    uStack_2c = 0xffffffff;
  }
  else {
    FUN_0070e610();
  }
  *(int *)(in_ECX + 0x1c) = *(int *)(in_ECX + 0x1c) + 1;
  if (*(int *)(param_1 + 0x10) != 0x3d) {
    FUN_0070d750();
  }
  *(undefined4 *)(param_1 + 8) = *(undefined4 *)(param_1 + 4);
  if (*(int *)(param_1 + 0x20) == 0x11f) {
    uVar2 = FUN_006ffec0(param_1 + 0x18);
    *(undefined4 *)(param_1 + 0x10) = uVar2;
  }
  else {
    *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(param_1 + 0x20);
    *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(param_1 + 0x24);
    *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(param_1 + 0x28);
    *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(param_1 + 0x2c);
    *(undefined4 *)(param_1 + 0x20) = 0x11f;
  }
  iVar3 = FUN_00712740();
  FUN_0070fc00(param_1,auStack_28,0);
  iVar1 = local_5c;
  uVar4 = FUN_00712740();
  FUN_00713370(((iVar3 << 9 | uVar4) << 8 | *(uint *)(*(int *)(local_54 + 0x18) + 8)) << 6 | 9,
               *(undefined4 *)(*(int *)(iVar1 + 0xc) + 8));
  *(undefined4 *)(iVar1 + 0x24) = local_58;
  __security_check_cookie(local_c ^ (uint)&local_5c);
  return;
}

