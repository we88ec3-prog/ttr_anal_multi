
/* WARNING: Removing unreachable block (ram,0x00773c04) */

void FUN_00773a20(undefined4 param_1)

{
  char cVar1;
  undefined4 *puVar2;
  int *piVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  uint uVar6;
  int iVar7;
  undefined4 uVar8;
  int in_ECX;
  undefined4 *******pppppppuVar9;
  undefined4 uVar10;
  undefined4 *puVar11;
  undefined4 ******local_4c [4];
  undefined4 local_3c;
  uint local_38;
  undefined4 ******local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009209ae;
  local_10 = ExceptionList;
  uVar6 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar6;
  FUN_00764810(param_1,uVar6);
  FUN_00764810(param_1,uVar6);
  FUN_00764810(param_1,uVar6);
  FUN_00764b00(*(undefined1 *)(in_ECX + 0x7c));
  FUN_007648e0(*(undefined4 *)(in_ECX + 0x80));
  puVar2 = *(undefined4 **)(in_ECX + 0x60);
  puVar11 = (undefined4 *)*puVar2;
  while (puVar11 != puVar2) {
    uVar10 = 0;
    FUN_00402160(L"FONTITEM",8);
    local_8 = 0;
    FUN_004297b0();
    local_8._0_1_ = 1;
    iVar7 = FUN_00891268(0x98);
    local_8._0_1_ = 2;
    if (iVar7 != 0) {
      pppppppuVar9 = (undefined4 *******)local_30[0];
      if (local_1c < 0x10) {
        pppppppuVar9 = local_30;
      }
      uVar10 = FUN_0072e420(iVar7,pppppppuVar9);
    }
    local_8 = (uint)local_8._1_3_ << 8;
    if (0xf < local_1c) {
      FUN_0089120c(local_30[0]);
    }
    piVar3 = (int *)puVar11[4];
    local_1c = 0xf;
    local_20 = 0;
    local_30[0] = (undefined4 ******)((uint)local_30[0] & 0xffffff00);
    uVar8 = (**(code **)(*piVar3 + 4))();
    FUN_00776b00(uVar8);
    (**(code **)(*piVar3 + 0xc))();
    FUN_00764810(uVar10);
    (**(code **)(*piVar3 + 0x18))(uVar10);
    FUN_0072e0d0();
    if (*(char *)((int)puVar11 + 0x15) == '\0') {
      puVar4 = (undefined4 *)puVar11[2];
      if (*(char *)((int)puVar4 + 0x15) == '\0') {
        cVar1 = *(char *)((int)*puVar4 + 0x15);
        puVar11 = puVar4;
        puVar4 = (undefined4 *)*puVar4;
        while (cVar1 == '\0') {
          cVar1 = *(char *)((int)*puVar4 + 0x15);
          puVar11 = puVar4;
          puVar4 = (undefined4 *)*puVar4;
        }
      }
      else {
        cVar1 = *(char *)((int)puVar11[1] + 0x15);
        puVar5 = (undefined4 *)puVar11[1];
        puVar4 = puVar11;
        while ((puVar11 = puVar5, cVar1 == '\0' && (puVar4 == (undefined4 *)puVar11[2]))) {
          cVar1 = *(char *)((int)puVar11[1] + 0x15);
          puVar5 = (undefined4 *)puVar11[1];
          puVar4 = puVar11;
        }
      }
    }
    local_8 = 0xffffffff;
  }
  puVar2 = *(undefined4 **)(in_ECX + 0x70);
  puVar11 = (undefined4 *)*puVar2;
  while (puVar11 != puVar2) {
    local_30[0] = (undefined4 ******)((uint)local_30[0] & 0xffff0000);
    uVar8 = 0;
    local_1c = 7;
    local_20 = 0;
    FUN_00402160(L"FONTITEM",8);
    local_8 = 3;
    uVar10 = FUN_00633110(local_4c,local_30,L"BOLD");
    local_8._0_1_ = 4;
    FUN_00402800(uVar10);
    local_8._0_1_ = 3;
    if (7 < local_38) {
      FUN_0089120c(local_4c[0]);
    }
    FUN_004297b0();
    local_8._0_1_ = 5;
    iVar7 = FUN_00891268(0x98);
    local_8._0_1_ = 6;
    if (iVar7 != 0) {
      pppppppuVar9 = (undefined4 *******)local_4c[0];
      if (local_38 < 0x10) {
        pppppppuVar9 = local_4c;
      }
      uVar8 = FUN_0072e420(iVar7,pppppppuVar9);
    }
    local_8 = CONCAT31(local_8._1_3_,3);
    if (0xf < local_38) {
      FUN_0089120c(local_4c[0]);
    }
    piVar3 = (int *)puVar11[4];
    local_38 = 0xf;
    local_3c = 0;
    local_4c[0] = (undefined4 ******)((uint)local_4c[0] & 0xffffff00);
    uVar10 = (**(code **)(*piVar3 + 4))();
    FUN_00776b00(uVar10);
    (**(code **)(*piVar3 + 0xc))();
    FUN_00764810(uVar8);
    (**(code **)(*piVar3 + 0x18))(uVar8);
    FUN_0072e0d0();
    if (*(char *)((int)puVar11 + 0x15) == '\0') {
      puVar4 = (undefined4 *)puVar11[2];
      if (*(char *)((int)puVar4 + 0x15) == '\0') {
        cVar1 = *(char *)((int)*puVar4 + 0x15);
        puVar11 = puVar4;
        puVar4 = (undefined4 *)*puVar4;
        while (cVar1 == '\0') {
          cVar1 = *(char *)((int)*puVar4 + 0x15);
          puVar11 = puVar4;
          puVar4 = (undefined4 *)*puVar4;
        }
      }
      else {
        cVar1 = *(char *)((int)puVar11[1] + 0x15);
        puVar5 = (undefined4 *)puVar11[1];
        puVar4 = puVar11;
        while ((puVar11 = puVar5, cVar1 == '\0' && (puVar4 == (undefined4 *)puVar11[2]))) {
          cVar1 = *(char *)((int)puVar11[1] + 0x15);
          puVar5 = (undefined4 *)puVar11[1];
          puVar4 = puVar11;
        }
      }
    }
    local_8 = 0xffffffff;
    if (7 < local_1c) {
      FUN_0089120c(local_30[0]);
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

