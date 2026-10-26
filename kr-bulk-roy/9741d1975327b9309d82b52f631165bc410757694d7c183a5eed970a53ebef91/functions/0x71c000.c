
void FUN_0071c000(void)

{
  int in_EAX;
  undefined4 uVar1;
  int in_ECX;
  undefined4 *unaff_ESI;
  
  if (in_ECX == in_EAX) {
    *unaff_ESI = &DAT_00bf2375;
    *(undefined1 *)(unaff_ESI + 1) = 0;
    return;
  }
  uVar1 = FUN_0071bf40();
  *unaff_ESI = uVar1;
  *(undefined1 *)(unaff_ESI + 1) = 1;
  return;
}

