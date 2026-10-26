
void FUN_007fcfa0(undefined4 *param_1,int *param_2)

{
  int *piVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  void *pvVar5;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  void *local_54;
  uint local_50;
  int *local_4c;
  int *local_48;
  int *local_44;
  undefined1 local_40 [16];
  size_t local_30;
  undefined1 local_28 [16];
  uint local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00934656;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_44 = param_2;
  local_14 = uVar2;
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    local_8 = 0;
    FUN_00798de0(uVar2);
    _atexit((_func_4879 *)&LAB_00bcd2e0);
  }
  local_8 = 0xffffffff;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fb76ec);
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    local_8 = 1;
    FUN_00798de0(uVar2);
    _atexit((_func_4879 *)&LAB_00bcd2e0);
    local_8 = 0xffffffff;
  }
  piVar3 = (int *)FUN_0079a5f0(&DAT_00fb76a8);
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    local_8 = 2;
    FUN_00798de0(uVar2);
    _atexit((_func_4879 *)&LAB_00bcd2e0);
    local_8 = 0xffffffff;
    if ((DAT_00fb79e8 & 1) == 0) {
      DAT_00fb79e8 = DAT_00fb79e8 | 1;
      local_8 = 3;
      FUN_00798de0();
      _atexit((_func_4879 *)&LAB_00bcd2e0);
      local_8 = 0xffffffff;
    }
  }
  piVar1 = DAT_00fb76a8;
  iVar4 = (**(code **)(*piVar3 + 0xa4))(piVar3);
  if (-1 < iVar4) {
    local_84 = 0;
    local_80 = 0;
    local_7c = 0;
    local_78 = 0;
    local_74 = 0;
    local_70 = 0;
    local_5c = 1;
    local_6c = 0x3f800000;
    local_68 = 0x3f800000;
    local_64 = 0x3f800000;
    local_60 = 0x3f800000;
    (**(code **)(*local_44 + 0x24))(&local_84,piVar1);
    (**(code **)(*piVar1 + 0xc))(1,1,1);
    (**(code **)(*piVar3 + 0xa8))(piVar3);
  }
  local_58 = 0;
  local_50 = 0;
  (**(code **)(*piVar3 + 0x194))(piVar3,0,&local_4c,&local_58,&local_50);
  if (local_4c != (int *)0x0) {
    (**(code **)(*piVar3 + 0x1a4))(piVar3,&local_48);
    if (local_48 != (int *)0x0) {
      param_1[3] = local_50;
      (**(code **)(*local_4c + 0x34))(local_4c,local_40);
      (**(code **)(*local_48 + 0x34))(local_48,local_28);
      local_54 = (void *)0x0;
      iVar4 = (**(code **)(*local_4c + 0x2c))(local_4c,0,0,&local_54,0);
      if ((-1 < iVar4) && (local_54 != (void *)0x0)) {
        pvVar5 = (void *)FUN_0087dc3d(local_30);
        *param_1 = pvVar5;
        FID_conflict__memcpy(pvVar5,local_54,local_30);
        (**(code **)(*local_4c + 0x30))(local_4c);
      }
      local_44 = (int *)0x0;
      iVar4 = (**(code **)(*local_48 + 0x2c))(local_48,0,0,&local_44,0);
      if ((-1 < iVar4) && (local_44 != (int *)0x0)) {
        pvVar5 = (void *)FUN_0087dc3d(local_18 & 0xfffffffe);
        param_1[1] = pvVar5;
        FID_conflict__memcpy(pvVar5,local_44,local_18);
        (**(code **)(*local_48 + 0x30))(local_48);
      }
      (**(code **)(*piVar3 + 0x168))(piVar3,param_1 + 5);
      param_1[4] = local_30 / local_50;
      param_1[2] = local_18 >> 1;
      (**(code **)(*local_48 + 8))(local_48);
    }
    (**(code **)(*local_4c + 8))(local_4c);
  }
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    local_8 = 4;
    FUN_00798de0();
    _atexit((_func_4879 *)&LAB_00bcd2e0);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fb76ec);
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

