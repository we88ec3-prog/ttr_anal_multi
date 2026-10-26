
undefined4 FUN_00874c70(int *param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int in_ECX;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  int *piStack_34;
  int *piStack_30;
  int local_2c;
  int aiStack_28 [9];
  
  local_2c = in_ECX;
  iVar2 = (**(code **)(*param_1 + 4))();
  if (*(int *)(iVar2 + 4) == *(int *)(in_ECX + 0x28)) {
    piVar1 = *(int **)(in_ECX + 0x34);
    piVar4 = *(int **)(in_ECX + 0x30);
    aiStack_28[1] = 0;
    aiStack_28[2] = 0;
    aiStack_28[3] = 0;
    aiStack_28[4] = 0;
    aiStack_28[5] = 0;
    piStack_30 = aiStack_28;
    aiStack_28[0] = param_2;
    FUN_00874e10(&piStack_34,piVar4,piVar1);
    piVar3 = (int *)0x0;
    if (piStack_34 == piVar1) {
      if (piVar4 != *(int **)(local_2c + 0x34)) {
        piVar3 = (int *)(*piVar4 + 4);
      }
      piStack_34 = (int *)0x3f800000;
      piVar4 = piVar3;
    }
    else {
      piVar1 = (int *)*piStack_34;
      if (*piVar1 == param_2) {
        piStack_34 = (int *)0x3f800000;
        piVar3 = piVar1 + 1;
        piVar4 = piVar3;
      }
      else {
        piVar5 = (int *)0x0;
        if (piVar4 == piStack_34) {
          piVar5 = piVar1;
        }
        piVar3 = piVar5 + 1;
        piVar4 = piVar1 + 1;
        local_2c = *piVar1 - *piVar5;
        piStack_34 = (int *)((float)(param_2 - *piVar5) / (float)local_2c);
      }
    }
    param_1[0x24] = (int)piStack_34;
    param_1[0x26] = (int)piVar4;
    param_1[0x25] = (int)piVar3;
    FUN_00874410();
    return 1;
  }
  return 0;
}

