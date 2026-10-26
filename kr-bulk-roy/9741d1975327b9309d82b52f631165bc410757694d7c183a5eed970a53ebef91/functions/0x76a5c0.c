
void FUN_0076a5c0(undefined4 param_1,undefined4 param_2,int param_3,int param_4,int param_5,
                 int param_6,undefined4 param_7)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int *piVar5;
  int *in_ECX;
  int *piVar6;
  int iVar7;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091eca8;
  local_10 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_00745a50(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  (**(code **)(*in_ECX + 0x180))(uVar3);
  iVar1 = (param_5 - param_3) / 10;
  iVar2 = (param_6 - param_4) / 10;
  iVar4 = ((param_6 + iVar2 * -8) - param_4) / 2;
  iVar7 = ((param_5 + iVar1 * -8) - param_3) / 2;
  piVar5 = _malloc(0x158);
  local_8 = 0;
  piVar6 = (int *)0x0;
  if (piVar5 != (int *)0x0) {
    FUN_00754880();
    *piVar5 = (int)FoxUI::FXUIStatic::vftable;
    piVar6 = piVar5;
  }
  local_8 = 0xffffffff;
  in_ECX[0x33] = (int)piVar6;
  (**(code **)(*piVar6 + 0x38))(0,0x41c3,iVar7,iVar4,iVar1 * 8 + iVar7,iVar4 + iVar2 * 6);
  ExceptionList = local_10;
  return;
}

