
undefined4
FUN_004fc250(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,char param_5)

{
  undefined4 *puVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  int iVar7;
  undefined4 *puVar8;
  uint uVar9;
  undefined4 uVar10;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  int local_3c;
  int local_38;
  undefined4 local_34;
  undefined4 *local_2c;
  uint local_24;
  int local_20;
  uint local_1c;
  int local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009367da;
  local_10 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_004d3610(*(undefined4 *)(*(int *)(param_4 + 4) + 4));
  *(int *)(*(int *)(param_4 + 4) + 4) = *(int *)(param_4 + 4);
  *(undefined4 *)*(undefined4 *)(param_4 + 4) = *(undefined4 *)(param_4 + 4);
  *(int *)(*(int *)(param_4 + 4) + 8) = *(int *)(param_4 + 4);
  *(undefined4 *)(param_4 + 8) = 0;
  iVar4 = FUN_004fb960(param_2);
  if (iVar4 == 0) {
    ExceptionList = local_10;
    return 0;
  }
  local_18 = iVar4;
  if ((DAT_00f8d9a4 & 1) == 0) {
    DAT_00f8d9a4 = DAT_00f8d9a4 | 1;
    local_8 = 0;
    FUN_0051c120(uVar3);
    _atexit((_func_4879 *)&LAB_00bccc90);
    local_8 = 0xffffffff;
  }
  local_24 = *(int *)(iVar4 + 0x30) - *(int *)(iVar4 + 0x2c) >> 3;
  param_1 = 0;
  if (local_24 != 0) {
    do {
      puVar1 = (undefined4 *)(*(int *)(iVar4 + 0x2c) + param_1 * 8);
      local_20 = FUN_0051d700(*puVar1);
      if (local_20 != 0) {
        switch(*(undefined4 *)(local_20 + 8)) {
        case 1:
          break;
        case 2:
          break;
        case 3:
        case 4:
        case 0x1b:
          break;
        default:
          break;
        case 9:
        case 10:
          break;
        case 0xb:
        case 0x19:
          break;
        case 0x11:
        case 0x12:
        case 0x13:
        case 0x28:
        case 0x29:
        case 0x2a:
          break;
        case 0x1f:
          break;
        case 0x2b:
        }
        if ((DAT_00fb9390 & 1) == 0) {
          DAT_00fb9390 = DAT_00fb9390 | 1;
          local_8 = 1;
          FUN_0044ad70();
          _atexit((_func_4879 *)&LAB_00bcd610);
          local_8 = 0xffffffff;
        }
        puVar5 = (undefined4 *)DAT_00fb9398[1];
        uVar10 = *puVar1;
        cVar2 = *(char *)((int)puVar5 + 0x15);
        puVar8 = puVar5;
        while (cVar2 == '\0') {
          if ((int)puVar8[3] < 0xb) {
            puVar8 = (undefined4 *)puVar8[2];
          }
          else {
            puVar8 = (undefined4 *)*puVar8;
          }
          cVar2 = *(char *)((int)puVar8 + 0x15);
        }
        puVar8 = DAT_00fb9398;
        if (*(char *)((int)puVar5 + 0x15) == '\0') {
          do {
            if ((int)puVar5[3] < 10) {
              puVar6 = (undefined4 *)puVar5[2];
            }
            else {
              puVar6 = (undefined4 *)*puVar5;
              puVar8 = puVar5;
            }
            puVar5 = puVar6;
          } while (*(char *)((int)puVar6 + 0x15) == '\0');
          if (puVar8 != DAT_00fb9398) {
            iVar4 = puVar8[4];
            FUN_00404c10(uVar10);
            iVar7 = FUN_0051d700(uVar10);
            if ((iVar7 != 0) &&
               (((int)(uint)*(byte *)(iVar4 + 1) < *(int *)(iVar7 + 0x58) ||
                ((int)(uint)*(byte *)(iVar4 + 2) < *(int *)(iVar7 + 0x5c))))) goto LAB_004fc58d;
          }
        }
        if ((DAT_00fb9390 & 1) == 0) {
          DAT_00fb9390 = DAT_00fb9390 | 1;
          local_8 = 4;
          FUN_0044ad70();
          _atexit((_func_4879 *)&LAB_00bcd610);
          local_8 = 0xffffffff;
        }
        puVar5 = DAT_00fb9398;
        uVar10 = *puVar1;
        FUN_0044af30();
        if (local_2c != puVar5) {
          local_1c = (uint)*(ushort *)(local_2c[4] + 1);
          local_4c = 0;
          local_48 = 0;
          local_44 = 0;
          local_8 = 5;
          FUN_0044ab70(&local_1c);
          local_3c = 0;
          local_38 = 0;
          local_34 = 0;
          local_8 = CONCAT31(local_8._1_3_,6);
          FUN_0044aa10(&local_4c);
          FUN_00404c10(uVar10);
          iVar4 = FUN_0051d700(uVar10);
          if (iVar4 == 0) {
LAB_004fc4f1:
            FUN_007838f0();
            local_8 = 0xffffffff;
            FUN_007838f0();
            goto LAB_004fc58d;
          }
          uVar3 = 0;
          uVar9 = local_38 - local_3c >> 1;
          if (uVar9 != 0) {
            do {
              if ((uint)*(ushort *)(local_3c + uVar3 * 2) == *(uint *)(iVar4 + 4))
              goto LAB_004fc4f1;
              uVar3 = uVar3 + 1;
            } while (uVar3 < uVar9);
          }
          FUN_007838f0();
          local_8 = 0xffffffff;
          FUN_007838f0();
        }
        if (param_5 != '\0') {
          FUN_0040f060();
          iVar4 = (**(code **)(*DAT_00fba7a4 + 0x20))();
          if ((*(uint *)(local_20 + 4) != (uint)*(ushort *)(iVar4 + 0x88)) &&
             (*(uint *)(local_20 + 4) != 0)) goto LAB_004fc58d;
        }
        FUN_004fc740(param_4);
        FUN_004fc620();
      }
LAB_004fc58d:
      param_1 = param_1 + 1;
      iVar4 = local_18;
    } while (param_1 < local_24);
  }
  ExceptionList = local_10;
  return 1;
}

