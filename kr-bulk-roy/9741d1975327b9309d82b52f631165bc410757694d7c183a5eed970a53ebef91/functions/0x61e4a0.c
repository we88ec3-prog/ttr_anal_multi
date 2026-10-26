
void FUN_0061e4a0(int param_1,byte param_2,byte param_3)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  undefined4 *puVar5;
  uint uVar6;
  int local_30;
  int local_2c;
  uint local_28;
  undefined4 *local_24;
  uint local_20;
  int local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093dd5c;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if ((DAT_00fab278 & 1) == 0) {
    DAT_00fab278 = DAT_00fab278 | 1;
    local_c = 0;
    FUN_00817da0(DAT_00d61f20 ^ (uint)&stack0xffffffc0);
    _atexit((_func_4879 *)&LAB_00bcced0);
  }
  local_c = 0xffffffff;
  local_24 = (undefined4 *)(uint)param_2;
  FUN_008195e0(&local_24);
  if (local_28 == DAT_00fab280) {
LAB_0061e52e:
    local_30 = 0;
  }
  else {
    FUN_008196d0();
    puVar5 = local_24;
    if (*(undefined4 **)(local_28 + 0x14) == local_24) {
      if ((param_3 != 0) || (*(int *)(local_28 + 0x18) == 0)) goto LAB_0061e52e;
      puVar5 = (undefined4 *)**(undefined4 **)(local_28 + 0x14);
    }
    local_30 = puVar5[4];
  }
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 1;
    FUN_004e1590();
    _atexit((_func_4879 *)&LAB_00bccc80);
    local_c = 0xffffffff;
  }
  if (((param_2 < 10) &&
      (local_2c = (uint)param_2 * 0x210 + DAT_00f94304, *(int *)(local_2c + 0x5c) != 0)) &&
     (local_2c != 0)) {
    local_2c = local_2c + 0x1d4;
  }
  else {
    local_2c = 0;
  }
  if (local_30 != 0) {
    if (local_2c != 0) {
      puVar5 = (undefined4 *)(param_1 + 0xf0);
      local_28 = 0;
      local_24 = (undefined4 *)CONCAT22(local_24._2_2_,(ushort)param_3);
      uVar4 = 0;
      while( true ) {
        do {
          if (((byte)local_28 < 4) && ((byte)(uVar4 + 1) < 0xb)) {
            uVar6 = (uint)*(ushort *)
                           (local_30 + 4 + ((local_28 & 0xff) * 0xb + (uVar4 + 1 & 0xff)) * 2);
          }
          else {
            uVar6 = 0;
          }
          local_20 = uVar6;
          FUN_00826280(&local_20);
          if ((local_1c == *(int *)(local_2c + 4)) ||
             (puVar1 = *(undefined4 **)(local_1c + 0x10), puVar1 == (undefined4 *)0x0)) {
            (**(code **)(*(int *)*puVar5 + 0x19c))(uVar6,1,local_24);
          }
          else {
            (**(code **)(*(int *)*puVar5 + 0x19c))(*puVar1,*(undefined1 *)(puVar1 + 1),local_24);
          }
          (**(code **)(*(int *)*puVar5 + 200))();
          uVar4 = uVar4 + 1;
          puVar5 = puVar5 + 1;
        } while (uVar4 < 6);
        local_28 = local_28 + 1;
        if (2 < local_28) break;
        uVar4 = 0;
      }
    }
    iVar3 = *(int *)(*(int *)(param_1 + 0x13c) + 0xcc);
    uVar4 = *(int *)(local_30 + 0x6c) - *(int *)(local_30 + 0x68) >> 3;
    if (iVar3 != 0) {
      FUN_00408920(iVar3,uVar4);
    }
    uVar6 = 0;
    if (uVar4 != 0) {
      do {
        iVar3 = *(int *)(*(int *)(param_1 + 0x13c) + 0xcc);
        if (((iVar3 == 0) || ((int)uVar6 < 0)) ||
           (*(int *)(iVar3 + 0xac) - *(int *)(iVar3 + 0xa8) >> 2 <= (int)uVar6)) {
          iVar3 = 0;
        }
        else {
          iVar3 = *(int *)(*(int *)(iVar3 + 0xa8) + uVar6 * 4);
        }
        puVar5 = (undefined4 *)(*(int *)(local_30 + 0x68) + uVar6 * 8);
        if ((iVar3 != 0) && (puVar5 != (undefined4 *)0x0)) {
          (**(code **)(**(int **)(iVar3 + 0x248) + 0x19c))(*puVar5,*(undefined1 *)(puVar5 + 1),2);
        }
        uVar6 = uVar6 + 1;
      } while (uVar6 < uVar4);
    }
    piVar2 = *(int **)(param_1 + 0x13c);
    puVar5 = (undefined4 *)piVar2[0x19];
    for (puVar1 = (undefined4 *)*puVar5; puVar1 != puVar5; puVar1 = (undefined4 *)*puVar1) {
      iVar3 = puVar1[2];
      if ((*(int *)(iVar3 + 0x60) != 0) && ((*(int **)(iVar3 + 0x1c))[2] != 6)) {
        (**(code **)(**(int **)(iVar3 + 0x1c) + 0x30))(iVar3);
      }
    }
    (**(code **)(*piVar2 + 0x128))();
    (**(code **)(**(int **)(param_1 + 0x13c) + 200))();
  }
  ExceptionList = local_14;
  return;
}

