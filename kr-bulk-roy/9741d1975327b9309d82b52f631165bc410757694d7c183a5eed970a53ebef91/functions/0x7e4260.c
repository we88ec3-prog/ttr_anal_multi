
/* WARNING: Removing unreachable block (ram,0x007e42ba) */
/* WARNING: Removing unreachable block (ram,0x007e42c0) */
/* WARNING: Removing unreachable block (ram,0x007e42cf) */
/* WARNING: Removing unreachable block (ram,0x007e42d1) */
/* WARNING: Removing unreachable block (ram,0x007e42d5) */

void FUN_007e4260(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = (*(int *)(param_1 + 0x5c) - *(int *)(param_1 + 0x58)) / 0x2c;
  if (iVar2 != 0) {
    iVar3 = 0;
    do {
      puVar1 = *(undefined4 **)(iVar3 + 0x28 + *(int *)(param_1 + 0x58));
      if (puVar1 != (undefined4 *)0x0) {
        (**(code **)*puVar1)(1);
        *(undefined4 *)(iVar3 + 0x28 + *(int *)(param_1 + 0x58)) = 0;
      }
      iVar3 = iVar3 + 0x2c;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  if (*(int *)(param_1 + 0x58) != *(int *)(param_1 + 0x5c)) {
    *(int *)(param_1 + 0x5c) = *(int *)(param_1 + 0x58);
  }
  return;
}

