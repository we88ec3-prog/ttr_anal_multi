
int FUN_008eacd0(undefined4 param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  int unaff_ESI;
  undefined4 local_8;
  
  uVar1 = *(undefined4 *)(unaff_ESI + 0x18);
  local_8 = 0;
  uVar2 = FUN_008b9850(uVar1);
  FUN_008eac30(param_1,&local_8);
  FUN_008eac50(param_1,*(undefined4 *)(unaff_ESI + 0x30));
  iVar3 = FUN_008b97e0(uVar1,uVar2);
  if (iVar3 == 0) {
    *(int *)(unaff_ESI + 0x34) = (int)(short)local_8;
    *(undefined4 *)(unaff_ESI + 0x38) = 0;
    *(undefined4 *)(unaff_ESI + 0xb0) = 0;
    *(undefined4 *)(unaff_ESI + 0xb4) = 0;
    if (*(char *)(unaff_ESI + 0x40) == '\0') {
      *(undefined1 *)(unaff_ESI + 0x40) = 1;
      *(undefined4 *)(unaff_ESI + 0x3c) = 0;
    }
    iVar3 = 0;
  }
  return iVar3;
}

