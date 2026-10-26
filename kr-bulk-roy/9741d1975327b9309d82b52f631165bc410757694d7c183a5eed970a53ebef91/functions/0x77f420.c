
undefined4 FUN_0077f420(int param_1)

{
  uint *puVar1;
  int *piVar2;
  int *piVar3;
  uint uVar4;
  int *in_ECX;
  uint uVar5;
  undefined4 *puVar6;
  int iStack_3c;
  int *piStack_38;
  int *piStack_34;
  uint uStack_30;
  uint uStack_2c;
  undefined4 uStack_14;
  int iStack_10;
  
  uStack_2c = param_1;
  uStack_30 = 0x77f43b;
  FUN_007802f0();
  if (in_ECX + 0x18 != (int *)0x0) {
    uStack_2c = 0;
    uStack_30 = 4;
    piStack_38 = *(int **)(param_1 + 0x88);
    iStack_3c = 0x77f453;
    piStack_34 = in_ECX + 0x18;
    FUN_00721910();
  }
  if (in_ECX + 0x1a != (int *)0x0) {
    piStack_38 = *(int **)(param_1 + 0x88);
    uStack_2c = 0;
    uStack_30 = 0x2c;
    iStack_3c = 0x77f46b;
    piStack_34 = in_ECX + 0x1a;
    FUN_00721910();
  }
  if (in_ECX + 0x25 != (int *)0x0) {
    piStack_38 = *(int **)(param_1 + 0x88);
    uStack_2c = 0;
    uStack_30 = 0x2c;
    iStack_3c = 0x77f486;
    piStack_34 = in_ECX + 0x25;
    FUN_00721910();
  }
  uStack_2c = 0x77f48f;
  uStack_14 = (**(code **)(*in_ECX + 0x34))();
  piStack_38 = *(int **)(param_1 + 0x88);
  uStack_2c = 0;
  uStack_30 = 4;
  piStack_34 = &uStack_14;
  iStack_10 = in_ECX[0x37] - in_ECX[0x36] >> 2;
  iStack_3c = 0x77f4bb;
  FUN_00721910();
  iStack_3c = 0;
  FUN_00721910(*(undefined4 *)(param_1 + 0x88),&stack0xffffffe0,4);
  puVar6 = (undefined4 *)0x0;
  if (piStack_34 != (undefined4 *)0x0) {
    do {
      iStack_3c = *(int *)(in_ECX[0x32] + (int)puVar6 * 4);
      FUN_00721910(*(undefined4 *)(param_1 + 0x88),&iStack_3c,4,0);
      if (iStack_3c != 0) {
        piVar2 = *(int **)(param_1 + 0x18);
        if (&iStack_3c < piVar2) {
          piVar3 = *(int **)(param_1 + 0x14);
          if (&iStack_3c < piVar3) goto LAB_0077f543;
          if (piVar2 == *(int **)(param_1 + 0x1c)) {
            FUN_00797930();
          }
          if (*(undefined4 **)(param_1 + 0x18) != (undefined4 *)0x0) {
            **(undefined4 **)(param_1 + 0x18) =
                 *(undefined4 *)
                  (*(uint *)(param_1 + 0x14) + ((int)&iStack_3c - (int)piVar3 >> 2) * 4);
          }
        }
        else {
LAB_0077f543:
          if (piVar2 == *(int **)(param_1 + 0x1c)) {
            FUN_00797930();
          }
          if (*(int **)(param_1 + 0x18) != (int *)0x0) {
            **(int **)(param_1 + 0x18) = iStack_3c;
          }
        }
        *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + 4;
        in_ECX = piStack_38;
      }
      puVar6 = (undefined4 *)((int)puVar6 + 1);
    } while (puVar6 < piStack_34);
  }
  uStack_2c = 0;
  if (uStack_30 != 0) {
    do {
      iStack_3c = *(int *)(in_ECX[0x36] + uStack_2c * 4);
      FUN_00721910(*(undefined4 *)(param_1 + 0x88),&iStack_3c,4,0);
      if (iStack_3c != 0) {
        piVar2 = *(int **)(param_1 + 0x18);
        puVar1 = (uint *)(param_1 + 0x14);
        if ((&iStack_3c < piVar2) && (piVar3 = (int *)*puVar1, piVar3 <= &iStack_3c)) {
          if (piVar2 == *(int **)(param_1 + 0x1c)) {
            uVar4 = (int)piVar2 - (int)piVar3 >> 2;
            if (0x3ffffffe < uVar4) {
LAB_0077f692:
                    /* WARNING: Subroutine does not return */
              FUN_0087db30("vector<T> too long");
            }
            uVar4 = uVar4 + 1;
            uVar5 = (int)*(int **)(param_1 + 0x1c) - (int)piVar3 >> 2;
            if (uVar5 < uVar4) {
              if (0x3fffffff - (uVar5 >> 1) < uVar5) {
                uVar5 = 0;
              }
              else {
                uVar5 = uVar5 + (uVar5 >> 1);
              }
              if (uVar5 < uVar4) {
                uVar5 = uVar4;
              }
              FUN_00797980(uVar5);
            }
          }
          if (*(undefined4 **)(param_1 + 0x18) != (undefined4 *)0x0) {
            **(undefined4 **)(param_1 + 0x18) =
                 *(undefined4 *)(*puVar1 + ((int)&iStack_3c - (int)piVar3 >> 2) * 4);
          }
        }
        else {
          if (piVar2 == *(int **)(param_1 + 0x1c)) {
            uVar4 = (int)((int)piVar2 - *puVar1) >> 2;
            if (0x3ffffffe < uVar4) goto LAB_0077f692;
            uVar4 = uVar4 + 1;
            uVar5 = (int)((int)*(int **)(param_1 + 0x1c) - *puVar1) >> 2;
            if (uVar5 < uVar4) {
              if (0x3fffffff - (uVar5 >> 1) < uVar5) {
                uVar5 = 0;
              }
              else {
                uVar5 = uVar5 + (uVar5 >> 1);
              }
              if (uVar5 < uVar4) {
                uVar5 = uVar4;
              }
              FUN_00797980(uVar5);
            }
          }
          if (*(int **)(param_1 + 0x18) != (int *)0x0) {
            **(int **)(param_1 + 0x18) = iStack_3c;
          }
        }
        *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + 4;
        in_ECX = piStack_38;
      }
      uStack_2c = uStack_2c + 1;
    } while (uStack_2c < uStack_30);
  }
  return 1;
}

