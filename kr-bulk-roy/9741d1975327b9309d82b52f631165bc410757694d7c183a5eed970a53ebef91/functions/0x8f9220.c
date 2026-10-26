
int FUN_008f9220(void)

{
  int *piVar1;
  int in_EAX;
  int iVar2;
  int unaff_ESI;
  
  *(int *)(unaff_ESI + 0x14) = in_EAX;
  piVar1 = (int *)(unaff_ESI + 0x18);
  *piVar1 = *(int *)(in_EAX + 0x74);
  FUN_008b82d0(*(undefined4 *)(unaff_ESI + 0x1c));
  if (*piVar1 == 0) {
    iVar2 = FUN_008f8120();
    if (iVar2 == 0) {
      *(int *)(in_EAX + 0x74) = *piVar1;
      *(code **)(in_EAX + 0x78) = FUN_008f3f40;
      return 0;
    }
  }
  else {
    iVar2 = 0;
  }
  return iVar2;
}

