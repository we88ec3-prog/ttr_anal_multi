
void FUN_0069a1c0(int param_1)

{
  ushort uVar1;
  ushort *puVar2;
  uint *puVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  uint *puVar8;
  uint local_40;
  uint local_3c;
  uint *local_38;
  int local_34;
  uint local_30;
  int local_2c;
  int local_28;
  int local_24;
  uint local_20;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0093c90a;
  local_14 = ExceptionList;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xffffffb0;
  ExceptionList = &local_14;
  uVar6 = *(undefined4 *)(DAT_00fb1318 + 0xbfe8);
  FUN_006dbd10(uVar6);
  FUN_006dbf20(uVar6,*(undefined4 *)(param_1 + 0x120));
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590(uVar4);
    _atexit((_func_4879 *)&LAB_00bccc80);
    local_c = 0xffffffff;
  }
  if (*(int *)(param_1 + 0x120) - 1U < 0xf) {
    local_38 = (uint *)(*(int *)(param_1 + 0x120) * 0x108 + DAT_00f94300);
  }
  else {
    local_38 = (uint *)0x0;
  }
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 1;
    FUN_004e1590(uVar4);
    _atexit((_func_4879 *)&LAB_00bccc80);
    local_c = 0xffffffff;
  }
  if (*(uint *)(param_1 + 0x120) < 10) {
    local_3c = DAT_00f94304 + *(uint *)(param_1 + 0x120) * 0x210;
    local_3c = -(uint)(*(int *)(local_3c + 0x5c) != 0) & local_3c;
  }
  else {
    local_3c = 0;
  }
  local_34 = 1;
  local_40 = 2;
  puVar3 = local_38;
  do {
    puVar8 = puVar3 + 4;
    if ((local_34 < 3) || (5 < local_34)) {
      if (local_34 - 1U < 0xf) {
        if ((puVar8 != (uint *)0x0) && (puVar3[6] != 0)) {
          if ((DAT_00f8d9a4 & 1) == 0) {
            DAT_00f8d9a4 = DAT_00f8d9a4 | 1;
            local_c = 2;
            FUN_0051c120();
            _atexit((_func_4879 *)&LAB_00bccc90);
            local_c = 0xffffffff;
          }
          local_30 = puVar3[5];
          FUN_008438c0(&local_30);
          if (((local_2c != DAT_00f8d91c) && (*(int *)(local_2c + 0x10) != 0)) &&
             (iVar5 = *(int *)(*(int *)(local_2c + 0x10) + 0x68), iVar5 != 0)) {
            uVar1 = *(ushort *)(iVar5 + 8);
            iVar5 = FUN_00404ba0();
            iVar5 = *(int *)(iVar5 + 0x6928);
            local_30 = (uint)uVar1;
            FUN_004a4cc0(&local_30);
            if (((local_28 == *(int *)(iVar5 + 0x14)) || (*(int *)(local_28 + 0x10) == 0)) ||
               (*(int *)(*(int *)(local_28 + 0x10) + 0xc) == 0)) goto LAB_0069a472;
          }
          local_20 = puVar3[6];
          local_1c = puVar3[7];
          iVar5 = FUN_00409560();
          FUN_004dd400(iVar5,&local_24,&local_20);
          if ((local_24 == *(int *)(iVar5 + 4)) || (iVar5 = *(int *)(local_24 + 0x18), iVar5 == 0))
          {
            if ((*(uint *)(local_3c + 0xf8) & local_40) == 0) {
              uVar6 = 0;
              uVar4 = 0;
LAB_0069a466:
              uVar7 = *puVar8;
              goto LAB_0069a469;
            }
          }
          else {
            puVar2 = *(ushort **)(iVar5 + 0x54);
            if (((*(uint *)(local_3c + 0xf8) & local_40) == 0) && (*(int *)(iVar5 + 0x24) == 0)) {
              if (puVar2 == (ushort *)0x0) {
                uVar6 = FUN_004dc850();
                uVar4 = *(uint *)(iVar5 + 0x30);
                goto LAB_0069a466;
              }
              if (*puVar2 == 0) {
                uVar6 = FUN_004dc850();
                uVar7 = *puVar8;
                uVar4 = *(uint *)(iVar5 + 0x30);
              }
              else {
                uVar6 = FUN_004dc850();
                uVar4 = (uint)(byte)puVar2[1];
                uVar7 = (uint)*puVar2;
              }
LAB_0069a469:
              FUN_006dc180(uVar7,uVar4,uVar6);
            }
          }
        }
      }
      else {
        FUN_006edb60(&DAT_00c0dddc,local_34);
      }
    }
LAB_0069a472:
    local_34 = local_34 + 1;
    local_40 = local_40 << 1 | (uint)((int)local_40 < 0);
    puVar3 = puVar8;
    if (0xf < local_34) {
      uVar4 = (uint)(ushort)local_38[0x40];
      if ((ushort)local_38[0x40] == 0) {
        uVar4 = *(int *)(param_1 + 0x120) + 31000;
      }
      FUN_006dc180(uVar4,*(undefined1 *)((int)local_38 + 0x102),0);
      (**(code **)(**(int **)(param_1 + 0xc4) + 200))();
      ExceptionList = local_14;
      return;
    }
  } while( true );
}

