
void FUN_0058d060(int param_1)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  void **ppvVar6;
  uint uVar7;
  int iVar8;
  undefined4 uVar9;
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
  uVar7 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  puVar2 = *(undefined4 **)(param_1 + 8);
  puVar3 = (undefined4 *)*puVar2;
  local_14 = uVar7;
  ppvVar6 = &local_10;
  local_10 = ExceptionList;
  while (ExceptionList = ppvVar6, puVar3 != puVar2) {
    FUN_004297b0(uVar7);
    local_8 = 0;
    iVar8 = FUN_00891268(0x98);
    local_8 = CONCAT31(local_8._1_3_,1);
    if (iVar8 == 0) {
      uVar9 = 0;
    }
    else {
      ppppppuVar10 = (undefined4 ******)local_30[0];
      if (local_1c < 0x10) {
        ppppppuVar10 = local_30;
      }
      uVar9 = FUN_0072e420(iVar8,ppppppuVar10);
    }
    local_8 = 0xffffffff;
    if (0xf < local_1c) {
      FUN_0089120c(local_30[0]);
    }
    local_1c = 0xf;
    local_20 = 0;
    local_30[0] = (undefined4 *****)((uint)local_30[0] & 0xffffff00);
    FUN_00764810(uVar9);
    FUN_00764810(uVar9);
    FUN_0072e0d0();
    ppvVar6 = ExceptionList;
    if (*(char *)((int)puVar3 + 0x45) == '\0') {
      puVar4 = (undefined4 *)puVar3[2];
      if (*(char *)((int)puVar4 + 0x45) == '\0') {
        cVar1 = *(char *)((int)*puVar4 + 0x45);
        puVar3 = puVar4;
        puVar4 = (undefined4 *)*puVar4;
        while (cVar1 == '\0') {
          cVar1 = *(char *)((int)*puVar4 + 0x45);
          puVar3 = puVar4;
          puVar4 = (undefined4 *)*puVar4;
        }
      }
      else {
        cVar1 = *(char *)((int)puVar3[1] + 0x45);
        puVar5 = (undefined4 *)puVar3[1];
        puVar4 = puVar3;
        while ((puVar3 = puVar5, cVar1 == '\0' && (puVar4 == (undefined4 *)puVar3[2]))) {
          cVar1 = *(char *)((int)puVar3[1] + 0x45);
          puVar5 = (undefined4 *)puVar3[1];
          puVar4 = puVar3;
        }
      }
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

