
void FUN_007b3b30(int param_1)

{
  float fVar1;
  float fVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  int in_ECX;
  float local_8c;
  uint local_80;
  float local_7c;
  float fStack_78;
  float fStack_74;
  float fStack_70;
  float fStack_6c;
  float fStack_68;
  float fStack_64;
  float fStack_60;
  float fStack_5c;
  float fStack_58;
  float fStack_54;
  float fStack_50;
  undefined4 uStack_4c;
  float fStack_48;
  float fStack_44;
  float fStack_40;
  float fStack_3c;
  float fStack_38;
  float fStack_34;
  float fStack_30;
  undefined4 uStack_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093526c;
  local_14 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xffffff68;
  ExceptionList = &local_14;
  if (*(int *)(in_ECX + 4) != 0) {
    local_7c = (float)in_ECX;
    if ((DAT_00fb79e8 & 1) == 0) {
      DAT_00fb79e8 = DAT_00fb79e8 | 1;
      local_c = 0;
      FUN_00798de0(uVar3);
      _atexit((_func_4879 *)&LAB_00bcd2e0);
    }
    iVar5 = DAT_00fb76a8;
    local_28 = *(undefined4 *)(param_1 + 0x40);
    local_24 = *(undefined4 *)(param_1 + 0x44);
    local_20 = *(undefined4 *)(param_1 + 0x48);
    local_1c = 0;
    if ((DAT_00fb79e8 & 1) == 0) {
      DAT_00fb79e8 = DAT_00fb79e8 | 1;
      local_c = 1;
      FUN_00798de0(uVar3);
      _atexit((_func_4879 *)&LAB_00bcd2e0);
    }
    local_c = 0xffffffff;
    piVar4 = (int *)FUN_0079a5f0(&DAT_00fb76a8);
    (**(code **)(*piVar4 + 0xe8))(piVar4,0x8b,&local_80);
    fStack_68 = (float)(local_80 >> 0x10 & 0xff) * 0.003921569;
    fStack_64 = (float)(local_80 >> 8 & 0xff) * 0.003921569;
    fStack_60 = (float)(local_80 & 0xff) * 0.003921569;
    fStack_5c = (float)(local_80 >> 0x18) * 0.003921569;
    fStack_6c = (fStack_5c + *(float *)(param_1 + 0x30)) * 0.78431374;
    if (0.0 <= fStack_6c) {
      if (1.0 < fStack_6c) {
        fStack_6c = 1.0;
      }
    }
    else {
      fStack_6c = 0.0;
    }
    fStack_78 = (fStack_68 + *(float *)(param_1 + 0x24)) * 0.78431374;
    if (0.0 <= fStack_78) {
      if (1.0 < fStack_78) {
        fStack_78 = 1.0;
      }
    }
    else {
      fStack_78 = 0.0;
    }
    fVar2 = 0.0;
    fStack_70 = 1.0;
    fStack_74 = (fStack_64 + *(float *)(param_1 + 0x28)) * 0.78431374;
    if (0.0 <= fStack_74) {
      if (1.0 < fStack_74) {
        fStack_74 = 1.0;
      }
    }
    else {
      fStack_74 = 0.0;
    }
    fVar1 = (fStack_60 + *(float *)(param_1 + 0x2c)) * 0.78431374;
    if ((fVar1 < 0.0) || (fVar2 = fVar1, fVar1 <= 1.0)) {
      fStack_70 = fVar2;
    }
    fStack_48 = fStack_78;
    fStack_44 = fStack_74;
    fStack_3c = fStack_6c;
    fStack_58 = *(float *)(param_1 + 4);
    fStack_54 = *(float *)(param_1 + 8);
    fStack_50 = *(float *)(param_1 + 0xc);
    uStack_4c = *(undefined4 *)(param_1 + 0x10);
    fStack_40 = fStack_70;
    fStack_38 = fStack_58;
    fStack_34 = fStack_54;
    fStack_30 = fStack_50;
    uStack_2c = uStack_4c;
    iVar5 = FUN_0083ff20(iVar5 + 0x144,*(undefined4 *)(*(int *)((int)local_7c + 8) + 0x16c));
    if (((*(int *)(iVar5 + 4) != 0) &&
        ((**(code **)(**(int **)(iVar5 + 4) + 0x88))(*(int **)(iVar5 + 4),"vecLight",&local_28),
        *(int *)(iVar5 + 4) != 0)) &&
       ((**(code **)(**(int **)(iVar5 + 4) + 0x88))(*(int **)(iVar5 + 4),"lightColor",&fStack_38),
       *(int *)(iVar5 + 4) != 0)) {
      (**(code **)(**(int **)(iVar5 + 4) + 0x88))(*(int **)(iVar5 + 4),"ambientColor",&fStack_48);
    }
    fVar2 = fStack_44 + fStack_48 + fStack_40;
    if (fVar2 == 0.0) {
      local_8c = 0.1;
      local_7c = fVar2;
    }
    else {
      local_7c = fStack_34 + fStack_38 + fStack_30;
      local_8c = local_7c / fVar2;
    }
    if (local_8c <= 0.5) {
      if (local_8c < 0.0) {
        local_8c = 0.0;
      }
    }
    else {
      local_8c = 0.5;
    }
    if (*(int *)(iVar5 + 4) != 0) {
      (**(code **)(**(int **)(iVar5 + 4) + 0x78))(*(int **)(iVar5 + 4),"contrast",local_8c);
    }
  }
  ExceptionList = local_14;
  return;
}

