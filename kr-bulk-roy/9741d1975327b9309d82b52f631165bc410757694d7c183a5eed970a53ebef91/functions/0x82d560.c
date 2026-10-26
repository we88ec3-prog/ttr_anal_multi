
void FUN_0082d560(uint param_1,uint param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  uint in_ECX;
  int in_EDX;
  undefined4 unaff_EDI;
  
  for (; uVar2 = param_1, in_ECX < param_3; in_ECX = in_ECX + 1) {
    for (; uVar2 < param_2; uVar2 = uVar2 + 1) {
      iVar1 = (*(int *)(in_EDX + 8) * in_ECX + uVar2) * 0x18;
      *(undefined4 *)(*(int *)(in_EDX + 0x20) + 4 + iVar1) = 1;
      *(undefined4 *)(*(int *)(in_EDX + 0x20) + 8 + iVar1) = unaff_EDI;
    }
  }
  return;
}

