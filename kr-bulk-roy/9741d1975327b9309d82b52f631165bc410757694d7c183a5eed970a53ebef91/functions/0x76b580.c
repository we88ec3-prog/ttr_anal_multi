
void FUN_0076b580(undefined4 param_1,undefined4 param_2,int param_3,int param_4,int param_5,
                 int param_6,int *param_7)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  int *piVar5;
  int in_ECX;
  int iVar6;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00920a60;
  local_10 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_0076a5c0(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  iVar2 = (param_5 - param_3) / 10;
  iVar1 = ((param_6 - param_4) / 10) * 8;
  iVar6 = ((param_5 + iVar2 * -7) - param_3) / 2;
  param_7 = _malloc(0x248);
  local_8 = 0;
  if (param_7 == (int *)0x0) {
    param_7 = (int *)0x0;
  }
  else {
    FUN_00754880(uVar3);
    local_8 = CONCAT31(local_8._1_3_,1);
    *param_7 = (int)FoxUI::FXUIContentButton::vftable;
    FUN_0077b520(param_7 + 0x57);
    *(undefined1 *)(param_7 + 0x56) = 1;
  }
  local_8 = 0xffffffff;
  *(int **)(in_ECX + 0xd8) = param_7;
  uVar4 = FUN_008fed10();
  (**(code **)(*param_7 + 0x38))(3,0x41c3,iVar6,iVar1,iVar6 + iVar2 * 3,uVar4);
  piVar5 = _malloc(0x248);
  local_8 = 2;
  if (piVar5 == (int *)0x0) {
    piVar5 = (int *)0x0;
  }
  else {
    FUN_00754880();
    local_8 = CONCAT31(local_8._1_3_,3);
    *piVar5 = (int)FoxUI::FXUIContentButton::vftable;
    FUN_0077b520(piVar5 + 0x57);
    *(undefined1 *)(piVar5 + 0x56) = 1;
  }
  local_8 = 0xffffffff;
  *(int **)(in_ECX + 0xdc) = piVar5;
  (**(code **)(*piVar5 + 0x38))(4,0x41c3,iVar6 + iVar2 * 4,iVar1,iVar2 * 7 + iVar6,uVar4);
  ExceptionList = local_10;
  return;
}

