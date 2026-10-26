
undefined4 FUN_008e21a0(int param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *(int *)(param_1 + 0x290);
  if (iVar1 != 0) {
    if (*(int *)(iVar1 + 0x5b0) == 0xffff) {
      return 6;
    }
    if (param_2 != (undefined4 *)0x0) {
      if (*(int *)(iVar1 + 0xb94) == 0) {
        uVar2 = FUN_008de030();
        *(undefined4 *)(iVar1 + 0xb94) = uVar2;
      }
      *param_2 = *(undefined4 *)(iVar1 + 0xb94);
    }
    if (param_3 != (undefined4 *)0x0) {
      if (*(int *)(iVar1 + 0xb98) == 0) {
        uVar2 = FUN_008de030();
        *(undefined4 *)(iVar1 + 0xb98) = uVar2;
      }
      *param_3 = *(undefined4 *)(iVar1 + 0xb98);
    }
    if (param_4 != (undefined4 *)0x0) {
      *param_4 = *(undefined4 *)(iVar1 + 0x5b8);
    }
  }
  return 0;
}

