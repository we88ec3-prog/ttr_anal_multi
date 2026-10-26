
void FUN_0076aa70(undefined4 param_1,undefined4 param_2,int param_3,int param_4,int param_5,
                 int param_6,undefined4 param_7)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  undefined4 uVar4;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00920a90;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_0076a5c0(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  iVar1 = ((param_5 - param_3) / 10) * 3;
  param_3 = (param_5 - iVar1 / 2) - param_3;
  piVar3 = _malloc(0x248);
  local_8 = 0;
  if (piVar3 == (int *)0x0) {
    piVar3 = (int *)0x0;
  }
  else {
    FUN_00754880(uVar2);
    local_8 = CONCAT31(local_8._1_3_,1);
    *piVar3 = (int)FoxUI::FXUIContentButton::vftable;
    FUN_0077b520(piVar3 + 0x57);
    *(undefined1 *)(piVar3 + 0x56) = 1;
  }
  local_8 = 0xffffffff;
  *(int **)(in_ECX + 0xd8) = piVar3;
  uVar4 = FUN_008fed10();
  (**(code **)(*piVar3 + 0x38))
            (1,0x41c3,param_3,((param_6 - param_4) / 10) * 8,iVar1 + param_3,uVar4);
  ExceptionList = local_10;
  return;
}

