
uint FUN_008dd9a0(void)

{
  byte *pbVar1;
  undefined4 *in_EAX;
  int iVar2;
  int iVar3;
  int *unaff_EBX;
  uint uVar4;
  byte local_8 [4];
  
  uVar4 = 0;
  iVar2 = FUN_008bab70(*in_EAX,local_8,*(undefined1 *)(in_EAX + 3));
  if (iVar2 == 0) {
    iVar3 = 0;
    if (*(byte *)(in_EAX + 3) != 0) {
      do {
        pbVar1 = local_8 + iVar3;
        iVar3 = iVar3 + 1;
        uVar4 = uVar4 << 8 | (uint)*pbVar1;
      } while (iVar3 < (int)(uint)*(byte *)(in_EAX + 3));
    }
  }
  *unaff_EBX = iVar2;
  return uVar4;
}

