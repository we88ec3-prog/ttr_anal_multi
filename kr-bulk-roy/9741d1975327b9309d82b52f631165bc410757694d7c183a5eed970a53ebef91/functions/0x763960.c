
void FUN_00763960(int param_1)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int *piVar6;
  int iVar7;
  undefined4 uVar8;
  int in_ECX;
  undefined4 *****pppppuVar9;
  undefined4 uVar10;
  undefined4 ****local_230 [4];
  undefined4 local_220;
  uint local_21c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00920ac9;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (param_1 != 0) {
    piVar6 = (int *)(in_ECX + 0x2c);
    if (7 < *(uint *)(in_ECX + 0x40)) {
      piVar6 = (int *)*piVar6;
    }
    FUN_0077c7b0(piVar6,local_14);
    FUN_00764810(param_1);
    FUN_00764810(param_1);
    FUN_0074d5c0(*(undefined4 *)(in_ECX + 0x50));
    puVar2 = *(undefined4 **)(in_ECX + 0x4c);
    puVar3 = (undefined4 *)*puVar2;
    while (puVar3 != puVar2) {
      FUN_004297b0();
      uVar10 = 0;
      local_8 = 0;
      iVar7 = FUN_00891268(0x98);
      local_8 = CONCAT31(local_8._1_3_,1);
      if (iVar7 != 0) {
        pppppuVar9 = (undefined4 *****)local_230[0];
        if (local_21c < 0x10) {
          pppppuVar9 = local_230;
        }
        uVar10 = FUN_0072e420(iVar7,pppppuVar9);
      }
      local_8 = 0xffffffff;
      if (0xf < local_21c) {
        FUN_0089120c(local_230[0]);
      }
      piVar6 = (int *)puVar3[4];
      local_21c = 0xf;
      local_220 = 0;
      local_230[0] = (undefined4 ****)((uint)local_230[0] & 0xffffff00);
      uVar8 = (**(code **)(*piVar6 + 4))();
      FUN_00776b00(uVar8);
      (**(code **)(*piVar6 + 0xc))();
      FUN_00764810(uVar10);
      (**(code **)(*piVar6 + 0x18))(uVar10);
      FUN_0072e0d0();
      if (*(char *)((int)puVar3 + 0x15) == '\0') {
        puVar4 = (undefined4 *)puVar3[2];
        if (*(char *)((int)puVar4 + 0x15) == '\0') {
          cVar1 = *(char *)((int)*puVar4 + 0x15);
          puVar3 = puVar4;
          puVar4 = (undefined4 *)*puVar4;
          while (cVar1 == '\0') {
            cVar1 = *(char *)((int)*puVar4 + 0x15);
            puVar3 = puVar4;
            puVar4 = (undefined4 *)*puVar4;
          }
        }
        else {
          cVar1 = *(char *)((int)puVar3[1] + 0x15);
          puVar5 = (undefined4 *)puVar3[1];
          puVar4 = puVar3;
          while ((puVar3 = puVar5, cVar1 == '\0' && (puVar4 == (undefined4 *)puVar3[2]))) {
            cVar1 = *(char *)((int)puVar3[1] + 0x15);
            puVar5 = (undefined4 *)puVar3[1];
            puVar4 = puVar3;
          }
        }
      }
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

