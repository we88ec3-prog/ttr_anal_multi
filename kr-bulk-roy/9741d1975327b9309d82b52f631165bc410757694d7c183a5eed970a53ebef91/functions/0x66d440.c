
void FUN_0066d440(undefined4 *param_1)

{
  undefined4 *in_EAX;
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  
  for (; in_ECX != param_1; in_ECX = in_ECX + 0x14) {
    *in_EAX = *in_ECX;
    puVar1 = in_EAX + 1;
    iVar2 = 0x1e;
    do {
      *(undefined2 *)puVar1 = *(undefined2 *)(((int)in_ECX - (int)in_EAX) + (int)puVar1);
      puVar1 = (undefined4 *)((int)puVar1 + 2);
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    FUN_0066d660(in_EAX + 0x10,in_ECX + 0x10);
    in_EAX = in_EAX + 0x14;
  }
  return;
}

