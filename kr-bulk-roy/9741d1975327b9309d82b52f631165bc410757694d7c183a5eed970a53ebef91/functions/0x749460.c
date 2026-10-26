
/* WARNING: Type propagation algorithm not settling */

void FUN_00749460(undefined4 param_1)

{
  uint uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int *piVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  char cVar7;
  int iVar8;
  undefined4 uVar9;
  int iVar10;
  int in_ECX;
  undefined4 *******pppppppuVar11;
  undefined4 uVar12;
  undefined4 *******local_4c [4];
  undefined4 local_3c;
  uint local_38;
  undefined4 *******local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00921526;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  uVar1 = *(uint *)(in_ECX + 0x28);
  if ((uVar1 & 0x8000) != 0) {
    *(uint *)(in_ECX + 0x28) = uVar1 ^ 0x8000;
  }
  if ((*(uint *)(in_ECX + 0x28) & 0x10000) != 0) {
    *(uint *)(in_ECX + 0x28) = *(uint *)(in_ECX + 0x28) ^ 0x10000;
  }
  if ((*(uint *)(in_ECX + 0x28) & 0x20000) != 0) {
    *(uint *)(in_ECX + 0x28) = *(uint *)(in_ECX + 0x28) ^ 0x20000;
  }
  FUN_007649b0(*(undefined4 *)(in_ECX + 0x20),local_14);
  FUN_007649b0(*(undefined4 *)(in_ECX + 0x48));
  FUN_007649b0(*(undefined4 *)(in_ECX + 0x28));
  FUN_00764a50(*(undefined2 *)(in_ECX + 0x5c));
  FUN_00764bb0();
  FUN_007649b0(*(undefined4 *)(in_ECX + 8));
  FUN_007649b0(*(undefined4 *)(in_ECX + 0x10));
  FUN_007649b0(*(undefined4 *)(in_ECX + 0xc));
  FUN_007649b0(*(undefined4 *)(in_ECX + 0x14));
  FUN_0072e0d0();
  FUN_00764bb0();
  FUN_007649b0(*(undefined4 *)(in_ECX + 0x2c));
  FUN_007649b0(*(undefined4 *)(in_ECX + 0x34));
  FUN_007649b0(*(undefined4 *)(in_ECX + 0x30));
  FUN_007649b0(*(undefined4 *)(in_ECX + 0x38));
  FUN_0072e0d0();
  uVar12 = param_1;
  (**(code **)(**(int **)(in_ECX + 0x1c) + 0x10))(param_1);
  FUN_00776bf0(uVar12);
  if ((uVar1 >> 0xf & 1) == 0) {
    if ((*(uint *)(in_ECX + 0x28) & 0x8000) != 0) {
      *(uint *)(in_ECX + 0x28) = *(uint *)(in_ECX + 0x28) ^ 0x8000;
    }
  }
  else {
    *(uint *)(in_ECX + 0x28) = *(uint *)(in_ECX + 0x28) | 0x8000;
  }
  if ((uVar1 & 0x10000) == 0) {
    if ((*(uint *)(in_ECX + 0x28) & 0x10000) != 0) {
      *(uint *)(in_ECX + 0x28) = *(uint *)(in_ECX + 0x28) ^ 0x10000;
    }
  }
  else {
    *(uint *)(in_ECX + 0x28) = *(uint *)(in_ECX + 0x28) | 0x10000;
  }
  if ((uVar1 >> 0x11 & 1) == 0) {
    if ((*(uint *)(in_ECX + 0x28) & 0x20000) != 0) {
      *(uint *)(in_ECX + 0x28) = *(uint *)(in_ECX + 0x28) ^ 0x20000;
    }
  }
  else {
    *(uint *)(in_ECX + 0x28) = *(uint *)(in_ECX + 0x28) | 0x20000;
  }
  puVar2 = *(undefined4 **)(in_ECX + 0x50);
  puVar3 = (undefined4 *)*puVar2;
  while (puVar3 != puVar2) {
    piVar4 = (int *)puVar3[4];
    (**(code **)(*piVar4 + 0x10))();
    FUN_004297b0();
    uVar12 = 0;
    local_8 = 0;
    iVar8 = FUN_00891268(0x98);
    local_8 = CONCAT31(local_8._1_3_,1);
    if (iVar8 != 0) {
      pppppppuVar11 = local_4c[0];
      if (local_38 < 0x10) {
        pppppppuVar11 = local_4c;
      }
      uVar12 = FUN_0072e420(iVar8,pppppppuVar11);
    }
    local_8 = 0xffffffff;
    if (0xf < local_38) {
      FUN_0089120c(local_4c[0]);
    }
    local_38 = 0xf;
    local_3c = 0;
    local_4c[0] = (undefined4 *******)((uint)local_4c[0] & 0xffffff00);
    uVar9 = (**(code **)(*piVar4 + 4))();
    FUN_00776b00(uVar9);
    (**(code **)(*piVar4 + 0xc))();
    FUN_00764810(uVar12);
    cVar7 = (**(code **)(*piVar4 + 0x18))(uVar12);
    if (cVar7 != '\0') {
      FUN_0072e0d0();
    }
    if (*(char *)((int)puVar3 + 0x15) == '\0') {
      puVar5 = (undefined4 *)puVar3[2];
      if (*(char *)((int)puVar5 + 0x15) == '\0') {
        cVar7 = *(char *)((int)*puVar5 + 0x15);
        puVar3 = puVar5;
        puVar5 = (undefined4 *)*puVar5;
        while (cVar7 == '\0') {
          cVar7 = *(char *)((int)*puVar5 + 0x15);
          puVar3 = puVar5;
          puVar5 = (undefined4 *)*puVar5;
        }
      }
      else {
        cVar7 = *(char *)((int)puVar3[1] + 0x15);
        puVar6 = (undefined4 *)puVar3[1];
        puVar5 = puVar3;
        while ((puVar3 = puVar6, cVar7 == '\0' && (puVar5 == (undefined4 *)puVar3[2]))) {
          cVar7 = *(char *)((int)puVar3[1] + 0x15);
          puVar6 = (undefined4 *)puVar3[1];
          puVar5 = puVar3;
        }
      }
    }
  }
  FUN_00764bb0();
  puVar2 = *(undefined4 **)(in_ECX + 100);
  for (puVar3 = (undefined4 *)*puVar2; puVar3 != puVar2; puVar3 = (undefined4 *)*puVar3) {
    iVar8 = FUN_00749e40();
    if (iVar8 != -1) {
      FUN_004297b0();
      local_8 = 2;
      iVar10 = FUN_00891268(0x98);
      local_8 = CONCAT31(local_8._1_3_,3);
      if (iVar10 != 0) {
        pppppppuVar11 = local_30[0];
        if (local_1c < 0x10) {
          pppppppuVar11 = local_30;
        }
        FUN_0072e420(iVar10,pppppppuVar11);
      }
      local_8 = 0xffffffff;
      if (0xf < local_1c) {
        FUN_0089120c(local_30[0]);
      }
      local_1c = 0xf;
      local_20 = 0;
      local_30[0] = (undefined4 *******)((uint)local_30[0] & 0xffffff00);
      FUN_0074d5c0(iVar8);
      FUN_0072e0d0();
    }
  }
  FUN_0072e0d0();
  if (*(int *)(in_ECX + 0x3c) != 0) {
    FUN_00776bf0(param_1);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

