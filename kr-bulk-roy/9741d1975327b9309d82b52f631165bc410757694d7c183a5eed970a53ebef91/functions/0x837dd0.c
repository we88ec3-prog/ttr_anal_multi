
void FUN_00837dd0(void)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 8);
  if (iVar1 != 0) {
    FUN_00837dd0();
    FUN_0089120c(iVar1);
    *(undefined4 *)(in_ECX + 8) = 0;
  }
  iVar1 = *(int *)(in_ECX + 0xc);
  if (iVar1 != 0) {
    FUN_00837dd0();
    FUN_0089120c(iVar1);
    *(undefined4 *)(in_ECX + 0xc) = 0;
  }
  return;
}

