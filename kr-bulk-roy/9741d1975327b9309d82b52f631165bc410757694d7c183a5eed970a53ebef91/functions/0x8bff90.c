
undefined4 FUN_008bff90(int param_1,int *param_2,uint param_3)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 local_2c [2];
  ushort local_22;
  uint local_20;
  short local_1c;
  short local_18;
  undefined4 local_14;
  undefined4 local_10;
  int local_8;
  
  local_8 = *param_2;
  uVar1 = *(undefined2 *)(*(int *)(local_8 + 0x8c) + 0x44086);
  if (param_3 < *(uint *)(local_8 + 0x10)) {
    if (param_3 == 0) {
      iVar2 = *(int *)(local_8 + 0xa4);
    }
    else {
      iVar2 = param_3 - 1;
    }
    puVar4 = (undefined4 *)(*(int *)(*(int *)(local_8 + 0x8c) + 0x38) + iVar2 * 0x24);
    puVar5 = local_2c;
    for (iVar3 = 9; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
    *(uint *)(param_1 + 0x4c) = local_20 >> 0x10;
    *(uint *)(param_1 + 0x50) = local_20 & 0xffff;
    *(undefined4 *)(param_1 + 0x54) = local_10;
    FUN_008ba350(param_1,local_14);
    switch(uVar1) {
    case 1:
      *(undefined1 *)(param_1 + 0x5e) = 1;
      break;
    case 2:
      *(undefined1 *)(param_1 + 0x5e) = 3;
      break;
    case 4:
      *(undefined1 *)(param_1 + 0x5e) = 4;
      break;
    case 8:
      *(undefined1 *)(param_1 + 0x5e) = 2;
      *(undefined2 *)(param_1 + 0x5c) = 0x100;
    }
    *(int *)(param_1 + 0x68) = (int)local_18;
    *(int *)(param_1 + 100) = (int)local_1c;
    *(int *)(param_1 + 0x24) = (int)local_18 << 6;
    *(uint *)(param_1 + 0x28) = (uint)local_22 << 6;
    *(undefined4 *)(param_1 + 0x48) = 0x62697473;
    *(int *)(param_1 + 0x20) = (int)local_1c << 6;
    *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x50) << 6;
    *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x4c) << 6;
    FUN_008b86a0(param_1 + 0x18,(uint)*(ushort *)(*(int *)(local_8 + 0x8c) + 6) << 6);
    return 0;
  }
  return 6;
}

