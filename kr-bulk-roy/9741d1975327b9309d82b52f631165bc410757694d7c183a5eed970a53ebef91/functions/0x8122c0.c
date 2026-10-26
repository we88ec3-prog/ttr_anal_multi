
int FUN_008122c0(void)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  if (iVar1 == 0) {
    FUN_006edb60("Source::Release: m_refCount == 0");
    return 0;
  }
  if (iVar1 == 1) {
    FUN_0080fce0();
    return 0;
  }
  *(int *)(in_ECX + 4) = iVar1 + -1;
  return iVar1 + -1;
}

