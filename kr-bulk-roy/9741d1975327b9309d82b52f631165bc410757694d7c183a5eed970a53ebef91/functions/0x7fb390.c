
void FUN_007fb390(void)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = (**(code **)(**(int **)(in_ECX + 0x10) + 0x68))
                    (*(int **)(in_ECX + 0x10),*(int *)(in_ECX + 0x4c) * 0x18,0x208,0x142,0,
                     in_ECX + 0x48,0);
  if (iVar1 < 0) {
    MessageBoxA((HWND)0x0,"CreateVertexBuffer() - FAILED","PSystem",0);
  }
  return;
}

