
void FUN_00611ee0(int param_1,byte param_2)

{
  short sVar1;
  int iVar2;
  code *pcVar3;
  uint uVar4;
  short *psVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 *in_ECX;
  uint uVar8;
  short *psVar9;
  int *piVar10;
  int local_4c;
  uint local_44;
  uint local_3c;
  int local_38;
  int local_34;
  uint local_30;
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0091d6b2;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  in_ECX[4] = 0;
  if (7 < (uint)in_ECX[5]) {
    in_ECX = (undefined4 *)*in_ECX;
  }
  uVar8 = DAT_00fb11a8 & 1;
  *(undefined2 *)in_ECX = 0;
  if (uVar8 == 0) {
    DAT_00fb11a8 = DAT_00fb11a8 | 1;
    local_8 = 0;
    FUN_00813890(local_14);
    _atexit((_func_4879 *)&LAB_00bccec0);
  }
  local_8 = 0xffffffff;
  local_34 = param_1;
  FUN_0082ef00(&local_34);
  if ((local_38 != DAT_00fb11b0) && (iVar2 = *(int *)(local_38 + 0x10), iVar2 != 0)) {
    uVar8 = (uint)param_2;
    local_34 = 1;
    if (uVar8 < (uint)(*(int *)(iVar2 + 0x18) - *(int *)(iVar2 + 0x14) >> 2)) {
      iVar6 = *(int *)(*(int *)(iVar2 + 0x14) + uVar8 * 4);
      local_3c = *(int *)(iVar6 + 0x18) - *(int *)(iVar6 + 0x14) >> 2;
    }
    else {
      local_3c = 0;
    }
    local_44 = 0;
    if (local_3c != 0) {
      do {
        iVar6 = *(int *)(*(int *)(iVar2 + 0x14) + uVar8 * 4);
        if (local_44 < (uint)(*(int *)(iVar6 + 0x18) - *(int *)(iVar6 + 0x14) >> 2)) {
          piVar10 = *(int **)(*(int *)(iVar6 + 0x14) + local_44 * 4);
        }
        else {
          piVar10 = (int *)0x0;
        }
        uVar4 = (**(code **)(*piVar10 + 4))();
        if (((~-(uint)((uVar4 & 0x12100000) != 0x12100000) & (uint)piVar10) != 0) &&
           (*(int *)(iVar2 + 8) != 2)) {
          if (local_34 != 0) {
            if ((DAT_00fe5ae4 & 1) == 0) {
              DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
              local_8 = 1;
              FUN_00584c40(&DAT_00fe5ac4);
              _atexit((_func_4879 *)&LAB_00bcf390);
              local_8 = 0xffffffff;
            }
            local_34 = 0x2cc;
            FUN_005740f0(&local_34);
            if (local_4c == DAT_00fe5ac8) {
              pcVar3 = (code *)swi(3);
              (*pcVar3)();
              return;
            }
            psVar9 = (short *)(local_4c + 0x10);
            if (7 < *(uint *)(local_4c + 0x24)) {
              psVar9 = *(short **)psVar9;
            }
            psVar5 = psVar9;
            do {
              sVar1 = *psVar5;
              psVar5 = psVar5 + 1;
            } while (sVar1 != 0);
            FUN_00404300(psVar9,(int)psVar5 - (int)(psVar9 + 1) >> 1);
            local_34 = 0;
          }
          if ((DAT_00fc1094 & 1) == 0) {
            DAT_00fc1094 = DAT_00fc1094 | 1;
            local_8 = 2;
            FUN_0052f7e0();
            _atexit((_func_4879 *)&LAB_00bcdc80);
            local_8 = 0xffffffff;
          }
          iVar6 = FUN_005300f0();
          if (iVar6 != 0) {
            uVar7 = FUN_00612f00();
            local_8 = 3;
            FUN_004041f0(uVar7,0,0xffffffff);
            local_8 = 0xffffffff;
            if (7 < local_1c) {
              FUN_0089120c(local_30);
            }
            local_1c = 7;
            local_20 = 0;
            local_30 = local_30 & 0xffff0000;
          }
        }
        local_44 = local_44 + 1;
      } while (local_44 < local_3c);
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

