
undefined4 FUN_00846aa0(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  int in_ECX;
  int iStack_18;
  int iStack_14;
  int iStack_10;
  uint local_c;
  
  if (*(int *)(in_ECX + 0x74) == 0) {
    return 0;
  }
  iVar1 = FUN_00845bb0(param_1);
  if (iVar1 == 0) {
    return 0;
  }
  local_c = (uint)(*(int *)(in_ECX + 0x7c) != *(int *)(in_ECX + 0x80));
  if (local_c != 0) {
    *(uint *)(in_ECX + 0xb4) = 2 - (uint)(param_1[0x34] != 1);
  }
  uVar2 = (**(code **)(*param_1 + 0xfc))(*(int *)(in_ECX + 0x74) + 0x16c);
  *(undefined4 *)(in_ECX + 0xbc) = uVar2;
  uVar3 = (**(code **)(*param_1 + 0xf4))();
  iStack_18 = -0x5da00000;
  FUN_0082ef00(&iStack_18);
  iVar1 = *(int *)(in_ECX + 0x38);
  if ((iStack_14 == iVar1) || (*(int *)(iStack_14 + 0x10) == 0)) {
    iStack_14 = -0x5db00000;
    FUN_0082ef00(&iStack_14);
    if (((iStack_18 != iVar1) && (*(int *)(iStack_18 + 0x10) != 0)) ||
       ((((iVar1 = FUN_00846220(), iVar1 != 0 || (*(int *)(in_ECX + 0x94) != 0)) ||
         (*(int *)(in_ECX + 0x98) != 0)) || (*(int *)(in_ECX + 0xb8) != 0)))) goto LAB_00846bb9;
    if (iStack_10 != 0) {
      if (*(int *)(in_ECX + 0xbc) == 0) {
        if (uVar3 < 4) goto LAB_00846bb9;
      }
      else {
        *(undefined4 *)(in_ECX + 0xb4) = 3;
      }
    }
  }
  else {
LAB_00846bb9:
    *(undefined4 *)(in_ECX + 0xb4) = 1;
  }
  if (*(int *)(in_ECX + 0x78) == 0) {
    return 0;
  }
  FUN_0084e870(*(int *)(in_ECX + 0x78));
  iVar1 = *(int *)(in_ECX + 0xb4);
  if (iVar1 != 1) {
    if (iVar1 == 2) {
      iVar1 = FUN_0084e090(uVar3,0);
      if (iVar1 != 0) {
        *(undefined4 *)(*(int *)(in_ECX + 0x78) + 0x3c) = 1;
      }
      goto LAB_00846c04;
    }
    if ((iVar1 != 3) || (iVar1 = FUN_0084e090(*(undefined4 *)(in_ECX + 0xbc),1), iVar1 == 0))
    goto LAB_00846c04;
  }
  *(undefined4 *)(*(int *)(in_ECX + 0x78) + 0x3c) = 1;
LAB_00846c04:
  FUN_0084d9e0(*(undefined4 *)(in_ECX + 0x78));
  uVar2 = (**(code **)(*param_1 + 0x48))(*(undefined4 *)(in_ECX + 0x78));
  return uVar2;
}

