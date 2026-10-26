
int * FUN_007f3680(int *param_1,int param_2,float param_3,float param_4,float param_5)

{
  float fVar1;
  float fVar2;
  uint uVar3;
  undefined4 *puVar4;
  int iVar5;
  float *pfVar6;
  int iVar7;
  float *pfVar8;
  float local_74;
  float local_70;
  float local_6c;
  float local_68;
  float local_64;
  float local_60;
  float local_5c;
  float local_58;
  float local_54;
  float local_50;
  float local_4c;
  float local_48;
  undefined **local_34 [3];
  float local_28;
  float local_24;
  float local_20;
  char *local_1c;
  int local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093484b;
  local_10 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  puVar4 = (undefined4 *)FUN_00891268(0x18,uVar3);
  if (puVar4 == (undefined4 *)0x0) {
    puVar4 = (undefined4 *)0x0;
  }
  else {
    *puVar4 = 0;
    puVar4[3] = 0;
    puVar4[4] = 0;
    puVar4[5] = 0;
  }
  *param_1 = (int)puVar4;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[5] = 0;
  iVar5 = FUN_00891268(0xc,uVar3);
  if (iVar5 == 0) {
    local_1c = (char *)0x0;
    std::exception::exception((exception *)local_34,&local_1c);
    local_34[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_34,&DAT_00c857a8);
  }
  param_1[4] = iVar5;
  *(int *)iVar5 = iVar5;
  *(int *)(param_1[4] + 4) = param_1[4];
  local_8 = 0;
  FUN_007fcfa0(*param_1,param_2);
  iVar5 = *(int *)*param_1;
  if (iVar5 != 0) {
    local_18 = iVar5;
  }
  local_14 = 0;
  if (((int *)*param_1)[4] != 0) {
    do {
      pfVar8 = (float *)(*(int *)(*param_1 + 0xc) * local_14 + local_18);
      _memset(&local_74,0,0x34);
      local_54 = 1.0;
      local_64 = 1.0;
      local_74 = 1.0;
      FUN_00780a00();
      FUN_00791100();
      local_50 = param_3;
      local_4c = param_4;
      local_48 = param_5;
      local_28 = pfVar8[2] * local_5c + pfVar8[1] * local_68 + local_74 * *pfVar8 + param_3;
      local_24 = pfVar8[2] * local_58 + pfVar8[1] * local_64 + local_70 * *pfVar8 + param_4;
      fVar1 = *pfVar8;
      fVar2 = pfVar8[1];
      *pfVar8 = local_28;
      pfVar8[1] = local_24;
      local_20 = pfVar8[2] * local_54 + fVar2 * local_60 + local_6c * fVar1 + param_5;
      pfVar8[2] = local_20;
      pfVar6 = (float *)FUN_0077e800();
      pfVar8[3] = *pfVar6;
      pfVar8[4] = pfVar6[1];
      pfVar8[5] = pfVar6[2];
      local_14 = local_14 + 1;
    } while (local_14 < *(uint *)(*param_1 + 0x10));
  }
  iVar5 = (**(code **)(**(int **)(param_2 + 0x74) + 0xc))();
  param_1[1] = iVar5;
  iVar7 = FUN_00843ef0();
  if (iVar7 != 0) {
    param_1[3] = *(int *)(iVar7 + 0xb8);
  }
  param_1[2] = *(int *)(iVar5 + 0x164);
  ExceptionList = local_10;
  return param_1;
}

