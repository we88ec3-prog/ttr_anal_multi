
void FUN_0062b4e0(undefined4 param_1,undefined4 param_2,uint param_3)

{
  int *piVar1;
  uint uVar2;
  int *piVar3;
  int unaff_ESI;
  
  uVar2 = param_3;
  FUN_00627850(*(undefined4 *)(unaff_ESI + 0x110),param_2);
  FUN_0062daa0(&param_1);
  if (param_3 != *(uint *)(unaff_ESI + 0x104)) {
    piVar1 = (int *)(param_3 + 0x40);
    if (uVar2 < (uint)(*(int *)(param_3 + 0x44) - *(int *)(param_3 + 0x40) >> 2)) {
      *(undefined4 *)(*piVar1 + uVar2 * 4) = param_2;
      return;
    }
    piVar3 = (int *)FUN_00831f50();
    if ((*(char *)(*piVar3 + 0x254) == '\x01') && (uVar2 == 1)) {
      FUN_0044b4a0(piVar1);
    }
    FUN_004a8680();
  }
  return;
}

