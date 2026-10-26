
int FUN_008120e0(void)

{
  int iVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0xc) == 0) {
    FUN_006edb60("Buffer::Release: m_refCount == 0");
  }
  if (*(int *)(in_ECX + 0xc) == 1) {
    FUN_0080fc90();
    return 0;
  }
  iVar1 = *(int *)(in_ECX + 0xc) + -1;
  *(int *)(in_ECX + 0xc) = iVar1;
  return iVar1;
}

