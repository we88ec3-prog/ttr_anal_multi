
bool FUN_0081b270(void)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  
  iVar1 = FUN_0089289d();
  iVar2 = FUN_0089289d();
  return (uint)((iVar2 * iVar1) % 100000) < *(uint *)(in_ECX + 8);
}

