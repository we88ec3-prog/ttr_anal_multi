
int FUN_00727190(undefined4 param_1)

{
  int iVar1;
  undefined4 *unaff_EDI;
  undefined1 local_40 [4];
  int local_3c;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_20;
  undefined4 local_1c;
  
  local_30 = *unaff_EDI;
  local_34 = param_1;
  local_20 = 0;
  local_1c = 0;
  iVar1 = FUN_00727310();
  if (iVar1 == 0) {
    iVar1 = FUN_007274b0(local_40,4);
    if (iVar1 != 1) {
      FUN_00728940();
      if ((iVar1 != 2) && ((iVar1 != -5 || (local_3c != 0)))) {
        return iVar1;
      }
      return -3;
    }
    *unaff_EDI = local_2c;
    iVar1 = FUN_00728940();
  }
  return iVar1;
}

