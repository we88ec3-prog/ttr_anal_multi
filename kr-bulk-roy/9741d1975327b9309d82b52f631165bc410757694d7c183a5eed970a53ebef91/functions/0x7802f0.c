
undefined4 FUN_007802f0(int param_1)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  int in_ECX;
  undefined4 *puVar4;
  int *piVar5;
  int aiStack_34 [2];
  int *piStack_2c;
  undefined4 uStack_28;
  int iStack_24;
  undefined4 local_14 [4];
  
  aiStack_34[1] = *(undefined4 *)(param_1 + 0x88);
  iStack_24 = 0;
  local_14[0] = *(undefined4 *)(in_ECX + 0x18);
  uStack_28 = 4;
  piStack_2c = local_14;
  puVar4 = (undefined4 *)(in_ECX + 8);
  aiStack_34[0] = 0x780320;
  FUN_00721910();
  if (0xf < *(uint *)(in_ECX + 0x1c)) {
    puVar4 = (undefined4 *)*puVar4;
  }
  if ((puVar4 != (undefined4 *)0x0) && (iStack_24 != 0)) {
    aiStack_34[0] = 0;
    FUN_00721910(*(undefined4 *)(param_1 + 0x88),puVar4,iStack_24);
  }
  aiStack_34[0] = 0;
  FUN_00721910(*(undefined4 *)(param_1 + 0x88),&stack0xffffffe0,4);
  piStack_2c = *(int **)(in_ECX + 0x38);
  piVar5 = (int *)*piStack_2c;
  if (piVar5 != piStack_2c) {
    do {
      aiStack_34[0] = piVar5[4];
      FUN_00721910(*(undefined4 *)(param_1 + 0x88),aiStack_34,4,0);
      if (aiStack_34[0] != 0) {
        piVar2 = *(int **)(param_1 + 0x18);
        if (aiStack_34 < piVar2) {
          piVar3 = *(int **)(param_1 + 0x14);
          if (aiStack_34 < piVar3) goto LAB_007803d2;
          if (piVar2 == *(int **)(param_1 + 0x1c)) {
            FUN_00797930();
          }
          if (*(undefined4 **)(param_1 + 0x18) != (undefined4 *)0x0) {
            **(undefined4 **)(param_1 + 0x18) =
                 *(undefined4 *)
                  (*(uint *)(param_1 + 0x14) + ((int)aiStack_34 - (int)piVar3 >> 2) * 4);
          }
        }
        else {
LAB_007803d2:
          if (piVar2 == *(int **)(param_1 + 0x1c)) {
            FUN_00797930();
          }
          if (*(int **)(param_1 + 0x18) != (int *)0x0) {
            **(int **)(param_1 + 0x18) = aiStack_34[0];
          }
        }
        *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + 4;
      }
      if (*(char *)((int)piVar5 + 0x15) == '\0') {
        piVar2 = (int *)piVar5[2];
        if (*(char *)((int)piVar2 + 0x15) == '\0') {
          cVar1 = *(char *)(*piVar2 + 0x15);
          piVar5 = piVar2;
          piVar2 = (int *)*piVar2;
          while (cVar1 == '\0') {
            cVar1 = *(char *)(*piVar2 + 0x15);
            piVar5 = piVar2;
            piVar2 = (int *)*piVar2;
          }
        }
        else {
          cVar1 = *(char *)(piVar5[1] + 0x15);
          piVar3 = (int *)piVar5[1];
          piVar2 = piVar5;
          while ((piVar5 = piVar3, cVar1 == '\0' && (piVar2 == (int *)piVar5[2]))) {
            cVar1 = *(char *)(piVar5[1] + 0x15);
            piVar3 = (int *)piVar5[1];
            piVar2 = piVar5;
          }
        }
      }
    } while (piVar5 != piStack_2c);
  }
  return 1;
}

