
void FUN_004cde30(float param_1)

{
  short *psVar1;
  int iVar2;
  undefined4 *puVar3;
  float *pfVar4;
  int *in_ECX;
  float fVar5;
  float fVar6;
  float fVar7;
  float10 fVar8;
  undefined1 auStack_7c [4];
  float local_78;
  float local_74;
  float local_70;
  float local_6c;
  float local_68;
  float fStack_64;
  float fStack_60;
  float fStack_5c;
  float local_58;
  undefined1 local_54 [40];
  undefined1 auStack_2c [4];
  float fStack_28;
  float fStack_24;
  float fStack_20;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0093799e;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_7c;
  ExceptionList = &local_14;
  psVar1 = (short *)in_ECX[0x10e];
  if ((((psVar1 != (short *)0x0) && (in_ECX[0x10d] != 0)) && (*psVar1 != *(short *)in_ECX[0x10f]))
     && ((*(int *)(psVar1 + 0xc) != 0 &&
         (iVar2 = FUN_00434740(DAT_00d61f20 ^ (uint)&stack0xffffff78), *(int *)(iVar2 + 0x40) != 0))
        )) {
    FUN_00797e10();
    local_58 = local_70 - (float)in_ECX[0x28];
    local_78 = local_68 - (float)in_ECX[0x2a];
    local_74 = local_78 * local_78 +
               local_58 * local_58 +
               (local_6c - (float)in_ECX[0x29]) * (local_6c - (float)in_ECX[0x29]);
    if (400.0 <= local_74) {
      FUN_00434740();
      iVar2 = FUN_0079a860();
      if (iVar2 == 0) goto LAB_004cdf3e;
    }
    if (local_74 < 22500.0) {
      FUN_004cedb0(in_ECX);
    }
  }
LAB_004cdf3e:
  in_ECX[0x110] = (int)((float)in_ECX[0x110] + param_1);
  if (0.02 < param_1) {
    if ((DAT_00fb79e8 & 1) == 0) {
      DAT_00fb79e8 = DAT_00fb79e8 | 1;
      local_c = 0;
      FUN_00798de0();
      _atexit((_func_4879 *)&LAB_00bcd2e0);
      local_c = 0xffffffff;
    }
    if (DAT_00fb76e8 != 0) {
      puVar3 = (undefined4 *)(**(code **)(**(int **)(DAT_00fb76e8 + 4) + 0x24))(local_54);
      local_68 = (float)*puVar3;
      fStack_64 = (float)puVar3[1];
      fStack_60 = (float)puVar3[2];
      (**(code **)(*(int *)(in_ECX[0x57] + 4) + 8))(auStack_2c);
      local_70 = fStack_64 - fStack_28;
      local_6c = fStack_60 - fStack_24;
      local_68 = fStack_5c - fStack_20;
      local_78 = local_68 * local_68 + local_70 * local_70 + local_6c * local_6c;
      fVar8 = (float10)FUN_008ff870();
      local_78 = (float)fVar8;
      if ((200.0 < local_78) && ((float)in_ECX[0x110] < 0.05)) {
        FUN_007a5bb0();
        goto LAB_004ce241;
      }
    }
  }
  local_74 = (float)in_ECX[0x110];
  in_ECX[0x110] = 0;
  FUN_004c87d0(local_74);
  (**(code **)(*in_ECX + 100))();
  if ((in_ECX[0x109] != 0) && (*(int *)(in_ECX[0x109] + 0x24) != 0)) {
    FUN_007bd8d0(local_74);
  }
  if (in_ECX[0x10a] == 0) {
    iVar2 = (**(code **)(*in_ECX + 0x70))();
    if (iVar2 < 0x1e) {
      in_ECX[0x10a] = 1;
    }
  }
  else {
    iVar2 = (**(code **)(*in_ECX + 0x70))();
    if (0x28 < iVar2) {
      in_ECX[0x10a] = 0;
    }
  }
  iVar2 = in_ECX[0x10b];
  if (iVar2 != 0) {
    local_78 = (float)in_ECX[0x2d];
    *(float *)(iVar2 + 0x10) = local_78;
    if (*(int *)(iVar2 + 4) != 0) {
      FUN_0077ef50(local_78,local_78,local_78);
    }
    pfVar4 = (float *)(**(code **)(*in_ECX + 0x4c))();
    if ((in_ECX[0x57] == 0) || (in_ECX[0xdc] == 0)) {
      fVar5 = *pfVar4;
      fVar6 = pfVar4[1];
      fVar7 = pfVar4[2];
    }
    else {
      FUN_007a8630(0x40800000);
      fVar5 = fStack_28;
      fVar6 = fStack_24;
      fVar7 = fStack_20;
    }
    iVar2 = in_ECX[0x10b];
    *(float *)(iVar2 + 0x24) = fVar5;
    *(float *)(iVar2 + 0x28) = fVar6;
    *(float *)(iVar2 + 0x2c) = fVar7;
    FUN_007beb30(in_ECX[0x10b],local_74);
  }
  iVar2 = in_ECX[0x10c];
  if (iVar2 != 0) {
    local_78 = (float)in_ECX[0x2d];
    *(float *)(iVar2 + 0x10) = local_78;
    if (*(int *)(iVar2 + 4) != 0) {
      FUN_0077ef50(local_78,local_78,local_78);
    }
    pfVar4 = (float *)(**(code **)(*in_ECX + 0x4c))();
    if ((in_ECX[0x57] == 0) || (in_ECX[0xdc] == 0)) {
      fStack_28 = *pfVar4;
      fStack_24 = pfVar4[1];
      fStack_20 = pfVar4[2];
    }
    else {
      FUN_007a8630(0x40800000);
    }
    iVar2 = in_ECX[0x10c];
    *(float *)(iVar2 + 0x24) = fStack_28;
    *(float *)(iVar2 + 0x28) = fStack_24;
    *(float *)(iVar2 + 0x2c) = fStack_20;
    FUN_007beb30(in_ECX[0x10c],local_74);
  }
LAB_004ce241:
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_7c);
  return;
}

