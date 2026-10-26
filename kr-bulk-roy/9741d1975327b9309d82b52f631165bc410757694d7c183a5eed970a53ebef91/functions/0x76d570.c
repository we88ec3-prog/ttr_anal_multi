
void FUN_0076d570(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int *piVar6;
  int *piVar7;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00918ff0;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_0075abf0(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  uVar2 = FUN_008fed10(uVar1);
  uVar3 = FUN_008fed10();
  uVar4 = FUN_008fed10();
  uVar5 = FUN_008fed10();
  piVar6 = _malloc(0x194);
  local_8 = 0;
  piVar7 = (int *)0x0;
  if (piVar6 != (int *)0x0) {
    FUN_00744320();
    local_8 = CONCAT31(local_8._1_3_,1);
    *piVar6 = (int)FoxUI::FXUIButton::vftable;
    FUN_0077b520(piVar6 + 0x2a);
    *(undefined1 *)(piVar6 + 0x29) = 1;
    piVar7 = piVar6;
  }
  local_8 = 0xffffffff;
  *(int **)(in_ECX + 0x10c) = piVar7;
  (**(code **)(*piVar7 + 0x38))(1,0x41c3,uVar5,0,uVar4,0x14);
  (**(code **)(**(int **)(in_ECX + 0x10c) + 0xb4))(0xce);
  piVar7 = _malloc(0x194);
  local_8 = 2;
  if (piVar7 == (int *)0x0) {
    piVar7 = (int *)0x0;
  }
  else {
    FUN_00744320();
    local_8 = CONCAT31(local_8._1_3_,3);
    *piVar7 = (int)FoxUI::FXUIButton::vftable;
    FUN_0077b520(piVar7 + 0x2a);
    *(undefined1 *)(piVar7 + 0x29) = 1;
  }
  local_8 = 0xffffffff;
  *(int **)(in_ECX + 0x104) = piVar7;
  (**(code **)(*piVar7 + 0x38))(2,0x41c3,uVar4,0,uVar3,0x14);
  (**(code **)(**(int **)(in_ECX + 0x104) + 0xb4))(0xce);
  piVar7 = _malloc(0x194);
  local_8 = 4;
  if (piVar7 == (int *)0x0) {
    piVar7 = (int *)0x0;
  }
  else {
    FUN_00744320();
    local_8 = CONCAT31(local_8._1_3_,5);
    *piVar7 = (int)FoxUI::FXUIButton::vftable;
    FUN_0077b520(piVar7 + 0x2a);
    *(undefined1 *)(piVar7 + 0x29) = 1;
  }
  local_8 = 0xffffffff;
  *(int **)(in_ECX + 0x108) = piVar7;
  (**(code **)(*piVar7 + 0x38))(3,0x41c3,uVar3,0,uVar2,0x14);
  (**(code **)(**(int **)(in_ECX + 0x108) + 0xb4))(0xce);
  ExceptionList = local_10;
  return;
}

