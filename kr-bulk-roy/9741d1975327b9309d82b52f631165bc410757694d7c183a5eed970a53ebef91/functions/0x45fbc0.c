
void FUN_0045fbc0(void)

{
  short sVar1;
  code *pcVar2;
  uint uVar3;
  uint uVar4;
  short *psVar5;
  undefined4 uVar6;
  int in_ECX;
  short *psVar7;
  int iVar8;
  int iVar9;
  int local_8c;
  int local_88;
  uint local_84;
  undefined4 local_80;
  int local_7c;
  int local_78;
  uint local_74;
  uint local_70;
  undefined4 local_60;
  uint local_5c;
  uint local_54;
  undefined4 local_44;
  uint local_40;
  uint local_38;
  undefined4 local_28;
  uint local_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00931674;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&local_8c;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xffffff68;
  ExceptionList = &local_14;
  iVar8 = *(int *)(in_ECX + 4);
  uVar3 = (*(int *)(iVar8 + 0x108) - *(int *)(iVar8 + 0x104)) / 0x18;
  local_74 = uVar3;
  if (uVar3 != 0) {
    iVar8 = *(int *)(*(int *)(iVar8 + 0xf8) + 0xcc);
    local_88 = in_ECX;
    if (iVar8 != 0) {
      FUN_00408920(iVar8,uVar3);
    }
    local_84 = 0;
    if (uVar3 != 0) {
      local_8c = 0;
      do {
        iVar8 = *(int *)(*(int *)(*(int *)(in_ECX + 4) + 0xf8) + 0xcc);
        if (((iVar8 == 0) || ((int)local_84 < 0)) ||
           (*(int *)(iVar8 + 0xac) - *(int *)(iVar8 + 0xa8) >> 2 <= (int)local_84)) {
          iVar8 = 0;
        }
        else {
          iVar8 = *(int *)(*(int *)(iVar8 + 0xa8) + local_84 * 4);
        }
        iVar9 = *(int *)(*(int *)(in_ECX + 4) + 0x104) + local_8c;
        if ((DAT_00f8d9a4 & 1) == 0) {
          DAT_00f8d9a4 = DAT_00f8d9a4 | 1;
          local_c = 0;
          FUN_0051c120(uVar4);
          _atexit((_func_4879 *)&LAB_00bccc90);
          local_c = 0xffffffff;
        }
        local_80 = *(undefined4 *)(iVar9 + 8);
        FUN_008438c0(&local_80);
        if (local_7c == DAT_00f8d91c) {
          iVar9 = 0;
        }
        else {
          iVar9 = *(int *)(local_7c + 0x10);
        }
        local_5c = 7;
        local_60 = 0;
        local_70 = local_70 & 0xffff0000;
        FUN_004026e0(iVar9,0,0xffffffff);
        local_c._0_1_ = 1;
        local_c._1_3_ = 0;
        if (*(char *)(*(int *)(*(int *)(local_88 + 4) + 0x104) + 0x14 + local_8c) == '\0') {
          *(undefined4 *)(iVar8 + 0x154) = 0xffff2222;
          if ((DAT_00fe5ae4 & 1) == 0) {
            DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
            local_c._0_1_ = 2;
            local_c._1_3_ = 0;
            FUN_00584c40(&DAT_00fe5ac4);
            _atexit((_func_4879 *)&LAB_00bcf390);
          }
          local_c._0_1_ = 1;
          local_80 = 0x2f0;
          FUN_005740f0(&local_80);
          if (local_78 == DAT_00fe5ac8) {
            pcVar2 = (code *)swi(3);
            (*pcVar2)();
            return;
          }
          psVar7 = (short *)(local_78 + 0x10);
          if (7 < *(uint *)(local_78 + 0x24)) {
            psVar7 = *(short **)psVar7;
          }
          local_40 = 7;
          local_44 = 0;
          local_54 = local_54 & 0xffff0000;
          psVar5 = psVar7;
          do {
            sVar1 = *psVar5;
            psVar5 = psVar5 + 1;
          } while (sVar1 != 0);
          FUN_00402160(psVar7,(int)psVar5 - (int)(psVar7 + 1) >> 1);
          local_c._0_1_ = 3;
          uVar6 = FUN_00460810();
          local_c = CONCAT31(local_c._1_3_,4);
          FUN_00402800(uVar6);
          if (7 < local_24) {
            FUN_0089120c(local_38);
          }
          local_c._0_1_ = 1;
          local_24 = 7;
          local_28 = 0;
          local_38 = local_38 & 0xffff0000;
          if (7 < local_40) {
            FUN_0089120c(local_54);
          }
          local_40 = 7;
          local_44 = 0;
          local_54 = local_54 & 0xffff0000;
        }
        else {
          *(undefined4 *)(iVar8 + 0x154) = 0xffffffff;
        }
        FUN_00757710();
        (**(code **)(**(int **)(iVar8 + 0x248) + 0x1ac))
                  (*(undefined4 *)(iVar9 + 0x20),*(undefined4 *)(iVar9 + 0x1c),0,0,
                   *(undefined4 *)(*(int *)(*(int *)(local_88 + 4) + 0x104) + 0xc + local_8c));
        local_c = 0xffffffff;
        if (7 < local_5c) {
          FUN_0089120c(local_70);
        }
        local_8c = local_8c + 0x18;
        local_84 = local_84 + 1;
        local_5c = 7;
        local_60 = 0;
        local_70 = local_70 & 0xffff0000;
        in_ECX = local_88;
      } while (local_84 < local_74);
    }
    FUN_00749920(*(undefined4 *)(*(int *)(in_ECX + 4) + 0xf8));
    (**(code **)(**(int **)(*(int *)(in_ECX + 4) + 0xf8) + 200))();
    (**(code **)(**(int **)(in_ECX + 4) + 0xd0))();
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&local_8c);
  return;
}

