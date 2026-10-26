
void FUN_008edea0(void)

{
  int iVar1;
  char cVar2;
  int unaff_ESI;
  undefined1 local_34 [36];
  undefined4 local_10;
  undefined1 local_c [8];
  
  if (*(int *)(unaff_ESI + 0x10) < *(int *)(unaff_ESI + 0x130)) {
    if (*(char *)(unaff_ESI + 0x231) != '\0') {
      *(undefined4 *)(unaff_ESI + 0xc) = 0x86;
    }
  }
  else {
    cVar2 = FUN_008edd70(local_c,&local_10,local_34);
    if (cVar2 != '\0') {
      return;
    }
    iVar1 = *(int *)(unaff_ESI + 0x130);
    while (0 < iVar1) {
      *(int *)(unaff_ESI + 0x1c) = *(int *)(unaff_ESI + 0x1c) + -1;
      if (*(ushort *)(*(int *)(unaff_ESI + 0x18) + *(int *)(unaff_ESI + 0x1c) * 4) <
          *(ushort *)(unaff_ESI + 0x74)) {
        FUN_008ede40(local_10);
      }
      else if (*(char *)(unaff_ESI + 0x231) != '\0') {
        *(undefined4 *)(unaff_ESI + 0xc) = 0x86;
        return;
      }
      *(int *)(unaff_ESI + 0x130) = *(int *)(unaff_ESI + 0x130) + -1;
      iVar1 = *(int *)(unaff_ESI + 0x130);
    }
  }
  *(undefined4 *)(unaff_ESI + 0x130) = 1;
  *(undefined4 *)(unaff_ESI + 0x20) = *(undefined4 *)(unaff_ESI + 0x1c);
  return;
}

