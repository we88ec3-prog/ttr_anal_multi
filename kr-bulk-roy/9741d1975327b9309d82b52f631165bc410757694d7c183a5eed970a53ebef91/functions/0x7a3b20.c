
void FUN_007a3b20(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int in_EAX;
  undefined1 *unaff_ESI;
  
  *(undefined4 *)(unaff_ESI + 0x14) = 0xf;
  *(undefined4 *)(unaff_ESI + 0x10) = 0;
  puVar1 = (undefined4 *)(in_EAX + 0x1c);
  *unaff_ESI = 0;
  FUN_00402bb0(in_EAX);
  puVar2 = (undefined4 *)(unaff_ESI + 0x1c);
  *puVar2 = 0;
  *(undefined4 *)(unaff_ESI + 0x20) = 0;
  if (puVar2 != puVar1) {
    uVar3 = *(undefined4 *)(unaff_ESI + 0x20);
    *(undefined4 *)(unaff_ESI + 0x20) = *(undefined4 *)(in_EAX + 0x20);
    *(undefined4 *)(in_EAX + 0x20) = uVar3;
    uVar3 = *puVar2;
    *puVar2 = *puVar1;
    *puVar1 = uVar3;
  }
  return;
}

