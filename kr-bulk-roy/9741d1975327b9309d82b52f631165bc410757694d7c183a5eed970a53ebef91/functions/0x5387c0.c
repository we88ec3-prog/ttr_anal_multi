
bool FUN_005387c0(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int unaff_ESI;
  int unaff_EDI;
  
  uVar2 = param_1;
  if (unaff_EDI == 0) {
    return false;
  }
  uVar1 = FUN_00537d90(param_2);
  FUN_00538270(unaff_EDI,uVar1);
  param_1 = uVar2;
  FUN_008438c0(&param_1);
  if (param_2 == *(int *)(unaff_ESI + 0x14)) {
    uVar2 = 0;
  }
  else {
    uVar2 = *(undefined4 *)(param_2 + 0x10);
  }
  FUN_00538270(unaff_EDI,uVar2);
  return *(uint *)(unaff_EDI + 4) <= *(uint *)(unaff_ESI + 0x20);
}

