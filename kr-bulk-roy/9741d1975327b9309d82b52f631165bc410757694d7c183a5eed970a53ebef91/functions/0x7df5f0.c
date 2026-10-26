
void FUN_007df5f0(int *param_1)

{
  int iVar1;
  int *piVar2;
  int in_ECX;
  uint uVar3;
  undefined4 *puVar4;
  int unaff_EDI;
  uint uVar5;
  int iVar6;
  int iVar7;
  int local_7c;
  int iStack_78;
  int *piStack_74;
  undefined4 *puStack_70;
  int *local_68;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  uint local_28;
  undefined4 local_24;
  void *pvStack_20;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093799e;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&local_7c;
  ExceptionList = &local_14;
  local_28 = 0;
  local_2c = 0;
  local_30 = 0;
  local_34 = 0;
  local_68 = param_1;
  local_3c = 0;
  local_40 = 0;
  local_44 = 0;
  local_48 = 0;
  local_50 = 0;
  local_54 = 0;
  local_58 = 0;
  local_5c = 0;
  local_24 = 0x3f800000;
  local_38 = 0x3f800000;
  local_4c = 0x3f800000;
  local_60 = 0x3f800000;
  local_7c = in_ECX;
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    local_c = 0;
    FUN_00798de0(DAT_00d61f20 ^ (uint)&stack0xffffff78);
    _atexit((_func_4879 *)&LAB_00bcd2e0);
  }
  local_c = 0xffffffff;
  piVar2 = (int *)FUN_0079a5f0(&DAT_00fb76a8);
  (**(code **)(*piVar2 + 0xb0))(piVar2,0x100,&local_60);
  FUN_007f3540();
  iVar1 = (*(int *)(in_ECX + 0x1c) - *(int *)(in_ECX + 0x18)) / 0x14;
  if (iVar1 != 0) {
    iVar7 = 0;
    iStack_78 = iVar1;
    do {
      puVar4 = (undefined4 *)(*(int *)(in_ECX + 0x18) + iVar7);
      puStack_70 = puVar4;
      (**(code **)(*param_1 + 0x114))(*puVar4);
      iVar1 = (int)(puVar4[2] - puVar4[1]) / 0x18;
      if (iVar1 != 0) {
        iVar6 = 0;
        local_7c = iVar1;
        do {
          puVar4 = (undefined4 *)(puVar4[1] + iVar6);
          (**(code **)(*param_1 + 0x11c))(*puVar4);
          uVar3 = 0;
          uVar5 = (int)(puVar4[3] - puVar4[2]) >> 2;
          if (uVar5 != 0) {
            do {
              FUN_007f39f0(*(undefined4 *)(puVar4[2] + uVar3 * 4),*(undefined4 *)(unaff_EDI + 4));
              uVar3 = uVar3 + 1;
            } while (uVar3 < uVar5);
          }
          iVar1 = *(int *)(unaff_EDI + 4);
          if (((*(int *)(iVar1 + 4) != 0) && (*(int *)(iVar1 + 8) != 0)) &&
             ((FUN_007f33a0(), *(uint *)(iVar1 + 0x14) <= *(uint *)(iVar1 + 0x24) ||
              (*(uint *)(iVar1 + 0x1c) <= *(uint *)(iVar1 + 0x2c))))) {
            *(undefined4 *)(iVar1 + 0x2c) = 0;
            *(undefined4 *)(iVar1 + 0x24) = 0;
          }
          FUN_007f3540();
          iVar6 = iVar6 + 0x18;
          local_7c = local_7c + -1;
          puVar4 = puStack_70;
          param_1 = piStack_74;
        } while (local_7c != 0);
        local_7c = 0;
        in_ECX = unaff_EDI;
      }
      iVar7 = iVar7 + 0x14;
      iStack_78 = iStack_78 + -1;
    } while (iStack_78 != 0);
  }
  iVar1 = *(int *)(in_ECX + 4);
  if (((*(int *)(iVar1 + 4) != 0) && (*(int *)(iVar1 + 8) != 0)) &&
     ((FUN_007f33a0(), *(uint *)(iVar1 + 0x14) <= *(uint *)(iVar1 + 0x24) ||
      (*(uint *)(iVar1 + 0x1c) <= *(uint *)(iVar1 + 0x2c))))) {
    *(undefined4 *)(iVar1 + 0x2c) = 0;
    *(undefined4 *)(iVar1 + 0x24) = 0;
  }
  ExceptionList = pvStack_20;
  __security_check_cookie(local_28 ^ (uint)&stack0xffffff78);
  return;
}

