
void FUN_0062d6f0(undefined4 param_1,undefined4 param_2,uint param_3)

{
  uint uVar1;
  int unaff_ESI;
  
  uVar1 = param_3;
  FUN_0062d7c0(*(undefined4 *)(*(int *)(unaff_ESI + 0x110) + 0x118),param_2);
  FUN_0062daa0(&param_1);
  if (param_3 != *(uint *)(unaff_ESI + 0x120)) {
    if (uVar1 < (uint)(*(int *)(param_3 + 0x44) - *(int *)(param_3 + 0x40) >> 2)) {
      *(undefined4 *)(*(int *)(param_3 + 0x40) + uVar1 * 4) = param_2;
      return;
    }
    FUN_004a8680();
  }
  return;
}

