
void FUN_007448d0(void)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  undefined4 ***pppuVar4;
  int iVar5;
  int *piVar6;
  undefined4 uVar7;
  undefined4 **local_30 [4];
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
  FUN_00776b00(*(undefined4 *)(in_ECX + 0x8c),local_14);
  FUN_00776b00(*(undefined4 *)(in_ECX + 0x90));
  iVar5 = 0;
  piVar6 = (int *)(in_ECX + 0x94);
  do {
    uVar7 = 0;
    if (*piVar6 != 0) {
      FUN_004297b0();
      local_8 = 0;
      iVar2 = FUN_00891268(0x98);
      local_8 = CONCAT31(local_8._1_3_,1);
      if (iVar2 != 0) {
        pppuVar4 = (undefined4 ***)local_30[0];
        if (local_1c < 0x10) {
          pppuVar4 = local_30;
        }
        uVar7 = FUN_0072e420(iVar2,pppuVar4);
      }
      local_8 = 0xffffffff;
      if (0xf < local_1c) {
        FUN_0089120c(local_30[0]);
      }
      local_1c = 0xf;
      local_20 = 0;
      local_30[0] = (undefined4 **)((uint)local_30[0] & 0xffffff00);
      FUN_00776b00(iVar5);
      piVar1 = (int *)*piVar6;
      uVar3 = (**(code **)(*piVar1 + 4))();
      FUN_00776b00(uVar3);
      (**(code **)(*piVar1 + 0xc))();
      FUN_00764810(uVar7);
      (**(code **)(*piVar1 + 0x18))(uVar7);
      FUN_0072e0d0();
    }
    iVar5 = iVar5 + 1;
    piVar6 = piVar6 + 1;
  } while (iVar5 < 4);
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

