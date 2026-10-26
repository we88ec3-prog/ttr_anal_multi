
void FUN_0058e480(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  undefined4 *puVar1;
  int *piVar2;
  undefined4 *puVar3;
  void **ppvVar4;
  undefined4 *puVar5;
  char cVar6;
  uint uVar7;
  undefined4 *******pppppppuVar8;
  int iVar9;
  int *piVar10;
  undefined4 *puVar11;
  undefined4 *local_50;
  undefined4 ******local_4c [4];
  undefined4 local_3c;
  uint local_38;
  uint local_30;
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009168a0;
  uVar7 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  puVar1 = *(undefined4 **)(param_1 + 0x1c);
  puVar11 = (undefined4 *)*puVar1;
  local_14 = uVar7;
  ppvVar4 = &local_10;
  local_50 = puVar11;
  local_10 = ExceptionList;
  do {
    ExceptionList = ppvVar4;
    if (puVar11 == puVar1) {
      ExceptionList = local_10;
      __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
      return;
    }
    local_30 = local_30 & 0xffff0000;
    local_1c = 7;
    local_20 = 0;
    FUN_004026e0(puVar11 + 3,0,0xffffffff);
    local_8 = 0;
    piVar2 = *(int **)(puVar11[10] + 4);
    if (piVar2 != (int *)0x0) {
      local_38 = 7;
      local_3c = 0;
      local_4c[0] = (undefined4 ******)((uint)local_4c[0] & 0xffff0000);
      local_8._0_1_ = 1;
      local_8._1_3_ = 0;
      cVar6 = FUN_0058ef10(param_1,L"DockSideMode");
      if (cVar6 == '\0') {
        local_8 = (uint)local_8._1_3_ << 8;
        if (7 < local_38) {
          FUN_0089120c(local_4c[0],uVar7);
        }
      }
      else {
        pppppppuVar8 = (undefined4 *******)local_4c[0];
        if (local_38 < 8) {
          pppppppuVar8 = local_4c;
        }
        iVar9 = FUN_008935e3(pppppppuVar8);
        local_8 = (uint)local_8._1_3_ << 8;
        if (7 < local_38) {
          FUN_0089120c(local_4c[0],uVar7);
        }
        if (iVar9 != 0) {
          FUN_0058ee60(param_1);
          FUN_0058ee60(param_1);
          FUN_0058ee60(param_1);
          FUN_0058ee60(param_1);
          piVar10 = _malloc(0x20);
          if (piVar10 == (int *)0x0) {
            piVar10 = (int *)0x0;
          }
          else {
            DAT_00fba828 = DAT_00fba828 + 1;
            piVar10[1] = DAT_00fba828;
            piVar10[7] = iVar9;
            piVar10[3] = 0;
            piVar10[4] = 0;
            piVar10[5] = 0;
            piVar10[2] = 0x191;
            *piVar10 = (int)FoxUI::FXUIDockInfoGuide::vftable;
            piVar10[6] = 0;
          }
          if ((int *)piVar2[7] != (int *)0x0) {
            (**(code **)(*(int *)piVar2[7] + 0x1c))(1);
            piVar2[7] = 0;
          }
          if (piVar10 == (int *)0x0) {
            piVar10 = _malloc(0xc);
            if (piVar10 == (int *)0x0) {
              piVar10 = (int *)0x0;
            }
            else {
              DAT_00fba828 = DAT_00fba828 + 1;
              piVar10[1] = DAT_00fba828;
              *piVar10 = (int)FoxUI::FXUIDockInfo::vftable;
              piVar10[2] = 6;
            }
          }
          piVar2[7] = (int)piVar10;
          puVar11 = local_50;
          if ((piVar2[0x18] != 0) && (piVar10[2] != 6)) {
            (**(code **)(*piVar10 + 0x30))(piVar2);
          }
          goto LAB_0058e6d6;
        }
      }
      (**(code **)(*piVar2 + 0xb4))(0x191);
      if (piVar2[7] != 0) {
        (**(code **)(*piVar2 + 0xb4))(*(undefined4 *)(piVar2[7] + 8));
      }
    }
LAB_0058e6d6:
    FUN_0058cac0(puVar11[10],param_2,param_3,param_4,param_5);
    if (*(char *)((int)puVar11 + 0x2d) == '\0') {
      puVar3 = (undefined4 *)puVar11[2];
      if (*(char *)((int)puVar3 + 0x2d) == '\0') {
        cVar6 = *(char *)((int)*puVar3 + 0x2d);
        puVar11 = puVar3;
        puVar3 = (undefined4 *)*puVar3;
        while (local_50 = puVar11, cVar6 == '\0') {
          cVar6 = *(char *)((int)*puVar3 + 0x2d);
          puVar11 = puVar3;
          puVar3 = (undefined4 *)*puVar3;
        }
      }
      else {
        cVar6 = *(char *)((int)puVar11[1] + 0x2d);
        puVar5 = (undefined4 *)puVar11[1];
        puVar3 = puVar11;
        while ((puVar11 = puVar5, local_50 = puVar11, cVar6 == '\0' &&
               (puVar3 == (undefined4 *)puVar11[2]))) {
          cVar6 = *(char *)((int)puVar11[1] + 0x2d);
          puVar5 = (undefined4 *)puVar11[1];
          puVar3 = puVar11;
        }
      }
    }
    local_8 = 0xffffffff;
    ppvVar4 = ExceptionList;
    if (7 < local_1c) {
      FUN_0089120c(local_30,uVar7);
      ppvVar4 = ExceptionList;
    }
  } while( true );
}

