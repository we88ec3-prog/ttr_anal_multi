
void FUN_006dbb50(void)

{
  int in_EAX;
  undefined4 *puVar1;
  undefined2 *unaff_EDI;
  
  puVar1 = (undefined4 *)FUN_006db770();
  *puVar1 = *(undefined4 *)(in_EAX + 4);
  puVar1[1] = *(undefined4 *)(in_EAX + 4);
  puVar1[2] = *(undefined4 *)(in_EAX + 4);
  *(undefined2 *)(puVar1 + 0xc) = 0;
  if (puVar1 + 4 != (undefined4 *)0x0) {
    *(undefined2 *)(puVar1 + 4) = *unaff_EDI;
    puVar1[6] = *(undefined4 *)(unaff_EDI + 4);
    puVar1[7] = *(undefined4 *)(unaff_EDI + 6);
    puVar1[8] = *(undefined4 *)(unaff_EDI + 8);
    puVar1[9] = *(undefined4 *)(unaff_EDI + 10);
    puVar1[10] = *(undefined4 *)(unaff_EDI + 0xc);
    puVar1[0xb] = *(undefined4 *)(unaff_EDI + 0xe);
  }
  return;
}

