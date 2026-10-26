
undefined4 FUN_0084afd0(int param_1)

{
  int *piVar1;
  int *piVar2;
  int in_ECX;
  int unaff_ESI;
  int aiStack_3c [2];
  int *piStack_34;
  undefined4 uStack_30;
  int iStack_2c;
  int iVar3;
  int iVar4;
  int iStack_1c;
  int aiStack_14 [4];
  
  iStack_2c = param_1;
  uStack_30 = 0x84afeb;
  FUN_007802f0();
  piStack_34 = (int *)(in_ECX + 0x54);
  if (piStack_34 != (int *)0x0) {
    iStack_2c = 0;
    uStack_30 = 0x1c;
    aiStack_3c[1] = *(undefined4 *)(param_1 + 0x88);
    aiStack_3c[0] = 0x84b004;
    FUN_00721910();
  }
  piStack_34 = (int *)(in_ECX + 0x98);
  if (piStack_34 != (int *)0x0) {
    aiStack_3c[1] = *(undefined4 *)(param_1 + 0x88);
    iStack_2c = 0;
    uStack_30 = 4;
    aiStack_3c[0] = 0x84b01e;
    FUN_00721910();
  }
  piStack_34 = (int *)(in_ECX + 0x9c);
  if (piStack_34 != (int *)0x0) {
    aiStack_3c[1] = *(undefined4 *)(param_1 + 0x88);
    iStack_2c = 0;
    uStack_30 = 4;
    aiStack_3c[0] = 0x84b038;
    FUN_00721910();
  }
  piStack_34 = (int *)(in_ECX + 0xa4);
  if (piStack_34 != (int *)0x0) {
    iStack_2c = 0;
    uStack_30 = 4;
    aiStack_3c[1] = *(undefined4 *)(param_1 + 0x88);
    aiStack_3c[0] = 0x84b052;
    FUN_00721910();
  }
  aiStack_3c[1] = *(undefined4 *)(param_1 + 0x88);
  aiStack_14[0] = (*(int *)(in_ECX + 0x78) - *(int *)(in_ECX + 0x74)) / 0x14;
  iStack_2c = 0;
  uStack_30 = 4;
  piStack_34 = aiStack_14;
  aiStack_3c[0] = 0x84b081;
  FUN_00721910();
  iVar4 = 0;
  if (0 < unaff_ESI) {
    iVar3 = 0;
    do {
      iStack_2c = *(int *)(iVar3 + *(int *)(in_ECX + 0x74));
      aiStack_3c[0] = 0;
      FUN_00721910(*(undefined4 *)(param_1 + 0x88),&iStack_2c,4);
      if (iStack_2c != 0) {
        piVar1 = *(int **)(param_1 + 0x18);
        if (&iStack_2c < piVar1) {
          piVar2 = *(int **)(param_1 + 0x14);
          if (&iStack_2c < piVar2) goto LAB_0084b0fb;
          if (piVar1 == *(int **)(param_1 + 0x1c)) {
            aiStack_3c[0] = 0x84b0e6;
            FUN_00797930();
          }
          in_ECX = iStack_1c;
          if (*(undefined4 **)(param_1 + 0x18) != (undefined4 *)0x0) {
            **(undefined4 **)(param_1 + 0x18) =
                 *(undefined4 *)
                  (*(int *)(param_1 + 0x14) + ((int)&iStack_2c - (int)piVar2 >> 2) * 4);
          }
        }
        else {
LAB_0084b0fb:
          if (piVar1 == *(int **)(param_1 + 0x1c)) {
            aiStack_3c[0] = 0x84b108;
            FUN_00797930();
          }
          if (*(int **)(param_1 + 0x18) != (int *)0x0) {
            **(int **)(param_1 + 0x18) = iStack_2c;
          }
        }
        *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + 4;
      }
      iVar3 = iVar3 + 0x14;
      iVar4 = iVar4 + 1;
    } while (iVar4 < unaff_ESI);
  }
  iStack_2c = *(int *)(in_ECX + 0x94);
  aiStack_3c[0] = 0;
  FUN_00721910(*(undefined4 *)(param_1 + 0x88),&iStack_2c,4);
  if (aiStack_3c[0] != 0) {
    piVar1 = *(int **)(param_1 + 0x18);
    if ((aiStack_3c < piVar1) && (piVar2 = *(int **)(param_1 + 0x14), piVar2 <= aiStack_3c)) {
      if (piVar1 == *(int **)(param_1 + 0x1c)) {
        FUN_00797930();
      }
      if (*(undefined4 **)(param_1 + 0x18) != (undefined4 *)0x0) {
        **(undefined4 **)(param_1 + 0x18) =
             *(undefined4 *)(*(int *)(param_1 + 0x14) + ((int)aiStack_3c - (int)piVar2 >> 2) * 4);
        *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + 4;
        return 1;
      }
    }
    else {
      if (piVar1 == *(int **)(param_1 + 0x1c)) {
        FUN_00797930();
      }
      if (*(int **)(param_1 + 0x18) != (int *)0x0) {
        **(int **)(param_1 + 0x18) = aiStack_3c[0];
      }
    }
    *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + 4;
  }
  return 1;
}

