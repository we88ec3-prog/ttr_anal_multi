
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00761b00(void)

{
  int in_EAX;
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (*(uint *)(in_EAX + 0x14c) < *(uint *)(in_EAX + 0x118)) {
    if ((_DAT_00fe2ffc & 1) == 0) {
      _DAT_00fe2ffc = _DAT_00fe2ffc | 1;
      _DAT_00fe3000 = 1;
      _DAT_00fe3004 = 0;
      _atexit((_func_4879 *)&DAT_00bcfed0);
    }
    uVar1 = *(uint *)(in_EAX + 0x14c);
    if (*(uint *)(in_EAX + 0x118) < uVar1) {
      return;
    }
    if ((int)uVar1 < 0) {
      uVar1 = 0;
    }
    iVar2 = FUN_00776f20(in_EAX + 0x108,uVar1);
    if (iVar2 < 0) {
      return;
    }
    *(int *)(in_EAX + 0x14c) = *(int *)(in_EAX + 0x14c) + iVar2;
    FUN_007619a0();
  }
  iVar2 = *(int *)(*(int *)(in_EAX + 0x24) + 0x3d4);
  if ((((iVar2 == 1) || (iVar2 == 2)) ||
      (iVar2 = *(int *)(*(int *)(in_EAX + 0x24) + 0x404), iVar2 == 1)) || (iVar2 == 2)) {
    uVar3 = *(undefined4 *)(in_EAX + 0x160);
    if (*(char *)(in_EAX + 0x150) != '\0') {
      *(undefined4 *)(in_EAX + 0x164) = *(undefined4 *)(in_EAX + 0x14c);
      FUN_00761800();
      return;
    }
  }
  else {
    uVar3 = *(undefined4 *)(in_EAX + 0x14c);
    *(undefined4 *)(in_EAX + 0x160) = uVar3;
  }
  *(undefined4 *)(in_EAX + 0x164) = uVar3;
  FUN_00761800();
  return;
}

