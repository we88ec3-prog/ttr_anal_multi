
int FUN_008bdae0(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_008bdcd0();
  if (iVar1 == 0) {
    return 7;
  }
  iVar2 = FUN_008bc140(iVar1,param_1);
  if (iVar2 != 0) {
    FUN_008bdd00(iVar1);
    return iVar2;
  }
  FUN_008bdab0(*param_1);
  return 0;
}

