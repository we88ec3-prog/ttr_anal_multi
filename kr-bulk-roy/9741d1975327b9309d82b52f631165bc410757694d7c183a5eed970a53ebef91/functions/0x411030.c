
void FUN_00411030(void)

{
  undefined4 uVar1;
  undefined4 in_ECX;
  int unaff_ESI;
  
  FUN_004e0fc0(unaff_ESI + 0x114);
  if (*(int *)(unaff_ESI + 0x124) != *(int *)(unaff_ESI + 0x128)) {
    uVar1 = FUN_00858240(*(int *)(unaff_ESI + 0x128),in_ECX);
    FUN_00516210(*(undefined4 *)(unaff_ESI + 0x128));
    *(undefined4 *)(unaff_ESI + 0x128) = uVar1;
  }
  FUN_00823850();
  *(undefined4 *)(unaff_ESI + 0x148) = 0;
  *(undefined4 *)(unaff_ESI + 0x158) = 0;
  return;
}

