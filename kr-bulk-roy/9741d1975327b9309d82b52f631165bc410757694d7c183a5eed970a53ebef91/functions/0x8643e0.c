
void FUN_008643e0(int param_1)

{
  uint uVar1;
  uint *puVar2;
  uint uVar3;
  int iVar4;
  uint local_38 [3];
  undefined1 local_2c [4];
  uint *local_28;
  uint *local_24;
  uint *local_20;
  void *local_14;
  undefined1 *puStack_10;
  int local_c;
  
  puStack_10 = &LAB_0090e021;
  local_14 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xffffffb8;
  ExceptionList = &local_14;
  local_38[2] = *(uint *)(param_1 + 8);
  if (1 < local_38[2]) {
    puVar2 = (uint *)0x0;
    local_28 = (uint *)0x0;
    local_24 = (uint *)0x0;
    local_20 = (uint *)0x0;
    local_c = 0;
    local_38[1] = 0;
    if (local_38[2] != 0) {
      do {
        local_38[0] = 0;
        FUN_0083edb0(local_2c,local_38);
        if (local_38[0] == 0) {
LAB_008644aa:
          uVar3 = 0;
        }
        else {
          uVar3 = local_38[0] & 0xffff;
          puVar2 = local_24;
          if (((uint)((*(int *)(param_1 + 0x14) - *(int *)(param_1 + 0x10)) / 0x11c) <= uVar3) ||
             (*(uint *)(*(int *)(param_1 + 0x20) + uVar3 * 4) != local_38[0] >> 0x10))
          goto LAB_008644aa;
          uVar3 = uVar3 * 0x11c + *(int *)(param_1 + 0x10);
        }
        local_38[0] = uVar3;
        if (uVar3 != 0) {
          if ((local_38 < puVar2) && (local_28 <= local_38)) {
            iVar4 = (int)local_38 - (int)local_28;
            if (puVar2 == local_20) {
              FUN_00797930();
              puVar2 = local_24;
            }
            if (puVar2 != (uint *)0x0) {
              *puVar2 = local_28[iVar4 >> 2];
            }
          }
          else {
            if (puVar2 == local_20) {
              FUN_00797930();
              puVar2 = local_24;
            }
            if (puVar2 != (uint *)0x0) {
              *puVar2 = uVar3;
            }
          }
          puVar2 = puVar2 + 1;
          local_24 = puVar2;
        }
        local_38[1] = local_38[1] + 1;
      } while (local_38[1] < local_38[2]);
    }
    puVar2 = local_28;
    if (DAT_00fe3510 == (undefined *)0x0) {
      if ((DAT_00fe5ac0 & 1) == 0) {
        DAT_00fe5ac0 = DAT_00fe5ac0 | 1;
        local_c._0_1_ = 1;
        FUN_00842f30(&DAT_00fe4b60);
        local_c._0_1_ = 2;
        FUN_008762c0();
        _atexit((_func_4879 *)&LAB_00bd0fc0);
        local_c = (uint)local_c._1_3_ << 8;
      }
      DAT_00fe3510 = &DAT_00fe4b60;
    }
    FUN_00877c20(DAT_00fe3510,&local_28,param_1 + 0x44);
    if (puVar2 != (uint *)0x0) {
      FUN_0089120c(puVar2,uVar1);
    }
  }
  ExceptionList = local_14;
  return;
}

