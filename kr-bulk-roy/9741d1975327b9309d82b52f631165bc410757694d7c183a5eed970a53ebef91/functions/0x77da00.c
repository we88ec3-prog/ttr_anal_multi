
void FUN_0077da00(void)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int *piVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  int iVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  int in_ECX;
  undefined4 ******ppppppuVar10;
  undefined4 *****local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091fa73;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_007649b0(*(undefined4 *)(in_ECX + 8),local_14);
  puVar2 = *(undefined4 **)(in_ECX + 0x10);
  puVar3 = (undefined4 *)*puVar2;
  while (puVar3 != puVar2) {
    FUN_004297b0();
    local_8 = 0;
    iVar7 = FUN_00891268(0x98);
    local_8 = CONCAT31(local_8._1_3_,1);
    if (iVar7 == 0) {
      uVar8 = 0;
    }
    else {
      ppppppuVar10 = (undefined4 ******)local_30[0];
      if (local_1c < 0x10) {
        ppppppuVar10 = local_30;
      }
      uVar8 = FUN_0072e420(iVar7,ppppppuVar10);
    }
    local_8 = 0xffffffff;
    if (0xf < local_1c) {
      FUN_0089120c(local_30[0]);
    }
    local_20 = 0;
    piVar4 = (int *)puVar3[4];
    local_1c = 0xf;
    local_30[0] = (undefined4 *****)((uint)local_30[0] & 0xffffff00);
    uVar9 = (**(code **)(*piVar4 + 4))();
    FUN_00776b00(uVar9);
    (**(code **)(*piVar4 + 0xc))();
    FUN_00764810(uVar8);
    (**(code **)(*piVar4 + 0x18))(uVar8);
    FUN_0072e0d0();
    if (*(char *)((int)puVar3 + 0x15) == '\0') {
      puVar5 = (undefined4 *)puVar3[2];
      if (*(char *)((int)puVar5 + 0x15) == '\0') {
        cVar1 = *(char *)((int)*puVar5 + 0x15);
        puVar3 = puVar5;
        puVar5 = (undefined4 *)*puVar5;
        while (cVar1 == '\0') {
          cVar1 = *(char *)((int)*puVar5 + 0x15);
          puVar3 = puVar5;
          puVar5 = (undefined4 *)*puVar5;
        }
      }
      else {
        cVar1 = *(char *)((int)puVar3[1] + 0x15);
        puVar6 = (undefined4 *)puVar3[1];
        puVar5 = puVar3;
        while ((puVar3 = puVar6, cVar1 == '\0' && (puVar5 == (undefined4 *)puVar3[2]))) {
          cVar1 = *(char *)((int)puVar3[1] + 0x15);
          puVar6 = (undefined4 *)puVar3[1];
          puVar5 = puVar3;
        }
      }
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

