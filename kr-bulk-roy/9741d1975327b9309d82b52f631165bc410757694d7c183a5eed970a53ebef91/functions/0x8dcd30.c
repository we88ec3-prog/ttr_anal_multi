
undefined4 FUN_008dcd30(int param_1,uint param_2,uint *param_3)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x290);
  if (iVar1 != 0) {
    if (*(int *)(iVar1 + 0x5b0) == 0xffff) {
      return 6;
    }
    if (*(uint *)(iVar1 + 0xc) < param_2) {
      return 6;
    }
    if (param_3 != (uint *)0x0) {
      *param_3 = (uint)*(ushort *)(*(int *)(iVar1 + 0x488) + param_2 * 2);
    }
  }
  return 0;
}

