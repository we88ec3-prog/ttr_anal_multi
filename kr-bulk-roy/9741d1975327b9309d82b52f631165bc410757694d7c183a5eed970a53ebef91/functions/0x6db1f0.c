
void FUN_006db1f0(undefined4 param_1,uint param_2)

{
  uint *puVar1;
  uint uVar2;
  int *in_EAX;
  undefined4 *puVar3;
  int *piVar4;
  int local_24;
  undefined4 local_14;
  
  if (*in_EAX != 0) {
    FUN_006db3c0(&param_1);
    if (local_24 == in_EAX[0xb]) {
      puVar3 = (undefined4 *)FUN_006db2c0(in_EAX + 10,&param_1);
      *puVar3 = 0;
      puVar3[1] = 0;
      puVar3[2] = 0;
      puVar3[3] = local_14;
      puVar3[4] = 0;
      puVar3[5] = 0;
      piVar4 = (int *)FUN_006db3c0(&param_1);
      local_24 = *piVar4;
      if (local_24 == in_EAX[0xb]) {
        return;
      }
    }
    *(int *)(local_24 + 0x18) = *(int *)(local_24 + 0x18) + 1;
    *(int *)(local_24 + 0x1c) = *(int *)(local_24 + 0x1c) + param_2;
    *(int *)(local_24 + 0x20) = *(int *)(local_24 + 0x20) + 1;
    puVar1 = (uint *)(local_24 + 0x28);
    uVar2 = *puVar1;
    *puVar1 = *puVar1 + param_2;
    *(int *)(local_24 + 0x2c) =
         *(int *)(local_24 + 0x2c) + ((int)param_2 >> 0x1f) + (uint)CARRY4(uVar2,param_2);
  }
  return;
}

