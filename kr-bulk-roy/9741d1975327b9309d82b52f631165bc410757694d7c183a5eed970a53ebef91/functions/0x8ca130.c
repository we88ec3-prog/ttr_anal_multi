
undefined4 FUN_008ca130(int param_1,uint param_2,undefined4 *param_3)

{
  ushort uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  if (param_1 == 0) {
    return 0x23;
  }
  if (*(ushort *)(param_1 + 0x108) <= param_2) {
    return 0x10;
  }
  iVar2 = *(int *)(param_1 + 0x218);
  if (iVar2 == 0) {
    return 7;
  }
  uVar3 = (**(code **)(iVar2 + 0x10))(0);
  *param_3 = uVar3;
  iVar4 = *(int *)(param_1 + 0x1d4);
  if (iVar4 == 0x10000) {
    if (0x101 < param_2) {
      return 0;
    }
  }
  else {
    if (iVar4 == 0x20000) {
      if ((*(char *)(param_1 + 0x264) == '\0') && (iVar4 = FUN_008c9f80(), iVar4 != 0)) {
        return 0;
      }
      if (*(ushort *)(param_1 + 0x268) <= param_2) {
        return 0;
      }
      uVar1 = *(ushort *)(*(int *)(param_1 + 0x26c) + param_2 * 2);
      if (uVar1 < 0x102) {
        uVar3 = (**(code **)(iVar2 + 0x10))((uint)uVar1);
        *param_3 = uVar3;
        return 0;
      }
      *param_3 = *(undefined4 *)(*(int *)(param_1 + 0x270) + -0x408 + (uint)uVar1 * 4);
      return 0;
    }
    if (iVar4 != 0x28000) {
      return 0;
    }
    if ((*(char *)(param_1 + 0x264) == '\0') && (iVar4 = FUN_008c9f80(), iVar4 != 0)) {
      return 0;
    }
    if (*(ushort *)(param_1 + 0x268) <= param_2) {
      return 0;
    }
    param_2 = param_2 + (int)*(char *)(*(int *)(param_1 + 0x26c) + param_2);
  }
  uVar3 = (**(code **)(iVar2 + 0x10))(param_2);
  *param_3 = uVar3;
  return 0;
}

