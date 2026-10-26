
undefined4 * FUN_00724ed0(undefined4 *param_1,int *param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int *piVar4;
  undefined4 uVar5;
  int in_ECX;
  int *piVar6;
  undefined4 local_2c;
  int *local_28;
  int *local_24;
  int local_1c;
  int local_18 [3];
  int local_c [2];
  
  uVar3 = param_3;
  piVar6 = param_2;
  puVar2 = param_1;
  iVar1 = *(int *)(in_ECX + 4);
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  *param_1 = 1;
  if (iVar1 == 0) {
    iVar1 = param_2[1];
    if (iVar1 != 0) {
      param_2 = (int *)0x0;
      param_2 = (int *)&param_2;
    }
    if (*param_2 == 0) {
      param_2 = (int *)iVar1;
      uVar5 = FUN_00721400();
      if (*(char *)(in_ECX + 3) == '\x02') {
        FUN_0071d6a0(in_ECX,puVar2,&param_2,uVar5);
      }
    }
    else {
      if (iVar1 != 0) {
        param_2 = (int *)0x0;
        piVar6 = (int *)&param_2;
      }
      param_2 = (int *)*piVar6;
      FUN_00726b60();
    }
    FUN_0071d5a0(puVar2,0,uVar3);
  }
  else {
    FUN_0071efc0(&local_2c,param_2,param_3);
    *puVar2 = local_2c;
    piVar6 = local_28;
    if (local_28 != local_24) {
      do {
        iVar1 = piVar6[1];
        param_2 = (int *)((int)(puVar2[2] - puVar2[1]) >> 3);
        piVar4 = piVar6;
        if (iVar1 != 0) {
          param_1 = (undefined4 *)0x0;
          piVar4 = (int *)&param_1;
        }
        if (*piVar4 == 0) {
          piVar4 = piVar6;
          if (iVar1 == 0) {
            if (*piVar6 == 0) {
              local_18[1] = 0;
              piVar4 = local_18 + 1;
            }
            else {
              local_18[2] = *(undefined4 *)(*piVar6 + 4);
              piVar4 = local_18 + 2;
            }
            local_18[0] = *piVar4;
            piVar4 = local_18;
          }
          local_c[0] = *piVar4;
          local_1c = iVar1;
          if (*(char *)(in_ECX + 3) == '\x02') {
            FUN_0071d6a0(in_ECX,puVar2,&local_1c,local_c);
          }
        }
        else {
          piVar4 = piVar6;
          if (iVar1 != 0) {
            local_c[1] = 0;
            piVar4 = local_c + 1;
          }
          local_c[0] = *piVar4;
          FUN_00726b60();
        }
        FUN_0071d5a0(puVar2,param_2,param_3);
        piVar6 = piVar6 + 2;
      } while (piVar6 != local_24);
      return puVar2;
    }
  }
  return puVar2;
}

