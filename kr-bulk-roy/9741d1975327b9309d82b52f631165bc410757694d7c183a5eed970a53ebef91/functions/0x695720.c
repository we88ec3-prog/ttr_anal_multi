
void FUN_00695720(void)

{
  undefined4 *puVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  undefined4 uVar7;
  int in_ECX;
  uint uVar8;
  short *psVar9;
  int iVar10;
  uint uVar11;
  int local_3c;
  uint local_38;
  int local_28;
  int local_24;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_009484f4;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if ((DAT_00fc7f1c & 1) == 0) {
    DAT_00fc7f1c = DAT_00fc7f1c | 1;
    local_c = 0;
    FUN_0053c300(DAT_00d61f20 ^ (uint)&stack0xffffffb8);
    _atexit(FUN_00bce1d0);
  }
  iVar3 = DAT_00fcdddc;
  local_c = 0xffffffff;
  if (DAT_00fcdddc != 0) {
    puVar1 = (undefined4 *)(DAT_00fcdddc + 4);
    FUN_00695aa0(&local_28,puVar1);
    local_c = 1;
    uVar11 = local_24 - local_28 >> 1;
    iVar4 = FUN_0053c0b0();
    iVar10 = *(int *)(*(int *)(in_ECX + 0x80) + 0xcc);
    if (iVar10 != 0) {
      FUN_00408920(iVar10,iVar4 + uVar11);
    }
    iVar10 = 0;
    local_38 = 0;
    if (uVar11 != 0) {
      do {
        sVar2 = *(short *)(local_28 + local_38 * 2);
        psVar9 = (short *)*puVar1;
        uVar5 = *(int *)(iVar3 + 8) - (int)psVar9 >> 1;
        uVar8 = 0;
        if (uVar5 != 0) {
          do {
            if (*psVar9 == sVar2) {
              if ((DAT_00fb1378 & 1) == 0) {
                DAT_00fb1378 = DAT_00fb1378 | 1;
                local_c._0_1_ = 2;
                FUN_00539c20();
                _atexit((_func_4879 *)&LAB_00bccfb0);
                local_c = CONCAT31(local_c._1_3_,1);
              }
              iVar4 = FUN_0053a9d0(sVar2);
              if (iVar4 != 0) {
                iVar10 = iVar10 + 1;
                FUN_00695560(local_38);
                uVar5 = 0;
                iVar6 = *(int *)(iVar4 + 0x2c) - *(int *)(iVar4 + 0x28) >> 2;
                if (iVar6 != 0) {
                  local_3c = iVar10;
                  if (iVar6 == 0) goto LAB_00695910;
                  do {
                    iVar6 = *(int *)(*(int *)(iVar4 + 0x28) + uVar5 * 4);
                    if ((*(char *)(iVar6 + 10) != '\0') && (iVar6 != 0)) {
                      iVar6 = *(int *)(*(int *)(in_ECX + 0x80) + 0xcc);
                      if ((iVar6 == 0) ||
                         ((iVar10 < 0 ||
                          (iVar10 = local_3c,
                          *(int *)(iVar6 + 0xac) - *(int *)(iVar6 + 0xa8) >> 2 <= local_3c)))) {
                        uVar7 = 0;
                      }
                      else {
                        uVar7 = *(undefined4 *)(*(int *)(iVar6 + 0xa8) + local_3c * 4);
                      }
                      iVar10 = iVar10 + 1;
                      FUN_00695100(uVar7);
                      local_3c = iVar10;
                    }
LAB_00695910:
                    uVar5 = uVar5 + 1;
                  } while (uVar5 < (uint)(*(int *)(iVar4 + 0x2c) - *(int *)(iVar4 + 0x28) >> 2));
                }
              }
              break;
            }
            uVar8 = uVar8 + 1;
            psVar9 = psVar9 + 1;
          } while (uVar8 < uVar5);
        }
        local_38 = local_38 + 1;
      } while (local_38 < uVar11);
    }
    FUN_00749920(*(undefined4 *)(in_ECX + 0x80));
    (**(code **)(**(int **)(in_ECX + 0x80) + 200))();
    if (local_28 != 0) {
      FUN_0089120c(local_28);
    }
  }
  ExceptionList = local_14;
  return;
}

