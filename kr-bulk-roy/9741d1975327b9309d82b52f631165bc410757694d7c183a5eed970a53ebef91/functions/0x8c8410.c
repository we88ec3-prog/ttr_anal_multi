
undefined4
FUN_008c8410(int param_1,uint param_2,undefined4 *param_3,undefined4 *param_4,uint *param_5)

{
  if ((param_4 == (undefined4 *)0x0) || (param_5 == (uint *)0x0)) {
    return 6;
  }
  if (param_3 == (undefined4 *)0x0) {
    *param_5 = (uint)*(ushort *)(param_1 + 0x98);
    return 0;
  }
  if (*(ushort *)(param_1 + 0x98) <= param_2) {
    return 0x8e;
  }
  *param_3 = *(undefined4 *)(*(int *)(param_1 + 0x9c) + param_2 * 0x10);
  *param_4 = *(undefined4 *)(*(int *)(param_1 + 0x9c) + 8 + param_2 * 0x10);
  *param_5 = *(uint *)(*(int *)(param_1 + 0x9c) + 0xc + param_2 * 0x10);
  return 0;
}

