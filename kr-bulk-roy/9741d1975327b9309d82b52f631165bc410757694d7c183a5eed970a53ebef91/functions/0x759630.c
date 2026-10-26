
void FUN_00759630(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  undefined4 extraout_EDX;
  int *piVar4;
  int *piVar5;
  int *piVar6;
  undefined4 ***local_78;
  undefined4 ***local_70 [4];
  undefined4 local_60;
  uint local_5c;
  undefined1 local_54 [64];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091ef43;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  uVar1 = FUN_00764bb0(local_14);
  FUN_00764810(uVar1);
  piVar6 = *(int **)(in_ECX + 0x1c);
  piVar4 = (int *)*piVar6;
  if (piVar4 != piVar6) {
    do {
      iVar2 = FUN_00891268(0x98);
      piVar5 = (int *)0x0;
      local_8 = 0;
      if (iVar2 != 0) {
        piVar5 = (int *)FUN_0072e420(iVar2,"Color");
      }
      local_8 = 0xffffffff;
      FUN_00776b00(piVar4[2]);
      iVar2 = piVar4[3];
      FUN_004297b0();
      local_8 = 1;
      if (local_5c < 0x10) {
        local_78 = local_70;
      }
      else {
        local_78 = local_70[0];
      }
      uVar3 = (**(code **)(*piVar5 + 0x14))();
      FUN_00730d80(local_54,&DAT_00c0d6dc,iVar2);
      FUN_0072e770(uVar3,local_78);
      local_8 = 0xffffffff;
      if (0xf < local_5c) {
        FUN_0089120c(local_70[0]);
      }
      local_5c = 0xf;
      local_60 = 0;
      local_70[0] = (undefined4 ***)((uint)local_70[0] & 0xffffff00);
      FUN_0072e0d0();
      piVar4 = (int *)*piVar4;
    } while (piVar4 != piVar6);
  }
  FUN_0072e0d0();
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc,extraout_EDX,param_1,piVar6,uVar1);
  return;
}

