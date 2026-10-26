
void FUN_0061c7c0(int param_1,byte param_2,undefined4 param_3)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  int *piVar6;
  uint uVar7;
  undefined2 uVar8;
  uint uVar9;
  int iVar10;
  int local_34;
  undefined4 *local_30;
  uint local_24;
  int local_20;
  int iStack_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093de48;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590(DAT_00d61f20 ^ (uint)&stack0xffffffc0);
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  if ((((param_2 < 10) &&
       (iVar1 = (uint)param_2 * 0x210 + DAT_00f94304, *(int *)(iVar1 + 0x5c) != 0)) && (iVar1 != 0))
     && (piVar2 = (int *)(iVar1 + 0xfc), piVar2 != (int *)0x0)) {
    if ((DAT_00fab278 & 1) == 0) {
      DAT_00fab278 = DAT_00fab278 | 1;
      local_c = 1;
      FUN_00817da0();
      _atexit((_func_4879 *)&LAB_00bcced0);
    }
    local_c = 0xffffffff;
    iVar3 = FUN_00819220(param_2,param_3);
    if (iVar3 != 0) {
      uVar7 = 0;
      do {
        local_30 = (undefined4 *)(param_1 + (uVar7 + 10) * 0x1c);
        local_34 = 0;
        do {
          if (local_34 < 6) {
            if (((byte)uVar7 < 4) && ((byte)(local_34 + 1U) < 0xb)) {
              uVar9 = (uint)*(ushort *)
                             (iVar3 + 4 + ((uVar7 & 0xff) * 0xb + (local_34 + 1U & 0xff)) * 2);
            }
            else {
              uVar9 = 0;
            }
            if ((DAT_00fb11a8 & 1) == 0) {
              DAT_00fb11a8 = DAT_00fb11a8 | 1;
              local_c = 2;
              FUN_00813890();
              _atexit((_func_4879 *)&LAB_00bccec0);
              local_c = 0xffffffff;
            }
            local_24 = uVar9;
            FUN_008438c0(&local_24);
            if (local_20 == DAT_00fb11d0) {
              iVar10 = 0;
            }
            else {
              iVar10 = *(int *)(local_20 + 0x10);
            }
            piVar5 = (int *)*piVar2;
            uVar9 = *(int *)(iVar1 + 0x100) - (int)piVar5 >> 3;
            uVar4 = 0;
            piVar6 = piVar5;
            if (uVar9 != 0) {
              do {
                if (*piVar6 == iVar10) {
                  uVar8 = (undefined2)piVar5[uVar4 * 2 + 1];
                  piVar5 = (int *)*local_30;
                  goto LAB_0061ca4a;
                }
                uVar4 = uVar4 + 1;
                piVar6 = piVar6 + 2;
              } while (uVar4 < uVar9);
            }
            piVar5 = (int *)*local_30;
            uVar8 = 0;
          }
          else {
            uVar9 = FUN_0081a8e0(iVar3);
            if ((DAT_00fb11a8 & 1) == 0) {
              DAT_00fb11a8 = DAT_00fb11a8 | 1;
              local_c = 3;
              FUN_00813890();
              _atexit((_func_4879 *)&LAB_00bccec0);
              local_c = 0xffffffff;
            }
            local_24 = uVar9 & 0xffff;
            FUN_008438c0(&local_24);
            if (iStack_1c == DAT_00fb11d0) {
              iVar10 = 0;
            }
            else {
              iVar10 = *(int *)(iStack_1c + 0x10);
            }
            piVar5 = (int *)*piVar2;
            uVar9 = *(int *)(iVar1 + 0x100) - (int)piVar5 >> 3;
            uVar4 = 0;
            piVar6 = piVar5;
            if (uVar9 != 0) {
              do {
                if (*piVar6 == iVar10) {
                  uVar8 = (undefined2)piVar5[uVar4 * 2 + 1];
                  goto LAB_0061ca44;
                }
                uVar4 = uVar4 + 1;
                piVar6 = piVar6 + 2;
              } while (uVar4 < uVar9);
            }
            uVar8 = 0;
LAB_0061ca44:
            piVar5 = (int *)*local_30;
          }
LAB_0061ca4a:
          (**(code **)(*piVar5 + 0x19c))(iVar10,uVar8,1);
          FUN_0061cac0(iVar10,uVar8,local_34,0);
          local_30 = local_30 + 1;
          local_34 = local_34 + 1;
        } while (local_34 < 7);
        FUN_0061d540(param_1);
        uVar7 = uVar7 + 1;
      } while ((int)uVar7 < 3);
    }
  }
  ExceptionList = local_14;
  return;
}

