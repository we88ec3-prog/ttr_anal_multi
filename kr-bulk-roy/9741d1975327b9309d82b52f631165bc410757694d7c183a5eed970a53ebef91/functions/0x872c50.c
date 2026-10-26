
undefined4 FUN_00872c50(int param_1)

{
  int *piVar1;
  int *piVar2;
  int in_ECX;
  uint unaff_EDI;
  int iStack_24;
  uint uVar3;
  int local_10 [3];
  
  iStack_24 = param_1;
  FUN_008447d0();
  iStack_24 = 0;
  local_10[0] = *(int *)(in_ECX + 0x188) - *(int *)(in_ECX + 0x184) >> 2;
  FUN_00721910(*(undefined4 *)(param_1 + 0x88),local_10,4);
  uVar3 = 0;
  if (unaff_EDI != 0) {
    do {
      iStack_24 = *(int *)(*(int *)(in_ECX + 0x184) + uVar3 * 4);
      FUN_00721910(*(undefined4 *)(param_1 + 0x88),&iStack_24,4,0);
      if (iStack_24 != 0) {
        piVar1 = *(int **)(param_1 + 0x18);
        if ((&iStack_24 < piVar1) && (piVar2 = *(int **)(param_1 + 0x14), piVar2 <= &iStack_24)) {
          if (piVar1 == *(int **)(param_1 + 0x1c)) {
            FUN_00797930();
          }
          if (*(undefined4 **)(param_1 + 0x18) != (undefined4 *)0x0) {
            **(undefined4 **)(param_1 + 0x18) =
                 *(undefined4 *)
                  (*(uint *)(param_1 + 0x14) + ((int)&iStack_24 - (int)piVar2 >> 2) * 4);
          }
        }
        else {
          if (piVar1 == *(int **)(param_1 + 0x1c)) {
            FUN_00797930();
          }
          if (*(int **)(param_1 + 0x18) != (int *)0x0) {
            **(int **)(param_1 + 0x18) = iStack_24;
          }
        }
        *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + 4;
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < unaff_EDI);
  }
  return 1;
}

