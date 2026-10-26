
void FUN_006b4ab0(void)

{
  int iVar1;
  int in_EAX;
  int unaff_ESI;
  
  iVar1 = *(int *)(in_EAX + 8);
  if (iVar1 == *(int *)(*(int *)(unaff_ESI + 0x1cc) + 0x20)) {
    *(undefined4 *)(unaff_ESI + 0x1d8) = 0;
    *(undefined4 *)(unaff_ESI + 0x1dc) = 0;
    *(undefined1 *)(unaff_ESI + 0x1e0) = 0;
    FUN_006b4bb0(unaff_ESI);
    FUN_006b4f80(unaff_ESI);
  }
  else {
    if (iVar1 == *(int *)(*(int *)(unaff_ESI + 0x1d0) + 0x20)) {
      FUN_006b5240(unaff_ESI);
      FUN_006b4bb0(unaff_ESI);
      FUN_006b4f80(unaff_ESI);
      return;
    }
    if (iVar1 == *(int *)(*(int *)(unaff_ESI + 0x1d4) + 0x20)) {
      FUN_006b53e0();
      return;
    }
  }
  return;
}

