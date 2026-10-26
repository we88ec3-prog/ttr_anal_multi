
void FUN_00621830(void)

{
  int iVar1;
  int in_EAX;
  int unaff_ESI;
  
  iVar1 = *(int *)(in_EAX + 8);
  if (iVar1 == *(int *)(*(int *)(unaff_ESI + 0xec) + 0x20)) {
    FUN_0061f710(1);
    FUN_006221d0();
    return;
  }
  if (iVar1 == *(int *)(*(int *)(unaff_ESI + 0xf0) + 0x20)) {
    FUN_0061f710(0);
    FUN_006221d0();
    return;
  }
  if (iVar1 == *(int *)(*(int *)(unaff_ESI + 0xf4) + 0x20)) {
    FUN_0061fc20(1);
    FUN_006221d0();
    return;
  }
  if (iVar1 == *(int *)(*(int *)(unaff_ESI + 0xf8) + 0x20)) {
    FUN_0061fc20(0);
    FUN_006221d0();
    return;
  }
  if (iVar1 == *(int *)(*(int *)(unaff_ESI + 0xfc) + 0x20)) {
    FUN_0061fd40(1);
    FUN_006221d0();
    return;
  }
  if (iVar1 == *(int *)(*(int *)(unaff_ESI + 0x100) + 0x20)) {
    FUN_0061fd40(0);
    FUN_006221d0();
    return;
  }
  if (iVar1 == *(int *)(*(int *)(unaff_ESI + 0x108) + 0x20)) {
    FUN_0061fcb0(1);
    FUN_006221d0();
    return;
  }
  if (iVar1 == *(int *)(*(int *)(unaff_ESI + 0x10c) + 0x20)) {
    FUN_0061fcb0(0);
    FUN_006221d0();
    return;
  }
  if (iVar1 == *(int *)(*(int *)(unaff_ESI + 0x110) + 0x20)) {
    FUN_00621ed0(unaff_ESI,1);
    return;
  }
  if (iVar1 == *(int *)(*(int *)(unaff_ESI + 0x114) + 0x20)) {
    FUN_00621ed0(unaff_ESI,0);
  }
  return;
}

