
void FUN_0077ef30(void)

{
  undefined4 *in_EAX;
  int in_ECX;
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)(in_ECX + 0x68);
  for (iVar1 = 0xb; iVar1 != 0; iVar1 = iVar1 + -1) {
    *in_EAX = *puVar2;
    puVar2 = puVar2 + 1;
    in_EAX = in_EAX + 1;
  }
  return;
}

