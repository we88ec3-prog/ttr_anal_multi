
void FUN_007fdde0(undefined4 *param_1)

{
  undefined4 *in_EAX;
  int iVar1;
  undefined4 *in_EDX;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  for (; in_EDX != param_1; in_EDX = in_EDX + 0xc) {
    if (in_EAX != (undefined4 *)0x0) {
      *in_EAX = *in_EDX;
      iVar1 = 0xb;
      puVar2 = in_EDX;
      puVar3 = in_EAX;
      while( true ) {
        puVar3 = puVar3 + 1;
        puVar2 = puVar2 + 1;
        if (iVar1 == 0) break;
        iVar1 = iVar1 + -1;
        *puVar3 = *puVar2;
      }
    }
    in_EAX = in_EAX + 0xc;
  }
  return;
}

