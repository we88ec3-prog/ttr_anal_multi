
void FUN_007f80a0(int *param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  float fVar5;
  int in_ECX;
  float fVar6;
  int local_78;
  int local_74;
  int local_70;
  int local_6c;
  int local_68;
  int local_64;
  uint local_60;
  float local_5c;
  undefined1 local_58 [32];
  undefined1 local_38 [24];
  float local_20;
  uint local_1c;
  uint local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0093214c;
  local_10 = ExceptionList;
  local_18 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_64 = in_ECX;
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    local_8 = 0;
    FUN_00798de0(local_18);
    _atexit((_func_4879 *)&LAB_00bcd2e0);
    if ((DAT_00fb79e8 & 1) == 0) {
      DAT_00fb79e8 = DAT_00fb79e8 | 1;
      local_8 = 1;
      FUN_00798de0();
      _atexit((_func_4879 *)&LAB_00bcd2e0);
    }
  }
  local_8 = 0xffffffff;
  (**(code **)(**(int **)(in_ECX + 0x7c) + 0x44))(*(int **)(in_ECX + 0x7c),0,local_38);
  (**(code **)(**(int **)(in_ECX + 0x7c) + 0x4c))(*(int **)(in_ECX + 0x7c),0,&local_6c,0,0);
  (**(code **)(*param_1 + 0x44))(param_1,0,local_58);
  (**(code **)(*param_1 + 0x4c))(param_1,0,&local_78,0,0);
  local_5c = (float)local_78 / (float)local_6c;
  local_70 = local_74;
  local_60 = 0;
  fVar5 = local_20;
  if (local_1c != 0) {
    do {
      uVar2 = local_60;
      fVar6 = 0.0;
      local_5c = 0.0;
      if (fVar5 != 0.0) {
        iVar3 = FUN_008fed10();
        do {
          iVar4 = FUN_008fed10();
          uVar1 = *(uint *)(local_70 + ((iVar3 * local_78 >> 2) + iVar4) * 4);
          iVar4 = (uVar2 * local_6c >> 2) + (int)fVar6;
          *(uint *)(local_68 + iVar4 * 4) =
               ((uVar1 >> 0x10 & 0xff | (int)*(char *)(local_68 + 3 + iVar4 * 4) << 8) << 8 |
               uVar1 >> 8 & 0xff) << 8 | uVar1 & 0xff;
          fVar6 = (float)((int)fVar6 + 1);
          fVar5 = local_20;
          local_5c = fVar6;
        } while ((uint)fVar6 < (uint)local_20);
      }
      local_60 = uVar2 + 1;
      in_ECX = local_64;
    } while (local_60 < local_1c);
  }
  (**(code **)(*param_1 + 0x50))(param_1,0);
  (**(code **)(**(int **)(in_ECX + 0x7c) + 0x50))(*(int **)(in_ECX + 0x7c),0);
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}

