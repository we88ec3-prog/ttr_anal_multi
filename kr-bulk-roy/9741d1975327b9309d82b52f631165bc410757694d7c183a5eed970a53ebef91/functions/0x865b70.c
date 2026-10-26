
undefined4 FUN_00865b70(undefined4 param_1)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  int *unaff_ESI;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00917f8b;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  iVar2 = FUN_00891268(0xa8,uVar1);
  local_8 = 0;
  if (iVar2 == 0) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = (int *)FUN_00783670(iVar2,param_1);
  }
  local_8 = 0xffffffff;
  if (piVar3[0x16] != 0) {
    unaff_ESI[0x17] = (int)piVar3;
    uVar4 = (**(code **)(*unaff_ESI + 4))();
    ExceptionList = local_10;
    return uVar4;
  }
  (*(code *)**(undefined4 **)(*(int *)(*piVar3 + 4) + (int)piVar3))(1,uVar1,iVar2);
  ExceptionList = local_10;
  return 0;
}

