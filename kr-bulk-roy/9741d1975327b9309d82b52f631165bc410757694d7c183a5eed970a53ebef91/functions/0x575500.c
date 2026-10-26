
void FUN_00575500(undefined4 param_1)

{
  float fVar1;
  int iVar2;
  undefined4 uVar3;
  char cVar4;
  uint uVar5;
  float *pfVar6;
  int iVar7;
  int *unaff_EDI;
  uint in_stack_00000018;
  int in_stack_00000020;
  int in_stack_00000024;
  undefined4 in_stack_00000028;
  float local_20;
  undefined4 local_1c;
  float local_18;
  float local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  uVar3 = in_stack_00000028;
  iVar2 = in_stack_00000020;
  puStack_c = &LAB_0090ac88;
  local_10 = ExceptionList;
  uVar5 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  iVar7 = *unaff_EDI;
  local_20 = (float)FUN_00575df0(&param_1);
  if (local_20 != *(float *)(iVar7 + 4)) {
    cVar4 = FUN_005436a0(uVar5);
    if (cVar4 == '\0') {
      pfVar6 = &local_20;
      goto LAB_0057556c;
    }
  }
  local_14 = *(float *)(iVar7 + 4);
  pfVar6 = &local_14;
LAB_0057556c:
  fVar1 = *pfVar6;
  if (fVar1 != *(float *)(*unaff_EDI + 4)) {
    iVar7 = (**(code **)(**(int **)((int)fVar1 + 0x2c) + 0x10))();
    if (iVar7 != 0) {
      local_18 = (float)iVar2;
      local_14 = (float)in_stack_00000024;
      (**(code **)(**(int **)((int)fVar1 + 0x2c) + 0x28))
                (&local_18,uVar3,local_1c,0xffffffff,0,0xffffffff);
    }
  }
  if (0xf < in_stack_00000018) {
    FUN_0089120c(param_1);
  }
  ExceptionList = local_10;
  return;
}

