
void FUN_0077d0f0(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int unaff_ESI;
  int *unaff_EDI;
  
  if ((*(float *)(unaff_ESI + 0x24) < *(float *)(unaff_ESI + 0x1c)) &&
     (*(char *)(unaff_ESI + 0x20) != '\0')) {
    FUN_008ff2e0((double)(*(float *)(unaff_ESI + 0x1c) / *(float *)(unaff_ESI + 0x24)));
  }
  iVar3 = FUN_008fed10();
  iVar5 = *(int *)(unaff_ESI + 0x30);
  iVar4 = *(int *)(unaff_ESI + 0x28) * (iVar3 % iVar5);
  iVar1 = *(int *)(unaff_ESI + 0x34);
  iVar2 = *(int *)(unaff_ESI + 0x2c);
  unaff_EDI[2] = *(int *)(unaff_ESI + 0x28) + iVar4;
  *unaff_EDI = iVar4;
  iVar5 = ((iVar3 / iVar5) % iVar1) * iVar2;
  unaff_EDI[3] = iVar2 + iVar5;
  unaff_EDI[1] = iVar5;
  return;
}

