
void FUN_0062b570(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  uint *puVar2;
  uint *puVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint auStack_3c [2];
  uint *puStack_34;
  uint uStack_30;
  uint local_2c;
  int local_28;
  int local_24;
  undefined4 local_20;
  void *local_14;
  undefined1 *puStack_10;
  undefined1 local_c;
  undefined3 uStack_b;
  
  puStack_10 = &LAB_00928c54;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_c = 0;
  uStack_b = 0;
  FUN_006d4dc0(param_2,param_3,DAT_00d61f20 ^ (uint)&stack0xffffffb8);
  local_2c = local_24 - local_28 >> 2;
  auStack_3c[1] = 0;
  if (local_2c != 0) {
    do {
      iVar4 = local_28;
      if ((DAT_00fdfb10 & 1) == 0) {
        DAT_00fdfb10 = DAT_00fdfb10 | 1;
        local_c = 1;
        FUN_00590760();
        _atexit((_func_4879 *)&LAB_00bce760);
        local_c = 0;
      }
      bVar1 = *(byte *)(iVar4 + 2 + auStack_3c[1] * 4);
      if ((DAT_00fdfb10 & 1) == 0) {
        DAT_00fdfb10 = DAT_00fdfb10 | 1;
        local_c = 2;
        FUN_00590760();
        _atexit((_func_4879 *)&LAB_00bce760);
        local_c = 0;
      }
      uVar7 = (uint)*(byte *)(iVar4 + auStack_3c[1] * 4);
      uVar5 = (uint)bVar1;
      auStack_3c[0] = uVar5 << 0x10 | uVar7;
      puVar2 = (uint *)*param_1;
      uVar6 = (int)(param_1[1] - (int)puVar2) >> 2;
      uStack_30 = 0;
      puVar3 = puVar2;
      if (uVar6 != 0) {
        do {
          puStack_34 = puVar3;
          if ((*puStack_34 == (uVar7 << 0x10 | uVar5)) || (*puStack_34 == auStack_3c[0]))
          goto LAB_0062b754;
          puStack_34 = puStack_34 + 1;
          uStack_30 = uStack_30 + 1;
          puVar3 = puStack_34;
        } while (uStack_30 < (uint)((int)(param_1[1] - (int)puVar2) >> 2));
      }
      puVar3 = (uint *)param_1[1];
      if ((auStack_3c < puVar3) && (puVar2 <= auStack_3c)) {
        if (puVar3 == (uint *)param_1[2]) {
          if (0x3ffffffe < uVar6) {
LAB_0062b78f:
                    /* WARNING: Subroutine does not return */
            FUN_0087db30("vector<T> too long");
          }
          uVar6 = uVar6 + 1;
          uVar5 = (int)param_1[2] - (int)puVar2 >> 2;
          if (uVar5 < uVar6) {
            if (0x3fffffff - (uVar5 >> 1) < uVar5) {
              uVar5 = 0;
            }
            else {
              uVar5 = uVar5 + (uVar5 >> 1);
            }
            if (uVar5 < uVar6) {
              uVar5 = uVar6;
            }
            FUN_00797980(uVar5);
          }
        }
        if ((undefined4 *)param_1[1] != (undefined4 *)0x0) {
          *(undefined4 *)param_1[1] =
               *(undefined4 *)(*param_1 + ((int)auStack_3c - (int)puVar2 >> 2) * 4);
        }
      }
      else {
        if (puVar3 == (uint *)param_1[2]) {
          if (0x3ffffffe < uVar6) goto LAB_0062b78f;
          uVar6 = uVar6 + 1;
          uVar5 = (int)param_1[2] - (int)puVar2 >> 2;
          if (uVar5 < uVar6) {
            if (0x3fffffff - (uVar5 >> 1) < uVar5) {
              uVar5 = 0;
            }
            else {
              uVar5 = uVar5 + (uVar5 >> 1);
            }
            if (uVar5 < uVar6) {
              uVar5 = uVar6;
            }
            FUN_00797980(uVar5);
          }
        }
        if ((uint *)param_1[1] != (uint *)0x0) {
          *(uint *)param_1[1] = auStack_3c[0];
        }
      }
      param_1[1] = param_1[1] + 4;
LAB_0062b754:
      auStack_3c[1] = auStack_3c[1] + 1;
    } while (auStack_3c[1] < local_2c);
  }
  if (local_28 != 0) {
    FUN_0089120c(local_28);
  }
  ExceptionList = local_14;
  return;
}

