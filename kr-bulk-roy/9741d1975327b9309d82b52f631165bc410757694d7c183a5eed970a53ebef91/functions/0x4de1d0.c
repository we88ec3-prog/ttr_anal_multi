
undefined4 FUN_004de1d0(uint param_1,int *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  uint uVar3;
  int *piVar4;
  int in_ECX;
  uint uVar5;
  undefined4 *puVar6;
  int *piVar7;
  uint local_8;
  
  if (param_2 < 6) {
    local_8 = 0;
  }
  else {
    local_8 = ((int)param_2 - 6U) / 0xe;
  }
  if (*(int *)(param_1 + 2) != 0) {
    FUN_00797a00();
  }
  if (local_8 != 0) {
    piVar7 = (int *)(param_1 + 6);
    param_1 = local_8;
    do {
      puVar6 = *(undefined4 **)(in_ECX + 0x5efc);
      uVar3 = *(int *)(in_ECX + 0x5f00) - (int)puVar6 >> 2;
      uVar5 = 0;
      if (uVar3 != 0) {
        do {
          if (*(int *)*puVar6 == *piVar7) {
            iVar1 = *(int *)(*(int *)(in_ECX + 0x5efc) + uVar5 * 4);
            if (iVar1 != 0) {
              *(int *)(iVar1 + 10) = piVar7[1];
              *(int *)(iVar1 + 0xe) = piVar7[2];
              *(short *)(iVar1 + 0x12) = (short)piVar7[3];
              goto LAB_004de347;
            }
            break;
          }
          uVar5 = uVar5 + 1;
          puVar6 = puVar6 + 1;
        } while (uVar5 < uVar3);
      }
      param_2 = piVar7;
      piVar4 = (int *)FUN_00891268(0x14);
      if (piVar4 == (int *)0x0) {
        piVar4 = (int *)0x0;
      }
      else {
        *piVar4 = 0;
        piVar4[1] = 0;
        *(undefined2 *)(piVar4 + 2) = 0;
        *(undefined4 *)((int)piVar4 + 10) = 0;
        *(undefined4 *)((int)piVar4 + 0xe) = 0;
        *(undefined2 *)((int)piVar4 + 0x12) = 0;
      }
      *piVar4 = *piVar7;
      *(int *)((int)piVar4 + 10) = piVar7[1];
      *(int *)((int)piVar4 + 0xe) = piVar7[2];
      *(short *)((int)piVar4 + 0x12) = (short)piVar7[3];
      puVar6 = *(undefined4 **)(in_ECX + 0x5f00);
      param_2 = piVar4;
      if (&param_2 < puVar6) {
        puVar2 = *(undefined4 **)(in_ECX + 0x5efc);
        if (&param_2 < puVar2) goto LAB_004de321;
        if (puVar6 == *(undefined4 **)(in_ECX + 0x5f04)) {
          FUN_004deab0();
        }
        if (*(undefined4 **)(in_ECX + 0x5f00) != (undefined4 *)0x0) {
          **(undefined4 **)(in_ECX + 0x5f00) =
               *(undefined4 *)(*(int *)(in_ECX + 0x5efc) + ((int)&param_2 - (int)puVar2 >> 2) * 4);
        }
      }
      else {
LAB_004de321:
        if (puVar6 == *(undefined4 **)(in_ECX + 0x5f04)) {
          FUN_004deab0();
        }
        if (*(undefined4 **)(in_ECX + 0x5f00) != (undefined4 *)0x0) {
          **(undefined4 **)(in_ECX + 0x5f00) = piVar4;
        }
      }
      *(int *)(in_ECX + 0x5f00) = *(int *)(in_ECX + 0x5f00) + 4;
LAB_004de347:
      piVar7 = (int *)((int)piVar7 + 0xe);
      param_1 = param_1 - 1;
    } while (param_1 != 0);
  }
  return 0;
}

