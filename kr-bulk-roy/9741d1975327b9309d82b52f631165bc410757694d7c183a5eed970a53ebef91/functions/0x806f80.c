
void FUN_00806f80(undefined4 param_1)

{
  int in_ECX;
  
  FUN_008438c0(&param_1);
  if ((in_ECX != *(int *)(in_ECX + 0x1c)) && (*(SOCKET **)(in_ECX + 0x10) != (SOCKET *)0x0)) {
    shutdown(**(SOCKET **)(in_ECX + 0x10),1);
  }
  return;
}

