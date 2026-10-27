
void FUN_004a9430(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = DAT_00fba7a4;
  iVar2 = FUN_004a90c0(param_1);
  if (iVar2 == 0) {
    *(undefined4 *)(iVar1 + 0xb4 + param_1 * 4) = 0;
  }
  return;
}

